/*
 * sort.cpp
 * @author Dan Woolsey
 *
 * sort (and info on stable_sort) sorting operations example
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[])
{
    std::vector<int> vec = {6, 3, -2, -4, 1, 9};

    // basic sort
    std::sort(vec.begin(), vec.end());
    // vec = {-4, -2, 1, 3, 6, 9}

    // sort as lambda for absolute values
    std::sort(vec.begin(), vec.end(), [](const int &a, const int &b) -> bool
    {
        return std::abs(a) < std::abs(b);
    });
    // vec = {1, -2, 3, -4, 6, 9}

    // reverse sort
    std::sort(vec.begin(), vec.end(), std::greater<int>());
    // vec = {9, 6, 3, 1, -2, -4}

    return 0;
}
