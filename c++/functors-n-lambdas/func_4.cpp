/*
 * func_4.cpp
 * @author Dan Woolsey
 *
 * Functor with external state example
 */

#include <iostream>

struct EvenCounter
{
    int *count;
    EvenCounter(int *_count) : count(_count) {};

    inline void operator()(int x)
    {
        if(x%2 == 0)
        {
            (*count)++;
        }
    }
};

int main(int argc, char *argv[])
{
    int count = 0;
    EvenCounter even_counter(&count);

    for(int i=0; i<100; ++i)
    {
        even_counter(i);
    }
    std::cout << "# of even numbers = " << count << std::endl;

    return 0;
}
