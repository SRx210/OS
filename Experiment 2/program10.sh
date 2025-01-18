printf "Enter a year: "
read year

if [ $((year % 4)) -eq 0 ] && [ $((year % 100)) -ne 0 ] || [ $((year % 400)) -eq 0 ]
then
    echo "The entered year $year is a leap year"
else
    echo "The entered year $year is not a leap year"
fi

