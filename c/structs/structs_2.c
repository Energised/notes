/*
 * structs_2.c
 * @author Dan Woolsey
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MyStruct
{
    char a[10];
    int b;
};
// sizeof(MyStruct) is 16 bytes (14 byte payload, 2 byte padding)

int main()
{
    struct MyStruct *ptr = (struct MyStruct*) malloc(sizeof(struct MyStruct));
    // ptr points to 16 bytes of memory

    (*ptr).b = 5; // this works, but can be made easier
    ptr->b = 5; // arrow works as dereferencer and dot operator

    for(int i=0; i<9; i++)
    {
        ptr->a[i] = 'z';
    }

    ptr->a[9] = '\0';

    return 0;
}
