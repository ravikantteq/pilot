#ifndef __LINEAR_MAX_SUBARRAY_FINDER_H__
#define __LINEAR_MAX_SUBARRAY_FINDER_H__

#include <vector>

typedef struct {
    int start;
    int end;
    int sum;
}SubArray;

class LinearMaxSubArrayFinder {
    public:
        static SubArray find(std::vector<int> arr);
};

#endif

