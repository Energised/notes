/*
 * for_each_n.cpp
 * @author Dan Woolsey
 *
 * for_each_n sequence operation example
 */

#include <iostream>
#include <list>
#include <algorithm>

int main(int argc, char* argv[])
{
    // seed rng
    std::srand(0);

    std::list<int> lst(10);

    // set each element equal to a random number between 0 and 100
    // only exists in C++17 onwards
    std::for_each_n(lst.begin(), 5, [](int &elem) -> void
    {
        elem = std::rand() % 100;
    });

    // print each element out
    std::cout << "lst = { ";

    std::for_each(lst.begin(), lst.end(), [](const int &elem) -> void
    {
        std::cout << elem << " ";
    });

    std::cout << "}" << std::endl;

    return 0;
}
