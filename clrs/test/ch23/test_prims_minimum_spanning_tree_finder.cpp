#include "gtest/gtest.h"
#include "ch23/sec2/prims_minimum_spanning_tree_finder.h"
#include "../common/graph_samples.h"

using namespace std;

class TestPrimsMinimumSpanningTreeFinder: public ::testing::Test {
    protected:
        virtual void SetUp() {
        }

        virtual void TearDown() {
        }
};

TEST_F(TestPrimsMinimumSpanningTreeFinder, findMinimumSpanningTree) {
    PrimsMinimumSpanningTreeFinder mst_finder;
    Graph graph = sample_weighted_graph();
    Graph mst = mst_finder.find(graph);
    int expected_sum = 37;
    int weights = 0;

    EXPECT_EQ(graph.get_vertices_count(), mst.get_vertices_count());
    for(int i = 0; i < mst.get_vertices_count(); i++) {
        for (int j = 0; j < mst.get_vertices_count(); j++) {
            if (mst.is_connected(i, j)) {
                weights += mst.get_edge(i, j).get_weight(); 
            }
        }
    }
    EXPECT_EQ(weights, expected_sum);
}
