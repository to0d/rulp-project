#/bin/sh

# ********************************************************************** #
# Global variables
# ********************************************************************** #
script_abs=$(readlink -f $0)
rcc_dir=$(dirname $script_abs)
project_dir=$(dirname $rcc_dir)

lib_dir=$rcc_dir/lib
llvm15_lib=$project_dir/llvm-15/lib
mark_block=$rcc_dir/lib/mark_block.out
cmd_format=$rcc_dir/lib/cmd_format.out
simd_check=$rcc_dir/simd_check.sh

FCF=$rcc_dir/util/scc-fcf-config.sh
XOPT=$project_dir/build/fopt

# ********************************************************************** #
# Trace Util
# ********************************************************************** #
OPT_TRACE=0
trace()
{
  if [ $OPT_TRACE -eq 1 ]; then
    for arg in "$@"
    do
      rst=`echo $arg | sed -e "s#$project_dir#hpcc#"`
      echo -n "$rst"
      echo -n " "
    done
    echo ""
  fi
}

# ********************************************************************** #
# relative_path Util
# ********************************************************************** #
relative_path=""
get_relative()
{
  file1=$1
  file2=$2
  
  dir1=$file1
  if [ -f "$file1" ]; then
      dir1=$(dirname "$(realpath "$file1")")
  fi

  relative_path=$(realpath --relative-to="$dir1" "$file2")
}

# ********************************************************************** #
# Trace Util
# ********************************************************************** #
EXEC_CMD_PRE=""
exec_cmd()
{
  local cmdstr=""
  for arg in "$@"
  do
    cmdstr=$cmdstr" "$arg
  done
  trace $EXEC_CMD_PRE $cmdstr
  bash -c "$cmdstr"
}

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$lib_dir:$llvm15_lib

show_version()
{
  echo "RCC version 3.24.12"   # major 3 minor 24.11
  echo ""
  $simd_check --simd-dump-version
}

show_help()
{
  cat $script_dir/config/help_scc.txt
}

usage()
{
  echo "[info] usage: rcc -c <src> -o obj [-I include] [-t]"
  exit 1
}