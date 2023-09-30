#include "gtest/gtest.h"
#include "ch02/sec3/binary_search_finder.h"

using namespace std;

class TestBinarySearchFinder: public ::testing::Test {
 protected:
  virtual void SetUp() {
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test
    // (right before the destructor).
  }
};

TEST_F(TestBinarySearchFinder, findWhenElementExists){
    vector<int> A = {3, 4, 5, 6, 1, 2};
    int elementAt = BinarySearchFinder::search(A, 5);
    EXPECT_EQ(elementAt, 2);
}

TEST_F(TestBinarySearchFinder, findWhenElementDoesNotExist){
    vector<int> A = {3, 4, 5, 6, 1, 2};
    int elementAt = BinarySearchFinder::search(A, 9);
    EXPECT_EQ(elementAt, -1);
}
