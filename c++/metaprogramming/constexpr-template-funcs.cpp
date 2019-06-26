/*
 * constexpr-template-funcs.cpp
 * @author Dan Woolsey
 *
 * constexpr behaviour via full template specialisation
 */

#include <iostream>

// much more verbose method BUT
// may end up being easier for expressing more complicated conditions

template<unsigned int N>
struct fib
{
    static constexpr unsigned int value = fib<N-1>::value + fib<N-2>::value;
};

template<>
struct fib<0>
{
    static constexpr unsigned int value = 0;
};

template<>
struct fib<1>
{
    static constexpr unsigned int value = 1;
};

int main(int argc, char *argv[])
{
    constexpr unsigned int value = fib<5>::value;
    std::cout << value << std::endl;
    // value is already known at compile time

    int arr[fib<6>::value];
    // fib_struct<6>::value == 8, arr is pointer to 8 bits

    return 0;
}
