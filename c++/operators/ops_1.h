/*
 * ops_1.h
 * @author Dan Woolsey
 *
 * Header file for operator overloading example
 */

#ifndef __OPS_1__
#define __OPS_1__

class Vec3
{
private:
    float x, y, z;

public:
    Vec3(float _x, float _y, float _z);
    Vec3 add(const Vec3 &rhs) const;
    Vec3 add(const float &rhs) const;
};

#endif
