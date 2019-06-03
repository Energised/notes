/*
 * Dog.cpp
 * @author Dan Woolsey
 *
 * Implementation of Dog : DomesticatedAnimal : Animal
 */

#include <iostream>
using namespace std;

#include "Dog.h"

Dog::Dog(const std::string &_name) : DomesticatedAnimal(_name)
{
    std::cout << "(" << name << ") Constructor - Dog" << std::endl;
}

Dog::~Dog()
{
    std::cout << "(" << name << ") Destructor - Dog" << std::endl;
}

void Dog::pet() const
{
    std::cout << "(" << name << ") Petting the Dog" << std::endl;
}

void Dog::speak() const
{
    std::cout << "(" << name << ") Woof! says the Dog" << std::endl;
}

// commented out so Husky.cpp will work properly
//
//int main(int argc, char* argv[])
//{
//    //Dog x("Odie");
//    DomesticatedAnimal *y = new Dog("Odie");
//    y->speak();
//    y->pet();
//    delete y;
//
//    return 0;
//}
