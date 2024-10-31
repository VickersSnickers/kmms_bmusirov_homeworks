#include "random_array.hpp"

#include <random>
#include <time.h>

void mbr::rand_array(int* arr, int size, double max) {
    std::mt19937 mt(time(nullptr));
    for (int i = 0; i < size; ++i) {
        arr[i] = (mt() % (int) max);
    } 
}