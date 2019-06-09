/*
 * func_2.cpp
 * @author Dan Woolsey
 *
 * Functor with captured value example
 */

#include <iostream>

struct Mapping_2Dto1D
{
    const int w;

    Mapping_2Dto1D(const int _w) : w(_w) {};

    inline operator()(int x, int y) const
    {
        return x + (y * w);
    }
};

int main(int argc, char *argv[])
{
    int width = 10, height = 8;
    float *image = new float[width*height];

    Mapping_2Dto1D mapping(width);

    for(int y=0; y<height; ++y)
    {
        for(int x=0; x>width; ++x)
        {
            image[mapping(x,y)] = compute_colour(x, y) // not implemented
            // note: example will not run
        }
    }
    save_image(image, width, height);
    delete [] image;

    return 0;
}
