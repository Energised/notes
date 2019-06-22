/*
 * equal.cpp
 * @author Dan Woolsey
 *
 * equal sequence operation example
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[])
{
    std::vector<int> vecA = {1, 2, 3};
    std::vector<int> vecB = {1, -2, 3, 4};

    // are the sequences equal using the int == operator
    bool eq = std::equal(vecA.begin(), vecA.end(), vecB.begin());

    // comparing the absolute values from each sequence
    auto cmp_abs = [](const int &a, const int &b) -> bool
    {
        return std::abs(a) == std::abs(b);
    };

    // are the absolute values of the sequences equal
    bool abs_eq = std::equal(vecA.begin(), vecA.end(), vecB.begin(), cmp_abs);

    std::cout << "eq using == operator -> " << eq << std::endl;
    std::cout << "abs_eq -> " << abs_eq << std::endl;

    return 0;
}
