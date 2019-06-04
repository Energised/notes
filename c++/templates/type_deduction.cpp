/*
 * type_deduction.cpp
 * @author Dan Woolsey
 *
 * Type deduction example from templates lecture
 */

#include <iostream>

template<typename OUT, typename IN>
OUT my_cast(IN &var)
{
    return (OUT) var;
}

int main(int argc, char *argv[])
{
    double pi = 3.14;

    int int_pi = my_cast<int>(pi); // int my_cast(double &)
    // OUT = int, IN = double

    // unsigned int uint_pi = my_cast<unsigned int, float>(pi); // wont work ofc
    // unsigned int my_cast(float &)
    // OUT = unsigned int, IN = float
    // WARNING: pi is implicitly cast to a float before the function call

    //std::string string_pi = my_cast<std::string>(pi);
    //std::string my_cast(double &)
    // OUT = std::string, IN = double
    // ERROR: No cast operator from double to std::string

    return 0;
}
