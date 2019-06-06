/*
 * list.cpp
 * @author Dan Woolsey
 *
 * std::list (doubly linked list) STL example
 */

#include <iostream>
#include <list>

int main(int argc, char *argv[])
{
    std::list<int> lst;

    lst.push_back(3);
    lst.push_front(2);

    std::cout << "lst = { ";

    // auto == std::list<int>::iterator
    for(auto it=lst.begin(); it!=lst.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << "}" << std::endl;

    std::cout << "lst = { ";
    // auto == std::list<int>::reverse_iterator
    for(auto it=lst.rbegin(); it!=lst.rend(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << "}" << std::endl;

    return 0;
}
