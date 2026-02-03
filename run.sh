#!/bin/bash

if [ -z "$1" ]; then
    echo "Please enter filename"
    exit 1
fi
IFS='.' read -ra ADDR <<< "$1"
# Print each value of the array by using
# the loop
for val in "${ADDR[@]}";
do
    g++ "$1" -o "$val"
    exec "./$val"
    break
done
