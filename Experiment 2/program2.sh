#write a program for menu driven program when user selects an option (state) it should disply capital of the state
echo "A. Goa"
echo "B. Maharastra"
echo "C. Karnataka"
echo "D. Tamil Nadu"
echo "E. Gujarat"
printf "Enter your choice: "
read choice

case $choice in
a|A) echo "$choice 's capital is Panaji";;
b|B) echo "$choice 's capital is Mumbai";;
c|C) echo "$choice 's capital is Bangalore";;
d/D) echo "$choice 's capital is Chennai";;
e|E) echo "$choice 's capital is Ahmedabad";;
*) echo "Invalid Choice";;
esac



