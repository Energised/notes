/*
 * Crow.cpp
 * @author Dan Woolsey
 *
 * Implementation of Crow example; base class Animal; from inheritance slides
 */

#include <iostream>
#include <string>
using namespace std;

#include "Crow.h"

Crow::Crow(const std::string &_name) : Animal(_name)
{
    std::cout << "(" << name << ") Constructor - Crow" << std::endl;
}

Crow::~Crow()
{
    std::cout << "(" << name << ") Destructor - Crow" << std::endl;
}

// Crow is an Animal and has a specific noise it makes
// bc Crow knows how to make a noise it can instantiated

void Crow::speak() const
{
    std::cout << "(" << name << ") Cacaw! says the Crow" << std::endl;
}

// for compiling Crow.cpp; must
// 1) comment main from Animal.cpp
// 2) g++ Animal.cpp Crow.cpp -o Crow

int main(int argc, char* argv[])
{
    //Crow x("Kevin"); // this works btw
    Animal *x = new Crow("Kevin");
    // (Kevin) Constructor - Animal
    // (Kevin) Constructor - Crow

    x->speak();
    // (Kevin) Cacaw! says the Crow

    delete x;
    // (Kevin) Destructor - Crow
    // (Kevin) Destructor - Animal

    return 0;
}
