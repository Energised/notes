/*
 * runtime-assert.cpp
 * @author Dan Woolsey
 *
 * Using old C-style error handling method - assert
 */

#include <iostream>
#include <cassert>

void process_rgba(unsigned char *rgba_buffer, unsigned int length)
{
    assert((length%4) == 0 && "Length of packed RGBA buffer must be multiple of 4 bytes");

    for(int i=0; i<length; i+=4)
    {
        unsigned char r = rgba_buffer[i];
        unsigned char g = rgba_buffer[i+1];
        unsigned char b = rgba_buffer[i+2];
        unsigned char a = rgba_buffer[i+3];

        // do something with them here
    }
}

int main(int argc, char *argv[])
{
    const unsigned int len = 5*4;
    unsigned char *rgba_buffer = new unsigned char[len]();

    process_rgba(rgba_buffer, len);

    return 0;
}
