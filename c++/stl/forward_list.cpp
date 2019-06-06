/*
 * forward_list.cpp
 * @author Dan Woolsey
 *
 * std::forward_list (singly linked list) STL example
 */

#include <iostream>
#include <forward_list>

int main(int argc, char *argv[])
{
    std::forward_list<int> lst;

    lst.push_front(3);
    lst.push_front(2);

    std::cout << "lst = { ";
    for(auto it=lst.begin(); it!=lst.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << "}" << std::endl;

    // ERROR: forward_list does not have reverse iterators
    return 0;
}
