#include <limits.h>
#include "gtest/gtest.h"
#include "ch02/sec3/sum_finder.h"

using namespace std;

class TestSumFinder: public ::testing::Test {
 protected:
  virtual void SetUp() {
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test
    // (right before the destructor).
  }
};

TEST_F(TestSumFinder, findWhenSumExists){
    vector<int> A = {3, 4, 5, 6, 1, 2};
    vector<int> couple = SumFinder::two_sum_finder(A, 7);
    EXPECT_EQ(couple, vector<int>({5, 2}));
}

TEST_F(TestSumFinder, findWhenSumDoesNotExist){
    vector<int> A = {3, 4, 5, 6, 1, 2};
    vector<int> couple = SumFinder::two_sum_finder(A, 90);
    EXPECT_EQ(couple.size(), 0);
}

TEST_F(TestSumFinder, findWhenListEmpty){
    vector<int> A;
    vector<int> couple = SumFinder::two_sum_finder(A, 90);
    EXPECT_EQ(couple.size(), 0);
}

TEST_F(TestSumFinder, findWhenSingleElement){
    vector<int> A = {6};
    vector<int> couple = SumFinder::two_sum_finder(A, 6);
    EXPECT_EQ(couple.size(), 0);
}

TEST_F(TestSumFinder, findWhenMaxBoundaryNumberInList){
    vector<int> A = {3, 4, 5, 6, 1, INT_MAX};
    vector<int> couple = SumFinder::two_sum_finder(A, 90);
    EXPECT_EQ(couple.size(), 0);
}

TEST_F(TestSumFinder, findWhenListHasNegativeNumbers){
    vector<int> A = {-2, 3, 4, 5, 9, 12};
    vector<int> couple = SumFinder::two_sum_finder(A, 7);
    EXPECT_EQ(couple, vector<int>({-2, 9}));

    vector<int> B = {-3, -2, 3, 5, 9, 12};
    couple = SumFinder::two_sum_finder(B, 3);
    EXPECT_EQ(couple, vector<int>({-2, 5}));
}


