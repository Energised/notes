/*
 * Vector_3f_template.cpp
 * @author Dan Woolsey
 *
 * Implementation of Vec3f with overloaded + and friend ostream operator <<
 * using template types
 */

#include <iostream>

template<typename T>
class Vec3f
{
private:
    T x,y,z;
public:
    Vec3f(const T &_x, const T &_y, const T &_z);

    Vec3f<T> operator+(const Vec3f<T> &rhs); // was Vec3f& but return implementation is an instance not a reference

    template<typename E>
    friend std::ostream& operator<<(std::ostream &os, const Vec3f<E> &rhs);
};

template<typename T>
Vec3f<T>::Vec3f(const T &_x, const T &_y, const T &_z) : x(_x), y(_y), z(_z) {}

template<typename T>
Vec3f<T> Vec3f<T>::operator+(const Vec3f &rhs)
{
    return Vec3f<T>(x + rhs.x, y + rhs.y, z + rhs.z);
}

template<typename T>
std::ostream& operator<<(std::ostream &os, const Vec3f<T> &rhs)
{
    os << "Vec3f(" << rhs.x << ", " << rhs.y << ", " << rhs.z << ")";
    return os;
}

int main(int argc, char *argv[])
{
    Vec3f<int> a(1.5, 1.5, 1.5); // for int types linux compiler rounds down
    Vec3f<int> b(1.5, 2.5, 3.5); // odd - could add 0.5 to values and then cast to int

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    Vec3f<int> c = a + b;

    std::cout << c << std::endl;

    return 0;
}
