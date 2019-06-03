/*
 * int_vector.c
 * @author Dan Woolsey
 *
 * Implementation of resizable int vector structure functions
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "int_vector.h"

void intvector_print(struct intvector *obj)
{
    printf("[");
    for(int i=0; i<obj->length; i++)
    {
        printf(" %d", obj->data[i]); // encapsulate reusable behaviour
    }
    printf(" ]");
}

void intvector_constructor(struct intvector *obj, const unsigned int length)
{
    obj->data = NULL;
    obj->length = 0;
    intvector_resize(obj, length);
}

// example of reusing common functionality
void intvector_resize(struct intvector *obj, const unsigned int new_length)
{
    if(new_length > 0)
    {
        if(obj->length > 0)
        {
            obj->data = (int*) realloc(obj->data, new_length * sizeof(int));
        }
        else
        {
            obj->data = (int*) malloc(new_length * sizeof(int));
        }
    }
    else
    {
        intvector_destructor(obj);
    }
    obj->length = new_length;
}

// there is an assumption: if you are passed a pointer it is safe to use
void intvector_destructor(struct intvector *obj)
{
    if(obj->data != NULL) // always test if pointers are safe to free
    {
        free(obj->data);
        obj->data = NULL;
    }
    obj->length = 0;
}

void intvector_push_back(struct intvector *obj, const int value)
{
    intvector_resize(obj, obj->length + 1);
    obj->data[obj->length - 1] = value;
}

void intvector_pop_back(struct intvector *obj)
{
    intvector_resize(obj, obj->length - 1);
}

int main()
{
    struct intvector x;
    intvector_constructor(&x, 5);

    for(int i=0; i<5; i++)
    {
        x.data[i] = i*2;
    }

    printf("x = ");
    intvector_print(&x);
    printf("\n");

    intvector_push_back(&x, 42);

    printf("x = ");
    intvector_print(&x);
    printf("\n");

    intvector_pop_back(&x);

    printf("x = ");
    intvector_print(&x);
    printf("\n");

    intvector_resize(&x, 3);

    printf("x = ");
    intvector_print(&x);
    printf("\n");

    intvector_resize(&x, 10);

    printf("x = ");
    intvector_print(&x);
    printf("\n");

    intvector_destructor(&x);

    return 0;
}
