/*
 * func_5.cpp
 * @author Dan Woolsey
 *
 * Passing functor to function example
 */

#include <iostream>

template<typename T, typename F>
void insertion_sort(T arr[], int n, F compare)
{
    int i,j;
    T key;
    for(int i=1; i<n; i++)
    {
        key = arr[i];
        j = i-1;
        while(j>=0 && compare(key, arr[j])) // will fail on this line if functor has wrong types
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

struct MyStruct
{
    int value;
};

struct MyStruct_ASC
{
    inline bool operator()(const MyStruct &x, const MyStruct &y) const
    {
        return x.value < y.value;
    }
};

struct MyStruct_DESC
{
    inline bool operator()(const MyStruct &x, const MyStruct &y) const
    {
        return x.value > y.value;
    }
};

int main(int argc, char *argv[])
{
    int n = 10;
    MyStruct *arr = new MyStruct[n];

    for(int i=0; i<n; ++i)
    {
        arr[i].value = rand() % 100;
    }

    MyStruct_ASC cmp_asc;
    insertion_sort(arr, n, cmp_asc);

    std::cout << "Insertion Sort - Ascending" << std::endl;
    for(int i=0; i<n; ++i)
    {
        std::cout << arr[i].value << std::endl;
    }

    insertion_sort(arr, n, MyStruct_DESC());

    std::cout << std::endl << "Insertion Sort - Descending" << std::endl;
    for(int i=0; i<n; ++i)
    {
        std::cout << arr[i].value << std::endl;
    }

    return 0;
}
