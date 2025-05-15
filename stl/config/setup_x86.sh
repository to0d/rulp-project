#/bin/sh

script_abs=$(readlink -f $0)
conf_dir=$(dirname $script_abs)
stl_dir=$(dirname $conf_dir)

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
FCF=$llvm_dir/llvm-config
SCF=$stl_dir/config/config_x86.sh

###############################################
# Create links
###############################################
mkdir -p $stl_dir/build

rm -rf $stl_dir/build/fcc
rm -rf $stl_dir/build/fcx
rm -rf $stl_dir/build/flc
rm -rf $stl_dir/build/fcf
rm -rf $stl_dir/build/scf

ln -s $FCC $stl_dir/build/fcc
ln -s $FCX $stl_dir/build/fcx
ln -s $FLC $stl_dir/build/flc
ln -s $FCF $stl_dir/build/fcf
ln -s $SCF $stl_dir/build/scf
