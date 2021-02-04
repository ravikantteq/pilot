#include "gtest/gtest.h"
#include "ch06/sec1/array_heap.h"

using namespace std;

class TestArrayHeap: public ::testing::Test {
 protected:
  virtual void SetUp() {
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test
    // (right before the destructor).
  }
};

TEST_F(TestArrayHeap, createHeapObject) {
    ArrayHeap heap(MAX_HEAP);
    EXPECT_EQ(heap.size(), 0);
}

TEST_F(TestArrayHeap, addValueToHeap) {
    ArrayHeap heap(MAX_HEAP);
    heap.add(5);
    heap.add(6);
    heap.add(19);
    EXPECT_EQ(heap.size(), 3);
}

TEST_F(TestArrayHeap, getTopValue) {
    ArrayHeap heap(MAX_HEAP);
    heap.add(5);
    heap.add(6);
    heap.add(19);
    EXPECT_EQ(heap.size(), 3);
    EXPECT_EQ(heap.top(), 19);
    EXPECT_EQ(heap.size(), 3);
}

TEST_F(TestArrayHeap, popFromHeap) {
    ArrayHeap heap(MAX_HEAP);
    heap.add(5);
    heap.add(6);
    heap.add(19);
    EXPECT_EQ(heap.size(), 3);
    EXPECT_EQ(heap.pop(), 19);
    EXPECT_EQ(heap.pop(), 6);
    EXPECT_EQ(heap.pop(), 5);
    EXPECT_EQ(heap.size(), 0);
}

TEST_F(TestArrayHeap, addBulkValuesToHeap) {
    int arr[] = {19, 14, 25, 7, 36, 38, 42};
    ArrayHeap heap(MAX_HEAP);
    for(auto num: arr) {
        heap.add(num);
    }
    EXPECT_EQ(heap.size(), sizeof(arr)/sizeof(int));
    EXPECT_EQ(heap.pop(), 42);
    EXPECT_EQ(heap.pop(), 38);
    EXPECT_EQ(heap.pop(), 36);
}

TEST_F(TestArrayHeap, testMaxHeapProperty) {
    ArrayHeap heap(MAX_HEAP);
    heap.add(6);
    heap.add(5);
    heap.add(19);
    EXPECT_EQ(heap.size(), 3);
    EXPECT_EQ(heap.pop(), 19);
    EXPECT_EQ(heap.top(), 6);
}
