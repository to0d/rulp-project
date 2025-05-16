#/bin/sh

# ********************************************************************** #
# Global variables
# ********************************************************************** #
script_abs=$(readlink -f $0)
script_dir=$(dirname $script_abs)
project_dir=$script_dir

include_dir=$project_dir/include
lfc_dir=$project_dir/lfc
bld_dir=$project_dir/build


# ********************************************************************** #
# Utils
# ********************************************************************** #
OPT_TRACE=0
trace()
{
    if [ $OPT_TRACE -eq 1 ]; then
        for arg in "$@"
        do
            echo -n "$arg"
            echo -n " "
        done
        echo ""
    fi
}

relative_path=""
get_relative()
{
    file1=$1
    file2=$2
    dir1=$(dirname "$(realpath "$file1")")
    relative_path=$(realpath --relative-to="$dir1" "$file2")
}
