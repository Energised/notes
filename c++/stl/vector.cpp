/*
 * vector.cpp
 * @author Dan Woolsey
 *
 * sts::vector example from STL slides
 */

#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
    // make an empty vector of ints; currently size 0
    std::vector<int> vec;

    // push 10 elements
    for(int i=0; i<10; i++)
    {
        vec.push_back(i);
    }

    std::cout << "vec.size() = " << vec.size() << std::endl;

    // pop the last element of the vector
    vec.pop_back();

    std::cout << "vec.size() = " << vec.size() << std::endl;

    // vec auto-destructed once out of scope

    return 0;
}
