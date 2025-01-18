echo "1. Display Processor Information"
echo "2. Display Real Time Main Memory Information"
echo "3. Display Real Time Process Status"
echo "4. Exit"
printf "Enter your choice: "
read choice

case $choice in
1) echo "Displaying Process Information"
   lscpu
   ;;

2) echo "Displaying Real Time Main Memory Information"
   cat /proc/meminfo
   ;;

3) echo "Displaying Real Time Process Status"
   ps
   ;;

4) exit;;

*) echo "Invalid Choice";;

esac 
