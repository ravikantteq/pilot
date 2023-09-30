#include "gtest/gtest.h"
#include "ch22/sec1/edge.h"

using namespace std;

class TestEdge: public ::testing::Test {
 protected:
     Vertex v0;
     Vertex v1;
     TestEdge() : v0(0), v1(1) {}
     virtual void SetUp() {
     }

     virtual void TearDown() {
         // Code here will be called immediately after each test
         // (right before the destructor).
     }
};

TEST_F(TestEdge, createEdgeObject) {
    Edge edge(v0, v1);
    EXPECT_EQ(edge.get_from().get_index(), v0.get_index());
    EXPECT_EQ(edge.get_to().get_index(), v1.get_index());
}

TEST_F(TestEdge, testGetFrom) {
    Edge edge(v0, v1);
    EXPECT_EQ(edge.get_from().get_index(), v0.get_index());
}

TEST_F(TestEdge, testGetTo) {
    Edge edge(v0, v1);
    EXPECT_EQ(edge.get_to().get_index(), v1.get_index());
}
