#include "gtest/gtest.h"
#include "ch02/sec1/binary_iterative_insertion_sorter.h"

using namespace std;

class TestBinaryIterativeInsertionSorter : public ::testing::Test {
 protected:
  virtual void SetUp() {
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test
    // (right before the destructor).
  }
};

TEST_F(TestBinaryIterativeInsertionSorter, findPlacement){
    vector<int> A = {1, 2, 3, 4, 5, 6};
    // find placement for 0;
    int placement = BinaryIterativeInsertionSorter::find_placement(A, 0, A.size()-1, 0);
    EXPECT_EQ(placement, 0);

    // find placement for 10;
    placement = BinaryIterativeInsertionSorter::find_placement(A, 0, A.size()-1, 10);
    EXPECT_EQ(placement, 6);

    // find placement for 4;
    placement = BinaryIterativeInsertionSorter::find_placement(A, 0, A.size()-1, 4);
    EXPECT_EQ(placement, 4);
}

TEST_F(TestBinaryIterativeInsertionSorter, sortNumbers){
    vector<int> A = {3, 2, 6, 4, 5, 1};
    BinaryIterativeInsertionSorter::sort(A);
    vector<int> sorted_A = {1, 2, 3, 4, 5, 6};
    EXPECT_EQ(A, sorted_A);
}
