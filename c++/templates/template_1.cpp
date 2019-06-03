/*
 * template_1.cpp
 * @author Dan Woolsey
 *
 * Template example from lecture 7
 */

#include <iostream>
using namespace std;

template<typename T>
void foo(T var)
{
    std::cout << "foo() = " << var << std::endl;
}

struct MyStruct
{
    int a,b;
};

int main(int argc, char *argv[])
{
    foo(1); //void foo(int);
    // foo() = 1

    int *p = nullptr;
    foo(p); // void foo(int *)
    // foo() = 0

    const double pi = 3.14;
    foo(pi); // void foo(const double)
    // foo() = 3.14

    MyStruct s{1,2};
    //foo(s); // void foo(MyStruct)
    //ERROR: MyStruct doesnt have an << ostream operator
    // would need to implement the operator ourselves for the struct
}
