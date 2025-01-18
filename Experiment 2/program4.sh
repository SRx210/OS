printf "Enter any number: "
read num

for (( i=1; i<=10; i++ ))
do
	product=$(( num * i ))
	echo "$num * $i = $product"
done
