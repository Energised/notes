/*
 * ops_3.h
 *
 * Header file for slide 5 of operator overloading presentation
 */

#ifndef __OPS_3__
#define __OPS_3__

class Vec3
{
private:
    float x, y, z;
public:
    Vec3(float _x, float _y, float _z);
    friend Vec3 operator+(const Vec3 &lhs, const float &rhs);
    friend Vec3 operator+(const float &lhs, const Vec3 &rhs);
};

#endif
