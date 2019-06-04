/*
 * Vector_3f.cpp
 * @author Dan Woolsey
 *
 * Implementation of Vec3f with overloaded + and friend ostream operator <<
 */

#include <iostream>

class Vec3f
{
private:
    float x,y,z;
public:
    Vec3f(const float &_x, const float &_y, const float &_z);

    Vec3f operator+(const Vec3f &rhs); // was Vec3f& but return implementation is an instance not a reference

    friend std::ostream& operator<<(std::ostream &os, const Vec3f &rhs);
};

Vec3f::Vec3f(const float &_x, const float &_y, const float &_z) : x(_x), y(_y), z(_z) {}

Vec3f Vec3f::operator+(const Vec3f &rhs)
{
    return Vec3f(x + rhs.x, y + rhs.y, z + rhs.z);
}

std::ostream& operator<<(std::ostream &os, const Vec3f &rhs)
{
    os << "Vec3f(" << rhs.x << ", " << rhs.y << ", " << rhs.z << ")";
    return os;
}

int main(int argc, char *argv[])
{
    Vec3f a(1.5, 1.5, 1.5);
    Vec3f b(1.5, 2.5, 3.5);

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    Vec3f c = a + b;

    std::cout << c << std::endl;

    return 0;
}
