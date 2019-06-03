# threads.py
# dan woolsey
#
# threading module in Python 2.x
#
# - Higher level interface that allows for the creation of multiple 'threads of control'
#
# 		With thanks to https://pymotw.com/2/threading/ and docs.python.org
#
# NOTEABLE TERMS:
#
#	daemon -> long running background process that answers requests for services and can perform actions
#             at pre-defined times
#
#	synchronisation primative -> software mechanisms provided by a platform to support thread or process
#						         synchronisation
#
#	semaphore -> An ADT used for controlling access (by multiple processes) to a common resource in a 
#				 concurrent system
#
# CREATING A THREAD:
#
#	threading.Thread(group=None, target=None, name=None, args=(), kwargs={})
#
#		- group  -> only used with the 'ThreadGroup' class
#		- target -> callable object invoked by the run() method in the thread (what's actually gonna run)
#		- name   -> name of the thread, defaults to 'Thread-N' where N is a decimal
#		- args   -> tuple containing the arguments for target
#		- kwargs -> dictionary containing keyword arguments for target
#
#	NOTE - When defining a thread, you can get away with only passing in a target (so long as the target function doesn't 
#		   require any arguments to be passed)


import threading
import time

# -------------------------

print("TEST 1 - CREATING THREADS\n")

def worker(times):
	print 'worker' * times

threads = []

for i in range(5):
	t = threading.Thread(target=worker, args=(i,)) # must use that comma
	threads.append(t)
	t.start()

# -------------------------

print("\nTEST 2 - MORE THREADS\n")

def service_1():
	print threading.currentThread(), ' START'
	time.sleep(1)
	print threading.currentThread(), ' END'

def service_2():
	print threading.currentThread(), ' START'
	time.sleep(1)
	print threading.currentThread(), ' END'

a = threading.Thread(target=service_1, name="a")
b = threading.Thread(target=service_2, name="b")
c = threading.Thread(target=service_1, name="c")

a.start()
b.start()
c.start()

# -----------------------

# LOGGING MODULE
#
#	There are multiple ways to define a logger in Python:
#
#	logger = logging.getLogger(name.of.logger)
#
#		- getLogger(name) - generates a logger object
#
#	logger = logging.basicConfig(level='',format='',filename='',filemode='',datefmt='')
#
#		- level    -> The debugger has levels to indicate the severity of an error, this option lets you choose the
#				      level of errors and above that get processed by the logger
#		- format   -> The display format for each debug message being processed
#		- filename -> If you want the output to be saved to a file, specify the filename here
#		- filemode -> Specify the way you want the file to be accessed e.g. 'w' for write, 'a' for append etc
#		- datefmt  -> The display format of the date on the debugger
#
# ------------------------

print("\nTEST 3 - THREADS AND LOGGING\n")

import logging

logging.basicConfig(level=logging.DEBUG,
					format='[%(levelname)s] (%(threadName)-10s) %(message)s')

def work_1():
	logging.debug("START")
	time.sleep(1)
	logging.debug("END")

def work_2():
	logging.debug("START")
	time.sleep(2)
	logging.debug("END")

a = threading.Thread(target=work_1, name="a")
b = threading.Thread(target=work_2, name="b")
c = threading.Thread(target=work_1) # will use a default name if not specified

c.start()
b.start()
a.start()

# ------------------------
#
# USING DAEMONS
#
# We can set a thread as a daemon thread using the command:
#
#		a = threading.Thread(target=func_name, name="daemon_example")
#		a.setDaemon(True)

print("\nTEST 4 - USING DAEMONS\n")

logging.basicConfig(level=logging.DEBUG,
					format='[%(levelname)s] (%(threadName)-10s) %(message)s')

def daemon():
	logging.debug("START")
	time.sleep(3)
	logging.debug("END")

def non_daemon():
	logging.debug("START")
	time.sleep(1)
	logging.debug("END")

a = threading.Thread(target=daemon, name="daemon")
b = threading.Thread(target=non_daemon, name="normal")

a.setDaemon(True)

a.start()
b.start()

logging.debug('-> This should be true: %s', a.isAlive())

a.join(4) # calling the .join() of a thread will make the program wait for that thread to finish and close
          # before doing anything else (useful for daemon threads like this)
          #
          # .join() can also take an argument for a timeout length in case the thread goes on for too long
          #
          # (if this time is less than 4 then the daemon thread 'a' will not close)

logging.debug('-> This should be false: %s', a.isAlive())

# ------------------------
#
# ENUMERATING THREADS 
#
#	- calling threading.enumerate() returns a list containing all active threads (including daemons and dummy threads)

print("\nTEST 5 - ENUMERATING THREADS\n")

import random

logging.basicConfig(level=logging.DEBUG,
					format='(%(threadName)-10s) %(message)s')

def action():
	t = threading.current_thread() # allows us to access the thread object 
	pause = random.randint(1,5)
	logging.debug('SLEEPING %s', pause)
	time.sleep(pause)
	logging.debug('END')

for i in range(3):
	t = threading.Thread(target=action)
	t.setDaemon(True)
	t.start()

main_thread = threading.current_thread()
for i in threading.enumerate():
	logging.debug('-> %s', i.getName())
	if i is main_thread:
		continue
	logging.debug('JOINING %s',t.getName())
	i.join()

# ----------------
#
# SUBCLASSING THREADS
#
#	-> When a thread starts, it calls upon its run method, which runs the target method passed in
#	-> Making your own thread subclass means you dictate what happens in the run method

print("\nTEST 6 - SUBCLASSING THREADS\n")

logging.basicConfig(level=logging.DEBUG,
					format='(%(threadName)-10s) %(message)s')

class Work(threading.Thread):

	""" Basic thread """

	def run(self):
		logging.debug("doing work...")


for i in range(5):
	a = Work()
	a.start()
	a.join()

#
#	-> If you want to pass args or kwargs into your thread you need to rewrite the constructor and
#	   make the args and kwargs parameters public attributes

print("\nTEST 7 - PASSING ARGS TO SUBCLASSED THREADS\n")

class Work(threading.Thread):

	""" Thread with arguments """

	def __init__(self, group=None, target=None, name=None, args=(), kwargs=None, verbose=None):
		threading.Thread.__init__(self, group=group, target=target, name=name, verbose=verbose) # MUST call constructor of Thread if editing it
		self.args = args
		self.kwargs = kwargs

	def run(self):
		logging.debug("-> Thread %s with args %s", self.getName(), self.args)

for i in range(5):
	a = Work(args=(i,))
	a.start()
	a.join()

# -------------------
#
# TIMER OBJECTS 
#
#	-> An action that is run after a certain amount of time has passed:
#
#			t = threading.Timer(30.0, user_function)
#
#	-> Can call the method t.cancel() to end the Timer (while it's still waiting)
#

print("\nTEST 8 - TIMERS AND THREADS\n")

def delay():
	logging.debug("THIS THREAD HAD BEEN DELAYED")

t = threading.Timer(4,delay)
t.start()
logging.debug("-> Thread %s start",t.getName())
t.join()

# ------------------
#
# EVENT OBJECTS
#
#	-> You can build a program around an event and have your threads wait until that event is set
#	-> An event is a flag that happens when the flag is set to true
#
#		e = threading.Event()
#
#			isSet() -> returns true if set, false otherwise
#			set()   -> sets the flag to true
#			clear() -> sets the flag to false
#			wait(x) -> makes the thread wait until set() is called, x is an optional timeout

print("\nTEST 9 - EVENTS AND THREADS\n")

def wait_for_event(e):
	""" wait for the event to be set """
	logging.debug("wait_for_event starting")
	event_is_set = e.wait()
	logging.debug("event set: %s",event_is_set)

def wait_for_event_timeout(e, t):
	while not e.isSet():
		logging.debug("wait_for_event_timeout starting")
		event_is_set = e.wait(t) # timeout argument was 2, sleep was 3 so the rest is executed
		logging.debug("event set: %s", event_is_set)
		if event_is_set:
			logging.debug("processing event")
		else:
			logging.debug("doing other work")

e = threading.Event()

a = threading.Thread(name='block', target=wait_for_event, args=(e,))
a.start()

b = threading.Thread(name='non-block', target=wait_for_event_timeout, args=(e,2,))
b.start()

logging.debug("waiting before calling Event.set()")
time.sleep(3)
e.set()
logging.debug("event is set")

main_thread = threading.current_thread()
for t in threading.enumerate():
	if t is not main_thread:
		t.join()

#
# -----------------
#
# CONTROLLING ACCESS TO RESOURCES
#
#	-> To preserve data integrity with multiple threads accessing the same data we must use a lock object
#	-> Built in data structures (lists, dicts etc) are thread safe, but others are not and must be protected
#
#	A lock is an example of a 'synchronisation primative' and has two states: locked and unlocked (starts off unlocked)
#
#		l = threading.Lock()
#
#			acquire([blocking]) -> Blocks other threads until the lock is unlocked again, locks, returns true (blocking defaults to True)
#								-> When blocking is False, it won't block any threads, locks and returns True
#			release()			-> Sets lock to unlocked, if other threads are blocked then allow exactly 1 to proceed

print("\nTEST 10 - LOCKS AND THREADS\n")

class Counter(object):

	def __init__(self, start=0):
		self.lock = threading.Lock() # generate an unlocked lock
		self.value = start

	def inc(self):
		logging.debug("Waiting for lock")
		self.lock.acquire() # locks the lock
		try:
			logging.debug("Acquired Lock (is locked)") # do what you want here
			self.value += 1
		finally:
			self.lock.release()
			logging.debug("Released Lock (is unlocked)") # open lock at the end

def worker(c):
	for i in range(2):
		pause = random.random()
		logging.debug("SLEEPING %0.02f",pause)
		time.sleep(pause)
		c.inc()
	logging.debug("DONE")

counter = Counter()

for i in range(2):
	t = threading.Thread(target=worker, args=(counter,)) # creates 2 threads that will both increment Counters value
	t.start()

logging.debug("WAITING FOR WORKER THREADS")
main_thread = threading.current_thread()
for t in threading.enumerate():
	if t is not main_thread: # ensure all running threads are closed at the end
		t.join()
logging.debug("COUNTER: %d",counter.value)

# 	-> using this allows each thread to wait until the other has finised changing values before altering it again
#   -> this is used to stop multiple threads accessing data at the same time
#
#	-> example of not blocking a thread and writing our own handler for the current process

print("\nTEST 11 - LOCKS WITHOUT BLOCKS\n")

def lock_holder(lock): # unhelpful lock holder 
	logging.debug("START")
	count = 0
	while True:
		lock.acquire() # closes the lock
		try:
			logging.debug("HOLDING")
			time.sleep(0.5)
		finally:
			logging.debug("NOT HOLDING")
			lock.release() # opens the lock
		time.sleep(0.5)
		count += 1
		if count == 5: # generic value of 5 works, leave it :)
			break

def worker(lock):
	logging.debug("start")
	num_tries = 0
	num_acquires = 0
	while num_acquires < 3:
		time.sleep(0.5)
		logging.debug("trying to acquire")
		have_it = lock.acquire(0) # tries to access the lock
		try:
			num_tries += 1
			if have_it:
				logging.debug('iteration %d: acquired',  num_tries) # if it can then inc counter
				num_acquires += 1
			else:
				logging.debug('iteration %d: not acquired', num_tries)
		finally:
			if have_it:
				lock.release() # if it managed to close the lock then open it again
	logging.debug("done after %d iterations",num_tries)
	holder.join()
	

lock = threading.Lock()

holder = threading.Thread(target=lock_holder, name='holder', args=(lock,))
holder.setDaemon(True)
holder.start()

worker = threading.Thread(target=worker, name='worker',args=(lock,))
worker.start()

holder.join()

# -> use try, except, finally handlers since a ThreadError is thrown if the lock cannot be acquired or released
#
# -> locks cannot be acquired more than once, side effects can be caused by accessing a lock with multiple functions

print("\nTEST 12 - MULTIPLE ACCESS TO LOCKS\n")

lock = threading.Lock()

logging.debug("FIRST TRY: %s",lock.acquire())
logging.debug("SECOND TRY: %s",lock.acquire(0))

# -> both calls are accessing the same lock, so if the blocking argument wasn't false it would have blocked
# 
# -> when seperate code in a thread needs to reacquire a lock use an RLock
# -> RLock objects are set to a thread when locked, but when unlocked are freely accessable by any new thread

print("\nTEST 13 - USING RLOCKS")

lock = threading.RLock()

logging.debug("FIRST TRY: %s",lock.acquire())
logging.debug("SECOND TRY: %s",lock.acquire(0))

# ------------
#
# USING LOCKS AS CONTEXT MANAGERS
#
#	-> Removes the need to explicitly use acquire() and release() methods on locks
#	-> the 'with' statement handles the methods the lock uses

print("\nTEST 14 - USING LOCKS AS CONTEXT MANAGERS")

def worker_with(lock):
	with lock:
		logging.debug("LOCK ACQUIRED BY CONTEXT MANAGER")

def worker_no_with(lock):
	lock.acquire()
	try:
		logging.debug("LOCK ACQUIRED NORMALLY")
	finally:
		lock.release()

lock = threading.Lock()
w = threading.Thread(target=worker_with, args=(lock,))
x = threading.Thread(target=worker_no_with, args=(lock,))

w.start()
x.start()

# -------------
#
# THREAD SYNCHRONISATION WITH CONDITION OBJECTS
#
#	-> Condition objects use an RLock object it creates (a lock or RLock can be passed in)
#	-> We can use this to force threads to wait until a resource is updated
#
#		c = threading.Condition([lock])
#
#			acquire(*args)  -> Corresponds to the locks method inside of the condition
#			release()       -> Corresponds to the locks method inside of the condition
#			wait([timeout]) -> Wait until notified or timeout
#							-> If the calling thread hasn't acquired the lock a RunTime error is raised
#							-> Releases the lock, then blocks until notify() or notifyAll() is called on that condition
#			notify(n=1)     -> Wakes 'n' number of threads waiting on that condition
#							-> If the calling thread hasn't acquired the lock a RunTime error is raised
#							-> The awakened thread hasn't released the lock yet, so its caller needs to
#			notifyAll()		-> Same as above, but notifys all threads currently active
#			 

print("\nTEST 15 - THREAD SYNCHRONISATION WITH CONDITION OBJECTS\n")

logging.basicConfig(level=logging.DEBUG,
                    format='%(asctime)s (%(threadName)-2s) %(message)s',
                    )

def consumer(cond):
	""" wait for the condition, use the resource """
	logging.debug("STARTING CONSUMER THREAD")
	t = threading.currentThread()
	with cond:
		cond.wait()
		logging.debug("RESOURCE IS AVAILABLE TO THE CONSUMER")

def producer(cond):
	""" setup the resource for the consumer """
	logging.debug("STARTING PRODUCER THREAD")
	with cond:
		logging.debug("MAKE RESOURCE AVAILABLE")
		cond.notifyAll()

condition = threading.Condition()

c1 = threading.Thread(target=consumer, args=(condition,))
c2 = threading.Thread(target=consumer, args=(condition,))
p = threading.Thread(target=producer, args=(condition,))

c1.start()
time.sleep(2)
c2.start()
time.sleep(2)
p.start() 

main_thread = threading.currentThread()
for t in threading.enumerate():
	if t is not main_thread:
		t.join()

# -------------------
#
# CONCURRENT THREAD ACCESS TO RESOURCES USING SEMAPHORES
#
#	-> Acts exactly like a lock, except uses an internal counter (set upon initialisation) that can't go below 0
#	-> If the counter reaches 0 then it blocks the thread until another thread releases it
#	-> Calling acquire() or release() will decrement or increment the counter by one respectively
#   -> Semaphores allow for multiple threads to access a resource at the same time
#
#		s = threading.Semaphore([value])
#
#			acquire([blocking]) -> Decrement the counter by 1 and return normally
#								-> If value=0, block until release is called by another thread
#								-> If acquire is called by multiple threads, calling release will only allow 1 thread through
#
#			release()           -> Increment the counter by 1, wake another thread if value = 0 

print("\nTEST 16 - CONCURRENT THREAD ACCESS TO RESOURCES\n")

class ActivePool(object):

	def __init__(self):
		super(ActivePool, self).__init__()
		self.active = []
		self.lock = threading.Lock()

	def make_active(self, name):
		with self.lock:
			self.active.append(name)
			logging.debug("RUNNING: %s", self.active)

	def make_inactive(self, name):
		with self.lock:
			self.active.remove(name)
			logging.debug("RUNNING: %s", self.active)

def worker(s, pool):
	logging.debug("WAITING TO JOIN THE POOL")
	with s:
		name = threading.currentThread().getName() # context managers handle acquire and release statements
		pool.make_active(name)
		time.sleep(0.1)
		pool.make_inactive(name)

pool = ActivePool()
s = threading.Semaphore(2) # start the semaphore counter at 2
for i in range(4):
	t = threading.Thread(target=worker, name=str(i), args=(s, pool,))
	t.start()

def end_threads():
	main_thread = threading.currentThread()
	for t in threading.enumerate():
		if t is not main_thread:
			t.join()

end_threads()

# -----------------
#
# THREAD SPECIFIC DATA USING LOCAL
#
#	-> As well as locking resources so multiple threads can use them, we need to hide resources from certain threads
#	-> This means we need an attribute that is different for each thread (a thread-specific attrbute)
#   -> To do this we need an instance of the class local()
#
#		local_data = threading.local()
#		local_data.value = 1
#		
#   -> The attribute set is thread specific, so only that thread will have access to that value

print("\nTEST 17 - THREAD SPECIFIC DATA USING LOCAL\n")

def show_value(data):
	try:
		value = data.value
	except AttributeError:
		logging.debug("NO VALUE YET")
	else:
		logging.debug("VALUE = %s",value)

def worker(data):
	show_value(data)
	data.value = random.randint(1,100)
	show_value(data)

local_data = threading.local()
show_value(local_data)
local_data.value = 1000
show_value(local_data)

for i in range(2):
	t = threading.Thread(target=worker, args=(local_data,))
	t.start()

end_threads()

#	-> local() can also be subclassed so starting global attributes can be set

print("\nTEST 18 - SUBCLASSING LOCAL\n")

class MyLocal(threading.local):

	def __init__(self, value):
		logging.debug("INITIALISING %r", self)
		self.value = value

local_data = MyLocal(1000)
show_value(local_data)

for i in range(2):
	t = threading.Thread(target=worker, args=(local_data,), name=str(i))
	t.start()

end_threads()

