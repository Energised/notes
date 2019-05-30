/*
 * Cat.h
 * @author Dan Woolsey
 *
 * Header file for Cat - complete type for DomesticatedAnimal
 */

#ifndef __CAT__
#define __CAT__

#include "DomesticatedAnimal.h"

class Cat : public DomesticatedAnimal
{
public:
    Cat(const std::string &_name);
    virtual ~Cat();
    // base implementation of pet()
    virtual void pet() const;
    // base implementation of speak()
    virtual void speak() const;
};

#endif
