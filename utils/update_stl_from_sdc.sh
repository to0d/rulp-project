#/bin/bash

script_abs=$(readlink -f $0)
utils_dir=$(dirname $script_abs)
prj_dir=$(dirname $utils_dir)

STL_PATH=$prj_dir/stl
SDC_PATH=$prj_dir/../sdc-stl/stl

update_source()
{
  local from_path=$1
  local to_path=$2

  if [ -f "$from_path" ]; then

    local suffix=`echo "${from_path##*.}"`
    local file_name=`basename $file`
    if [ $suffix == "h" -o $suffix == "c" -o $suffix == "cpp" -o $suffix == "sh" -o $suffix == "ll" -o $suffix == "txt" -o $suffix == "dot" -o $suffix == "output" -o $suffix == "md" -o $file_name == "makefile" ] ;
    then 
      echo "updating: " $to_path
      sed 's/SDC/LFC/g;s/sdc/lfc/g' $from_path > $to_path
    fi

  elif [ -d "$from_path" ]; then
    mkdir -p $to_path
    for file in "$from_path"/*; 
    do
      file_name=`basename $file`
      update_source $from_path/$file_name $to_path/$file_name
    done
  fi
}

update_source  $SDC_PATH/include/sdc    $STL_PATH/include/lfc
update_source  $SDC_PATH/docs/          $STL_PATH/docs/
update_source  $SDC_PATH/test_unit/     $STL_PATH/test_unit/
update_source  $SDC_PATH/test_fvt/      $STL_PATH/test_fvt/