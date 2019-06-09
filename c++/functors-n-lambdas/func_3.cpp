/*
 * func_3.cpp
 * @author Dan Woolsey
 *
 * Functor example with state for functor lecture
 */

#include <iostream>

struct EvenCounter
{
    int count;
    EvenCounter() : count(0) {};

    inline void operator()(int x)
    {
        if(x%2 == 0)
        {
            count++;
        }
    }
};

int main(int argc, char *argv[])
{
    EvenCounter even_counter;

    for(int i=0; i<100; ++i)
    {
        even_counter(i);
    }
    std::cout << "# of even numbers: " << even_counter.count << std::endl;

    return 0;
}
