/*
 * Animal.cpp
 * @author Dan Woolsey
 *
 * Implementation of Animal class from inheritance slides
 */

#include <iostream>
using namespace std;

#include "Animal.h"

Animal::Animal(const std::string &_name) : name(_name)
{
    std::cout << "(" << name << ") Constructor - Animal" << std::endl;
}

Animal::~Animal()
{
    std::cout << "(" << name << ") Destructor - Animal" << std::endl;
}

int main(int argc, char* argv[])
{
    // Animal a("Bob") // this will not work; Animal is not a complete type
    Animal *ptr_to_x = nullptr; // this is fine though
    return 0;
}
