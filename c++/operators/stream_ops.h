/*
 * stream_ops.h
 * @author Dan Woolsey
 *
 * Header file for stream operations overloading example
 */

#ifndef __STREAM_OPS__
#define __STREAM_OPS__

using namespace std;

class Vec3
{
private:
    float x, y, z;
public:
    friend std::ostream& operator<<(std::ostream& os, const Vec3 &rhs);
    friend std::istream& operator>>(std::istream& is, const Vec3 &rhs);
};

#endif
