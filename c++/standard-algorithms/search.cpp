/*
 * search.cpp
 * @author Dan Woolsey
 *
 * search sequence operation example
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[])
{
    std::vector<int> vec = {0, 1, -2, 3, 4, 2, 3};
    std::vector<int> pattern = {2, 3};

    // search for pattern using ints == operator
    auto it = std::search(vec.begin(), vec.end(), pattern.begin(), pattern.end());

    // test if the sequence was found
    if(it != vec.end())
    {
        std::cout << "Sequence found at index " << std::distance(vec.begin(), it) << std::endl;
    }

    // lambda for absolute equality
    auto eq_abs = [](const int &a, const int &b) -> bool
    {
        return std::abs(a) == std::abs(b);
    };

    // search for pattern using absolute lambda
    auto abs_it = std::search(vec.begin(), vec.end(), pattern.begin(), pattern.end(), eq_abs);

    // check if absolute sequence was found
    if(abs_it != vec.end())
    {
        std::cout << "Abs sequence found at index " << std::distance(vec.begin(), abs_it) << std::endl;
    }

    return 0;
}
