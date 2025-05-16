#/bin/sh

test()
{
    echo "************* test *************"
    echo -n "input : "
    for arg in "$@"
    do
        echo -n $arg
        echo -n " "
    done
    echo "";
    
    echo -n "output: "    
    ../../lib/cmd_format.out $*
    echo "";
    echo "";
}

test -o main.o -O 0 -I ../../../include/simd
test -funlist hpl_func_list.txt

echo "output: done!"