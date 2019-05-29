/*************************************************************************************************************************************/

class SomeObject {
private:
	// Member variables
	int some_value;
	AnotherObject some_resource;

public:
	
	// There are no member functions, constructors, or assignment operators defined.

	// Therefore the compiler gives you an automatically defined "default" versions
	// of the form: SomeObject() {}
	
	// This automatically defined "default constructor" will call the default 
	// constructors of all member variables that have one. 

	// This class has two member variables. One int variable, and one which is another
	// class type. 

	// int is a base-type and does not have a constructor. This means that when this 
	// class (SomeClass) is instanced, and it's constructor is invoked, the int 
	// some_value will not be intialized, meaning it can have any junk value that 
	// happened to be in that address. 

	// AnotherObject is a class type, and must be default constructible so that the
	// automatically defined default constructor here can call it. If it is not 
	// default constructible this is a compiler error. 
};

class AnotherObject {
private:
	// Member variables
	int some_value;

public:
	
	// This class actually implements a "default constructor" meaning one is not 
	// automatically created by the compiler. It explicitly sets some_value to be 42.

	AnotherObject() : some_value(42) {}
};

// Usage example.
SomeObject a;   // Calls the default constructor implicitly.
SomeObject b(); // Calls the default constructor explicitly.

// Both of the above internally call the default constructor of AnotherObject

/*************************************************************************************************************************************/

class ObjectWhichMustBeConstructed {
private:
	// Member variables
	int some_value;

public:
	
	// This class implements a constructor which accepts an integer. Because there is
	// "a" constructor, the compiler does not make an automatic default constructor, 
	// meaning this class cannot be created unless we give an integer value to the constructor. 

	ObjectWhichMustBeConstructed(int value) : some_value(value) {}
};

// Usage example.
ObjectWhichMustBeConstructed a;     // Error: Attempts to call the default constructor implicitly but there is no default constructor.
ObjectWhichMustBeConstructed b();   // Error: Attempts to call the default constructor explicitly but there is no default constructor.
ObjectWhichMustBeConstructed c(42); // Calls the constructor which accepts one int variable. 

/*************************************************************************************************************************************/

class ObjectWhichCanBeConstructed {
private:
	// Member variables
	int some_value;

public:
	
	// This class implements a constructor which accepts an integer. Because there is
	// "a" constructor, the compiler does not make an automatic default constructor. 

	ObjectWhichCanBeConstructed(int value) : some_value(value) {}

	// This class also implements a default constructor which takes no parameters. 

	ObjectWhichCanBeConstructed() : some_value(42) {}
};

// Usage example.
ObjectWhichCanBeConstructed a;     // Calls the default constructor implicitly.
ObjectWhichCanBeConstructed b();   // Calls the default constructor explicitly.
ObjectWhichCanBeConstructed c(42); // Calls the constructor which accepts one int variable. 

/*************************************************************************************************************************************/

class ObjectWithResource {
private:
	// Member variables
	int *some_pointer;

public:
	
	// This class also implements a default constructor which takes no parameters. 
	// The constructor acquires a resource which must be freed eventually.
		
	ObjectWithResource() {
		some_pointer = new int(42);
	}

	~ObjectWithResource() {
		if (some_pointer != nullptr) {
			delete some_pointer;
			some_pointer = nullptr;
		}
	}
};

// Usage example. Brackets indicate a change in scope:

{
	ObjectWithResource a; // Calls the default constructor implicitly.
}
// 'a' goes out of scope and the destructor is called. Freeing the resource. 

// However, consider what happens in this case...

{
	ObjectWithResource a; // Calls the default constructor implicitly.

	{
		ObjectWithResource b = a; // Calls the "default copy constructor" explicitly.
		// ObjectWithResource b(a); is equivalent to the above line.
	}
	// 'b' goes out of scope and the destructor is called. Freeing the resource. 
}
// 'a' goes out of scope and the destructor is called. 
// The resource was already freed, so freeing it again causes a segmentation fault. 

// So what happened here? The compiler as well as giving us default constructors and destructors 
// unless we give them explicitly, also gives us default copy-constructor, copy-assignment, 
// move-constructor, and move-assignment functions.

// Just like the default constructor, and default destructor these default functions simply call
// the corresponding function for each member variable. Base-types like int are copied by value as they
// do not define these functions. 

// Pointers are also copied by value, meaning that both 'a' and 'b' point to the same resource! Who owns the
// resource? Who is responsible for freeing it? How do they know if they need to? How do they know someone else
// has not already freed the resource?

/*************************************************************************************************************************************/

class ObjectWithResourceFixed {
private:
	// Member variables
	int *some_pointer;

public:
	
	// This class also implements a default constructor which takes no parameters. 
	// The constructor acquires a resource which must be freed eventually.
		
	ObjectWithResourceFixed() {
		some_pointer = new int(42);
	}

	~ObjectWithResourceFixed() {
		if (some_pointer != nullptr) {
			delete some_pointer;
			some_pointer = nullptr;
		}
	}

	// This class also implements a copy constructor which duplicates the resource
	// of another instance of this class.

	ObjectWithResourceFixed(const ObjectWithResourceFixed &other) {

		// Allocate the resource, and copy the value from the other object.
		some_pointer = new int( *(other.some_pointer) );
	}
};

// Usage example. Brackets indicate a change in scope:

{
	ObjectWithResourceFixed a; // Calls the default constructor implicitly.

	{
		ObjectWithResourceFixed b = a; // Calls the "copy constructor" explicitly.
		// ObjectWithResourceFixed b(a); is equivalent to the above line.
	}
	// 'b' goes out of scope and the destructor is called. Freeing its version of the resource. 
}
// 'a' goes out of scope and the destructor is called. Freeing its version of the resource. 

// Awesome, so now we duplicate the resource to 'b' and both 'a' and 'b' can be destructed 
// without harming one another!

// However, consider this further example...

{
	ObjectWithResourceFixed a; // Calls the default constructor implicitly.

	{
		ObjectWithResourceFixed b; // Calls the default constructor implicitly.
		
		b = a; // Calls the default copy assignment operator. Leaking the resource 'b' acquired when it was default constructed as it is replaced by 'a's resource.
	}
	// 'b' goes out of scope and the destructor is called. Freeing the resource. 
}
// 'a' goes out of scope and the destructor is called. 
// The resource was already freed, so freeing it again causes a segmentation fault. 

// We now have two memory errors! :(

/*************************************************************************************************************************************/

class ObjectWithResourceReallyFixed {
private:
	// Member variables
	int *some_pointer;

public:
	
	// This class also implements a default constructor which takes no parameters. 
	// The constructor acquires a resource which must be freed eventually.
		
	ObjectWithResourceReallyFixed() {
		some_pointer = new int(42);
	}

	~ObjectWithResourceReallyFixed() {
		if (some_pointer != nullptr) {
			delete some_pointer;
			some_pointer = nullptr;
		}
	}

	// This class also implements a copy constructor which duplicates the resource
	// of another instance of this class.

	ObjectWithResourceReallyFixed(const ObjectWithResourceReallyFixed &other) {

		// Allocate the resource, and copy the value from the other object.
		some_pointer = new int( *(other.some_pointer) );
	}

	// This class also implements a copy assignment operator which frees the resources of this class
	// before duplicating the resource of another instance of this class.

	ObjectWithResourceReallyFixed& operator=(const ObjectWithResourceReallyFixed &other) {

		// Check for self assignment and ignore it - if address of the other object is address of this object
		if (&other == this) return *this;

		// This object has already been constructed, meaning it has a resource. Before we duplicate the\
		// other classes resource we must dispose of our current one. 
		if (some_pointer != nullptr) {
			delete some_pointer;
			some_pointer = nullptr;
		}

		// Allocate the new resource, and copy the value from the other object.
		some_pointer = new int( *(other.some_pointer) );

		return *this;
	}
};

// Usage example. Brackets indicate a change in scope:

{
	ObjectWithResourceReallyFixed a; // Calls the default constructor implicitly.

	{
		ObjectWithResourceReallyFixed b; // Calls the default constructor implicitly.
		
		b = a; // Calls the copy assignment operator. Freeing the resource 'b' acquired when it was default constructed and duplicating by 'a's resource.
	}
	// 'b' goes out of scope and the destructor is called. Freeing the resource. 
}
// 'a' goes out of scope and the destructor is called. Freeing the resource. 

// Yay!

// However (boo), consider another use case which we should consider. What happens when we return a ObjectWithResourceReallyFixed object from a function?

ObjectWithResourceReallyFixed someFunction() {
	
	ObjectWithResourceReallyFixed a; // Calls the default constructor implicitly.

	return a;
}

ObjectWithResourceReallyFixed b = someFunction(); // Internally constructs 'a', acquiring a resource, then invokes the copy constructor, then destructs 'a'. 

// We constructed 'a' inside the function, we spent time duplicating it's resource (potentially gigabytes of data) to give to 'b'. Then we just threw away 'a' and freed it's resource!
// What a waste of computation time!

/*************************************************************************************************************************************/

class ObjectWithResourceReallyReallyFixed {
private:
	// Member variables
	int *some_pointer;

public:
	
	// This class also implements a default constructor which takes no parameters. 
	// The constructor acquires a resource which must be freed eventually.
		
	ObjectWithResourceReallyReallyFixed() {
		some_pointer = new int(42);
	}

	~ObjectWithResourceReallyReallyFixed() {
		if (some_pointer != nullptr) {
			delete some_pointer;
			some_pointer = nullptr;
		}
	}

	// This class also implements a copy constructor which duplicates the resource
	// of another instance of this class.

	ObjectWithResourceReallyReallyFixed(const ObjectWithResourceReallyReallyFixed &other) {

		// Allocate the resource, and copy the value from the other object.
		some_pointer = new int( *(other.some_pointer) );
	}

	// This class also implements a copy assignment operator which frees the resources of this class
	// before duplicating the resource of another instance of this class.

	ObjectWithResourceReallyReallyFixed& operator=(const ObjectWithResourceReallyReallyFixed &other) {

		// Check for self assignment and ignore it - if address of the other object is address of this object
		if (&other == this) return *this;

		// This object has already been constructed, meaning it has a resource. Before we duplicate the\
		// other classes resource we must dispose of our current one. 
		if (some_pointer != nullptr) {
			delete some_pointer;
			some_pointer = nullptr;
		}

		// Allocate the new resource, and copy the value from the other object.
		some_pointer = new int( *(other.some_pointer) );

		return *this;
	}

	// This class also implements a move constructor which steals ownership of the resource 
	// of another instance of this class.

	ObjectWithResourceReallyReallyFixed(ObjectWithResourceReallyReallyFixed &&other) {

		// Steal the resource from other
		some_pointer = other.some_pointer;

		// Make other forget it ever had a resource
		other.some_pointer = nullptr;
	}
};

// Usage example. 

ObjectWithResourceReallyReallyFixed someFunction() {
	
	ObjectWithResourceReallyReallyFixed a; // Calls the default constructor implicitly.

	return a;
}

ObjectWithResourceReallyReallyFixed b = someFunction(); 
// Internally constructs 'a', acquiring a resource, then invokes the move constructor, stealing the resource and making 'a' forget it existed, 
//then destructs 'a' which has nothing to free because the move constructor set 'a's pointer to nullptr. 

// So the move constructor allowed us to hand off ownership of the resource in O(1) constant time with no copying or memory overhead! Awesome! 
// If the resource was large and required looping over an array or something similar we would have gone from O(n) linear time to O(1) time. 

// However (groans...) there is still one more case we have not considered.

ObjectWithResourceReallyReallyFixed someFunction() {
	
	ObjectWithResourceReallyReallyFixed a; // Calls the default constructor implicitly.

	return a;
}

ObjectWithResourceReallyReallyFixed b; // Calls the default constructor implicitly.

b = someFunction(); // Internally constructs 'a', acquiring a resource, then invokes the copy assignment operator, freeing 'b's resource, duplicating 'a's, then destructs 'a'. 

// Again, we constructed 'a' inside the function, we spent time duplicating it's resource (potentially gigabytes of data) to give to 'b'. Then we just threw away 'a' and freed it's resource!
// What a waste of computation time!

/*************************************************************************************************************************************/

class ObjectWithResourceCompletelyFixed {
private:
	// Member variables
	int *some_pointer;

public:
	
	// This class also implements a default constructor which takes no parameters. 
	// The constructor acquires a resource which must be freed eventually.
		
	ObjectWithResourceCompletelyFixed() {
		some_pointer = new int(42);
	}

	~ObjectWithResourceCompletelyFixed() {
		if (some_pointer != nullptr) {
			delete some_pointer;
			some_pointer = nullptr;
		}
	}

	// This class also implements a copy constructor which duplicates the resource
	// of another instance of this class.

	ObjectWithResourceCompletelyFixed(const ObjectWithResourceCompletelyFixed &other) {

		// Allocate the resource, and copy the value from the other object.
		some_pointer = new int( *(other.some_pointer) );
	}

	// This class also implements a copy assignment operator which frees the resources of this class
	// before duplicating the resource of another instance of this class.

	ObjectWithResourceCompletelyFixed& operator=(const ObjectWithResourceCompletelyFixed &other) {

		// Check for self assignment and ignore it - if address of the other object is address of this object
		if (&other == this) return *this;

		// This object has already been constructed, meaning it has a resource. Before we duplicate the\
		// other classes resource we must dispose of our current one. 
		if (some_pointer != nullptr) {
			delete some_pointer;
			some_pointer = nullptr;
		}

		// Allocate the new resource, and copy the value from the other object.
		some_pointer = new int( *(other.some_pointer) );

		return *this;
	}

	// This class also implements a move constructor which steals ownership of the resource 
	// of another instance of this class.

	ObjectWithResourceCompletelyFixed(ObjectWithResourceCompletelyFixed &&other) {

		// Steal the resource from other
		some_pointer = other.some_pointer;

		// Make other forget it ever had a resource
		other.some_pointer = nullptr;
	}

	// This class also implements a move assignment which frees the resources of this class
	// before stealing ownership of the resource of another instance of this class.

	ObjectWithResourceCompletelyFixed& operator=(ObjectWithResourceCompletelyFixed &&other) {

		// Check for self assignment and ignore it - if address of the other object is address of this object
		if (&other == this) return *this;

		// This object has already been constructed, meaning it has a resource. Before we steal the
		// other classes resource we must dispose of our current one. 
		if (some_pointer != nullptr) {
			delete some_pointer;
			some_pointer = nullptr;
		}

		// Steal the resource from other
		some_pointer = other.some_pointer;

		// Make other forget it ever had a resource
		other.some_pointer = nullptr;

		return *this;
	}
};

// Usage example. 

ObjectWithResourceCompletelyFixed someFunction() {
	
	ObjectWithResourceCompletelyFixed a; // Calls the default constructor implicitly.

	return a;
}

ObjectWithResourceCompletelyFixed b; // Calls the default constructor implicitly.

b = someFunction(); // Internally constructs 'a', acquiring a resource, then invokes the move assignment operator, freeing 'b's resource, stealing the resource from 'a' and making 'a' forget it existed, then destructs 'a' which has nothing to free because the move constructor set 'a's pointer to nullptr. 

// So the move assignment operator allowed us to hand off ownership of the resource in O(1) time, including the caveat that we already had a resource that needed to be freed first. Awesome!

