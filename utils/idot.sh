#!/bin/sh
#####################################################
script_abs=$(readlink -f "$0")
script_dir=$(dirname $script_abs)
workspace=`pwd`

readonly PNG_TYPE="png"
readonly SVG_TYPE="svg"

relative_path=""
get_relative()
{
  file1=$1
  file2=$2
  
  dir1=$file1
  if [ -f "$file1" ]; then
      dir1=$(dirname "$(realpath "$file1")")
  fi

  relative_path=$(realpath --relative-to="$dir1" "$file2")
}

update_file_png()
{
  dot_abs=$(readlink -f $1)
  dot_dir=$(dirname $dot_abs)
  dot_suffix=`echo "${dot_abs##*.}"`
  dot_name=`basename $dot_abs`
  dot_name2=`echo $dot_name | awk -F . '{print $1}'`
  png_abs=$dot_dir/$dot_name2".png"

  get_relative $workspace $dot_abs 
  echo -n "process: "$relative_path
  dot -Tpng -o $png_abs $dot_abs
  echo " done"
}

update_file_svg()
{
  dot_abs=$(readlink -f $1)
  dot_dir=$(dirname $dot_abs)
  dot_suffix=`echo "${dot_abs##*.}"`
  dot_name=`basename $dot_abs`
  dot_name2=`echo $dot_name | awk -F . '{print $1}'`
  png_abs=$dot_dir/$dot_name2".svg"

  get_relative $workspace $dot_abs 
  echo -n "process: "$relative_path
  dot -Tsvg -o $png_abs $dot_abs
  echo " done"
}

update_folder()
{
  dot_files=$(find $1 -name "*.dot")
  out_type=$2
  for dot_file in $dot_files
  do
    if [ $out_type = $PNG_TYPE ]; then 
      update_file_png $dot_file
    elif [ $out_type = $SVG_TYPE ]; then 
      update_file_svg $dot_file
    else
      echo "invalid output type "$out_type
    fi
  done
}

update_dot()
{
  dot_file=$1
  out_type=$2

  if [ -d "$dot_file" ]; then # folder
    update_folder $dot_file $out_type
  elif [ -f "$dot_file" ]; then
    if [ $out_type = $PNG_TYPE ]; then 
      update_file_png $dot_file
    elif [ $out_type = $SVG_TYPE ]; then 
      update_file_svg $dot_file
    else
      echo "[err] invalid output type "$out_type
    fi
  else
    echo "[err] file not found: "$dot_file
  fi
}

input_file=$workspace
input_type=$SVG_TYPE

if [ $# -eq 0 ] ; then
  input_file=$workspace
elif [ $# -eq 1 ] ; then
  input_file=$1
elif [ $# -eq 2 ] ; then
  input_file=$1
  input_type=$2
else
  echo "[err] invalid parameters: "$#
  exit 1
fi

update_dot $input_file $input_type
