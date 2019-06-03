/*
 * ops_2.cpp
 * @author Dan Woolsey
 *
 * Implementation of example code from operator overloading slides
 */

#include <iostream>
using namespace std;

#include "ops_2.h"

Vec3::Vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

Vec3 Vec3::operator+(const Vec3 &rhs) const
{
    return Vec3(x+rhs.x, y+rhs.y, z+rhs.z);
}

Vec3 Vec3::operator+(const float &rhs) const
{
    return Vec3(x+rhs, y+rhs, z+rhs);
}

int main()
{
    Vec3 a(1,1,1), b(1,2,3);
    Vec3 c = a+b+5;
    // c = 5+a+b would return a compiler error
}
