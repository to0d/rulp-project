#/bin/sh

script_abs=$(readlink -f $0)
script_dir=$(dirname $script_abs)
rule_dir=$(dirname $script_dir)
project_dir=$(dirname $rule_dir)
lang_dir=$(dirname $project_dir)/lang
test_dir=$rule_dir/test_unit

lt_action_list=0
lt_action_make=0
lt_action_run=0
lt_action_clean=0

test_select=""

if [ $# -eq 0 ]; then
    lt_action_list=0
    lt_action_clean=0
    lt_action_make=0
    lt_action_run=1
else
    while getopts 'n:lrmch' OPTION
    do
        case $OPTION in
        l)  lt_action_list=1
            ;;
        r)  lt_action_run=1
            ;;
        m)  lt_action_make=1
            ;;
        n)  test_select=$OPTARG
            ;;
        c)  lt_action_clean=1
            ;;
        h)  usage
            exit 0
            ;; 
        \?) echo "lt error: unknown parameter '$OPTION'"
            usage
            exit 1
            ;;
        esac
    done
fi

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$project_dir/build
export PATH=$lang_dir/load:$PATH
export PROJECT_HOME=$project_dir

if [ $lt_action_clean == 1 ]; then
    cd $test_dir
    make clean
fi

if [ $lt_action_make == 1 ]; then
    cd $test_dir
    make
fi

if [ $lt_action_list == 1 ]; then
    cd $test_dir
    ./run.out --gtest_list_tests
fi

if [ $lt_action_run == 1 ]; then
    cd $test_dir

    if [ -z "$test_select" ]; then
        ./run.out
    else
        ./run.out --gtest_filter=$test_select
    fi
fi






