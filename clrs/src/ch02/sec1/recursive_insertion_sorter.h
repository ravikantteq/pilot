#ifndef __RECURSIVE_INSERTION_SORTER_H__
#define __RECURSIVE_INSERTION_SORTER_H__

#include <vector>

class RecursiveInsertionSorter {
    public:
        static void sort(std::vector<int>& A);
    private:
        static void sort(std::vector<int>& A, int size);
};

#endif
