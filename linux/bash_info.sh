#!/bin/bash
# bash_info.sh
#
# Notes on bash scripting and such like

# Simple scripts for simple people

echo Hello World

# FILE DESCRIPTORS:
#
#	These are streams used to access a file or other I/O resources
#
#		stdin  -> Standard Input
#		stdout -> Standard Output
#		stderr -> Standard Error
#
#	We can use '>' to redirect any of these and '|' to pipe any output to any input

ls -a > allfiles.txt # output redirected to a file

# extra (nmap brood.me | grep ssh) -> output pipes into another command

# VARIABLES:
#
#	-> No data types
#	-> Can contain numbers/characters/strings
#	-> To get the value of the variable, echo it using a dollar sign ($var_name)

STR="I am a string"
echo $STR
echo STR 

#	-> Echoing the stdout of a command can be done using a '$' and '()'

echo ls
echo $(ls)

#	-> Replacing ls with a variable called ls won't be interpreted as a command
#	-> Passing another commands name into a command is awkward:
#
#		echo ls <=> echo "ls" <=> ls
#		
#		echo $(ls) <=> ls <=> file1, file2, file3...
#
#	-> If you want the output of a function inside a variable
#

files=`ls`
files2=$(ls)
echo first: $files
echo second: $files2

#
# FUNCTIONS:
#
#	Below is an example of a function in bash:

function hello
{
	local HELLO="hello"
	echo $HELLO
}

#	-> A local variable only holds its value while inside of the function
#	-> To execute the function, just call its name

hello

# CONDITIONALS: 
#
#	The basic structure of an if statement is as such:
#
#		if [ expression ]; then
#			...codegoeshere...
#		fi
#
#	NOTE: Don't forget the spaces before and after the expression
#
#	For example:

echo "Test 1"

if [ "foo" = "foo" ]; then
	echo "expression is true"
fi

echo "Test 2"

if [ 1 = 2 ]; then
	echo "1 = 2"
else
	echo "1 != 2"
fi

# LOOPS:
#
#	Loops can take the following forms:
#
#	Numeric Tests:							File Tests:
#
#		-lt -> Less than						-nt -> Newer than
#		-gt -> Greater than						-d  -> Is a directory
#		-eq -> Equal to 						-f  -> Is a file
#		-ne -> Not equal 						-r  -> Is readable
#		-ge -> Greater than or equal to 		-w  -> Is writable
#		-le -> Less than or equal to 			-x  -> Is executable
#
#	String Tests:							Logical Tests:
#
#		  =  -> Equal to 						&&  -> Logical AND
#		 -z  -> Zero length 					||  -> Logical OR
#		 -n  -> Not zero length 				 !  -> Logical NOT
#
# NOTE:
#
#	In any comparison, make sure to follow these rules:
#
#		- Strings  -> use double square parenthesis [[ expression ]]
#		- Integers -> use double round brackets (( expression ))
#		- AVOID USING SINGLE SQUARE PARENTHESIS COMPARISON
#
# for   -> Iterates over a series of 'words' within a string

for i in $(ls); do
	echo File: $i
done

#
# 		c-like for loops
# 		----------------
#
#		-> Looks more like a for loop is C/Perl, evaluates to the above loop
#

for i in `seq 1 10`;
do
	echo $i
done

# while -> Executes code when an expression is true, stops when it's false or a break occurs

x=5
y=0
while [ $x -ge $y ]; do
	echo y is $y
	if [ $x = $y ]; then
		echo $x = $y
	fi
	let y+=1
done

# 
# until -> Opposite of a while loop, while expression is false until it evaluates to true
#

counter=20
until [ $counter -lt 10 ]; do
	echo counter: $counter
	let counter-=1
done

# A NOTE ON ARGUMENTS
#
#	-> Parameters including names and arguments can be called by the following variables:
#
#		$0 -> File name (currently being executed)
#		$1 -> First argument parsed
#		$2 -> Second argument parsed
#		...
#		$# -> Number of arguments
#		$* -> All arguments

echo $0

#   -> Using this, we can error check for if a user passes in an argument

if [ -z $1 ]; then # zero length test 
	echo "-> no arguments were passed"
fi

# 	-> This works the same for passing arguments to functions too

function args
{
	for i in $*;
	do
		echo $i
	done
}

args arg1 arg2 arg3 # will print out 3 arguments

# MENUS
#
#	-> Simple and elegent solution to user input
#	-> Gives an enumerated set of answers taken from the iterated string
#	
#		'select' -> acts like a for loop to return each option
#		  '$opt' -> variable that holds the option value of the number the user inputs
#		 'break' -> exits the select loop

options="A B C QUIT"

select opt in $options; do
	if [ $opt = "A" ]; then
		echo "done"
	elif [ $opt = "B" ]; then
		echo "not done"
	else
		echo "bad option"
	fi
	break
done

# USER INPUT
#
#	-> the 'read' command takes a users stdin from the terminal
#	-> it can take multiple input arguments at once 

echo "Enter your firstname and lastname: "
read firstname lastname
echo Hi $firstname $lastname

# NUMERICAL EVALUATION
#
#	-> echo requires different syntaxes to interpret expressions

echo "1 + 1": 1+1
echo '$((1 + 1)):' $((1+1))
echo '$[1+1]:' $[1+1]

# A NOTE ON DEBUGGING
#
#	-> To get more debugging information in your code you can change your first line to:
#
#			#!/bin/bash -x

# LS TRICKS
#
#	-> Using brace expansion on certain filesystems you can easily pull a large number of files quickly
#	-> The following expressions are all equivalent:

ls file1.txt file2.txt file3.txt file4.txt file5.txt

ls file{1..5}.txt



