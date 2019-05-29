#include <iostream>
#include <string>

// All animals have a name, and all animals make a noise. 
// But there is not default noise for an animal to make. 
class Animal {
protected:
	std::string name;
public:
	Animal(const std::string &_name);
	virtual ~Animal();
	// All Animals make a noise, but there is no "default" noise for an Animal.
	// Because Animal does not know how to make a noise it cannot be instantiated directly.
	virtual void speak() const = 0;
};
Animal::Animal(const std::string &_name) : name(_name) {
	std::cout << "(" << name << ") Constructor - Animal" << std::endl;
}
Animal::~Animal() {
	std::cout << "(" << name << ") Destructor  - Animal" << std::endl;
}

// Crows are a sub-class of Animal, and make a specific noise.
class Crow : public Animal {
public:
	Crow(const std::string &_name);
	virtual ~Crow();
	// Crow promises to provide a concrete implementation of Animal::speak()
	virtual void speak() const;
};
// Constructor must invoke Animal constructor from super-class.
Crow::Crow(const std::string &_name) : Animal(_name) {
	std::cout << "(" << name << ") Constructor - Crow" << std::endl;
}
Crow::~Crow() {
	std::cout << "(" << name << ") Destructor  - Crow" << std::endl;
}
// The Crow is an Animal and has a specific noise that it makes.
// Because Crow knows how to make a noise it can be instantiated.
void Crow::speak() const {
	std::cout << "(" << name << ") Cacaw! says the Crow" << std::endl;
}

// DomesticAnimals are a sub-class of Animal and have an additional functionality in that they can be petted.
// Non-domesticated Animals cannot be petted, so it makes sense for that functionality to not even be visible to the super-class (Animal).
class DomesticatedAnimal : public Animal {
public:
	DomesticatedAnimal(const std::string &_name);
	virtual ~DomesticatedAnimal();
	// Petting a DomesticatedAnimal is different for each type of Animal. 
	// A Parrot would be crushed by the same pets you might give to a St Bernard so there is no default implementation.
	// This would yield an ex-parrot. 
	virtual void pet() const = 0;
	// DomesticatedAnimal does not provide an implementation of the virtual function Animal::speak()
	// meaning DomesticatedAnimal cannot be directly instantiated, just like Animal itself. 
};
// Constructor must invoke Animal constructor from super-class.
DomesticatedAnimal::DomesticatedAnimal(const std::string &_name) : Animal(_name) {
	std::cout << "(" << name << ") Constructor - DomesticatedAnimal" << std::endl;
}
DomesticatedAnimal::~DomesticatedAnimal() {
	std::cout << "(" << name << ") Destructor  - DomesticatedAnimal" << std::endl;
}

// Cats (House Cats) are a sub-class of DomesticatedAnimal
// Cat provides an implementation of Animal::speak() and DomesticatedAnimal::pet() making it a complete type...
// Cat can therefore be directly instantiated.
class Cat : public DomesticatedAnimal {
public:
	Cat(const std::string &_name);
	virtual ~Cat();
	// Cat provides a base implementation of DomesticatedAnimal::pet()
	virtual void pet() const;
	// Cat provides a base implementation of Animal::speak()
	virtual void speak() const;
};
// Constructor must invoke DomesticatedAnimal constructor from super-class.
// This cascades and causes DomesticatedAnimal to invoke the Animal constructor from its super-class. 
Cat::Cat(const std::string &_name) : DomesticatedAnimal(_name) {
	std::cout << "(" << name << ") Constructor - Cat" << std::endl;
}
Cat::~Cat() {
	std::cout << "(" << name << ") Destructor  - Cat" << std::endl;
}
// Cat provides a base implementation of DomesticatedAnimal::pet()
void Cat::pet() const {
	std::cout << "(" << name << ") Petting the Cat" << std::endl;
}
// Cat provides a base implementation of Animal::speak()
void Cat::speak() const {
	std::cout << "(" << name << ") Meow! says the Cat" << std::endl;
}

// Dogs are a sub-class of DomesticatedAnimal
// Dog provides an implementation of Animal::speak() and DomesticatedAnimal::pet() making it a complete type...
// Dog can therefore be directly instantiated.
class Dog : public DomesticatedAnimal {
public:
	// Constructor must invoke DomesticatedAnimal constructor from super-class.
	// This cascades and causes DomesticatedAnimal to invoke the Animal constructor from its super-class. 
	Dog(const std::string &_name);
	virtual ~Dog();
	// Dog provides a base implementation of DomesticatedAnimal::pet()
	virtual void pet() const;
	// Dog provides a base implementation of Animal::speak()
	virtual void speak() const;
};
// Constructor must invoke DomesticatedAnimal constructor from super-class.
// This cascades and causes DomesticatedAnimal to invoke the Animal constructor from its super-class. 
Dog::Dog(const std::string &_name) : DomesticatedAnimal(_name) {
	std::cout << "(" << name << ") Constructor - Dog" << std::endl;
}
Dog::~Dog() {
	std::cout << "(" << name << ") Destructor  - Dog" << std::endl;
}
// Dog provides a base implementation of DomesticatedAnimal::pet()
void Dog::pet() const {
	std::cout << "(" << name << ") Petting the Dog" << std::endl;
}
// Dog provides a base implementation of Animal::speak()
void Dog::speak() const {
	std::cout << "(" << name << ") Woof! says the Dog" << std::endl;
}

// Huskys are a sub-class of Dog
// Husky provides an implementation of Animal::speak() overriding the implementation from Dog::speak()
// Husky inherits an implementation of DomesticatedAnimal::pet() from Dog::pet() making it a complete type...
// Husky can therefore be directly instantiated.
class Husky : public Dog {
public:
	Husky(const std::string &_name);
	virtual ~Husky();
	// Husky provides an overriding implementation of Dog::speak()
	virtual void speak() const;
	// Husky inherits a base implmentation of DomesticatedAnimal::pet() from Dog::pet()
};
// Constructor must invoke Dog constructor from super-class.
// This cascades and causes Dog to invoke the DomesticatedAnimal constructor from its super-class. 
// This cascades and causes DomesticatedAnimal to invoke the Animal constructor from its super-class. 
Husky::Husky(const std::string &_name) : Dog(_name) {
	std::cout << "(" << name << ") Constructor - Husky" << std::endl;
}
Husky::~Husky() {
	std::cout << "(" << name << ") Destructor  - Husky" << std::endl;
}
// Husky provides an overriding implementation of Dog::speak()
void Husky::speak() const {
	std::cout << "(" << name << ") Howl! says the Husky" << std::endl;
}

// StBernards are a sub-class of Dog
// StBernard inherits an implementation of Animal::speak() from Dog::speak()
// StBernard inherits an implementation of DomesticatedAnimal::pet() from Dog::pet() making it a complete type.
// StBernard provides an additional functionality of StBernard::slobber() that all super-classes are unaware of.
// StBernard can therefore be directly instantiated.
class StBernard : public Dog {
public:
	StBernard(const std::string &_name);
	virtual ~StBernard();
	// StBernard provides additional functionality that other Animals thankfully do not provide...
	virtual void slobber() const;
	// StBernard inherits a base implmentation of Animal::speak() from Dog::speak()
	// StBernard inherits a base implmentation of DomesticatedAnimal::pet() from Dog::pet()
};
// Constructor must invoke Dog constructor from super-class.
// This cascades and causes Dog to invoke the DomesticatedAnimal constructor from its super-class. 
// This cascades and causes DomesticatedAnimal to invoke the Animal constructor from its super-class. 
StBernard::StBernard(const std::string &_name) : Dog(_name) {
	std::cout << "(" << name << ") Constructor - StBernard" << std::endl;
}
StBernard::~StBernard() {
	std::cout << "(" << name << ") Destructor  - StBernard" << std::endl;
}
// StBernard provides additional functionality that other Animals thankfully do not provide...
void StBernard::slobber() const {
	std::cout << "(" << name << ") Drools..." << std::endl;
}

int main(int argc, char *argv[]) {

	std::cout << "Allocation Phase" << std::endl << std::endl;

	// Make an array of pointers to individual Animals
	const int num_animals = 5;
	Animal **animals = new Animal*[num_animals];
	
	// Instance each derived type and store their address 
	// in the array of generic Animals...
	animals[0] = new Crow("Kevin");
	animals[1] = new Cat("Garfield");
	animals[2] = new Dog("Odie");
	animals[3] = new Husky("Bolt");
	animals[4] = new StBernard("Sumo");

	std::cout << std::endl << "Testing Phase" << std::endl;
	
	// Visit each Animal in the list of generic Animals
	for (int i = 0; i < num_animals; i++) {
		std::cout << std::endl << "animal[" << i << "] ..." << std::endl << std::endl; 
		
		// All Animals must have acquired an implementation of 
		// the pure virtual function Animal::speak()
		animals[i]->speak();

		// Attempt to promote the Animal pointer to a DomesticatedAnimal pointer
		// Must use dynamic_cast in order to skip properly if the cast fails!
		if (DomesticatedAnimal *y = dynamic_cast<DomesticatedAnimal*>(animals[i])) {
			std::cout << "<< Type promoted from Animal to DomesticatedAnimal >>" << std::endl;
			
			// All DomesticatedAnimals must have acquired an implementation of 
		    // the pure virtual function DomesticatedAnimal::pet()
			y->pet();

			// Attempt to promote the DomesticatedAnimal pointer to a StBernard pointer
			// This implicitly skips hierarchy from DomesticatedAnimal -> Dog -> StBernard
			if (StBernard *z = dynamic_cast<StBernard*>(y)) {
				std::cout << "<< Type promoted from DomesticatedAnimal directly to StBernard >>" << std::endl; 
				
				// All StBernards have unique functionality not visible to any other class in the hierarchy
				z->slobber();				
			}
		}
	}

	std::cout << std::endl << "Deallocation Phase" << std::endl << std::endl;

	for (int i = 0; i < num_animals; i++) {
		// Each Animal was individually allocated, and must be individually deallocated
		delete animals[i];
	}
	// The array of pointers to Animals must also be deallocated individually
	delete [] animals;

	std::cin.get();
	return 0;
}