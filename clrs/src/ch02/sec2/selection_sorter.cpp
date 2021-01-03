#include "selection_sorter.h"

using namespace std;

void SelectionSorter::sort(vector<int>& A) {
    for (int i = 0; i < A.size() - 1; i++) {
        int smallest = A[i]; int index = i;
        for (int j = i+1; j < A.size(); j++) {
            if (A[j] < smallest) {
                smallest = A[j];
                index = j;
            }
        }
        if (smallest != A[i]) {
            A[index] = A[i]; 
            A[i] = smallest;
        }
    }
}
