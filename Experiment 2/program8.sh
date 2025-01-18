printf "Enter a string: "
read str1

rev=""
len=`expr "$str1" : '.*'`

while [ $len -gt 0 ]
do
	rev=$rev`echo $str1 | cut -c $len`
	len=`expr $len - 1`
done

echo "Reverse String: $rev"
