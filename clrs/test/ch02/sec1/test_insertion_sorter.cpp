#include <string>
#include "gtest/gtest.h"
#include "ch02/sec1/insertion_sorter.h"

using namespace std;

class TestInsertionSorter : public ::testing::Test {
 protected:
  virtual void SetUp() {
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test
    // (right before the destructor).
  }
};

TEST_F(TestInsertionSorter, sortNumbers){
    vector<int> A = {3, 2, 6, 4, 5, 1};
    InsertionSorter::sort(A);
    vector<int> sorted_A = {1, 2, 3, 4, 5, 6};
    EXPECT_EQ(A, sorted_A);
}
