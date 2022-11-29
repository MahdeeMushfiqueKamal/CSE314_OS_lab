# Shell Commands

The shell is a program that takes keyboard commands
and passes them to the operating system to carry out.

## Exploration

```bash
echo Hello World
echo ‘Hello World’
echo “Hello World”
```
all three works. But its recommended to wrap it in quotes. Double quote prints value of a variable. 

`man` - manual for a command. \
`tldr` - similar to `man`
`pwd` - present working directory. \
`cd` - change directory \
`cd ..` - parent directory
`cd -` - previous directory

`ls` - – Lists information about directory or file

`ls` flags: 
- `-a` : hidden files
- `-l` : details 
- `-R` : recursively list subdirectories 
- `-S` : sort by size

`mkdir` - Make directory. \
`mkdir` flags: `-p` : overwrite

`cp` src dst : copy from source to destination. \
`cp` flags
- `-r` copy directories recursively
- `-i` interactive i.e. prompts before overwriting

`mv` src dst - move.

`rm` - remove \ 
`rm` flags: 
- `-f` - ignore non existing files. 
- `-i` interactive i.e. prompts before overwriting
- `-r` remove contents recursively, delete folder. 

### Permission: 
10 characters. 1st char is `-` for file and `d` for directory. \
for files, next 3 char determines read, write and execute permission for `owner`. \ 
next 3 for `group` and next 3 for `any`. 
`r` - has read access. 
`w` - has write access. 
`x` - has execution access. 

change permission: 
`chmod a+x`; give permision to any for execute. 
`chmod [aog][+-][rwe]`

## File Viewing
`cat [FILE…]` - concatenate contents of files
`more` \
`less` \
`head -n5` - first 5 line. \
`tail -n5` - last 5 lines. \ 
Less is a file reading program, and Cat is a string manipulation program. \ 


`wc [FILE…]` - count the line, word and bytes \
`wc` flags: 
- `-c` - print the byte counts
- `-m` - print the character counts
- `-l` - print the newline counts

`grep PATTERN [FILE…]` - searches FILE for a match with PATTERN

## I/O Ridirection
`<` - get input from a file other than keyboard \
`>` - output to a file other than the screen \
`>>` - append output to a file 

## Pipelines 

`ls /bin /usr/bin | sort | uniq | less`