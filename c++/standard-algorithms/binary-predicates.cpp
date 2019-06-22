/*
 * binary-predicates.cpp
 * @author Dan Woolsey
 *
 * Binary functions - Predicates example
 */

#include <iostream>
#include <string>

// a function which takes 2 non-modifiable elements
// and performs some comparison to yield a boolean
bool predicate(const T &a, const T &b);

// example lambda binary predicate for testing if
// the first character of two strings are the same
auto same_start = [](const std::string &a, const std::string &b) -> bool
{
    return a[0] == b[0];
};

// example lambda binary predicate for comparing
// strings based solely on their lengths
auto shorter_string = [](const std::string &a, const std::string &b) -> bool
{
    return a.size() < b.size();
};

// a function which takes 2 non-modifiable elements
// and outputs a new value of a potentially different type
R transformation(const T &a, const T &b);
