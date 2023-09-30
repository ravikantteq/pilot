#include "gtest/gtest.h"
#include "ch02/sec3/linear_finder.h"

using namespace std;

class TestLinearFinder: public ::testing::Test {
 protected:
  virtual void SetUp() {
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test
    // (right before the destructor).
  }
};

TEST_F(TestLinearFinder, linearFinderWhenElementExists){
    vector<int> A = {3, 4, 5, 6, 1, 2};
    int elementAt = LinearFinder::search(A, 5);
    EXPECT_EQ(elementAt, 2);
}

TEST_F(TestLinearFinder, linearFinderWhenElementDoesNotExist){
    vector<int> A = {3, 4, 5, 6, 1, 2};
    int elementAt = LinearFinder::search(A, 9);
    EXPECT_EQ(elementAt, -1);
}
