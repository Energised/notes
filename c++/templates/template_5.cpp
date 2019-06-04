/*
 * template_5.cpp
 * @author Dan Woolsey
 *
 * Multiple parameters of different types
 */

#include <iostream>

template<typename A, typename B>
void foo(A v0, B v1)
{
    std::cout << v0 << " " << v1 << std::endl;
}

int main(int argc, char *argv[])
{
    foo(1, 2); // void foo(int, int)

    foo(1, "Hello world"); // void foo(int, std::string)

    int *p0 = nullptr, *p1 = nullptr;
    foo(p0, p1); // void foo(int *, int *)

    float *p2 = nullptr;
    foo(p0, p2); // void foo(int *, float *)

    return 0;
}
