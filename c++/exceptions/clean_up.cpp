/*
 * clean_up.cpp
 * @author Dan Woolsey
 *
 * Cleaning up allocated resources before exception handling
 */

#include <iostream>

void another_func()
{
    throw std::runtime_error("ohno...");
}

int* func()
{
    int *array = new int[10];
    try
    {
        another_func();
    }
    catch(...)
    {
        delete[] array;
        array = nullptr;
        throw;
    }
    return array;
}

int main(int argc, char* argv[])
{
    try
    {
        int *ptr = func();
    }
    catch(const std::exception &ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    return 0;
}
