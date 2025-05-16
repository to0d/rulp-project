#!/bin/bash

# Get absolute paths
script_abs=$(readlink -f "$0")
utils_dir=$(dirname "$script_abs")
prj_dir=$(dirname "$utils_dir")
add_script="$utils_dir/add_license.sh"

# Verify the license script exists
if [ ! -f "$add_script" ]; then
    echo "Error: License script not found at $add_script" >&2
    exit 1
fi

# Make the script executable if needed
if [ ! -x "$add_script" ]; then
    chmod +x "$add_script" || {
        echo "Error: Cannot make $add_script executable" >&2
        exit 1
    }
fi

# File processing function
update_file() {
    local file="$1"
    # Only process regular files (skip symlinks, directories, etc.)
    if [ -f "$file" ]; then
        "$add_script" "$file"
    fi
}

# Main processing function
process_directory() {
    local target_dir="$1"
    
    # Safety checks
    if [ ! -d "$target_dir" ]; then
        echo "Error: Directory $target_dir not found" >&2
        return 1
    fi

    # Export function for find command
    export -f update_file
    export add_script

    echo "Processing files in $target_dir..."
    find "$target_dir" -type f \( -name "*.h" -o -name "*.hpp" \) \
        -exec bash -c 'update_file "$0"' {} \;
    
    return $?
}

# Execute processing
process_directory "$prj_dir/stl/include"

exit $?