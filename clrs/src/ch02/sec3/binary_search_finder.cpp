#include "binary_search_finder.h"

using namespace std;

int BinarySearchFinder::search(vector<int>& A, int element) {
    int low = 0;
    int high = A.size()-1;
    while (low <= high) {
        int mid = low + (high - low)/2;
        if (A[mid] == element) {
            return mid;
        } else if (A[mid] > element) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}
