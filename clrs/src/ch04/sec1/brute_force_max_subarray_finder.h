#ifndef __BRUTE_FORCE_MAX_SUBARRAY_FINDER_H__
#define __BRUTE_FORCE_MAX_SUBARRAY_FINDER_H__

#include <vector>

typedef struct {
    int start;
    int end;
    int sum;
}SubArray;

class BruteForceMaxSubArrayFinder {
    public:
        static SubArray find(std::vector<int> arr);
};

#endif

