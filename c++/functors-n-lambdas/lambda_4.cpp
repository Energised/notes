/*
 * lambda_4.cpp
 * @author Dan Woolsey
 *
 * Passing lambda to function example
 */

#include <iostream>
#include <functional>

template<typename T>
// compiler has more type information about valid lambdas for this function
void insertion_sort(T arr[], int n, std::function<bool(const T&, const T&)> compare)
{
    int i,j;
    T key;
    for(i=1; i<n; i++)
    {
        key = arr[i];
        j = i-1;
        while(j >= 0 && compare(key, arr[j]))
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

// main code

int n = 10;
MyStruct *arr = new MyStruct[n];

for(int z=0; z<n; z++)
{
    arr[z].value = rand() % 100;
}

auto cmp_asc = [](const MyStruct &x, const MyStruct &y) -> bool
{
    return x.value < y.value;
};
insertion_sort(arr, n, cmp_asc); // fails here if types are wrong - better than func_5

for(int z=0; z<n; z++)
{
    std::cout << arr[z].value << std::endl;
}

// and fails here too
insertion_sort(arr, n, [](const MyStruct &x, const MyStruct &y) -> bool
{
    //compare DESC
    return x.value > y.value;
});

for(int z=0; z<n; z++)
{
    std::cout << arr[z].value << std::endl;
}
