#include <iostream>
#include <vector>
#include "recursive_insertion_sorter.h"

using namespace std;

void RecursiveInsertionSorter::sort(vector<int>& A) {
    sort(A, A.size());
}

void RecursiveInsertionSorter::sort(vector<int>& A, int size) {
    if (size == 1) {
        return;
    }
    int j = size - 1;
    int element = A[j];
    sort(A, j);

    // find correct placement for element
    int i = j-1;
    while (i >= 0 && element < A[i]) {
        A[i+1] = A[i];
        i--;
    }

    A[i+1] = element;
}

