/*
 * lambda_captures.cpp
 * @author Dan Woolsey
 *
 * Lambda example captures - not to be run
 */

int i;

auto f0 = [&]() {};          // OK: by-reference capture is default
auto f1 = [&, i]() {};       // OK: by-reference capture
                             //     i is captured by copy

auto f2 = [&, &i]() {};      // ERROR: by-reference capture is default
                             //        reference to i is already captured by '&'

auto f3 = [&, this]() {};    // OK: equivalent to [&]
auto f4 = [&, this, i]() {}; // OK: equivalent to [&, i]
auto f5 = [=]() {};          // OK: by-copy capture is default
auto f6 = [=, &i]() {};      // OK: by-copy capture
                             //     i is captured by reference

auto f7 = [i, i]() {};       // ERROR: i is repeated
