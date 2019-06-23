/*
 * binary_search.cpp
 * @author Dan Woolsey
 *
 * binary_search operation example
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[])
{
    std::vector<int> vec = {6, 3, -2, -4, 1, 9};

    // full list sort
    std::sort(vec.begin(), vec.end());

    // search for existence of a specific value
    if(std::binary_search(vec.begin(), vec.end(), 6))
    {
        std::cout << "6 is found in the vector!" << std::endl;
    }

    // combine with partial_sort
    auto pivot = vec.begin() + 4;
    std::partial_sort(vec.begin(), pivot, vec.end());

    if(std::binary_search(vec.begin(), pivot, 1))
    {
        std::cout << "1 is in the first 4 elements of the partially sorted vector" << std::endl;
    }

    return 0;
}
