#!/bin/bash

print_random_line() {
    if [ -f "$1" ]; then
        lines=$(wc -l < "$1")
        if [ "$lines" -gt 0 ]; then
            random_line=$((RANDOM % lines + 1))
            sed -n "${random_line}p" "$1"
        else
            echo "File is empty"
        fi
    else
        echo "File not found"
    fi
}

print_random_line "./tests/$1"
