ARRAY=(5 3 6 567 3 4 67 56 4 3)

echo ${ARRAY[*]}

for i in "${ARRAY[@]}"
	do
		for j in "${ARRAY[@]}"
			do 
