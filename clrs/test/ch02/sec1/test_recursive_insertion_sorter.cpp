#include "gtest/gtest.h"
#include "ch02/sec1/recursive_insertion_sorter.h"

using namespace std;

class TestRecursiveInsertionSorter : public ::testing::Test {
 protected:
  virtual void SetUp() {
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test
    // (right before the destructor).
  }
};

TEST_F(TestRecursiveInsertionSorter, sortNumbers){
    vector<int> A = {3, 2, 6, 4, 5, 1};
    RecursiveInsertionSorter::sort(A);
    vector<int> sorted_A = {1, 2, 3, 4, 5, 6};
    EXPECT_EQ(A, sorted_A);
}

TEST_F(TestRecursiveInsertionSorter, sortAlreadySortedNumbers){
    vector<int> A = {1, 2, 10, 15, 17};
    RecursiveInsertionSorter::sort(A);
    vector<int> sorted_A = {1, 2, 10, 15, 17};
    EXPECT_EQ(A, sorted_A);
}
