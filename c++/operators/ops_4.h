/*
 * ops_4.h
 * @author Dan Woolsey
 *
 * Header file for comparison operator example
 */

#ifndef __OPS_4__
#define __OPS_4__

class Vec3
{
private:
    float x, y, z;
public:
    Vec3(float _x, float _y, float _z);
    bool operator==(const Vec3 &rhs) const;
};

#endif
