echo "1. View Memory status in kilobytes"
echo "2. To view PID of a specific process"
echo "3. To view list of all logged in users"
echo "4. To forcefully delete directory having sub directories as well as files"
printf "Enter choice: "
read choice

case $choice in
1) free -k
   ;;

2) printf "Enter the name of the process: "
   read process_name
   pgrep $process_name
   ;;

3) who;;

4) printf "Enter directory path to delete: "
   read dir_path
   rm -rf $dir_path
   ;;

*) echo "Invalid Choice"
esac


