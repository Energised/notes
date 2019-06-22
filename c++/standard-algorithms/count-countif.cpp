/*
 * count-countif.cpp
 * @author Dan Woolsey
 *
 * count and count_if sequence operation examples
 */

#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, char* argv[])
{
    std::vector<int> vec = {1, 3, 3, 4, 5, 3};

    // how many 3's in the countainer
    int num_three = std::count(vec.begin(), vec.end(), 3);

    // how many even elements are there
    int num_even = std::count_if(vec.begin(), vec.end(), [](const int &elem)
    {
        return (elem % 2) == 0;
    });

    std::cout << "# of 3's -> " << num_three << std::endl;
    std::cout << "# of evens -> " << num_even << std::endl;

    return 0;
}
