/*
 * constexpr-functions.cpp
 * @author Dan Woolsey
 *
 * Using constexpr within functions example
 */

#include <iostream>

constexpr unsigned int fib(unsigned int N)
{
    if(N == 0) return 0;
    else if(N == 1) return 1;

    return fib(N-1) + fib(N-2);
}

int main(int argc, char *argv[])
{
    constexpr unsigned int value = fib(5);
    std::cout << value << std::endl;
    // value is already known at compile time

    int arr[fib(6)]; // fib(6) == 8, arr is a pointer to 8 ints

    for(int i=0; i<(sizeof(arr)/sizeof(int)); i++)
    {
        std::cout << arr[i] << ",";
    }
    std::cout << std::endl;

    return 0;
}
