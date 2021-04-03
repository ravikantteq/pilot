#include "gtest/gtest.h"
#include "ch22/sec1/weighted_edge.h"

using namespace std;

class TestWeightedEdge: public ::testing::Test {
 protected:
     Vertex v0;
     Vertex v1;
     TestWeightedEdge() : v0(0), v1(1) {}
     virtual void SetUp() {

     }

     virtual void TearDown() {
         // Code here will be called immediately after each test
         // (right before the destructor).
     }
};

TEST_F(TestWeightedEdge, createWeightedEdgeObject) {
    WeightedEdge edge(v0, v1, 35);
    EXPECT_EQ(edge.get_from().get_index(), v0.get_index());
    EXPECT_EQ(edge.get_to().get_index(), v1.get_index());
}

TEST_F(TestWeightedEdge, testGetFrom) {
    WeightedEdge edge(v0, v1, 35);
    EXPECT_EQ(edge.get_from().get_index(), v0.get_index());
}

TEST_F(TestWeightedEdge, testGetTo) {
    WeightedEdge edge(v0, v1, 35);
    EXPECT_EQ(edge.get_to().get_index(), v1.get_index());
}

TEST_F(TestWeightedEdge, testGetWeight) {
    WeightedEdge edge(v0, v1, 35);
    EXPECT_EQ(edge.get_weight(), 35);
}
