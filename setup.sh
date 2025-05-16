#/bin/sh

script_abs=$(readlink -f $0)
prj_dir=$(dirname $script_abs)

llvm_dir=`echo $LLVM_15`
if [ ! -n "$llvm_dir" ];
then
    echo "LLVM_15 is unset"
else
    echo "Running "$script_name" with LLVM_15=${llvm_dir}"
fi

###############################################
# Compile Tools for SCC project itself
#   - They must be chang toolchain 
###############################################
FCC=$llvm_dir/clang
FCX=$llvm_dir/clang++
FLC=$llvm_dir/llc
FPT=$llvm_dir/opt
FCF=$llvm_dir/llvm-config

###############################################
# Create links
###############################################
mkdir -p $prj_dir/build

rm -rf $prj_dir/build/fcc
rm -rf $prj_dir/build/fcx
rm -rf $prj_dir/build/flc
rm -rf $prj_dir/build/fopt
rm -rf $prj_dir/build/fcf

ln -s $FCC $prj_dir/build/fcc
ln -s $FCX $prj_dir/build/fcx
ln -s $FLC $prj_dir/build/flc
ln -s $FPT $prj_dir/build/fopt
ln -s $FCF $prj_dir/build/fcf

