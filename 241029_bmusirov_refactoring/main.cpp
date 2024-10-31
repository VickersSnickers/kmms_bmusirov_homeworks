#include "io.hpp"
#include "random_array.hpp"
#include "merge_sort.hpp"


int main() {
    int size = 10;
    int* arr = new int[size];
    mbr::rand_array(arr, size, 1000);
    mbr::print_array(arr, size);
    
    mbr::sortings::Merge_Sort(arr, 0, size-1);
    mbr::print_array(arr, size);

    delete [] arr;
}