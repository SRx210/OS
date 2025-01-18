terms=8
count=1

a=20
b=22

while [ $count -le $terms ] && [ $a -gt 12 ] && [ $b -gt 12 ]
do
	if [ $a -gt 12 ]
	then
		printf "$a "
		a=$(($a-2))
		printf "$b "
		b=$(($b-2))
		count=$(($count+1))
	fi	
done
	




