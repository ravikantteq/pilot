#include "gtest/gtest.h"
#include "ch02/prob/inversion_counter.h"


using namespace std;

class TestInversionCounter : public ::testing::Test {
 protected:
  virtual void SetUp() {
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test
    // (right before the destructor).
  }
};

TEST_F(TestInversionCounter, countInversions){
    vector<int> A = {2, 3, 8, 6, 1};
    int count = InversionCounter::count(A);
    EXPECT_EQ(count, 5);
}

TEST_F(TestInversionCounter, countInversionsSingleElement){
    vector<int> A = {6};
    int count = InversionCounter::count(A);
    EXPECT_EQ(count, 0);
}

TEST_F(TestInversionCounter, countInversionsForIncreasingList){
    vector<int> A = {1, 2, 3, 4, 5, 6};
    int count = InversionCounter::count(A);
    EXPECT_EQ(count, 0);
}

TEST_F(TestInversionCounter, countInversionsForDecreasingList){
    vector<int> A = {5, 4, 3, 2, 1};
    int count = InversionCounter::count(A);
    EXPECT_EQ(count, 10);
}

TEST_F(TestInversionCounter, countInversionsForNonIncreasingList){
    vector<int> A = {5, 4, 4, 3, 2};
    int count = InversionCounter::count(A);
    EXPECT_EQ(count, 8);
}
