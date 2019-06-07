/*
 * unordered_map.cpp
 * @author Dan Woolsey
 *
 * std::unordered_map<K,T> example from STL slides
 */

#include <iostream>
#include <unordered_map>
#include <string>

int main(int argc, char *argv[])
{
    std::unordered_map<std::string, int> u_map;

    u_map.insert(std::make_pair<std::string, int>("world", 32));
    u_map.insert(std::make_pair<std::string, int>("somekey", 1));
    u_map.insert(std::make_pair<std::string, int>("hello", 42));
    u_map.erase("somekey");

    {
        auto it = u_map.find("hello");
        if(it!=u_map.end())
        {
            std::cout << "u_map[hello] = " << it->second << std::endl;
        }
    }

    std::cout << "u_map = {";

    // auto == std::unordered_map<std::string, int>::iterator
    for(auto it=u_map.begin(); it!=u_map.end(); it++)
    {
        std::cout << "{ " << it->first << ", " << it->second << " )";
    }
    std::cout << "}" << std::endl;

    return 0;
}
