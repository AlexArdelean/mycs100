array=("5" "3" "7" "10" "6")

size=${#array[@]}
for ((i=0; i<${size}; i++))
    do
size_j=${#array[@]}
        for ((j=$i; j<${size_j}; j++))
            do
            if [ ${array[$i]} -gt ${array[$j]} ]
            then
                temp=${array[$i]}
                array[$i]=${array[$j]}
                array[$j]=$temp
            fi
            done
    done
    
size_out=${#array[@]}
for ((i=0; i<${size_out}; i++))
    do
        echo ${array[$i]}
    done
