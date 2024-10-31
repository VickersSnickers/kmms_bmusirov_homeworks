#include "merge_sort.hpp"
#include "merge.hpp"

void mbr::sortings::Merge_Sort(int A[], int p, int r){
    if (p < r) {
        int q = (p + r)/2;
        mbr::sortings::Merge_Sort(A, p, q);
        mbr::sortings::Merge_Sort(A, q+1, r);
        mbr::Merge(A, p, q, r);
    }
}