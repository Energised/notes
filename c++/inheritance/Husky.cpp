/*
 * Husky.cpp
 * @author Dan Woolsey
 *
 * Implementation of Husky : Dog : DomesticatedAnimal : Animal
 */

#include <iostream>
using namespace std;

#include "Husky.h"

Husky::Husky(const std::string &_name) : Dog(_name)
{
    std::cout << "(" << name << ") Constructor - Husky" << std::endl;
}

Husky::~Husky()
{
    std::cout << "(" << name << ") Destructor - Husky" << std::endl;
}

void Husky::speak() const
{
    std::cout << "(" << name << ") Howl! says the Husky" << std::endl;
}

int main(int argc, char *argv[])
{
    Dog *x = new Husky("Bolt");
    x->speak();
    x->pet();
    delete x;
    
    return 0;
}
