/*
 * incbyten.cpp
 * @author Dan Woolsey
 *
 * Implementation of IncByTen example
 */

#include <iostream>
using namespace std;

#include "incbyten.h"

IncByTen::IncByTen(int _value) : value(_value) {}

IncByTen& IncByTen::operator++()
{
    value += 10;
    return *this;
}

IncByTen IncByTen::operator++(int)
{
    IncByTen temp = *this;
    // value += 10; // we can use the prefix operator instead of this line
    ++(*this);
    return temp;
}

int IncByTen::get_value()
{
    return value;
}

int main()
{
    IncByTen a(5);
    IncByTen b = a++; // postfix: do operation return original
    IncByTen c = ++a; // prefix: do operation return result
    printf("a=%d\n", a.get_value());
    printf("b=%d\n", b.get_value());
    printf("c=%d\n", c.get_value());
    return 0;
}
