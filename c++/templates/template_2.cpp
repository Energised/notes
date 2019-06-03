/*
 * template_2.cpp
 * @author Dan Woolsey
 *
 * Template example expanded from Lecture 7
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

std::ostream& operator<<(std::ostream &os, MyStruct &obj)
{
    os << "{ " << obj.a << ", " << obj.b << " }"; // warning but cant define return type void
}

int main(int argc, char *argv[])
{
    MyStruct s{1,2};
    foo(s); // void foo(MyStruct)
    // foo() = { 1, 2 }
    return 0;
}
