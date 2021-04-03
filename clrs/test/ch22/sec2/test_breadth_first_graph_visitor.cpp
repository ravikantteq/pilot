#include "gtest/gtest.h"
#include "ch22/sec2/breadth_first_graph_visitor.h"
#include "../../common/graph_samples.h"

using namespace std;

class TestBreadthFirstGraphVisitor: public ::testing::Test {
    protected:
        Graph graph;
        BreadthFirstGraphVisitor* bfs_visitor;
        TestBreadthFirstGraphVisitor() : graph(sample_directed()){
            bfs_visitor = new BreadthFirstGraphVisitor(this->graph.get_vertices_count());
        }
        virtual void SetUp() {
        }

        virtual void TearDown() {
        }
        ~TestBreadthFirstGraphVisitor() {
            delete bfs_visitor;
        }
};

TEST_F(TestBreadthFirstGraphVisitor, visitFromSingleSource) {
    bfs_visitor->visit(graph, 0);
    EXPECT_EQ(bfs_visitor->parent[0], -1);
    EXPECT_EQ(bfs_visitor->parent[1], 0);
    EXPECT_EQ(bfs_visitor->parent[2], 3);
    EXPECT_EQ(bfs_visitor->parent[3], 0);
    EXPECT_EQ(bfs_visitor->parent[4], -1);
    EXPECT_EQ(bfs_visitor->parent[5], -1);
}
