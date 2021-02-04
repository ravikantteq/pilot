#ifndef __ARRAY_HEAP_H__
#define __ARRAY_HEAP_H__

#include <vector>

typedef enum HEAP_TYPE {
    MAX_HEAP = 0,
    MIN_HEAP = 1,
} HEAP_TYPE;

class ArrayHeap {
    private:
        std::vector<int> arr;
        int heap_size;
        HEAP_TYPE heap_type;
        int PARENT(int i);
        int LEFT(int i);
        int RIGHT(int i);
        int get(int index);
        bool heap_condition(int a, int b);
        void heapify(int i);
        void build_heap();
        void update_key(int index, int new_key);
    public:
        ArrayHeap(HEAP_TYPE heap_type) {
            this->heap_type = heap_type;
            heap_size = 0;
        }
        int size(); 
        void add(int element);
        int top();
        int pop();
};

#endif
