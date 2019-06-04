/*
 * partial_spec.cpp
 * @author Dan Woolsey
 *
 * Partial specialisation example from template lecture
 */

#include <iostream>
#include <cmath>

template<typename T>
struct Complex
{
    T real, imag;
};

// base templated function - matches any T that has an overload of std::abs
template<typename T>
T abs(T &val)
{
    return abs(val);
}

// partially specialised overload - matches a Complex<T> where T can be anything
template<typename T>
T abs(Complex<T> &val)
{
    return sqrt((val.real * val.real) + (val.imag * val.imag));
}

int main(int argc, char *argv[])
{
    double a = abs(-3.14); // |-3.14| = 3.14
    // double abs(double)

    //int b = abs<int>(-5.4); // int (|-5.4|) = 5 // cannot be converted to int implicitly
    // int abs(double) ... std::abs applied to double input,
    // returned as double, implicitly cast to int during return

    Complex<double> c{ 1.0, 2.0 }; // 1+2i
    double d = abs(c); // |1+2i| = 2.2360
    // double abs(Complex<double>)
    return 0;
}
