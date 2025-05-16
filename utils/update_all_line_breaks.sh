#/bin/sh

script_abs=$(readlink -f "$0")
script_dir=$(dirname $script_abs)
workspace=$(dirname $script_dir)

function convert_newlines {
    local file=$1
    local temp_file="${file}.cvt_tmp"
    sed 's/\r$//' < "$file" > "$temp_file"
    mv "$temp_file" "$file"
}

function need_convert {
    local file=$1
    local suffix=`echo "${file##*.}"`
    local src_name=`basename $file`
     
    if [ $suffix == "sh" -o $suffix == "dot" ] ; 
    then 
        return 1
    fi
   
    return 0
}

function process_files {
    local folder=$1

    for file in "$folder"/*; do
        if [ -f "$file" ]; then
            need_convert $file
            if [ $? -eq 1 ] ; then
                echo -n "."
                convert_newlines "$file"
            fi
        elif [ -d "$file" ]; then
            process_files "$file"
        fi
    done
}

echo -n "converted files: "
process_files $workspace
need_convert $workspace/".gitignore "
echo "done"
