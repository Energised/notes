/*
 * StBernard.h
 * @author Dan Woolsey
 *
 * Header file for StBernard class
 */

#ifndef __ST_BERNARD__
#define __ST_BERNARD__

#include "Dog.h"

class StBernard : public Dog
{
public:
    StBernard(const std::string &_name);
    virtual ~StBernard();
    // new functionality for this class
    virtual void slobber() const;
};

#endif
