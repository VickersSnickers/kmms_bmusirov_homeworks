#include "merge_sort.hpp"

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
