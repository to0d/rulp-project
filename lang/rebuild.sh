#!/bin/bash
#####################################################

script_abs=$(readlink -f $0)
rulp_dir=$(dirname $script_abs)

cpu_num=`lscpu | grep -e "^CPU(s):*" | awk '{print $2}'`
make_opt="-j"$cpu_num
make_opt=$make_opt" --no-print-directory"

DO_BUILD=1
DO_UT=1
DO_FVT=1

for arg in "$@"
do
  if [ $arg = "--only-fvt" ]; then
    DO_BUILD=0
    DO_UT=0
    DO_FVT=1
  else
    echo "unknown option: "$arg
    show_usage
    exit 1
  fi
done

function run_build()
{
  echo "******************  SETUP *****************"
  ./setup.sh
  if [ $? -ne 0 ] ; then
    exit 1
  fi
  echo ""

  echo "****************  Build RULP ****************"
  make clean-rulp $make_opt && make rulp $make_opt
  if [ $? -ne 0 ] ; then
    exit 1
  fi
  echo ""
}

function run_ut()
{
  echo "***************  Run UT **************"
  make -C test_unit clean $make_opt && make -C test_unit all $make_opt
  if [ $? -ne 0 ] ; then
    exit 1
  fi
  ./test_unit/run.sh
  echo ""
}

function run_fvt()
{
  echo "****************  Run FVT ****************"
}

echo "****************  Rebuild RULP ****************"
cd $rulp_dir

if [ $DO_BUILD -eq 1 ]; then
  run_build
fi

if [ $DO_UT -eq 1 ]; then
  run_ut
fi

if [ $DO_FVT -eq 1 ]; then
  run_fvt
fi

echo ""
echo ""