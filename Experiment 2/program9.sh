printf "Enter a number: "
read n

if [ $n%2 == 0 ]
then
	echo "The entered number $n is even"
else
	echo "The entered number $n is odd"
fi
