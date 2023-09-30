#include "merge_sorter.h"

using namespace std;

void MergeSorter::sort(vector<int>& A) {
    merge_sort(A, 0, A.size()-1);
}

void MergeSorter::merge_sort(vector<int>& A, int low, int high) {
    if (low < high) {
        int mid = low + (high - low)/2;
        merge_sort(A, low, mid);
        merge_sort(A, mid+1, high);
        merge(A, low, mid, high);
    }
}

void MergeSorter::merge(vector<int>& A, int p, int q, int r) {
    vector<int> sortedItems;
    int i = p, j = q+1;
    while(i <= q && j <= r) {
        if (A[i] <= A[j]) {
            sortedItems.push_back(A[i]); i++;
        } else {
            sortedItems.push_back(A[j]); j++;
        }
    }
    while (i <= q) { sortedItems.push_back(A[i]); i++;} 
    while (j <= r) { sortedItems.push_back(A[j]); j++;}
    for (int i = p; i <= r; i++) {
        A[i] = sortedItems[i-p];
    }
}
