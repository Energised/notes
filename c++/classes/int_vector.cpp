/*
 * int_vector.cpp
 * @author Dan Woolsey
 *
 * Implementation of C++ resiable int vector program
 */

#include <iostream>
using namespace std;
#include <cstring> // required for std::memcpy to work

#include "int_vector.h"

intvector::intvector(const unsigned int _length)
{
    length = _length;
    data = new int[length];
}

intvector::~intvector()
{
    if(data != nullptr)
    {
        delete [] data;
        data = nullptr;
    }
    length = 0;
}

void intvector::resize(const unsigned int new_length)
{
    if(new_length > 0)
    {
        if(length > 0)
        {
            int *old_data = data;
            data = new int[new_length];
            std::memcpy(data, old_data, std::min(length, new_length) * sizeof(int));
            delete [] old_data;
        }
        else
        {
            data = new int[new_length];
        }
    }
    else
    {
        if(data != nullptr)
        {
            delete [] data;
            data = nullptr;
        }
    }
    length = new_length;
}

void intvector::push_back(const int value)
{
    resize(length+1);
    data[length-1] = value;
}

void intvector::pop_back()
{
    resize(length-1);
}

void intvector::print()
{
    std::cout << "[";
    for(int i=0; i<length; i++)
    {
        std::cout << " " << data[i];
    }
    std::cout << " ]\n";
}

// returns reference to an int
// means the result of this operator can be written to
int& intvector::operator[](const int index)
{
    return data[index];
}

int main()
{
    intvector x(5);

    for(int i=0; i<5; i++)
    {
        x[i] = i * 2;
    }

    x.print();

    x.push_back(42);
    x.print();

    x.pop_back();
    x.print();

    x.resize(3);
    x.print();

    x.resize(10);
    x.print();

    // destructor is called implicitly once main scope is exited
    return 0;
}
