#include "sum_finder.h"
#include "merge_sorter.h"

using namespace std;

vector<int> SumFinder::two_sum_finder(vector<int>& A, int sum) {
    vector<int> B = A;
    MergeSorter::sort(B);
    
    // modify binary search concept
    int start = 0;
    int end = B.size()-1;
    while (start < end) {
        if (A[start] + A[end] == sum) {
            return {A[start], A[end]}; 
        } else if (A[start] + A[end] > sum) {
            end = end - 1;
        } else {
            start = start + 1;
        }
    }
    return {};
}
