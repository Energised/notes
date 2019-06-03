/*
 * Dog.h
 * @author Dan Woolsey
 *
 * Header file for Dog class
 */

#ifndef __DOG__
#define __DOG__

#include "DomesticatedAnimal.h"

class Dog : public DomesticatedAnimal
{
public:
    Dog(const std::string &_name);
    virtual ~Dog();
    virtual void pet() const;
    virtual void speak() const;
};

#endif
