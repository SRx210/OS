for (( i=5; i>=1; i-- ))
do
	for (( j=1; j<=i; j++ ))
	do
		printf "*"
	done
     	echo ""
done

echo ""

for (( i=1; i<=4; i++ ))
do
	for (( j=i; j<=4; j++ ))
	do
		printf "$j"
	done
     	echo ""
done

echo ""

for (( i=1; i<=4; i++ ))
do
	for (( j=1; j<=i; j++ ))
	do
		printf "$i"
	done
     	echo ""
done


