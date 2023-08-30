
# Write a shell script to see the current date, time, username, and directory
current_date=$(date +"%Y-%m-%d")
echo "Current date is , $current_date "
current_time=$(date +"%H:%M:%S")
echo "Current time, $current_time "
user=$(whoami)
echo "Current user is, $user"
current_directory=$(pwd)
echo "Current working directory is  $current_directory"
