printf "Enter first number: "
read num1

printf "Enter second number: "
read num2

echo "1. Addition"
echo "2. Subtraction"
echo "3. Multiplication"
echo "4. Division"
echo "5. Modulus"

printf "Enter your choice: "
read choice

case $choice in
1) 
    echo "Performing Addition"
    sum=`expr $num1 + $num2`
    echo "Sum = $sum"
    ;;
2) 
    echo "Performing Subtraction"
    sub=`expr $num1 - $num2`
    echo "Difference = $sub"
    ;;
3) 
    echo "Performing Multiplication"
    prod=`expr $num1 \* $num2`
    echo "Product = $prod"
    ;;
4) 
    echo "Performing Division"
    div=`expr $num1 / $num2`
    echo "Division = $div"
    ;;

5)
    echo "Performing Modulus"
    mod=`expr $num1 % $num2`
    echo "Modulus = $mod"
    ;;

esac
