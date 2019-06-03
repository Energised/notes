/*
 * Husky.h
 * @author Dan Woolsey
 *
 * Header file for Husky class
 */

#ifndef __HUSKY__
#define __HUSKY__

#include "Dog.h"

class Husky : public Dog
{
public:
    Husky(const std::string &_name);
    virtual ~Husky();
    // overriding implementation of speak()
    virtual void speak() const;
    // husky inherits a base implementation of pet() from Dog
};

#endif
