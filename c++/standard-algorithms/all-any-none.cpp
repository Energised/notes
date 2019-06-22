/*
 * all-any-none.cpp
 * @author Dan Woolsey
 *
 * all_of, any_of, none_of sequence operation examples
 */

#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, char* argv[])
{
    std::vector<int> vec = {1, 3, 4, 5};

    // are all elements less than 10
    bool all = std::all_of(vec.begin(), vec.end(), [](const int &elem) -> bool
    {
        return elem < 10;
    });

    // is at least 1 element even
    bool any = std::any_of(vec.begin(), vec.end(), [](const int &elem) -> bool
    {
        return (elem % 2) == 0;
    });

    // is no element greater than 5
    bool none = std::none_of(vec.begin(), vec.end(), [](const int &elem) -> bool
    {
        return elem > 5;
    });

    std::cout << "all less than 10? " << all << std::endl;
    std::cout << "any evens? " << any << std::endl;
    std::cout << "none greater than 5? " << none << std::endl;

    return 0;
}
