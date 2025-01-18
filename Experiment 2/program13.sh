echo "A. Goa"
echo "B. Maharastra"
echo "C. Karnataka"
echo "D. Tamil Nadu"
echo "E. Gujarat"

printf "Enter your choice: "
read choice

case $choice in
a|A) echo "Goa's capital is Panaji";;
b|B) echo "Maharastra's capital is Mumbai";;
c|C) echo "Karnataka's capital is Bangalore";;
d/D) echo "Tamil Nadu's capital is Chennai";;
e|E) echo "Gujarat's capital is Ahmedabad";;
*) echo "Invalid Choice";;
esac
