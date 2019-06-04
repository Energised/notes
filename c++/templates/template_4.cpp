/*
 * template_4.cpp
 * @author Dan Woolsey
 *
 * Multiple parameters for templates example
 */

#include <iostream>

template<typename T>
void foo(T v0, T v1)
{
    std::cout << v0 << " " << v1 << std::endl;
}

int main(int argc, char *argv[])
{
    foo(1, 2); // void foo(int, int)

    //foo(1, "Hello world"); // void foo(int, std::string)
    // ERROR: T cannot match int and std::string at the same time

    int *p0 = nullptr, *p1 = nullptr;
    foo(p0, p1); // void foo(int *, int *)

    float *p2 = nullptr;
    //foo(p0, p2) // void foo(int *. float *)
    // ERROR: T cannot match int* and float* at the same time

    return 0;
}
