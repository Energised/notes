/*
 * lower_upper.cpp
 * @author Dan Woolsey
 *
 * lower_bound and upper_bound search operation examples
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[])
{
    std::vector<int> vec = {6, 3, -2, 2, 2, 2, -4, 1, 9};

    // sort full list
    std::sort(vec.begin(), vec.end());

    // binary search for first element not less than 2
    auto lower_it = std::lower_bound(vec.begin(), vec.end(), 2);

    if(lower_it != vec.end())
    {
        std::cout << "lower bound at index " << std::distance(vec.begin(), lower_it) << std::endl;
    }

    // binary search for first element greater than 2
    auto upper_it = std::upper_bound(vec.begin(), vec.end(), 2);

    if(upper_it != vec.end())
    {
        std::cout << "upper bound at index " << std::distance(vec.begin(), upper_it) << std::endl;
    }

    return 0;
}
