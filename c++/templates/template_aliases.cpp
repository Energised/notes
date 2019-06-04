/*
 * template_aliases.cpp
 * @author Dan Woolsey
 *
 * Making complex templated types easier to use via aliases
 */

#include <iostream>

// alias complex templated type by easy to use moniker
//using std::string = std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>;
// above is just showing what C++ actually does

// alias a known type by a more meaningful name
using size_type = unsigned int;
size_type length = 42;

template<typename A, typename B>
struct SomeObject
{
    A a;
    B b;
};

// partial specialisation through aliasing
template<typename B>
using ConstrainedObject = SomeObject<int, B>;

SomeObject<int, double> x;
ConstrainedObject<double> y;

int main(int argc, char *argv[])
{
    return 0;
}
