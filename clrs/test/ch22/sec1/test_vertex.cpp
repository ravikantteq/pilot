#include "gtest/gtest.h"
#include "ch22/sec1/vertex.h"

using namespace std;

class TestVertex: public ::testing::Test {
 protected:
  virtual void SetUp() {
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test
    // (right before the destructor).
  }
};

TEST_F(TestVertex, createVertexObject) {
    Vertex vertex(0);
    EXPECT_EQ(vertex.get_index(), 0);
}

TEST_F(TestVertex, testGetIndex) {
    Vertex vertex(1);
    EXPECT_EQ(vertex.get_index(), 1);
}

TEST_F(TestVertex, testSetIndex) {
    Vertex vertex(0);
    EXPECT_EQ(vertex.get_index(), 0);

    vertex.set_index(1);
    EXPECT_EQ(vertex.get_index(), 1);
}
