/*
 * lambda_1.cpp
 * @author Dan Woolsey
 *
 * Lambda function syntax example
 */

#include <iostream>

// definition + usage
auto plusFive = [](int x) -> int
{
    return x+5;
};

int main(int argc, char *argv[])
{
    int y = 1;
    int z = plusFive(y);
    std::cout << "y = " << y << std::endl;
    std::cout << "z = " << z << std::endl;

    return 0;
}
