echo "1. Create file"
echo "2. To read from file"
echo "3. To append to exisiting file"
echo "4. Delete file"
echo "5. Rename an existing file"
printf "Enter your choice: "
read choice

case $choice in
1) echo "Enter the file name to be created: "
   read filename
   touch "$filename"
   echo "$filename created"
   ;;

2) printf "Enter file name to read: "
   read filename
   if [ -f "$filename" ]
   then
	cat "$filename"
   else
	echo "File does not exist"
   fi
   ;;  

3) echo "Enter the file name to append data: "
   read filename

   if [ -f "$filename" ]
   then
	if [ -w "$filename" ]
	then
		echo "Enter data into the file: "
		cat >> $filename
	else
		echo "File not writable"
 	fi
   else
	echo "File does not exist"
   fi
   ;;

4) echo "Enter the file name to be deleted: "
   read filename

   if [ -f "$filename" ]
   then
	rm "$filename"
        echo "File has been successfully deleted"
   else
        echo "File is not present"
   fi
   ;;

5) echo "Enter the file name: "
   read filename

   if [ -f "$filename" ]
   then
	printf "Enter new name of the file: "
        read newname
        mv "$filename" "$newname"
        echo "$filename has been renamed to $newname"
  else
	echo "File does not exist"
  fi
  ;;

*) echo "Invalid Choice"
esac
