#include "gtest/gtest.h"
#include "ch02/sec2/selection_sorter.h"

using namespace std;

class TestSelectionSorter : public ::testing::Test {
 protected:
  virtual void SetUp() {
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test
    // (right before the destructor).
  }
};

TEST_F(TestSelectionSorter, sortNumbers){
    vector<int> A = {3, 2, 6, 4, 5, 1};
    SelectionSorter::sort(A);
    vector<int> sorted_A = {1, 2, 3, 4, 5, 6};
    EXPECT_EQ(A, sorted_A);
}

TEST_F(TestSelectionSorter, sortAlreadySortedNumbers){
    vector<int> A = {1, 2, 3, 4, 5, 6};
    SelectionSorter::sort(A);
    vector<int> sorted_A = {1, 2, 3, 4, 5, 6};
    EXPECT_EQ(A, sorted_A);
}

TEST_F(TestSelectionSorter, sortSingleElementArray){
    vector<int> A = {1};
    SelectionSorter::sort(A);
    vector<int> sorted_A = {1};
    EXPECT_EQ(A, sorted_A);
}
