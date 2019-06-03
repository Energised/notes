/*
 * Crow.h
 * @author Dan Woolsey
 *
 * Header file for Crow class inheriting from Animal
 */

#ifndef __CROW__
#define __CROW__

#include "Animal.h"

class Crow : public Animal
{
public:
    Crow(const std::string &_name);
    virtual ~Crow();
    // Crow will provide a concrete implementation of Animal::speak();
    virtual void speak() const;
};

#endif
