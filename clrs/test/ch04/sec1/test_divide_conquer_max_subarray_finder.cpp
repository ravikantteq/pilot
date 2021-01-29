#include "gtest/gtest.h"
#include "ch04/sec1/divide_conquer_max_subarray_finder.h"

using namespace std;

class TestDivideConquerMaxSubArrayFinder : public ::testing::Test {
 protected:
  virtual void SetUp() {
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test
    // (right before the destructor).
  }
};

TEST_F(TestDivideConquerMaxSubArrayFinder, testm){
    vector<int> A = {17};
    SubArray res = DivideConquerMaxSubArrayFinder::find(A);
    EXPECT_EQ(res.start, 0);
    EXPECT_EQ(res.end, 0);
    EXPECT_EQ(res.sum, 17);
}

TEST_F(TestDivideConquerMaxSubArrayFinder, findMaxSubArrayPresentInMiddle){
    vector<int> A = {-3,-1,4,5,6,-2,-17};
    SubArray res = DivideConquerMaxSubArrayFinder::find(A);
    EXPECT_EQ(res.start, 2);
    EXPECT_EQ(res.end, 4);
    EXPECT_EQ(res.sum, 15);
}

TEST_F(TestDivideConquerMaxSubArrayFinder, findMaxSubArrayPresentInFirstElement){
    vector<int> A = {16,-18,4,5,6,-2, -17};
    SubArray res = DivideConquerMaxSubArrayFinder::find(A);
    EXPECT_EQ(res.start, 0);
    EXPECT_EQ(res.end, 0);
    EXPECT_EQ(res.sum, 16);
}

TEST_F(TestDivideConquerMaxSubArrayFinder, findMaxSubArrayPresentInLastElement){
    vector<int> A = {16,-18,4,5,6,-20, 17};
    SubArray res = DivideConquerMaxSubArrayFinder::find(A);
    EXPECT_EQ(res.start, 6);
    EXPECT_EQ(res.end, 6);
    EXPECT_EQ(res.sum, 17);
}

TEST_F(TestDivideConquerMaxSubArrayFinder, findMaxSubArrayWhenAllElementsNegative){
    vector<int> A = {-16,-18,-4,-5,-6,-20, -17};
    SubArray res = DivideConquerMaxSubArrayFinder::find(A);
    EXPECT_EQ(res.start, 2);
    EXPECT_EQ(res.end, 2);
    EXPECT_EQ(res.sum, -4);
}
