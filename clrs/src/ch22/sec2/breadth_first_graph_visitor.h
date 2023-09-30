#ifndef __BREADTH_FIRST_GRAPH_VISITOR_H__
#define __BREADTH_FIRST_GRAPH_VISITOR_H__

#include "../sec1/graph.h"

enum Color {
    WHITE,
    GREY,
    BLACK
};

class BreadthFirstGraphVisitor {
    public:
        std::vector<int> parent;
        std::vector<Color> color;
        std::vector<int> distance;

        BreadthFirstGraphVisitor(int v);
        void visit(Graph& graph);
        void visit(Graph& graph, int start);
        void visit_sub_graph(Graph& graph, Vertex& src);
};

#endif
