#include "brute_force_max_subarray_finder.h"
#include <limits.h>

using namespace std;

SubArray BruteForceMaxSubArrayFinder::find(vector<int> arr) {
    int max_sum = 0;
    SubArray res = {0, 0, INT_MIN};
    for (int i = 0; i < arr.size(); i++) {
        int max_sum_iteration = arr[i];
        int sum_level = arr[i];
        int end = i;
        for (int j = i+1; j < arr.size(); j++) {
            sum_level += arr[j];
            if (max_sum_iteration < sum_level) {
                max_sum_iteration = sum_level;
                end = j;
            }
        }
        if (max_sum_iteration > res.sum) {
            res = {.start = i, .end = end, .sum = max_sum_iteration};
        }
    }
    return res;
}
