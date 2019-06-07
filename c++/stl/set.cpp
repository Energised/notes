/*
 * set.cpp
 * @author Dan Woolsey
 *
 * std::set<T> example from STL slides
 */

#include <iostream>
#include <set>

int main(int argc, char *argv[])
{
    std::set<int> set;
    set.insert(1);
    set.insert(4);
    set.insert(1);
    set.insert(2);
    set.insert(3);
    set.erase(2);

    {
        auto it = set.find(4);
        // not safe to access data at 'it' until we know
        // it is not the end iterator for the container
        if(it != set.end())
        {
            // safe to access data at it
            std::cout << *it << " is in the set" << std::endl;
        }
    }

    std::cout << "set = {";
    // auto == std::set<int>::iterator
    for(auto it=set.begin(); it!=set.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << "}" << std::endl;

    return 0;
}
