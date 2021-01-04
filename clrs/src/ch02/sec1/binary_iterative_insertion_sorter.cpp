#include <iostream>
#include <vector>
#include "binary_iterative_insertion_sorter.h"

using namespace std;

void BinaryIterativeInsertionSorter::sort(vector<int>& A) {
    for (int j = 1; j < A.size(); j++) {
        int key = A[j];
        int placement = BinaryIterativeInsertionSorter::find_placement(A, 0, j-1, key);
        for (int i = j-1; i >= placement; i--) {
            A[i+1] = A[i];
        }
        A[placement] = key;
    }
}

int BinaryIterativeInsertionSorter::find_placement(vector<int>& A, int start, int end, int element) {
    int placement = end+1;
    while (start <= end) {
        int mid = start + (end - start)/2;
        if (A[mid] <= element) {
            placement = mid + 1;
            start = mid + 1;
        } else {
            placement = mid;
            end = mid - 1;
        }
    }
    return placement;
}
