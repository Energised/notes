/*
 * array.cpp
 * @author Dan Woolsey
 *
 * std::array example from STL (standard template library) containers slides
 */

#include <iostream>
#include <array>

int main(int argc, char *argv[])
{
    // make const sized array of int
    const int arr_len = 10;
    int arr[arr_len];

    // set elements
    for(int i=0; i<arr_len; i++)
    {
        arr[i] = i;
    }

    std::cout << "arr = { ";

    for(int i=0; i<arr_len; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << "}" << std::endl;

    // make const sized array of int
    // wrapper around: int arr[10]
    std::array<int, 10> arr_c;

    // set elements
    for(int i=0; i<arr_c.size(); i++)
    {
        arr_c[i] = i;
    }

    std::cout << "arr_c = {";

    // iterator style for loop
    // auto == std::array<int, 10>::iterator
    for(auto it=arr_c.begin(); it!=arr_c.end(); it++)
    {
        std::cout << *it << " ";
    }

    std::cout << "}" << std::endl;

    return 0;
}
