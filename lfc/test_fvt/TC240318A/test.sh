#/bin/sh

script_abs=$(readlink -f $0)
script_dir=$(dirname $script_abs)
test_dir=$(dirname $script_dir)
lfc_dir=$(dirname $test_dir)
prj_dir=$(dirname $lfc_dir)
LCF=$lfc_dir/config.sh

function output()
{
    for arg in "$@"
    do
        rst=`echo $arg | sed -e "s#$prj_dir#rulp#"`
        echo -n "$rst"
        echo -n " "
    done
    echo ""    
}

echo "LCF --cxxflags: "
output `$LCF --cxxflags`
echo ""

echo "LCF --includedir: "
output `$LCF --includedir`
echo ""

echo "LCF --libs: "
output `$LCF --libs`
echo ""

echo "LCF --ldflags: "
output `$LCF --ldflags`
echo ""

echo "LCF --x: "
output `$LCF --x`
echo ""

echo "LCF --libs --includedir: "
output `$LCF --libs --includedir`
echo ""

echo "output: done!"







