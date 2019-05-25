/*
 * struts_1.c
 * @author Dan Woolsey
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MyStruct
{
    int a;
    int b;
};
// sizeof(struct MyStruct) is 8 bytes

int main()
{
    struct MyStruct *ptr = (struct MyStruct*) malloc(3*sizeof(struct MyStruct));
    // ptr points to 24 bytes of memory

    for(int i=0; i<3; i++)
    {
        // ptr[i] is an instance of MyStruct
        ptr[i].a = i;
        ptr[i].b = i*2;
    }

    free(ptr);
    ptr = NULL;

    return 0;
}
