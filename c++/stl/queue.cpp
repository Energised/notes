/*
 * queue.cpp
 * @author Dan Woolsey
 *
 * std::queue<T,std::deque<T>> derived containers example
 */

#include <iostream>
#include <queue>

int main(int argc, char *argv[])
{
    std::queue<int> que;

    que.push(1);
    que.push(2);
    que.pop(); // removes 1
    que.push(3);
    que.push(4);

    std::cout << "que = { ";

    //auto == std::queue<int>::iterator
    while(!que.empty())
    {
        std::cout << que.front() << " ";
        que.pop();
    }
    std::cout << "}" << std::endl;

    return 0;
}
