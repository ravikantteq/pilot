#ifndef __MERGE_SORTER_H__
#define __MERGE_SORTER_H__

#include<vector>

class MergeSorter {
    public: 
        static void sort(std::vector<int>& A);
        static void merge_sort(std::vector<int>& A, int low, int high);
        static void merge(std::vector<int>& A, int p, int q, int r);
};

#endif
