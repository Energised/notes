# DJANGO WEB FRAMEWORK AND DATABASES
#
# dan woolsey
# 2016

# INFORMATION TO KNOW AND REMEMBER:
#
# Web Framework -> A code library that makes a devs life easier when building web applications
# Introspection -> The ability of a program to examine the type or properties of an object at runtime
# Model -> Contains the essential fields and behaviours of the data being stored
# ANSI -> American National Standards Institute
# ISO -> International Organisation for Standardisation
# Slug -> Label containing only letters, numbers, underscores and hyphens
# Relvar -> Shortening for relation variable
#
# The Design Philosophies of Django:
# https://docs.djangoproject.com/en/1.9/misc/design-philosophies/
#
# RELATIONAL DATABASE TERMS:
#
#   -----------------------------------------------------------------------------------------------------
#	| SQL TERM |  REL_DB TERM     | DESCRIPTION      
#   -----------------------------------------------------------------------------------------------------
#   |  Row     | Tuple/Record     | A data set representing a single item
#   |  Column  | Attribute/Field  | Labelled Element of a tuple
#   |  Table   | Relation         | Set of tuples sharing the same attributes / Set of columns and rows
#   |  View    | Derived relvar   | Any set of tuples, usually in response to a query
#   ------------------------------------------------------------------------------------------------------
#
# Functionality of a Framework:
#
#	-> URL Routing
#	-> HTML, XML, JSON and other output format templating
#	-> Database Manipulation
#	-> Security against web based attacks (CSRF etc)
#	-> Session storage and retrieval

# http://stackoverflow.com/questions/4507506/what-is-a-web-framework-how-does-it-compare-with-lamp
# Question on differences between LAMP and Web Frameworks 

# STARTING OFF WITH DJANGO

$ django-admin startproject mysite

# where mysite is the name of the site project
# run this in the cwd you want your project to be in
# this autogenerates some code django needs

# django-admin is a command line utility for django admin tasks
# it can be called as either:

#	django-admin <command> [options] - directly using the program
#	manage.py <command> [options] - addressing the manage file in a specific project
#	python -m django <command> [options] - directly address the django module

# RUNNING THE SERVER

$ python3 manage.py runserver

# must be done in the working directory of your server
# make sure you're using the correct version of python (3.5.x)

# NOTE: you can add either a port or an IP address as an argument to the runserver
#       command in order to run the server on a different port or IP address

# ADDING APPS TO YOUR PROJECT

$ python3 manage.py startapp <appname>

# this generates a directory for that app in your cwd

# APPS IN DJANGO
#
#	Here are a list of the basic applications that come with any django project:
#
#		django.contrib.admin 		 - Admin site
#		django.contrib.auth			 - Authentication system (user verification)
#		django.contrib.contenttypes  - Content Types framework (metadata for db's)
#		django.contrib.sessions		 - Sessions framework (data on a users visit to your site)
#		django.contrib.messages		 - Messaging framework
#		django.contrib.staticfiles   - Static file framework (files that won't change e.g. images, CSS, javascript)
#
# You can find add more apps to your project by editing the settings.py file in the project directory and appending
# them to the list INSTALLED_APPS

# DATABASES IN DJANGO
#
# In your projects settings.py file, you can edit information about the database your project will use
#
# You must use a RDBMS (Relational Database Management System) which include: SQLite, MySQL, PostgreSQL
#
# https://www.digitalocean.com/community/tutorials/sqlite-vs-mysql-vs-postgresql-a-comparison-of-relational-database-management-systems
# (useful information ^^)
#
# ACID (Atomicity, Consistency, Isolation, Durability) - Set of properties that ensure database transactions are processed reliably
# (ACID TRANSACTIONS - https://en.wikipedia.org/wiki/ACID)
#
# Step 1 - Generate SQL tables

	python3 manage.py migrate

# The command looks at the INSTALLED_APPS list and creates any tables that are necessary according to the settings.py file
#
# Step 2 - Define models
#
	from django.db import models

# - Each key needs to be defined as a model subclass
# - The metadata for each key is an attribute of that class
#
# All fields can take any number of general field options, refer to:
# https://docs.djangoproject.com/en/1.9/ref/models/fields/#field-options
#
# NOTE: All Field instances can have a human readable name as its first positional argument e.g.
#
#	new_attribute = models.IntegerField('how much i care')

class model_name(models.Model):
	attr_one = models.BigIntegerField() # 64 bit integer
	attr_two = models.BooleanField() # booleans
	attr_three = models.CharField(max_length=200) # max_length of the string
	attr_four = models.DateField(auto_now=False, auto_now_add=False)
	# auto_now -> if True, updates the date everytime the model is saved (date modified)
	# auto_now_add -> if True, only updates the time upon first creation (date created)
	# (these options are mutually exclusive, used together will result in an error)
	attr_five = models.DateTimeField(auto_now=False, auto_now_add=False) # same as DateField except with time
	attr_six = models.DecimalField(max_digits=5, decimal_places=2) # decimal - uses pythons decimal type
	attr_seven = models.EmailField(max_length=254) # checks if input is an email address - default max_length is 254
	attr_eight = models.FileField(upload_to=None, max_length=100) # EXPLAIN ANOTHER TIME
	attr_nine = models.FilePathField(path=None, match=None, recursive=False, max_length=100)
	# a string that has to be a path in the projects file system
	# path -> the absolute path from which the field gets its choices (required)
	# match -> a regex it will check file names against (optional)
	# recursive -> True if all subdirectories of path are included in the check
	# allow_files -> Default to True - allows files in the path
	# allow_folders -> Default to False - allows folders in the path (allow_files and allow_folders can be used together)
	attr_ten = models.FloatField() # float - uses pythons float type
	attr_eleven = models.ImageField(upload_to=None, height_field=None, width_field=None) # EXPLAIN ANOTHER TIME
	attr_twelve = models.IntegerField() # int
	attr_thirteen = models.GenericIPAddressField(protocol='both',unpack_ipv4=False)
	# protocol -> 'both', 'IPv4', 'IPv6'
	# unpack_ipv4 -> returns all IPv4 addresses in the form xxx.xxx.xxx.xxx
	attr_fourteen = models.NullBooleanField() # allows a boolean to also be null
	attr_fifteen = models.PositiveIntegerField() # only positive numbers
	attr_sixteen = models.SlugField() # charfield but specifically for slugs
	attr_seventeen = models.TextField() # text
	attr_eighteen = models.TimeField() # holds a time, same as DateField
	attr_nineteen = models.URLField() # holds a URL

# haven't covered every available field option, extra information available on the docs
#
# - Relation Fields
#
#		1) Foreign Key
#
			models.ForeignKey(othermodel, on_delete=models.CASCADE) # other model is the key it references
#
#			- Defines a many to one relationship
#			- othermodel -> Points to a name (string) or an object
#			- on_delete -> Decides how the db reacts to removing the object, can be:
#					
#				models.CASCADE -> Deletes the object containing the foreign key
#				models.PROTECT -> Stops deletion, raises ProtectedError exception
#				models.SET_NULL -> Set the foreign key to null (only if the option null is true)
#				models.SET_DEFAULT -> Sets the foreign key to it's default value, as long as one is set
#				models.SET() -> Pass in a value or call in order to avoid executing queries when models.py is imported
#				models.DO_NOTHING -> Does nothing but raise an IntegrityError unless otherwise specified in SQL
#
#

