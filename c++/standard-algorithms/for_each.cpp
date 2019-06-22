/*
 * for_each.cpp
 * @author Dan Woolsey
 *
 * example of for_each sequence operation
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[])
{
    // seed the random number generator
    std::srand(0);

    std::vector<int> vec(10);

    // set each element equal to a random number between 1 and 100
    std::for_each(vec.begin(), vec.end(), [](int &elem) -> void
    {
        elem = std::rand() % 100;
    });

    // print each element out
    std::cout << "vec = { ";

    std::for_each(vec.begin(), vec.end(), [](const int &elem) -> void
    {
        std::cout << elem << " ";
    });

    std::cout << "}" << std::endl;

    return 0;
}
