#/bin/bash

script_abs=$(readlink -f $0)
script_dir=$(dirname $script_abs)
project_dir=$(dirname $script_dir)
source $script_dir/rcc_util.sh

# ********************************************************************** #
# Global variables
# ********************************************************************** #
readonly CMD_INVALID="--invalid"
readonly CMD_COMPILE="--compile"
readonly CMD_CODEGEN="--codegen"
readonly CMD_VERSION="--version"
readonly CMD_CMDHELP="--cmdhelp"
readonly PARA_PARA="-para"
readonly PARA_OBJ="-o"
readonly PARA_INC="-I"
readonly PARA_MACRO="-D"
readonly PARA_OPT="-O"
readonly PARA_NODE="-N"
readonly PARA_TRACE="-t"
readonly PARA_TYPE="-x"
readonly PARA_SCCVIEW="-v"
readonly PARA_CMDVIEW="-V"
readonly PARA_KTF="-ktf"              # --keep-tmp-files
readonly PARA_CFG="--cfg"             # dump CFG
readonly PARA_CFG_ONLY="--cfg-only"   # dump CFG only
readonly PARA_DFG="--dfg"             # dump DFG
readonly PARA_TARGET="-target"
readonly PARA_MODE="-mode"
readonly PARA_LPATH="-L"
readonly PARA_LLIB="-l"
readonly PARA_ASSM="-S"
readonly PARA_PREP="--prep"
readonly PARA_IRLL="-emit-llvm"

OPT_SRC=
OPT_OBJ=""
OPT_LVL="0"
OPT_INC=""
OPT_MAC=""
OPT_TYPE=""
OPT_KTF=""
OPT_STR=""
OPT_CFG=""
OPT_CFG_ONLY=""
OPT_DFG=""
OPT_MODE="x86"
OPT_OTHER=""
OPT_ASSM=0
OPT_CIR=0
OPT_NODE=0
OPT_CMDVIEW=0
OPT_SCCVIEW=0
OPT_PREP=0
OPT_IRLL=0
OPT_IRSD=0
OPT_CSF=0
ACT_COMPILE=0
ACT_CODEGEN=0

# ********************************************************************** #
# Checking input options
# ********************************************************************** #
CMD_FMT_STR=`$cmd_format $@`
IFS=' ' read -r -a CMD_FMT_VEC <<< "$CMD_FMT_STR"

para_len=${#CMD_FMT_VEC[@]}
if [ $para_len -eq 0 ] ; then
  echo "[err][rcc] invalid arguments"
  exit 1
fi

cmd_type=${CMD_FMT_VEC[0]}
if [ $cmd_type == $CMD_VERSION ] ; then
  show_version
  exit 0
elif [ $cmd_type == $CMD_CMDHELP ] ; then
  show_help
  exit 0
elif [ $cmd_type == $CMD_COMPILE ] ; then
  ACT_COMPILE=1
elif [ $cmd_type == $CMD_CODEGEN ] ; then
  ACT_CODEGEN=1
else
  echo "[err][rcc] invalid command format: type="$cmd_type
  echo -n "input : "
    for arg in "$@"
    do
      echo -n "$arg"
      echo -n " "
    done
    echo ""
  echo "output: "$CMD_FMT_STR
  exit 1
fi

for ((i=1; i< $para_len; i++))
do
  cmd_para=${CMD_FMT_VEC[$i]}
  ii=`expr $i + 1`
  #echo $cmd_para

  if [ $cmd_para == $PARA_PARA ] ; then
    if [ $ACT_CODEGEN -eq 1 ]; then
      OPT_SRC=$OPT_SRC" "${CMD_FMT_VEC[$ii]}
      i=$ii
    else
      OPT_SRC=${CMD_FMT_VEC[$ii]}
      i=$ii
    fi
  elif [ $cmd_para == $PARA_OBJ ] ; then
    OPT_OBJ=${CMD_FMT_VEC[$ii]}
    i=$ii
  elif [ $cmd_para == $PARA_INC ] ; then
    OPT_INC=$OPT_INC" -I "${CMD_FMT_VEC[$ii]}
    i=$ii
  elif [ $cmd_para == $PARA_MACRO ] ; then
    OPT_MAC=$OPT_MAC" -D "${CMD_FMT_VEC[$ii]}
    i=$ii
  elif [ $cmd_para == $PARA_LPATH ] ; then
    OPT_OTHER=$OPT_OTHER" -L"${CMD_FMT_VEC[$ii]}
    i=$ii
  elif [ $cmd_para == $PARA_LLIB ] ; then
    OPT_OTHER=$OPT_OTHER" -l"${CMD_FMT_VEC[$ii]}
    i=$ii
  elif [ $cmd_para == $PARA_OPT ] ; then
    OPT_LVL=${CMD_FMT_VEC[$ii]}
    i=$ii
  elif [ $cmd_para == $PARA_NODE ] ; then
    OPT_NODE=${CMD_FMT_VEC[$ii]}
    i=$ii
  elif [ $cmd_para == $PARA_TYPE ] ; then
    OPT_TYPE=${CMD_FMT_VEC[$ii]}
    i=$ii
  elif [ $cmd_para == $PARA_TRACE ] ; then
    OPT_TRACE=1
  elif [ $cmd_para == $PARA_ASSM ] ; then
    OPT_ASSM=1
  elif [ $cmd_para == $PARA_PREP ] ; then
    OPT_PREP=1
  elif [ $cmd_para == $PARA_IRLL ] ; then
    OPT_IRLL=1
  elif [ $cmd_para == $PARA_SCCVIEW ] ; then
    OPT_SCCVIEW=1
  elif [ $cmd_para == $PARA_CMDVIEW ] ; then
    OPT_CMDVIEW=1
  elif [ $cmd_para == $PARA_KTF ] ; then
    OPT_KTF=$PARA_KTF
  elif [ $cmd_para == $PARA_CFG ] ; then
    OPT_CFG=$PARA_CFG
  elif [ $cmd_para == $PARA_CFG_ONLY ] ; then
    OPT_CFG_ONLY=$PARA_CFG_ONLY
  elif [ $cmd_para == $PARA_DFG ] ; then
    OPT_DFG=$PARA_DFG
  elif [ $cmd_para == $PARA_TARGET ] ; then
    OPT_TARGET=${CMD_FMT_VEC[$ii]}
    i=$ii
    OPT_OTHER=$OPT_OTHER" "$PARA_TARGET" "$OPT_TARGET
  else
    if [[ $cmd_para =~ ^(-W|-m|-D) ]]; then
      OPT_OTHER=$OPT_OTHER" "$cmd_para
    else
      echo "[err][rcc] invalid arguments: \'"$cmd_para"\'"
      exit 1
    fi
  fi
  
done

# Check transfer level: 0, 1, 2, 3
OPT_LVL=`expr $OPT_LVL`
if [ $OPT_LVL -gt 4 -o $OPT_LVL -lt 0 ] ; then
  echo "[err][rcc] invalid level: "$OPT_LVL
  exit 1
fi

# Check source file
if [ $ACT_COMPILE -eq 1 ]; then
  if [ ! -e $OPT_SRC ]; then
    echo "[err][rcc] source not found: "$OPT_SRC
    usage
    exit 1
  fi
fi 

# ********************************************************************** #
# Local variables
# ********************************************************************** #
scc_dir=$project_dir/rcc
BCC_OPT=""

src_name=`basename $OPT_SRC`
src_name2=`echo $src_name | awk -F . '{print $1}'`
src_suffix=`echo "${OPT_SRC##*.}"`
src_dir=$src_name".ll"
src_final=""
err_found=0

OPT_TRANS=
if [ $OPT_TRACE -eq 1 ]; then
  OPT_TRANS=$OPT_TRANS" -t"
fi

# Check compile mode
mcf=$scc_dir/config/mode-$OPT_MODE.sh
if [ ! -e $mcf ]; then
  echo "error, mode configure file not found: "$mcf
  exit 1
fi

CC=$scc_dir/build/fcc
OBJCPY=$scc_dir/build/llvm-objcopy

update_cc_option()
{
  BE_OPT=`$mcf --cflags`
  BCC_OPT=" -x c "$BE_OPT
}

update_cxx_option()
{
  BE_OPT=`$mcf --cxxflags`
  BCC_OPT=" -x c++ "$BE_OPT
}

update_rulp_option()
{
  BE_OPT=`$mcf --cxxflags`
  BCC_OPT=" -x rulp "$BE_OPT
}

update_ll_option()
{
  BE_OPT=`$mcf --cflags`
  BCC_OPT=$BE_OPT
}

# Check object type 
if [ $cmd_type == $CMD_COMPILE  ] ; then
  if [ ! -z $OPT_TYPE ] ; 
  then
    if [ $OPT_TYPE == "c" ] ; then
      update_cc_option
    elif [ $OPT_TYPE == "c++" ] ; then
      update_cxx_option
    elif [ $OPT_TYPE == "rulp" ] ; then
      update_rulp_option
    else
      echo "[err] invalid object type: "$OPT_TYPE
      exit 1
    fi
  else
    if [ $src_suffix == "c" ] ; then 
      update_cc_option
    elif [ $src_suffix == "cpp" ] ; then 
      update_cxx_option
    elif [ $src_suffix == "rulp" ] ; then
      update_rulp_option
    elif [ $src_suffix == "ll" ] ; then 
      OPT_CIR=1
      update_ll_option
    else
    
      echo "[err][rcc] invalid source suffix: "$src_suffix
      exit 1
    fi
  fi
fi

# Check object name 
if [ -z $OPT_OBJ ] ; then
  if [ $cmd_type == $CMD_COMPILE ] ; then
    OPT_OBJ=$src_name2".o"
  else
    echo "[err][rcc] object not specified: "$OPT_OBJ
    usage
    exit 1
  fi
fi

# ********************************************************************** #
# 
# ********************************************************************** #
CC_Name=clang

# ********************************************************************** #
# output options for debugging
# ********************************************************************** #
trace "[trace][rcc] cmd_typ="$cmd_type
trace "[trace][rcc] opt_src="$OPT_SRC
trace "[trace][rcc] opt_obj="$OPT_OBJf
trace "[trace][rcc] opt_lvl="$OPT_LVL
trace "[trace][rcc] opt_inc="$OPT_INC
trace "[trace][rcc] opt_mac="$OPT_MAC
trace "[trace][rcc] opt_trc="$OPT_TRACE
trace "[trace][rcc] bcc_opt="$BCC_OPT
trace "[trace][rcc] opt_typ="$OPT_TYPE
trace "[trace][rcc] cmdview="$OPT_CMDVIEW
trace "[trace][rcc] sccview="$OPT_SCCVIEW
trace "[trace][rcc] cc_name="$CC_Name
trace "[trace][rcc] opt_ktf="$OPT_KTF
trace "[trace][rcc] opt_oth="$OPT_OTHER
trace "[trace][rcc] opt_dmp="$OPT_CFG" "$OPT_CFG_ONLY" "$OPT_DFG
trace "[trace][rcc] opt_ass="$OPT_ASSM
trace "[trace][rcc] opt_cir="$OPT_CIR
trace "[trace][rcc] opt_nod="$OPT_NODE
trace "[trace][rcc] opt_pre="$OPT_PREP
trace "[trace][rcc] opt_irl="$OPT_IRLL



