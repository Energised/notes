/*
 * is_sorted.cpp
 * @author Dan Woolsey
 *
 * is_sorted sorting operation example
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[])
{
    std::vector<int> vec = {1, 2, -3, 4, 5};

    // is the sequence sorted using the < operator
    bool sorted = std::is_sorted(vec.begin(), vec.end());

    // absolute comparison lambda
    auto cmp_abs = [](const int &a, const int &b) -> bool
    {
        return std::abs(a) < std::abs(b);
    };

    // are the absolute values of the list sorted
    bool abs_sorted = std::is_sorted(vec.begin(), vec.end(), cmp_abs);

    std::cout << "sorted -> " << sorted << std::endl;
    std::cout << "abs_sorted -> " << abs_sorted << std::endl;

    return 0;
}
