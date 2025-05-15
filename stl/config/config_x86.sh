#/bin/bash

script_abs=$(readlink -f $0)
conf_dir=$(dirname $script_abs)
stl_dir=$(dirname $conf_dir)

show_cxxflags()
{
  echo -n " -I"$stl_dir/include" -std=c++17"
}

show_ldflags()
{
  echo -n "-lstdc++"
}

show_includedir()
{
  echo -n $stl_dir/include
}

llvm_dir=`echo $LLVM_15`
show_fcc()
{
  echo -n $llvm_dir/clang
}

for arg in "$@"
do
  if [ $arg = "--cxxflags" ]; then
    show_cxxflags
  elif [ $arg = "--ldflags" ]; then
    show_ldflags
  elif [ $arg = "--fcc" ]; then
    show_fcc
  elif [ $arg = "--includedir" ]; then
    show_includedir
  else
    echo "unknown option: "$arg
    show_usage
    exit 1
  fi
done

