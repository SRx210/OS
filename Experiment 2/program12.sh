printf "Enter a string: "
read str1

rev=""
len=`expr "$str1" : '.*'`

while [ $len -gt 0 ]
do
	rev=$rev`echo $str1 | cut -c $len`
	len=`expr $len - 1`
done

if [ $str1 == $rev ]
then
	echo "The enetered string is a palindrome"
else
	echo "The entered string is not a palindrome"
fi
