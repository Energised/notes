/*
 * ops_4.cpp
 * @author Dan Woolsey
 *
 * Implementation of comparison operator example
 */

#include <iostream>
using namespace std;
#include <string>

#include "ops_4.h"

Vec3::Vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

bool Vec3::operator==(const Vec3 &rhs) const
{
    // can refer to the lhs implicitly as variable names
    return (x == rhs.x) && (y == rhs.y) && (z == rhs.z);
}

int main()
{
    Vec3 a(1,2,3), b(1,2,3);
    if(a == b)
    {
        printf("Vectors a and b are equivalent\n");
    }
    return 0;
}
