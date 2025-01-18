printf "Enter file name: "
read file1

if [ -f "$file1" ]
then
	if [ -w "$file1" ]
	then
		echo "File Exits!" 
		echo "Enter data to append"
		cat >> $file1
	else
		echo "File is not writable!!"
	fi
else
	echo "File does not exist!!"
fi
