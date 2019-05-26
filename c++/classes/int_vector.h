/*
 * int_vector.h
 * @author Dan Woolsey
 *
 * Header file for C++ version for resizable int vector
 */

#ifndef __INT_VECTOR__
#define __INT_VECTOR__

class intvector
{
private:
    int *data;
    unsigned int length;

public:
    intvector(const unsigned int length);
    ~intvector();

    void resize(const unsigned int length);
    void push_back(const int value);
    void pop_back();
    void print();

    int& operator[](const int index); // overloaded index operator
    // same usage as pointer array
};

#endif
