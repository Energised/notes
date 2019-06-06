/*
 * deque.cpp
 * @author Dan Woolsey
 *
 * std::deque (double ended queue) example from STL slides
 */

#include <iostream>
#include <deque>

int main(int argc, char *argv[])
{
    std::deque<int> deq;

    deq.push_back(3);
    deq.push_front(2);
    deq.push_front(1);
    deq.push_back(4);
    deq.push_front(0);
    deq.pop_front();

    std::cout << "deq = { ";

    // iterator style for loop
    // auto == std::deque<int>::iterator
    for(auto it=deq.begin(); it!=deq.end(); it++)
    {
        std::cout << *it << " ";
    }

    std::cout << "}" << std::endl;

    // deq auto-destructed once out of scope
    return 0;
}
