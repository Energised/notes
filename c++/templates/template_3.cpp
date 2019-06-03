/*
 * template_3.cpp
 * @author Dan Woolsey
 *
 * Simon Says template example from L7
 */

#include <iostream>

void simon_says(const bool &value)
{
    std::cout << "(bool) Simon says " << (value ? "TRUE" : "FALSE") << std::endl;
}

template<typename T>
void simon_says(const T &value)
{
    std::cout << "(" << typeid(value).name() << ") Simon says " << value << std::endl;
}

int main(int argc, char *argv[])
{
    simon_says(true);

    simon_says(42);
    simon_says<unsigned int>(42);
    simon_says(42.1f); // float
    simon_says(42.2); // double

    simon_says("Hello World"); // char const[13]

    simon_says(std::string("Hello World")); // cba writing its type out

    // types are different from slides due to different compiler options per OS's

    return 0;
}
