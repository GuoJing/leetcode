#/bin/bash

# ./run.sh file2.txt

cnt=`head -n10 $1|wc -l`

if [ $cnt -lt 10 ]
    then exit 0
fi

head -n10 $1|tail -n1
