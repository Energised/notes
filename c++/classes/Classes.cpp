/*
 * Classes.cpp
 * @author Dan Woolsey
 */

#include <iostream>
using namespace std;

#include "Classes.h"

// default constructor
NameOfClass::NameOfClass()
{
    value = 42;
}

// overloaded constructor
NameOfClass::NameOfClass(int _value)
{
    value = _value;
}

// destructor
NameOfClass::~NameOfClass() {}

// member functions

void NameOfClass::setValue(int new_value)
{
    value = new_value;
}

int NameOfClass::getValue()
{
    return value;
}

void NameOfClass::doSomething()
{
    printf("Doing something\n");
}

int main()
{
    NameOfClass x = NameOfClass();
    NameOfClass y = NameOfClass(10);
    x.doSomething();
    y.doSomething();
    printf("%d\n%d\n",x.getValue(),y.getValue());
    return 0;
}
