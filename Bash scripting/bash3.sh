#!/bin/bash
#Write a shell script receiving a path as argument, depending on if it's a file or a directory, display or list its content.
#Check whether argument was provided or not
if [ $# -eq 0 ]; then
    echo "No path provided"
    exit 1
fi

path="$1"
#Check if the  path is a file
if [ -f "$path" ]; then
    echo "Content of the file '$path': "
    cat "$path"
#Check if the path is a directory
elif [ -d "$path" ]; then
    echo "Listing contentts of the directory '$path':"
    ls "$path"
    exit 0
else echo " The provoded path is neither a file or dir "
fi
