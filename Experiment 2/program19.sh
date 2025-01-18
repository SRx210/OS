echo "1. List of Files"
echo "2. Number of users on the system"
echo "3. Today's Date"
echo "4. Quit to UNIX"
printf "Enter your choice: "
read choice

case $choice in
1) list=$( ls )
   echo "$list"
   ;;

2) no_users=$( who )
   echo "$no_users"
   ;;

3) today_date=$(date +"%d %h %y")
   echo "$today_date"
   ;;

4) exit;;

*) echo "Invalid Choice";;
esac	



