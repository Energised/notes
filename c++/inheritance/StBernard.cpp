/*
 * StBernard.cpp
 * @author Dan Woolsey
 *
 * Implementation of StBernard : Dog : DomesticatedAnimal : Animal
 */

#include <iostream>
using namespace std;

#include "StBernard.h"

StBernard::StBernard(const std::string &_name) : Dog(_name)
{
    std::cout << "(" << name << ") Constructor - StBernard" << std::endl;
}

StBernard::~StBernard()
{
    std::cout << "(" << name << ") Destructor - StBernard" << std::endl;
}

void StBernard::slobber() const
{
    std::cout << "(" << name << ") Drools..." << std::endl;
}

int main(int argc, char *argv[])
{
    StBernard *x = new StBernard("Sumo");
    x->speak();
    x->pet();
    x->slobber();
    delete x;

    return 0;
}
