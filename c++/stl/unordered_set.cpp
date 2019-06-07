/*
 * unordered_set.cpp
 * @author Dan Woolsey
 *
 * std::unordered_set<T> example from STL slides
 */

#include <iostream>
#include <unordered_set>

int main(int argc, char *argv[])
{
    std::unordered_set<int> u_set;
    u_set.insert(1);
    u_set.insert(4);
    u_set.insert(1);
    u_set.insert(2);
    u_set.insert(3);
    u_set.erase(2);

    std::cout << "u_set = { ";

    // auto == std::unordered_set<int>::iterator
    for(auto it=u_set.begin(); it!=u_set.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << "}" << std::endl;

    return 0;
}
