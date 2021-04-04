#include "topological_sorter.h"

using namespace std;

TopologicalSorter::TopologicalSorter(int v) : DepthFirstGraphVisitor(v) {}

void TopologicalSorter::after_exploration(Graph& graph, Vertex& v) {
    graph.validate(v.get_index());
    sorted.push_front(v);
}

list<Vertex> TopologicalSorter::sort(Graph& graph) {
    sorted.clear();
    DepthFirstGraphVisitor visitor(graph.get_vertices_count());
    visit(graph);
    return sorted;
}
