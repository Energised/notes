/*
 * full_spec.cpp
 * @author Dan Woolsey
 *
 * Full Specialisation example from template lecture
 */

#include <iostream>

// overload - always compiled
void foo(bool val)
{
    std::cout << "Specifically a bool value: " << val << std::endl;
}

// generic template
// only compiled if invoked through usage
template<typename T>
void foo(T val)
{
    std::cout << "Some value: " << val << std::endl;
}

// full specialisation of template
// only compiled if invoked through usage
template<>
void foo<int>(int val)
{
    std::cout << "Specifically an int value: " << val << std::endl;
}

int main(int argc, char *argv[])
{
    foo(true); // specifically a bool value: 1
    foo(3.14); // some value: 3.14
    foo("Hello world"); // some value: hello world
    foo(42); // specifically an int value: 42

    return 0;
}
