# Shell Scripting

We need to specify shell type using `#!/bin/bash` on top. 

## Variables 
```
echo "Enter value"
read x
echo "x is $x""
```


## If-Else
```
if [ conditiong1 ]; then
    statement1
elif [ condition2 ]; then
    statement2
else
    statement3
fi
```

### String Comparison: 
`str1 = str2` : True if strings are equal
`str1 != str2`: True if strings are not equal
`-n str` : True if string is not null
`-z str` : True if string is null

