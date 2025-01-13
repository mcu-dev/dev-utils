#!/bin/bash

# Directories to process
directories=(".")

# Log file
log_file="clang-format.log"
> "$log_file" # Clear the log file

# Loop through each directory
for dir in "${directories[@]}"; do
    # Find all .c and .h files in the current directory, excluding the build folder
    files=$(find "$dir" -type d -name "build" -prune -o -type f \( -name "*.c" -o -name "*.h" \) -print)

    if [ -z "$files" ]; then
        echo "No files found for formatting in $dir." | tee -a "$log_file"
    else
        for file in $files; do
            echo "Formatting file: $file" | tee -a "$log_file"
            if clang-format -i -style=file "$file" 2>&1 | tee -a "$log_file"; then
                echo "Formatted file: $file" | tee -a "$log_file"
            else
                echo "Error formatting file: $file" | tee -a "$log_file"
            fi
        done
    fi
done
