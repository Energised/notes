/*
 * find-findif.cpp
 * @author Dan Woolsey
 *
 * find and find_if sequence operations examples
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[])
{
    std::vector<int> vec = {1, 3, 3, 4, 5, 3};

    // find first occurence of 3
    auto it_three = std::find(vec.begin(), vec.end(), 3);

    // test if 3 was actually found
    if(it_three != vec.end())
    {
        std::cout << "A 3 was found at index " << std::distance(vec.begin(), it_three) << std::endl;
    }

    // find first even element
    auto it_even = std::find_if(vec.begin(), vec.end(), [](const int &elem)
    {
        return (elem % 2) == 0;
    });

    // test if an even element was found
    if(it_even != vec.end())
    {
        std::cout << "An even element was found at index " << std::distance(vec.begin(), it_even) << std::endl;
    }

    return 0;
}
