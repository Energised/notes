/*
 * int_vector.h
 * @author Dan Woolsey
 *
 * Header file for resizable int vector example from Lecture 3
 */

#ifndef __INT_VECTOR__
#define __INT_VECTOR__

struct intvector
{
    int *data;
    unsigned int length;
};

void intvector_constructor(struct intvector *obj, const unsigned int length);

void intvector_destructor(struct intvector *obj);

void intvector_resize(struct intvector *obj, const unsigned int length);

void intvector_push_back(struct intvector *obj, const int value);

void intvector_pop_back(struct intvector *obj);

void intvector_print(struct intvector *obj);

#endif
