//#include "io.hpp"
//#include "random_array.hpp"
//#include "merge_sort.hpp"

#include <iostream>
#include <random>
#include <time.h>

namespace mbr {
    namespace sortings {
        void Merge(int A[], int p, int q, int r);
        void Merge_Sort(int A[], int p, int r);
    }

    void print_array(int arr[], int size);
    void rand_array(int* arr, int size, double max);
}

int main() {
    int size = 10;
    int* arr = new int[size];
    mbr::rand_array(arr, size, 1000);
    mbr::print_array(arr, size);
    
    mbr::sortings::Merge_Sort(arr, 0, size-1);
    mbr::print_array(arr, size);

    delete [] arr;
}

void mbr::sortings::Merge(int A[], int p, int q, int r){
    int n1 = q - p + 1;
    int L[n1] = {};
    for (int i = 0; i < n1; ++i){
        L[i] = A[p + i];
    }
    int n2 = r - q;
    int R[n2] = {};
    for (int i = 0; i < n2; ++i){
        R[i] = A[q + i + 1];
    }
    int i = 0, j = 0, k = p;

    while (i < n1 && j < n2){
        if (L[i] < R[j]) {
            A[k] = L[i];
            ++i;
        } else {
            A[k] = R[j];
            ++j;
        }
        ++k;
    }
    while (i < n1){
        A[k] = L[i];
        ++i;
        ++k;
    }
    while (j < n2){
        A[k] = R[j];
        ++j;
        ++k;
    }
    
}

void mbr::sortings::Merge_Sort(int A[], int p, int r){
    if (p < r) {
        int q = (p + r)/2;
        mbr::sortings::Merge_Sort(A, p, q);
        mbr::sortings::Merge_Sort(A, q+1, r);
        mbr::sortings::Merge(A, p, q, r);
    }
}

void mbr::print_array(int arr[], int size){
    for (int i = 0; i < size; ++i){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void mbr::rand_array(int* arr, int size, double max) {
    std::mt19937 mt(time(nullptr));
    for (int i = 0; i < size; ++i) {
        arr[i] = (mt() % (int) max);
    } 
}