/*
 * ops_1.cpp
 * @author Dan Woolsey
 *
 * Implementation of Vec3 class
 */

 #include <iostream>
 using namespace std;

 #include "ops_1.h"

 Vec3::Vec3(float _x, float _y,  float _z) : x(_x), y(_y), z(_z) {}

 Vec3 Vec3::add(const Vec3 &rhs) const
 {
     return Vec3(x+rhs.x, y+rhs.y, z+rhs.z);
 }

 Vec3 Vec3::add(const float &rhs) const
 {
     return Vec3(x+rhs, y+rhs, z+rhs);
 }

 int main()
 {
     Vec3 a(1,1,1), b(1,2,3);
     Vec3 c = a.add(b).add(5);
     return 0;
 }
