#include <limits.h>
#include "gtest/gtest.h"
#include "ch02/prob/bubble_sorter.h"


using namespace std;

class TestBubbleSorter : public ::testing::Test {
 protected:
  virtual void SetUp() {
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test
    // (right before the destructor).
  }
};

TEST_F(TestBubbleSorter, sortNumbers){
    vector<int> A = {3, 2, 6, 4, 5, 1};
    BubbleSorter::sort(A);
    vector<int> sorted_A = {1, 2, 3, 4, 5, 6};
    EXPECT_EQ(A, sorted_A);
}

TEST_F(TestBubbleSorter, whenListIsEmpty){
    vector<int> A;
    BubbleSorter::sort(A);
    EXPECT_EQ(A.size(), 0);
}

TEST_F(TestBubbleSorter, whenListHasNegativeNumbers){
    vector<int> A = {3, 2, -6, 4, 5, -1};
    BubbleSorter::sort(A);
    vector<int> sorted_A = {-6, -1, 2, 3, 4, 5};
    EXPECT_EQ(A, sorted_A);
}

TEST_F(TestBubbleSorter, listContainsMinMaxBoundaries){
    vector<int> A = {3, 2, INT_MAX, 4, 5, INT_MIN};
    BubbleSorter::sort(A);
    vector<int> sorted_A = {INT_MIN, 2, 3, 4, 5, INT_MAX};
    EXPECT_EQ(A, sorted_A);
}

