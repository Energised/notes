# primes.py
# Dan Woolsey

import math

def is_prime(element):
	if element > 1:
		if element == 2: # if element is 2
			return True
		elif (element % 2 == 0): # filters out all even numbers
			return False
		x = 0
		for x in range(3,int(math.sqrt(element) + 1),2): # from 3 to the square root of the current max point
			if ((element % x) == 0):
				return False
			elif x == 0:
				return False
		return True
	return False

def generate(maximum):
	a = 0
	for x in range(maximum):
		yield a
		a += 1
		if a > maximum:
			break


def build_primes_test():
	total = 0
	for pos in generate(100):
		if is_prime(pos):
			print(pos)
			total += pos
	print("TOTAL: " + str(total))


def get_primes_to(maximum):
	number = 2
	while number < maximum:
		if is_prime(number):
			yield number # every iteration of the generator yields a prime
		number += 1

if __name__ == "__main__":
	total = 0
	for val in get_primes_to(100):
		total += val
		print(val)
	print("Total: " + str(total))



