#include "gtest/gtest.h"
#include "ch04/sec1/brute_force_max_subarray_finder.h"

using namespace std;

class TestBruteForceMaxSubArrayFinder : public ::testing::Test {
 protected:
  virtual void SetUp() {
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test
    // (right before the destructor).
  }
};

TEST_F(TestBruteForceMaxSubArrayFinder, findMaxSubArrayPresentInMiddle){
    vector<int> A = {-3,-1,4,5,6,-2,-17};
    SubArray res = BruteForceMaxSubArrayFinder::find(A);
    EXPECT_EQ(res.start, 2);
    EXPECT_EQ(res.end, 4);
    EXPECT_EQ(res.sum, 15);
}

TEST_F(TestBruteForceMaxSubArrayFinder, findMaxSubArrayPresentInFirstElement){
    vector<int> A = {16,-18,4,5,6,-2, -17};
    SubArray res = BruteForceMaxSubArrayFinder::find(A);
    EXPECT_EQ(res.start, 0);
    EXPECT_EQ(res.end, 0);
    EXPECT_EQ(res.sum, 16);
}

TEST_F(TestBruteForceMaxSubArrayFinder, findMaxSubArrayPresentInLastElement){
    vector<int> A = {16,-18,4,5,6,-20, 17};
    SubArray res = BruteForceMaxSubArrayFinder::find(A);
    EXPECT_EQ(res.start, 6);
    EXPECT_EQ(res.end, 6);
    EXPECT_EQ(res.sum, 17);
}

TEST_F(TestBruteForceMaxSubArrayFinder, findMaxSubArrayWhenAllElementsNegative){
    vector<int> A = {-16,-18,-4,-5,-6,-20, -17};
    SubArray res = BruteForceMaxSubArrayFinder::find(A);
    EXPECT_EQ(res.start, 2);
    EXPECT_EQ(res.end, 2);
    EXPECT_EQ(res.sum, -4);
}
