/*
 * func_1.cpp
 * @author Dan Woolsey
 *
 * Basic functor example from Lecture 10
 */

#include <iostream>

struct Functor
{
    inline int operator()(int x) const
    {
        return x+5;
    }
};

int main(int argc, char *argv[])
{
    Functor plus_five; // instance of functor default constructed

    int y = 1;
    int z = plus_five(y); // z = 6
    // invoke call operator of functor
    std::cout << "z = " << z << std::endl;

    // int w = Functor(y); // w = 6
    // implicit construction - could be slow
    // std::cout << "w = " << w << std::endl;

    return 0;
}
