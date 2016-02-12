int1=$1
int2=$2
int3=$3

if [ "$#" -lt "3" ] || [ "$#" -gt "3" ]
	then echo "too many or few arguments" ; exit
fi



if [ "$int1" -gt "$int2" ] && [ "$int1" -gt "$int3" ]
	then echo "${int1}"
elif [ "$int2" -gt "$int3" ] && [ "$int2" -gt "$int1" ]
	then echo "${int2}" 
elif [ "$int3" -gt "$int1" ] && [ "$int3" -gt "$int2" ]
	then echo "${int3}"
fi
