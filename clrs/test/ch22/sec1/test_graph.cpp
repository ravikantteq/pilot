#include "gtest/gtest.h"
#include "ch22/sec1/graph.h"

using namespace std;

class TestGraph: public ::testing::Test {
 protected:
     int V;
  virtual void SetUp() {
      V = 5;
  }

  virtual void TearDown() {
      V = 0;
  }
};

TEST_F(TestGraph, createGraphObject) {
    Graph graph(V);
    EXPECT_EQ(graph.get_vertices_count(), V);
}

TEST_F(TestGraph, testAddEdge) {
    Graph graph(V);
    vector<Vertex>& vertices = graph.get_vertices();
    graph.add_edge(vertices[0], vertices[1], 30);
    graph.add_edge(vertices[0], vertices[2], 35);
    list<WeightedEdge>& edges = graph.get_edges(vertices[0]);
    EXPECT_EQ(edges.size(), 2);
    EXPECT_EQ(edges.front().get_weight(), 35);
    EXPECT_EQ(edges.front().get_to().get_index(), 2);
    edges.pop_front();
    EXPECT_EQ(edges.front().get_weight(), 30);
    EXPECT_EQ(edges.front().get_to().get_index(), 1);
}
