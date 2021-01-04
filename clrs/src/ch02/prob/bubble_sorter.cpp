#include "bubble_sorter.h"

using namespace std;

void BubbleSorter::sort(vector<int>& A) {
    if (A.size() == 0) return;
    for (int i = 0; i < A.size()-1; i++) {
        int idx = i; int smallest = A[i];
        for (int j = i+1; j < A.size(); j++) {
            if (A[j] < A[idx]) {
                idx = j;
                smallest = A[j];
            }
        }
        A[idx] = A[i];
        A[i] = smallest;
    }
}
