num=20

for (( i=1; i<=num; i++ ))
do
	result=$(( $i * $i ))
	echo "$i^2 = $result"
done
