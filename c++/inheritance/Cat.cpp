/*
 * Cat.cpp
 * @author Dan Woolsey
 *
 * Implementation of Cat; parent class DomesticatedAnimal; parent class Animal
 */

#include <iostream>
using namespace std;

#include "Cat.h"

Cat::Cat(const std::string &_name) : DomesticatedAnimal(_name)
{
    std::cout << "(" << name << ") Constructor - Cat" << std::endl;
}

Cat::~Cat()
{
    std::cout << "(" << name << ") Destructor - Cat" << std::endl;
}

// base implementation of pet()
void Cat::pet() const
{
    std::cout << "(" << name << ") Petting the Cat" << std::endl;
}

// base implementation of speak()
void Cat::speak() const
{
    std::cout << "(" << name << ") Meow! says the Cat" << std::endl;
}

int main(int argc, char** argv) // for some reason, warning is thrown for char* argv
{
    //Cat x("Garfield"); // this works
    Animal *x = new Cat("Garfield");
    x->speak();
    //x->pet();
    delete x;
    return 0;
}
