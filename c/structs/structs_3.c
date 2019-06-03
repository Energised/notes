/*
 * structs_3.c
 * @author Dan Woolsey
 *
 * CURRENTLY A NUMBER OF ISSUES WITH THIS FILE
 * EITHER BLAME THE COMPILER OR THE LECTURER, WHATEVERS EASIEST
 */

#include <stdio.h>
#include <stdlib.h>

// building an array of structures

struct Vec3f
{
    float x, y, z;
};
// sizeof(Vec3f) is 12 bytes

struct Vec3f *buffer_a = (struct Vec3f*) malloc(10 * sizeof(struct Vec3f));
// buffer_a is 12*10 == 120 bytes
// data is interleaved: x,y,z,x,y,z,...

for(int i=0; i<9; i++)
{
    buffer_a[i]->x = i;
    buffer_a[i]->y = i*2;
    buffer_a[i]->z = i*3;
}

// building a structure of arrays

struct Vec3f_buffer
{
    float *x, *y, *z;
};

struct Vec3f_buffer buffer_b;

buffer_b.x = (float*) malloc(10 * sizeof(float));
buffer_b.y = (float*) malloc(10 * sizeof(float));
buffer_b.z = (float*) malloc(10 * sizeof(float));
// buffer_b is 12/24 bytes containing pointers to 3 disjoint memory regions
// each x,y,z is a 10*4 == 40 byte region
