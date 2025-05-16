#!/bin/bash
#####################################################

script_abs=$(readlink -f $0)
project_dir=$(dirname $script_abs)
cpu_num=`lscpu | grep -e "^CPU(s):*" | awk '{print $2}'`
make_opt="-j"$cpu_num
make_opt=$make_opt" --no-print-directory"

DO_BUILD=1
DO_UT=1
DO_FVT=1
DO_STL=1
DO_RCC=1

FVT_OPT=""

for arg in "$@"
do
  if [ $arg = "--only-fvt" ]; then
    DO_BUILD=0
    DO_UT=0
    DO_FVT=1
    DO_STL=0
    DO_RCC=0
  elif [ $arg = "--only-ut" ]; then
    DO_BUILD=0
    DO_UT=1
    DO_FVT=0
    DO_STL=0
    DO_RCC=0
  elif [ $arg = "--only-stl" ]; then
    DO_BUILD=0
    DO_UT=0
    DO_FVT=0
    DO_STL=1
    DO_RCC=0
  elif [ $arg = "--only-rcc" ]; then
    DO_BUILD=0
    DO_UT=0
    DO_FVT=0
    DO_STL=0
    DO_RCC=1
  elif [ $arg = "-s" ]; then
    make_opt=$make_opt" -s"
  elif [ $arg = "-p" ]; then
    FVT_OPT=$FVT_OPT" -p"
  else
    echo "unknown option: "$arg
    show_usage
    exit 1
  fi
done

function red_echo() {
  echo -e "\033[31m$1\033[0m"
}


function setup() {

  red_echo "setup project"
  ./setup.sh
  if [ $? -ne 0 ] ; then
    exit 1
  fi
}

############################ LFC ############################
lfc_dir=$project_dir/lfc

function run_lfc_build()
{  
  cd $lfc_dir

  red_echo "[lfc] building project"
  make clean-lfc $make_opt && make lfc $make_opt
  if [ $? -ne 0 ] ; then
    exit 1
  fi
}

function run_lfc_ut()
{  
  red_echo "[lfc] building unittest"

  cd $lfc_dir
  rst_file=result.txt
  make -C test_unit clean -s $make_opt && make -C test_unit all $make_opt
  if [ $? -ne 0 ] ; then
    exit 1
  fi

  ./test_unit/run.sh > $rst_file 2>&1  
  fail_count=`cat $rst_file | grep FAILED | wc -l`
  if [ $fail_count -ne 0 ] ; then
    cat $rst_file | grep FAILED
    rm -rf $rst_file
    echo "failure found"
    exit 1
  fi

  succ_count=`cat $rst_file | grep PASSED`
  echo $succ_count
  rm -rf $rst_file
}

function run_lfc_fvt()
{
  red_echo "[lfc] building fvt"

  cd $lfc_dir
  make clean-fvt $make_opt && make fvt $make_opt
  if [ $? -ne 0 ] ; then
    exit 1
  fi

  ./test_fvt/run.sh -r $FVT_OPT
  if [ $? -ne 0 ] ; then
    exit 1
  fi
}

############################ LFM ############################
lfm_dir=$project_dir/lfm

function run_lfm_build()
{  
  cd $lfm_dir

  red_echo "[lfm] building project"
  make clean-lfm $make_opt && make lfm $make_opt
  if [ $? -ne 0 ] ; then
    exit 1
  fi
}

function run_lfm_ut()
{  
  red_echo "[lfm] building unittest"

  cd $lfm_dir
  rst_file=result.txt
  make -C test_unit clean -s $make_opt && make -C test_unit all $make_opt
  if [ $? -ne 0 ] ; then
    exit 1
  fi

  ./test_unit/run.sh > $rst_file 2>&1  
  fail_count=`cat $rst_file | grep FAILED | wc -l`
  if [ $fail_count -ne 0 ] ; then
    cat $rst_file | grep FAILED
    rm -rf $rst_file
    echo "failure found"
    exit 1
  fi

  succ_count=`cat $rst_file | grep PASSED`
  echo $succ_count
  rm -rf $rst_file
}

############################ LANG ############################
lang_dir=$project_dir/lang

function run_lang_build()
{
  red_echo "[lan] building project"
  cd $lang_dir
  make clean-lang $make_opt && make lang $make_opt
  if [ $? -ne 0 ] ; then
    exit 1
  fi
}

function run_lang_ut()
{
  red_echo "[lan] building unittest"
  cd $lang_dir
  rst_file=result.txt
  make -C test_unit clean $make_opt && make -C test_unit all $make_opt
  if [ $? -ne 0 ] ; then
    exit 1
  fi

  ./test_unit/run.sh > $rst_file 2>&1
  fail_count=`cat $rst_file | grep FAILED | wc -l`
  if [ $fail_count -ne 0 ] ; then
    cat $rst_file | grep FAILED
    rm -rf $rst_file
    echo "failure found"
    exit 1
  fi

  succ_count=`cat $rst_file | grep PASSED`
  echo $succ_count
  rm -rf $rst_file
}

############################ OPT ############################
opt_dir=$project_dir/opt

function run_opt_build()
{  
  red_echo "[opt] building project"

  cd $opt_dir
  make clean-opt $make_opt && make opt $make_opt
  if [ $? -ne 0 ] ; then
    exit 1
  fi
}

function run_opt_ut()
{
  red_echo "[opt] building unittest"

  cd $opt_dir
  rst_file=result.txt
  make -C test_unit clean $make_opt && make -C test_unit all $make_opt
  if [ $? -ne 0 ] ; then
    exit 1
  fi

  ./test_unit/run.sh > $rst_file 2>&1
  fail_count=`cat $rst_file | grep FAILED | wc -l`
  if [ $fail_count -ne 0 ] ; then
    cat $rst_file | grep FAILED
    rm -rf $rst_file
    echo "failure found"
    exit 1
  fi

  succ_count=`cat $rst_file | grep PASSED`
  echo $succ_count
  rm -rf $rst_file
}

############################ RULE ############################
rule_dir=$project_dir/rule

function run_rule_build()
{  
  red_echo "[rul] building project"

  cd $rule_dir
  make clean-rule $make_opt && make rule $make_opt
  if [ $? -ne 0 ] ; then
    exit 1
  fi
}

function run_rule_ut()
{
  red_echo "[rul] building unittest"

  cd $rule_dir
  rst_file=result.txt
  make -C test_unit clean $make_opt && make -C test_unit all $make_opt
  if [ $? -ne 0 ] ; then
    exit 1
  fi

  ./test_unit/run.sh > $rst_file 2>&1
  fail_count=`cat $rst_file | grep FAILED | wc -l`
  if [ $fail_count -ne 0 ] ; then
    cat $rst_file | grep FAILED
    rm -rf $rst_file
    echo "failure found"
    exit 1
  fi

  succ_count=`cat $rst_file | grep PASSED`
  echo $succ_count
  rm -rf $rst_file
}

############################ RCC ############################
rcc_dir=$project_dir/rcc

function run_rcc_build()
{  
  red_echo "[rcc] building project"

  cd $rcc_dir
  make clean-util $make_opt && make util $make_opt
  if [ $? -ne 0 ] ; then
    exit 1
  fi
}

function run_rcc_fvt()
{
  red_echo "[rcc] building fvt"

  cd $rcc_dir
  make -C test_fvt clean $make_opt && make -C test_fvt $make_opt
  if [ $? -ne 0 ] ; then
    exit 1
  fi

  ./test_fvt/run.sh -r $FVT_OPT
  if [ $? -ne 0 ] ; then
    exit 1
  fi
}

############################ STL ############################
stl_dir=$project_dir/stl

function setup_stl_x86() {

  cd $stl_dir

  red_echo "[stl] setup x86 mode"
  ./config/setup_x86.sh
  if [ $? -ne 0 ] ; then
    exit 1
  fi
}

function run_stl_ut()
{
  red_echo "[stl] building unittest"

  cd $stl_dir
  rst_file=result.txt
  make -C test_unit clean $make_opt && make -C test_unit all $make_opt
  if [ $? -ne 0 ] ; then
    exit 1
  fi

  ./test_unit/run.sh > $rst_file 2>&1
  fail_count=`cat $rst_file | grep FAILED | wc -l`
  if [ $fail_count -ne 0 ] ; then
    cat $rst_file | grep FAILED
    rm -rf $rst_file
    echo "failure found"
    exit 1
  fi

  succ_count=`cat $rst_file | grep PASSED`
  echo $succ_count
  rm -rf $rst_file
}

function run_stl_fvt()
{
  red_echo "[stl] running fvt"
  ./test_fvt/run.sh -r $FVT_OPT
  if [ $? -ne 0 ] ; then
    exit 1
  fi

  red_echo "[stl] running tpl"
  ./test_tpl/run.sh -r $FVT_OPT
  if [ $? -ne 0 ] ; then
    exit 1
  fi
}

function build_stl_fvt()
{
  red_echo "[stl] building fvt"
  cd $stl_dir
  make -C test_fvt clean $make_opt && make -C test_fvt $make_opt
  if [ $? -ne 0 ] ; then
    exit 1
  fi 

  red_echo "[stl] building tpl"
  cd $stl_dir
  make -C test_tpl clean $make_opt && make -C test_tpl $make_opt
  if [ $? -ne 0 ] ; then
    exit 1
  fi 
}

############################ REBUILD ############################

if [ $DO_BUILD -eq 1 ]; then
  setup
  run_lfc_build
  run_lfm_build
  run_lang_build
  run_opt_build
  run_rule_build
fi

if [ $DO_UT -eq 1 ]; then
  run_lfc_ut
  run_lfm_ut
  run_lang_ut
  run_opt_ut
  run_rule_ut
fi

if [ $DO_FVT -eq 1 ]; then
  run_lfc_fvt
fi

if [ $DO_RCC -eq 1 ]; then
  run_rcc_build
  run_rcc_fvt
fi

if [ $DO_STL -eq 1 ]; then
  setup_stl_x86
  run_stl_ut
  build_stl_fvt
  run_stl_fvt
fi