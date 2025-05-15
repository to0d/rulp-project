#/bin/bash

LFC_PATH=../
SCC_PATH=../../../sdc-stl/stl

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

update_source  $SCC_PATH/include/sdc    $LFC_PATH/include/lfc
update_source  $SCC_PATH/docs/          $LFC_PATH/docs/
update_source  $SCC_PATH/test_unit/     $LFC_PATH/test_unit/
update_source  $SCC_PATH/test_fvt/      $LFC_PATH/test_fvt/