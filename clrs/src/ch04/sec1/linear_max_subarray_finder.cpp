#include <limits.h>
#include "linear_max_subarray_finder.h"

using namespace std;

SubArray LinearMaxSubArrayFinder::find(vector<int> arr) {
    if (arr.size() == 0) return {0};
    int max_sum = INT_MIN;
    int start = 0;
    int end = 0;
    int current_sum = 0;
    int current_start = 0;

    for (int i = 0; i < arr.size(); i++) {
        current_sum += arr[i];
        if (current_sum > max_sum) {
            max_sum = current_sum;
            start = current_start;
            end = i;
        }
        if (current_sum < 0) {
            current_sum = 0;
            current_start = i+1;
        }
    }
    return {.start = start, .end = end, .sum = max_sum};
}
