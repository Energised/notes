# gen.py
# Dan Woolsey
# 
# generator testing in python3
#
# (Thanks to http://pymbook.readthedocs.org/en/latest/igd.html for the information)
#
# WORDS TO KNOW:
#
# 	Yield Statement - Local variables arn't thrown away, the function is paused and can be resumed, will
#					  return an iterator object
#
# NOTE: - Outside of Python, generators are referred to as COROUTINES
#       - An ITERABLE is an object capable of returning its members one at a time
#
# TWO MAIN WAYS TO USE GENERATORS:
#
# 1) iterate over them with a for loop - e.g. for value in generator_function()
# 2) call the next function - e.g. next(generator_iterator) - (generator_iterator is just an instance of generator_function())
#
# - When a generator is 'exhausted' it returns a StopIteration exception
#
# Generators can also both send and yield values at the same time:
#
#	- Where a yield statement would be used, assign the yield to a variable
#		e.g. reciever = yield random_variable (reciever and random_variable could be the same)
#
#	- Call the generator_instance.send() method - this both sends a value to the generator and yields a value which
#	  means it can be printed
#		e.g. generator_instance.send(None) - send a None type to start the generator
#			 print(generator_instance.send(x * y)) - will print out whatever generator_instance yields and will
#                                                    pass back to reciever whatever it's sending (x*y)
#
#

print("\nTEST 1 - BASIC INCREMENTAL GENERATOR\n")

def inc_five(x):
	a = 0
	for i in range(x): # allows us to iterate up to a range
		yield a # upon first call makes inc() return an iterator
		print("i have yielded")
		a += 5

for x in inc_five(10):
	print(x)

		
# -> In the file 'primes.py' the function 'get_primes_to(maximum)' is an example of a good generator

def get_primes_to(maximum):
	number = 2
	while number < maximum:
		if is_prime(number): # see primes.py for this function
			yield number # every iteration of the generator yields a prime
		number += 1

# -> Every yield in get_primes_to() generates a new prime number
#
# -> Generators are used mainly for LAZY EVALUATION:
#		
#		- A good approach to working with lots of data
#		- Don't have to load all your data into memory, generators pass a piece of data each time they yield
#
# -> Generators can't be reused, instead they must be reset in one of three ways:
#
#		1) Run the generator function again
#
#			g = generator_function()
#			for f in g: print(f)
#			g = generator_function()
#			for f in g: print(f)
#
#		2) Store the generator results on disk and access them later
#
#			y = list(generator_function)
#			for x in y: print(x)
#			for x in y: print(x)
#
#		3) Build an object based generator
#
#			-> Create an object with an '__iter__()' method that yields
#			-> Build an instance of that object and call it as many times as necessary


class Counter(object):

	def __init__(self, low, high):
		self.low = low
		self.high = high

	def __iter__(self):
		counter = self.low
		while self.high >= counter:
			yield counter
			counter += 1

g = Counter(5,10)

print("\nFIRST PASS:\n")
for num in g:
	print(num)

print("\nSECOND PASS:\n")
for num in g:
	print(num)


print("\nTEST 2 - REUSING GENERATORS\n")

def my_generator(start, maximum):
	while start < maximum:
		yield start
		start += 1

g = my_generator(1,10)

for i in g:
	print(i)

print("Generator used once")

for i in g: # this shouldn't print anything to the screen
	print(i)

# ------------------------
#
# GENERATOR EXPRESSIONS
#
#	-> Shorthand notation for generator objects

print("\nTEST 3 - GENERATOR EXPRESSIONS")

g = (x*x for x in range(1,10))

print(type(g))
print(g)

print("\n",sum(g))

# ---------------------
#
# CLOSURES
#
#	-> A function returned by another function
#	-> A function inside of a function remembers the scope of the encapsulating function
#	-> e.g. Even though 'num' is declared in the scope of 'add_number()', it's contained in the scope of 'adder()'
#
#	Every function has an __closure__ attribute which holds all variables in the enclosing scope - this allows closures to work

print("\nTEST 4 - CLOSURES")

def add_number(num):
	def adder(number):
		return num + number
	return adder

a = add_number(10)(32)
print(a)

