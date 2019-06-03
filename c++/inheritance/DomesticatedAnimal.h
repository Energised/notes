/*
 * DomesticatedAnimal.h
 * @author Dan Woolsey
 *
 * Header file for DomesticatedAnimal class example
 */

#ifndef __DOMESTICATED_ANIMAL__
#define __DOMESTICATED_ANIMAL__

#include "Animal.h"

// DomesticAnimal - subclass of Animal; can be petted
// Non-Domesticated animals can't be petted; no need to define petting
// in Animal superclass

class DomesticatedAnimal : public Animal
{
public:
    DomesticatedAnimal(const std::string &_name);
    virtual ~DomesticatedAnimal();
    // no default implementation for pet()
    // not every DomesticatedAnimal can be petted the same way
    virtual void pet() const = 0;
    // no implementation of virtual function speak()
    // DomesticatedAnimal cannot be directly instantiated
};

#endif
