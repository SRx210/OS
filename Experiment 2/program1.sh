#accept three nos and find out which one is greater
printf "Enter first number: "
read a
printf "Enter second number: "
read b
printf "Enter third number: "
read c

if [ $a -gt $b -a $a -gt $c ]
 then
      echo "$a is greatest"
elif [ $b -gt $c -a $b -gt $a ]
 then
      echo "$b is greatest"
else
      echo "$c is greatest number"
fi
