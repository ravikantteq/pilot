#ifndef __DEPTH_FIRST_GRAPH_VISITOR_H__
#define __DEPTH_FIRST_GRAPH_VISITOR_H__

#include "../sec1/graph.h"

enum Color {
    WHITE,
    GREY,
    BLACK
};

class DepthFirstGraphVisitor {
    public:
        std::vector<int> parent;
        std::vector<int> d; // discovered
        std::vector<int> f; // finished
        std::vector<Color> color;

        DepthFirstGraphVisitor();
        DepthFirstGraphVisitor(int v);
        void visit(Graph& graph);
        void visit(Graph& graph, int start);
        void visit_sub_graph(Graph& graph, Vertex& src);
        virtual void before_exploration(Graph& graph, Vertex& v);
        virtual void after_exploration(Graph& graph, Vertex& v);
};

#endif
