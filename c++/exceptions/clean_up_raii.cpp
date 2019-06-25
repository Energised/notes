/*
 * clean_up_raii.cpp
 * @author Dan Woolsey
 *
 * Automatic clean up with STL containers and exceptions
 */

#include <iostream>
#include <vector>

void another_func()
{
    throw std::runtime_error("ohno...");
}

std::vector<int> func()
{
    std::vector<int> array(10);

    another_func();
    // exception not caught
    // thrown one scope higher
    // arrays destructor called when leaves scope

    return array;
}

int main(int argc, char* argv[])
{
    try
    {
        std::vector<int> array = func();
    }
    catch(const std::exception &ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    return 0;
}
