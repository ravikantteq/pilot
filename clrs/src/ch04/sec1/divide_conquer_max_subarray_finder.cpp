#include <limits.h>
#include <iostream>
#include "divide_conquer_max_subarray_finder.h"

using namespace std;

SubArray DivideConquerMaxSubArrayFinder::find(vector<int> arr) {
    return DivideConquerMaxSubArrayFinder::divide_conquer_find(arr, 0, arr.size()-1);
}

SubArray DivideConquerMaxSubArrayFinder::divide_conquer_find(vector<int> arr, int low, int high) {
    SubArray res = {.start = 0, .end = 0, .sum = 0};
    if (low == high) {
        res = {.start = low, .end = high, .sum = arr[low]};
    } else if (low < high) {
        int mid = low + (high - low)/2;
        SubArray left_subarr = DivideConquerMaxSubArrayFinder::divide_conquer_find(arr, low, mid);
        SubArray right_subarr = DivideConquerMaxSubArrayFinder::divide_conquer_find(arr, mid+1, high);
        SubArray cross_subarr = DivideConquerMaxSubArrayFinder::find_max_crossing_subarray(arr, low, mid, high);
        if (left_subarr.sum >= right_subarr.sum && left_subarr.sum >= cross_subarr.sum){
            res = left_subarr;
            cout << "a" << res.sum;
        } else if(right_subarr.sum >= right_subarr.sum && right_subarr.sum >= cross_subarr.sum) {
            res = right_subarr;
            cout <<  "b" << res.sum;
        } else {
            res = cross_subarr;
            cout << "c" << res.sum;
        }
    }
    return res;
}

SubArray DivideConquerMaxSubArrayFinder::find_max_crossing_subarray(vector<int> arr, int low, int mid, int high) {
    int max_left = mid, left_sum = INT_MIN, sum = 0;
    for (int i = mid; i >= low; i--) {
        sum = sum + arr[i];
        if (sum >= left_sum)  {
            left_sum = sum;
            max_left = i;
        }
    }
    int max_right = mid+1, right_sum = INT_MIN;
    sum = 0;
    for (int i = mid+1; i <= high; i++) {
        sum = sum + arr[i];
        if (sum >= right_sum) {
            right_sum = sum;
            max_right = i;
        }
    }
    SubArray res = {.start = max_left, .end = max_right, .sum = left_sum + right_sum};
    return res;
}
