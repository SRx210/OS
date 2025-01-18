printf "Enter number of elements: "
read n

for (( i=0; i<$n; i++ ))
do
	read num[$i]
done

echo ""
echo "Entered elements are"
for (( i=0; i<$n; i++ ))
do
	printf ${num[$i]}
	printf " "
done
echo ""

for (( i=0; i<=$n; i++ ))
do
	for (( j=$i; j<=$n; j++ ))
	do
		if [ ${num[$i]} -gt ${num[$j]} ]
		then
			temp=${num[$i]}
			num[$i]=${num[$j]}
			num[$j]=$temp
		fi
	done
done

echo ""
echo "Sorted Elements are"
for (( i=0; i<=$n; i++ ))
do
	printf ${num[$i]}
	printf " "
done
echo ""
