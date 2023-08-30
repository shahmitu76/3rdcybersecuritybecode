#!/bin/bash

username="$1"
group_names=$(groups "$username")
echo "The groups for $username is $group_names"
IFS=''
read -ra group_array <<< "$group_names"
for group in "${group_array[@]}"; do
    echo "$username is part of the group $group"
done

