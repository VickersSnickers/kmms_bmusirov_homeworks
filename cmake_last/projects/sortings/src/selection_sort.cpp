#include "selection_sort.hpp"

void selection_sort(std::vector<int>& A, int size){
    for (int i = 0; i < size - 1; ++i){
        for (int j = i + 1; j < size; ++j){
            if (A[i] > A[j]){
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
}