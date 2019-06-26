/*
 * static-assert.cpp
 * @author Dan Woolsey
 *
 * Using static-assert to create compiler time error checking
 */

#include <iostream>

void process_rgba(unsigned int *rgba_buffer, unsigned int length)
{
    static_assert(sizeof(unsigned int) == 4, "Packed RGBA buffer requires that int is 4 bytes");
    constexpr unsigned int byte_mask = (1 << 8) - 1; // bit shift operation gives 255 (more efficient)

    for(int i=0; i<length; i++)
    {
        const unsigned int &rgba = rgba_buffer[i];
        unsigned char r = rgba          & byte_mask;
        unsigned char g = (rgba >> 8)   & byte_mask; // shift bits right
        unsigned char b = (rgba >> 16)  & byte_mask; // so nth byte (g, b and a)
        unsigned char a = (rgba >> 24)  & byte_mask; // starts at 0th bit

        std::cout << "R: " << r << std::endl;
        std::cout << "G: " << g << std::endl;
        std::cout << "B: " << b << std::endl;
        std::cout << "A: " << a << std::endl;
        // do something with these values
    }
}

int main(int argc, char *argv[])
{
    const unsigned int len = 5; // 5 discreet rgba colours
    // no values set within rgba_buffer; just example
    unsigned int *rgba_buffer = new unsigned int[len]();

    process_rgba(rgba_buffer, len);

    return 0;
}
