#include "linear_finder.h"

using namespace std;

int LinearFinder::search(vector<int>& A, int element) {
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == element) return i;
    }
    return -1;
}
