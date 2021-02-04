#include "heap_sorter.h"
#include "../sec1/array_heap.h"

using namespace std;

void HeapSorter::sort(vector<int>& arr) {
    ArrayHeap heap(MIN_HEAP);
    for (auto num: arr) {
        heap.add(num);
    }
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = heap.pop();
    }
}
