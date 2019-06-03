/*
 * Animal.h
 * @author Dan Woolsey
 *
 * Header file for example from Inheritance C++ slides
 */

// all animals have a name and all animals make a noise
// but there is not default noise for an animal to make

#ifndef __ANIMAL__
#define __ANIMAL__

class Animal
{
protected:
    std::string name;
public:
    Animal(const std::string &_name);
    virtual ~Animal();
    // all animals make a noise; but there is no default noise for an animal
    // "Animal" cannot be instantiated; doesn't know how to make a noise
    virtual void speak() const = 0;
    // since speak is a pure virtual function w/ no implementation
    // we cannot instantiate a version of Animal
};

#endif
