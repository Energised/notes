# decorators.py
# dan woolsey

# (https://realpython.com/blog/python/primer-on-python-decorators/)

# DEFINITION:
#	A function that takes another function and extends the behaviour of the latter function WITHOUT
#   explicitly modifying it

# THEY PROVIDE A SYNTAX FOR CALLING HIGHER ORDER FUNCTIONS

# (1) functions

# 		functions are FIRST CLASS OBJECTS -> can be passed around and used as arguments like primative types
#	
#    we can define functions in functions and show how scoping works

def parent():
	
	print("inside of parent function")

	def child_one():
		return "Inside of child one function"

	def child_two():
		return "Inside of child two function"

	print(child_one())
	print(child_two())

print(parent()) # outputs all 3 statements

print(child_one()) # NameError -> this function can only be accessed inside of parent

# to access those functions we can return those functions to variables outside the parent function

def parent(num):

	def child_one():
		print("inside of child one function")

	def child_two():
		print("inside of child two function")

	try:
		assert num == 10 # if true it carries on, if false it throws an assertion error
		return child_one
	except AssertionError:
		return child_two

foo = parent(10)
bar = parent(9)

print(foo) # function object child_one
print(bar) # function object child_two

# now using this information, we can now look at decorators

def my_decorator(some_func):

	def wrapper():

		print("before " + some_func.__name__ + " is called")
		some_func()
		print("after " + some_func.__name__ + " is called")

	return wrapper

def foo():
	print("foo")

foo = my_decorator(foo)

foo() # will call foo but exactly as wrapper shows it

# before foo is called
# output of foo
# after foo is called

# The @ symbol notation (pie notation) is a replacement for: 

foo = my_decorator(foo)

# we can rewrite our function foo as:

@my_decorator
def foo():
	print("foo")

# and the output will be the same as the above example

# NOTE ON functools.wraps
# (http://stackoverflow.com/questions/308999/what-does-functools-wraps-do)

from functools import wraps

# wraps allows data about the function being decorated to remain in that function
# without using wraps, any function you decorate will only store metadata for the wrapper and not the function

print(foo.__name__) # outputs wrapper

# if we re-define the decorator using wraps then we can change that output

def my_decorator(some_func):

	@wraps(some_func)
	def wrapper():

		print("before " + some_func.__name__ + " is called")
		some_func()
		print("after " + some_func.__name__ + " is called")

	return wrapper

print(foo.__name__) # outputs foo

# the same principle applies for all function metadata (e.g. docstrings)
