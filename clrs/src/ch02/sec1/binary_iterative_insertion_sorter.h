#ifndef __BINARY_ITERATIVE_INSERTION_SORTER_H__
#define __BINARY_ITERATIVE_INSERTION_SORTER_H__

#include <vector>

class BinaryIterativeInsertionSorter {
    public:
        static void sort(std::vector<int>& A);
        static int find_placement(std::vector<int>& A, int start, int end, int element);
};

#endif
