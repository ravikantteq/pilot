#ifndef __DIVIDE_CONQUER_MAX_SUBARRAY_FINDER_H__
#define __DIVIDE_CONQUER_MAX_SUBARRAY_FINDER_H__ 

#include <vector>

typedef struct {
    int start;
    int end;
    int sum;
}SubArray;

class DivideConquerMaxSubArrayFinder {
    private:
        static SubArray divide_conquer_find(std::vector<int> arr, int low, int high);
        static SubArray find_max_crossing_subarray(std::vector<int> arr, int low, int mid, int high);
    public:
        static SubArray find(std::vector<int> arr);
};

#endif

