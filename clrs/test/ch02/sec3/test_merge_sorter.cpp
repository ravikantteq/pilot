#include "gtest/gtest.h"
#include "ch02/sec3/merge_sorter.h"

using namespace std;

class TestMergeSorter: public ::testing::Test {
 protected:
  virtual void SetUp() {
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test
    // (right before the destructor).
  }
};

TEST_F(TestMergeSorter, mergeSortedListsWithSingleElementEach){
    vector<int> A = {2, 1};
    MergeSorter::merge(A, 0, 0, A.size()-1);
    vector<int> sorted_A = {1, 2};
    EXPECT_EQ(A, sorted_A);
}

TEST_F(TestMergeSorter, mergeSortedListsSimple){
    vector<int> A = {4, 5, 6, 1, 2, 3};
    MergeSorter::merge(A, 0, 2, A.size()-1);
    vector<int> sorted_A = {1, 2, 3, 4, 5, 6};
    EXPECT_EQ(A, sorted_A);
}

TEST_F(TestMergeSorter, mergeSortedListsComplex){
    vector<int> A = {2, 4, 5, 1, 3, 6};
    MergeSorter::merge(A, 0, 2, A.size()-1);
    vector<int> sorted_A = {1, 2, 3, 4, 5, 6};
    EXPECT_EQ(A, sorted_A);
}


TEST_F(TestMergeSorter, sortNumbers){
    vector<int> A = {3, 2, 6, 4, 5, 1};
    MergeSorter::sort(A);
    vector<int> sorted_A = {1, 2, 3, 4, 5, 6};
    EXPECT_EQ(A, sorted_A);
}

TEST_F(TestMergeSorter, sortNumbersSingleElement){
    vector<int> A = {1};
    MergeSorter::sort(A);
    vector<int> sorted_A = {1};
    EXPECT_EQ(A, sorted_A);
}

TEST_F(TestMergeSorter, sortEmptyList){
    vector<int> A;
    MergeSorter::sort(A);
    EXPECT_EQ(A.size(), 0);
}

