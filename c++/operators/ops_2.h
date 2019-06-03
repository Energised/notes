/*
 * ops_2.h
 * @author Dan Woolsey
 *
 * Header file for operator overloading example
 */

#ifndef __OPS_2__
#define __OPS_2__

class Vec3
{
private:
     float x, y, z;
public:
    Vec3(float _x, float _y, float _z);
    Vec3 operator+(const Vec3 &rhs) const;
    Vec3 operator+(const float &rhs) const;
};

#endif
