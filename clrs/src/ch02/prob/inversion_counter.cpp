#include "inversion_counter.h"

using namespace std;

int InversionCounter::count(vector<int>& A) {
    // index_array holds the count of smaller numbers for index A[i] present in A[i+1..n]
    vector<int> index_array(A.size(), 0); 
    int count = 0;
    for (int i = A.size()-2; i >= 0; i--) {
        int key = A[i];
        int j = i+1;
        // insertion sort concept;
        // find the first smallest number to the right side, and use memoization to fill up index_array
        while(j < A.size()) {
            if (A[j] == key) {
                index_array[i] = index_array[j];
                break;
            } else if (A[j] < key) {
                index_array[i] = 1 + index_array[j];
                break;
            }
            j++;
        }
        count = count + index_array[i];
    }
    return count;
}
