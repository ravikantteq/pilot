#include "gtest/gtest.h"
#include "ch06/sec4/heap_sorter.h"

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

TEST_F(TestArrayHeap, heapSorterAvgCase) {
    vector<int> arr = {19, 7, 6, 13, 41, 5};
    HeapSorter::sort(arr);
    EXPECT_EQ(arr, vector<int>({5, 6, 7, 13, 19, 41}));
}

TEST_F(TestArrayHeap, heapSorterAlreadySorted) {
    vector<int> arr = {5, 6, 7, 13, 19, 41};
    HeapSorter::sort(arr);
    EXPECT_EQ(arr, vector<int>({5, 6, 7, 13, 19, 41}));
}

TEST_F(TestArrayHeap, heapSorterBoundaryCase) {
    vector<int> arr = {5};
    HeapSorter::sort(arr);
    EXPECT_EQ(arr, vector<int>({5}));
}
