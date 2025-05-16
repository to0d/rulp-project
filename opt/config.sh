#/bin/bash

script_abs=$(readlink -f $0)
opt_dir=$(dirname $script_abs)

show_includedir()
{
  echo -n " -I"$opt_dir/include
}

show_cxxflags()
{
  show_includedir
}

show_libs()
{
  echo -n " -lrulp_opt"
}

show_ldflags()
{
  echo -n " -L"$opt_dir/build
}


show_usage()
{
  echo "rcf --cxxflags"
}


for arg in "$@"
do
  if [ $arg = "--cxxflags" ]; then
    show_cxxflags
  elif [ $arg = "--includedir" ]; then
    show_includedir
  elif [ $arg = "--libs" ]; then
    show_libs
  elif [ $arg = "--ldflags" ]; then
    show_ldflags
  else
    echo "unknown option: "$arg
    show_usage
    exit 1
  fi
done

