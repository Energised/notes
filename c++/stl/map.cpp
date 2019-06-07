/*
 * map.cpp
 * @author Dan Woolsey
 *
 * std::map<K,T> example from STL slides
 * map is ordered by key, comparison operator for std::string exists already
 */

#include <iostream>
#include <map>
#include <string>

int main(int argc, char *argv[])
{
    std::map<std::string, int> map;

    map.insert(std::make_pair<std::string, int>("world", 32));
    map.insert(std::make_pair<std::string, int>("somekey", 1));
    map.insert(std::make_pair<std::string, int>("hello", 42));
    map.erase("somekey");

    {
        auto it = map.find("hello");
        if(it!=map.end())
        {
            std::cout << "map[hello] = " << it->second << std::endl;
        }
    }

    std::cout << "map = { ";

    // auto == std::map<std::string, int>::iterator
    for(auto it=map.begin(); it!=map.end(); it++)
    {
        std::cout << "( " << it->first << ", " << it->second << " )";
    }
    std::cout << "}" << std::endl;

    return 0;
}
