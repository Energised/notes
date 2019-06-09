/*
 * lambda_3.cpp
 * @author Dan Woolsey
 *
 * Lambda with captured reference example
 */

#include <iostream>

int main(int argc, char *argv[])
{
    int count = 0;

    auto even_counter = [&count](int x) -> void
    {
        if(x % 2 == 0) count++;
    };

    // will make copies of all variables by reference it needs to use
    // will make these copies on declaration (not instantiation)
    auto even_counter_2 = [&](int x) -> void
    {
        if(x % 2 == 0) count++;
    };

    for(int i=0; i<100; ++i)
    {
        even_counter(i);
    }
    std::cout << "# of even numbers = " << count << std::endl;

    return 0;
}
