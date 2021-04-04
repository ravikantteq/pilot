#include "gtest/gtest.h"
#include "ch22/sec3/depth_first_graph_visitor.h"
#include "../../common/graph_samples.h"

using namespace std;

class TestDepthFirstGraphVisitor: public ::testing::Test {
    protected:
        Graph graph;
        DepthFirstGraphVisitor* dfs_visitor;
        TestDepthFirstGraphVisitor() : graph(sample_directed()){
            dfs_visitor = new DepthFirstGraphVisitor(this->graph.get_vertices_count());
        }
        virtual void SetUp() {
        }

        virtual void TearDown() {
        }
        ~TestDepthFirstGraphVisitor() {
            delete dfs_visitor;
        }
};

TEST_F(TestDepthFirstGraphVisitor, visitFromSingleSource) {
    dfs_visitor->visit(graph);
    EXPECT_EQ(dfs_visitor->parent[0], -1);
    EXPECT_EQ(dfs_visitor->parent[1], 0);
    EXPECT_EQ(dfs_visitor->parent[2], 3);
    EXPECT_EQ(dfs_visitor->parent[3], 1);
    EXPECT_EQ(dfs_visitor->parent[4], -1);
    EXPECT_EQ(dfs_visitor->parent[5], 4);
}
