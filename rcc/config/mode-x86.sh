#/bin/bash

show_cxxflags()
{
  echo ""
}

show_cflags()
{
  echo ""
}

show_ldflags()
{
  echo ""
}

show_name()
{
  echo "x86"
}

show_usage()
{
  echo "bcf --cxxflags"
}

show_baddr() 
{
  echo "0x20040000" # 0x20000000 + 256K
}

for arg in "$@"
do
  if [ $arg = "--cxxflags" ]; then
    show_cxxflags
  elif [ $arg = "--cflags" ]; then
    show_cflags
  elif [ $arg = "--ldflags" ]; then
    show_ldflags
  elif [ $arg = "--name" ]; then
    show_name
  elif [ $arg = "--baddr" ]; then
    show_baddr
  else
    echo "unknown option: "$arg
    show_usage
    exit 1
  fi
done
