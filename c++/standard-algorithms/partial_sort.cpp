/*
 * partial_sort.cpp
 * @author Dan Woolsey
 *
 * partial sort (and nth select) sorting operations example
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[])
{
    std::vector<int> vec = {6, 3, -2, -4, 1, 9};

    // pivot location set
    auto pivot = vec.begin() + 3;
    // pivot value in a sorted list would be 1

    // values are partitioned either side of the pivot
    std::nth_element(vec.begin(), pivot, vec.end());
    // vec = {-2, -4, 1, 6, 3, 9}

    // first partition is sorted too
    std::partial_sort(vec.begin(), pivot, vec.end());
    // vec = {-4, -2, 1, 6, 3, 9}

    // fully sorted list
    std::sort(vec.begin(), vec.end());
    // vec = {-4, -2, 1, 3, 6, 9}

    return 0;
}
