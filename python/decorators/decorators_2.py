#!/usr/local/bin/python3
# decorato.py
#
# more notes but from Fluent Python C7

registry = []

# basic decorator, returns the running of the given function
# NOTE: register is run on each job as soon as test() is run

def register(func):
    print("running register(%s)" % func)
    registry.append(func)
    return func

@register
def job_a():
    print("doing job a")

@register
def job_b():
    print("doing job b")

def job_c():
    print("doing job c")

def test():
    print("testing #1")
    print("registry = ", registry)
    job_a()
    job_b()
    job_c()

# ---------------------------------------------------
#
# 1) Defining decorator functions in the same file as the functions they decorate
# ^^^^^ NOT THE USUAL WAY ~> Define decorators in their own file
#
# ALSO -> In practice, most decorators define an inner function and return it


if __name__ == "__main__":
    test()
