#!/bin/bash

input_file="./tests/$1"
output_folder="./result"
push_swap_binary="./push_swap"

# Create the output folder if it doesn't exist
mkdir -p "$output_folder"

# Loop through each line in the input file
line_number=1
while IFS= read -r line || [[ -n "$line" ]]; do
    output_file="$output_folder/result_$line_number"
    "$push_swap_binary" $line | sed 's/\x1b\[[0-9;]*m//g' > "$output_file"
    ((line_number++))
done < "$input_file"