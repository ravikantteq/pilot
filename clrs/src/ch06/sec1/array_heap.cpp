#include "array_heap.h"

using namespace std;

int ArrayHeap::size() {
    return heap_size;
}

int ArrayHeap::PARENT(int i) {
    if (i <= 0) return -1;
    return (i-1)/2;
}

int ArrayHeap::LEFT(int i) {
    return 2*i+1;
}

int ArrayHeap::RIGHT(int i) {
    return 2*(i+1);
}

bool ArrayHeap::heap_condition(int a, int b) {
    if (heap_type == MAX_HEAP) {
        return a < b;
    } else {
        return a > b;
    }
}

void ArrayHeap::heapify(int i) {
    int idx_to_heapify = i;
    int left = LEFT(i);
    int right = RIGHT(i);

    if (left < size() && heap_condition(arr[idx_to_heapify], arr[left])) {
        idx_to_heapify = left;
    }
    if (right < size() && heap_condition(arr[idx_to_heapify], arr[right])) {
        idx_to_heapify = right;
    }

    if (idx_to_heapify != i) {
        swap(arr[i], arr[idx_to_heapify]);
        heapify(idx_to_heapify);
    }
}

void ArrayHeap::update_key(int index, int new_key) {
    if (index >= heap_size) {
        throw "out of bounds error";
    }
    for (int i = index; i > 0;) {
        int parent = PARENT(i);
        if (heap_condition(arr[parent], arr[i])) {
            swap(arr[i], arr[parent]);
        } else {
            break;
        }
        i = parent;
    }
}

int ArrayHeap::get(int index) {
    if (index < 0 || index >= heap_size) {
        throw "Out of range error"; 
    }
    return arr[index];
}

void ArrayHeap::build_heap() {
    int length = arr.size();
    heap_size = arr.size();
    for (int i = (length-1)/2; i >= 0; i--) {
        heapify(i);
    }
} 

int ArrayHeap::top() {
    if (size() == 0) {
        return -1;
    }
    return arr[0];
}

void ArrayHeap::add(int element) {
    arr.push_back(element);
    heap_size += 1;
    update_key(heap_size-1, element);
}

int ArrayHeap::pop() {
    if (size() == 0) return -1;
    int element = top();
    arr[0] = arr[heap_size-1];
    heap_size -= 1;
    heapify(0);
    return element;
}
