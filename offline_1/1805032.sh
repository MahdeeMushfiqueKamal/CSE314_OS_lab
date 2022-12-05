#!/bin/bash
MAX_SCORE=100
MAX_STUDENT_ID=5

if [ $# -ge 2 ]; then
    MAX_SCORE=$1
    MAX_STUDENT_ID=$2
elif [ $# -ge 1 ]; then
    MAX_SCORE=$1
fi

echo "maximum score is $MAX_SCORE"
echo "number of student is $MAX_STUDENT_ID"
`mkdir ans`
echo "student_id,score" > output.csv

# executing everyones solution
echo "Executing Submissions"
echo "---------------------"
for (( i=1 ; i <= MAX_STUDENT_ID; i++ ))
do 
    student_id=$((1805120+i))
    if [ -e ./Submissions/$student_id ]; then    
        echo "Executing submission for $student_id"  
        `./Submissions/$student_id/$student_id.sh > ans/$student_id.txt`
    fi
done

echo "---------------------"
echo "Checking Solutions"
echo "------------------"

for (( i=1 ; i <= MAX_STUDENT_ID; i++ ))
do 
    student_id=$((1805120+i))
    if [ -e ./ans/$student_id.txt ]; then    
        echo "Checking solution of $student_id"  
        num_of_diff=`diff ans/$student_id.txt AcceptedOutput.txt -w| grep '<\|>' | wc -l`
        student_mark=$(( MAX_SCORE -  num_of_diff*5))
        # handle negative mark case.
        if [ $student_mark -lt $((0)) ]; then
            student_mark=0
        fi
        # Copy checker
        for (( j=1; j<= MAX_STUDENT_ID; j++ ))
        do
            student_id_2=$((1805120+j))
            if [ $i -ne $j -a -e ./ans/$student_id_2.txt ]; then
                changes=`diff ans/$student_id.txt ans/$student_id_2.txt -Z -B| wc -l`
                if [ $changes -eq $((0)) ]; then
                    echo "$student_id copied from $student_id_2"
                    (( student_mark = -$student_mark ))
                    break
                fi
            fi
        done        
        echo "$student_id,$student_mark" >> output.csv
    else
        echo "Solution doesn't exist for $student_id"
        echo "$student_id,0" >> output.csv
    fi
done

echo `rm -r ans`
