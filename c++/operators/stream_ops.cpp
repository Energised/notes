/*
 * stream_ops.cpp
 * @author Dan Woolsey
 *
 * Implementation of stream operators overloading example
 */

#include <iostream>
using namespace std;
#include <string>

#include "stream_ops.h"

std::ostream& operator<<(std::ostream& os, const Vec3 &rhs)
{
    os << "(" << rhs.x << ", " << rhs.y << ", " << rhs.z << ")";
    return os;
}

std::istream& operator>>(std::istream& is, const Vec3 &rhs)
{
    //is >> rhs.x >> rhs.y >> rhs.z; // what is wrong with this line
    // raises runtime exception if 3 floats cannot be parsed
    return is;
}

int main()
{
    Vec3 a; // implicitly (0,0,0)
    std::cin >> a; // read 3 numbers from stdin + parse them as floats
    std::cout << "a= " << a << std::endl;
    return 0;
}
