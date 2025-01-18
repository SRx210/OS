printf "Enter a number: "
read num

reverse=0

while [ $num -gt 0 ]
do
	remainder=`expr $num % 10`
  	reverse=`expr $reverse \* 10 + $remainder`
	num=`expr $num / 10`
done

echo "The Reverse Number = $reverse"
