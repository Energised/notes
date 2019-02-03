# decorator testing
# dan woolsey

from functools import wraps

def my_decorator(some_func):

	@wraps(some_func)
	def wrapper():

		print("before " + some_func.__name__ + " is called")
		some_func()
		print("after " + some_func.__name__ + " is called")

	return wrapper

@my_decorator
def foo():
	print("foo")

print(foo.__name__) # outputs 'wrapper' when functools.wraps isn't used