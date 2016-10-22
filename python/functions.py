# DEFINING FUNCTIONS
#
# functions are objects.
#
# EXTRA PYTHON:
#
# 	continue - Statement that returns control to the start of the loop and continues on
#			 - At any point in the loop a continue is hit, control returns back to the start of the loop
#
# Three forms of function definitions:
#
# 	1) Default Argument Values
#		
#		Giving an argument a value inside the definition of the function

def foo(passes=5):
	for count in range(passes):
		print("Pass number: " + str(count))

foo() # by default will pass 5 times
foo(20) # overwrites passes value with 20

# These default values are evaluated at the point where the function is defined

x = 5

def bar(arg=x):
	return arg

x = 6

print(bar()) # will display 5 rather than 6

# NOTE: with mutable objects (e.g. lists, dictionaries, instances of classes) when it's edited
#       and it's a default value the latest edit becomes the new default

def f(a, li=[]):
	li.append(a)
	return li

print(f(1)) # returns [1]
print(f(2)) # returns [1,2]
print(f(3)) # returns [1,2,3]

#	2) Keyword Arguments
#
#		A function can have keywords passed into it in any order and arguments already
#		defined don't have to be redefined

# NOTE: An argument may not be assigned 2 values in one function definition



