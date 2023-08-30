#!/bin/bash

webpage=$(curl -s 'https://www.amazon.com.be/s?crid=J5K1X4I1IO0W&i=aps&k=hp%20laptop&ref=nb_sb_noss_1&sprefix=hp%20laptop%2Caps%2C392&url=search-alias%3Daps' \ -H 'user-agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/116.0.0.0 Safari/537.36')
type=$(echo "$webpage"  | grep -o '<span class="a-size-base-plus a-color-base a-text-normal">[^<]*</span>' | sed -E 's/<[^>]*>//g')
price=$(echo "$webpage"  | grep -o '<span class="a-price-whole">[^<]*<span class="a-price-decimal">[^<]*</span></span>' | sed -E 's/<[^>]*>//g') 
# Convert the data into arrays
IFS=$'\n' read -d '' -ra types <<< "$type"
IFS=$'\n' read -d '' -ra prices <<< "$price"

# Iterate over the arrays and print type along with price
for (( i = 0; i < ${#types[@]}; i++ )); do
  echo "Type: ${types[i]} , Price: ${prices[i]}"
done
#echo "Type: $type ,Price: $price"