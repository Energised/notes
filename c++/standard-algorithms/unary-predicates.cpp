/*
 * unary-predicates.cpp
 * @author Dan Woolsey
 *
 * Unary Functions - Predicates
 */

#include <iostream>

// function is allowed to modify elem
void func(T &elem);

// example lambda unary function
// for assigning elements a random int between 0-100
auto set_rand = [](int &elem) -> void
{
    elem = std::rand() % 100;
};

// function can only observe elem
void func_2(const T &elem);

// function is transformative from type T to type R
R transformation(const T &elem)

// special case of transformative function
// convert elem to boolean by testing some property of it
bool predicate(const T &elem);

// example lambda unary function
// for testing if ints are even
auto is_even = [](const int &elem) -> bool
{
    return (elem % 2) == 0;
};
