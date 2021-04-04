#ifndef __TOPOLOGICAL_SORTER_H__
#define __TOPOLOGICAL_SORTER_H__

#include <list>
#include "../sec3/depth_first_graph_visitor.h"

class TopologicalSorter: public DepthFirstGraphVisitor {
    public:
        TopologicalSorter(int v);
        std::list<Vertex> sorted;
        std::list<Vertex> sort(Graph& graph);
        void after_exploration(Graph& graph, Vertex& v);
};

#endif
