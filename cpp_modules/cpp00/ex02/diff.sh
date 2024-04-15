#! /bin/bash

# Input the file outputted by Makefile, the program will remove it's timestamp
#  and compare it to the reference file 19920104_091532.log ;
# If the two files are identical, diff will exit with status 0 and 
#  output "OK", otherwise it will exit with status 1 and output "KO".

if [ -z "$1" ]; then
    echo "Usage: $0 <my_logfile.log>"
    exit 1
fi

# Check if the file exists
if [ ! -f "$1" ]; then
    echo "File $1 does not exist"
    exit 1
fi

# Takes off the timestamp characters of each line
sed 's/^.\{17\}//' $1 > diff1.log
sed 's/^.\{17\}//' 19920104_091532.log > diff2.log

# Compare the two files and output the result
diff diff1.log diff2.log
if [ $? -eq 0 ]; then
    echo "OK"
else
    echo "KO"
fi
