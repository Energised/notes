/*
 * constexpr.cpp
 * @author Dan Woolsey
 *
 * Templated example of process_rgba
 */

#include <iostream>

template<int N>
void process_rgba(unsigned char *rgba_buffer)
{
    static_assert((N%4) == 0, "Length of packed RGBA buffer must be multiple of 4 bytes");

    for(int i=0; i<N; i++)
    {
        unsigned char r = rgba_buffer[i];
        unsigned char g = rgba_buffer[i+1];
        unsigned char b = rgba_buffer[i+2];
        unsigned char a = rgba_buffer[i+3];

        std::cout << "R: " << r << std::endl;
        std::cout << "G: " << g << std::endl;
        std::cout << "B: " << b << std::endl;
        std::cout << "A: " << a << std::endl;
        // do something with these values
    }
}

int main(int argc, char *argv[])
{
    constexpr unsigned int len = 5*4; // 5 discreet rgba colours represented w/ 4 byte char
    unsigned char *rgba_buffer = new unsigned char[len]();

    process_rgba<len>(rgba_buffer);

    return 0;
}
