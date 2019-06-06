/*
 * stack.cpp
 * @author Dan Woolsey
 *
 * std::stack<T, Container=std::deque<T>> example
 */

#include <iostream>
#include <stack>

int main(int argc, char *argv[])
{
    std::stack<int> stk;

    stk.push(1);
    stk.push(2);
    stk.pop();
    stk.push(3);
    stk.push(4);

    std::cout << "stk = { ";

    while(!stk.empty())
    {
        std::cout << stk.top() << " ";
        // is destructive - removes the element
        stk.pop();
    }
    std::cout << "}" << std::endl;

    return 0;
}
