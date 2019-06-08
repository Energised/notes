#include <iostream>
#include <string>

int main(int argc, char* argv[]) {

	// **************************************************************************************************************
	{
		//  +-- x is an integer
		//  |   +-- 1 is an integer literal
		//  |   |
		int x = 1;
	}
	// **************************************************************************************************************
	{
		//    +-- x is an float
		//    |   +-- 3.14f is an float literal
		//    |   |
		float x = 3.14f;
	}
	// **************************************************************************************************************
	{
		//  +-- x,y are an ints
		//  |   +-- 3.14f is an float literal
		//  |   |
		int x = 3.14f;       // Implicit cast to int, compiler likely throws truncation warning
		// warning C4244: 'initializing': conversion from 'float' to 'int', possible loss of data

		int y = (int) 3.14f; // Explicit cast to int, no warning
	}
	// **************************************************************************************************************
	{
		class A {
		private:
			int value;
		public:
			// Singular value constructor for converting int to A
			A(int _value) : value(_value) {}
		};
		
		// +-- x,y,z are instances of class A
		// |   +-- 42 is an int literal
		// |   |
		A  x(42);      // Explicitly invoke A's constructor which takes a single int
		A  y = 42;     // Implicit cast-like construction from int to type A via A's constructor
		A  z = (A) 42; // Explicit cast-like construction from int to type A via A's constructor
	}
	// **************************************************************************************************************
	{
		class A {
		private:
			int value;
		public:
			// Explicit singular value constructor for converting int to A
			explicit A(int _value) : value(_value) {}
		};

		// +-- x,y,z are instances of class A
		// |   +-- 42 is an int literal
		// |   |
		A  x(42);      // Explicitly invoke A's constructor which takes a single int
		A  z = (A) 42; // Explicit cast-like construction from int to type A via A's constructor

		// Implicit cast-like construction not possible, constructor is marked as explicit only
		//A  y = 42; // Error! 
	}
	// **************************************************************************************************************
	{
		class A {
		private:
			int value;
		public:
			// Explicit singular value constructor for converting int to A
			explicit A(int _value) : value(_value) {}

			// Cast operator for converting A to int
			operator int() const {
				// Simple example, could do something more interesting
				return value; 
			}
		};

		//  +-- x,y are instances of class A
		//  |   +-- 42 is an int literal
		//  |   |
		A   x(42);       // Explicitly invoke A's constructor which takes a single int
		A   y = (A) 42;  // Explicit cast-like construction from int to type A via A's constructor

		//  +-- m,n are type int
		//  |   +-- x is an instance of class type A
		//  |   |
		int m = x;       // Implicitly invoke A's cast int operator
		int n = (int) x; // Explicitly invoke A's cast int operator
	}
	// **************************************************************************************************************
	{
		class A {
		private:
			int value;
		public:
			// Explicit singular value constructor for converting int to A
			explicit A(int _value) : value(_value) {}

			// Explicit cast operator for converting A to int
			explicit operator int() const {
				// Simple example, could do something more interesting
				return value;
			}
		};

		//  +-- x,y are instances of class A
		//  |   +-- 42 is an int literal
		//  |   |
		A   x(42);       // Explicitly invoke A's constructor which takes a single int
		A   y = (A)42;   // Explicit cast-like construction from int to type A via A's constructor

		//  +-- m,n are type int
		//  |   +-- x is an instance of class type A
		//  |   |
		int n = (int) x; // Explicitly invoke A's cast int operator

		// Implicit cast not possible, cast operator is marked as expliciy only
		//int m = x; // Error! 
	}
	// **************************************************************************************************************
	{
		class A {
		private:
			int value;
		public:
			// Explicit singular value constructor for converting int to A
			explicit A(int _value) : value(_value) {}

			// Cast operator for converting A to int
			operator int() const {
				// Simple example, could do something more interesting
				return value;
			}
		};

		//  +-- x,y are instances of class A
		//  |   +-- 42.0f is an float literal
		//  |   |
		A   x(42.0f);       // Explicitly invoke A's constructor which takes a single int
		A   y = (A) 42.0f;  // Explicit cast-like construction from int to type A via A's constructor

		//  +-- m,n are type int
		//  |   +-- x is an instance of class type A
		//  |   |
		float m = x;        // Implicit invoke A's cast int operator, then implicitly cast int to float
		float n = (int) x;  // Explicit invoke A's cast int operator, then implicitly cast int to float
		float p = (float) ((int) x); // Explicit invoke A's cast int operator, then explicitly cast int to float
		// Compiler is able to find a path from A to float through int conversion
		// A -> int -> float
	}
	// **************************************************************************************************************
	{
		class A {
		private:
			int value;
		public:
			// Explicit singular value constructor for converting int to A
			A(int _value) : value(_value) {}

			// Expose private member variable
			int get_value() const {
				return value;
			}
		};

		class B {
		private:
			int value;
		public:
			// Explicit singular value constructor for converting int to B
			B(const A &obj) : value( obj.get_value() ) {}

			// Assign an A to an existing B
			B& operator=(const A &rhs) {
				value = rhs.get_value();
				return *this;
			}
		};

		B a(42);       // Implicitly construct an A using single value constructor, then explicit construct a B from the A
		B b( (A) 42 ); // Explicitly cast an int to an A (invoking single value constructor), then explicit B single value constructor
		B c( A(42) );  // Explicitly construct an A from an int, then explicit B single value constructor
		B d = 42;      // Implicitly construct an A from an int, then implicitly construct a B using single value constructor from A
		B e = (A) 42;  // Explicitly cast an int to an A (invoking single value constructor), then implicitly construct a B using single value constructor from A
		B f = A(42);   // Explicitly construct an A from an int, then implicitly construct a B using single value constructor from A

		b = 10;        // Implicitly construct an A using single value constructor, then assign from the A to the B
		b = (A) 10;    // Explicitly cast an int to an A (invoking single value constructor), then assign from the A to the B
		b = A(10);     // Explicitly construct an A from an int, then assign from the A to the B
	}
	// **************************************************************************************************************
	{
		class Cat {
		private:
			std::string name;
			unsigned int lives;
		public:
			Cat(const std::string &_name, const unsigned int &_lives) : name(_name), lives(_lives) {}

			// Return by const reference from const function
			const std::string& get_name() const {
				return name;
			}

			const unsigned int& get_lives() const {
				return lives;
			}
		};

		// This cat has a resource and will outlive all of the code below it. 
		Cat a("Garfield", 42);

		// **************************************************************************************************************
		{
			// No copy - Take Reference - name is a non modifyable reference to the string name within a.
			const std::string &name = a.get_name();
			std::cout << name << std::endl;

			// No copy - Take Reference - std::ostream operator<< for std::string accepts (const std::string &) directly.
			std::cout << a.get_name() << std::endl;
		}
		// **************************************************************************************************************
		{
			// No copy - Take Address - name is a pointer to the non-modifiable string name within a.
			const std::string *name = &(a.get_name());
			std::cout << *name << std::endl;
			// Getting more dangerous, but you may need to do this for some libraries. Avoid 99.99% of the time.
		}
		// **************************************************************************************************************
		{
			// Invoke Copy Constructor - name is a separate copy of the string name within a.
			const std::string name = a.get_name();
			std::cout << name << std::endl;
			// name is a non-modifiable string, its member variables and resource allocating were only allowed to be set during the constructor.
			//
			// It may not be necessary to create a duplicate of the existing resource by copying the originals lifespan is guaranteed to be longer
			// than our need to use it. In this case a const reference would be more efficient.
		}
		// **************************************************************************************************************
		{
			// Invokes Copy Constructor - name is a separate copy of the string name within a, made by copy construction.
			std::string name = a.get_name();
			std::cout << name << std::endl;
		}
		// **************************************************************************************************************
		{
			// Invokes Copy Assignment - name is an empty string, it is then copy assgined to be the string name within a.
			std::string name;
			name = a.get_name();
			std::cout << name << std::endl;
		}
		// **************************************************************************************************************
		{
			// When to invoke the copy constructor instead of passing by reference?
			{
				// This causes an error! We end up with a dangling reference to a string that has been destructed.
				Cat *b = new Cat("Garfield", 42);

				// Invoke Copy Constructor - name is a non-modifiable reference to the string name within b.
				const std::string &name = b->get_name();

				delete b; // Manually invoke the destructor. This kills the cat. :( 
				// Cascade calls destructors of b's member variable of type std::string

				// name is a non-modifiable reference to the string name with b which has now been destructed.
				// A destructed std::string has the same value as an empty std::string. So nothing prints.
				std::cout << name << std::endl;

				// Just because the error was handled gracefully in this 
				// case does not mean it was the correct behaviour!
			}
			// **************************************************************************************************************
			{
				// This does not cause an error. We end up with a detached copy of the string name within b
				Cat *b = new Cat("Garfield", 42);

				// Invoke Copy Constructor - name is a separate copy of the string name within b.
				const std::string name = b->get_name();

				delete b; // Manually invoke the destructor. This kills the cat. :( 
				// Cascade calls destructors of b's member variable of type std::string

				// name is a separate copy of the string name within b, when b is destructed its internal resource is deallocated but name is unaffected.
				std::cout << name << std::endl;
			}
		}
	}

	std::cin.get();
	return 0;
}