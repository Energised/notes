/*
 * my_sqrt.cpp
 * @author Dan Woolsey
 *
 * Catching exceptions with my_sqrt example
 */

#include <iostream>
#include <exception>
#include <cmath>

double my_sqrt(double val)
{
    if(val == 0.0)
    {
        // cannot instantiate std::exception, is a base class
        throw std::runtime_error("my_sqrt(): Zero is not a valid input. ");
    }
    return std::sqrt(val); // offload heavy lifting to standard lib
}

int main(int argc, char* argv[])
{
    try
    {
        std::cout << my_sqrt(2) << std::endl;
        std::cout << my_sqrt(1) << std::endl;

        // will never write to std::cout
        // exception thrown before my_sqrt returns
        // so ostream operator is never called
        std::cout << my_sqrt(0) << std::endl;
    }
    catch(const std::exception &ex)
    {
        std::cerr << "caught in main() : " << ex.what() << std::endl;
    }

    return 0;
}
