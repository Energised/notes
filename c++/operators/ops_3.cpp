/*
 * ops_3.cpp
 * @author Dan Woolsey
 *
 * Implementation of operator overloading for the lhs and rhs
 */

#include <iostream>
using namespace std;

#include "ops_3.h"

Vec3::Vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

Vec3 operator+(const Vec3 &lhs, const float &rhs)
{
    return Vec3(lhs.x+rhs, lhs.y+rhs, lhs.z+rhs);
}

Vec3 operator+(const float &lhs, const Vec3 &rhs)
{
    return Vec3(lhs+rhs.x, lhs+rhs.y, lhs+rhs.z);
}

int main()
{
    Vec3 a(1,2,3);
    Vec3 c = 5 + a + 2;
    return 0;
}
