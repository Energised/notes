/*
 * lambda_2.cpp
 * @author Dan Woolsey
 *
 * Lambda with captured value example
 */

#include <iostream>

int width = 10; height = 8;
float *image = new float[width * height]

auto mapping = [width](int x, int y) -> int // make copy of width for mapping at declaration; width=10
{
    return x + (y * width)
};

// to copy all values the lambda uses we can declare it with an '='
// makes copying multiple variables less verbose in the lambda declaration

auto mapping_2 = [=](int x, int y) -> int
{
    return x + (y * width);
};

int main(int argc; char *argv)
{
    for(int y=0; y<height; ++y)
    {
        for(int x=0; x<width; ++x)
        {
            image[mapping(x,y)] = compute_colour(x,y);
        }
    }

    save_image(image, width, height);
    delete [] image

    return 0;
}
