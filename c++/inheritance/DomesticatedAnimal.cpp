/*
 * DomesticatedAnimal.cpp
 * @author Dan Woolsey
 *
 * Implementation of DomesticatedAnimal class
 */

#include <iostream>
using namespace std;

#include "DomesticatedAnimal.h"

DomesticatedAnimal::DomesticatedAnimal(const std::string &_name) : Animal(_name)
{
    std::cout << "(" << name << ") Constructor - DomesticatedAnimal" << std::endl;
}

DomesticatedAnimal::~DomesticatedAnimal()
{
    std::cout << "(" << name << ") Destructor - DomesticatedAnimal" << std::endl;
}

// no main function; DomesticatedAnimal cannot be instantiated
