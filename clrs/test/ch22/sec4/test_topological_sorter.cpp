#include "gtest/gtest.h"
#include "ch22/sec4/topological_sorter.h"
#include "../../common/graph_samples.h"

using namespace std;

class TestTopologicalSorter: public ::testing::Test {
    protected:
        virtual void SetUp() {
        }

        virtual void TearDown() {
        }
};

TEST_F(TestTopologicalSorter, topologicalSort) {
    Graph graph = sample_directed();
    TopologicalSorter sorter(graph.get_vertices_count());
    list<Vertex> sorted = sorter.sort(graph);
    EXPECT_EQ(sorted.size(), graph.get_vertices_count());
    vector<int> sorted_indices;
    for (auto v:sorted) {
        sorted_indices.push_back(v.get_index());
    }
    EXPECT_EQ(sorted_indices, vector<int>({4,5,0,1,3,2}));
}
