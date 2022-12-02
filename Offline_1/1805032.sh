#!/bin/bash
MAX_SCORE=100
MAX_STUDENT_ID=5

if [ $# -ge 2 ]; then
    MAX_SCORE=$1
    MAX_STUDENT_ID=$2
elif [ $# -ge 1 ]; then
    MAX_SCORE=$1
fi

echo "maximum sore is $MAX_SCORE"
echo "number of student is $MAX_STUDENT_ID"
echo "`mkdir ans` Created directory ans for submission"

for (( i=1 ; i <= MAX_STUDENT_ID; i++ ))
do 
    student_id=$((1805120+i))
    echo "Executing submission for $student_id.........."  
    echo `./Submissions/$student_id/$student_id.sh > ans/$student_id.txt`
    num_of_diff=`diff ans/$student_id.txt AcceptedOutput.txt | wc -l`
    echo "$num_of_diff"
done

echo `rm -r ans`