#include "depth_first_graph_visitor.h"
#include <iostream>

using namespace std;

int time_ = 0;

DepthFirstGraphVisitor::DepthFirstGraphVisitor() {}
DepthFirstGraphVisitor::DepthFirstGraphVisitor(int v) : parent(v), d(v), f(v), color(v) {}

void DepthFirstGraphVisitor::before_exploration(Graph& graph, Vertex& v) {}
void DepthFirstGraphVisitor::after_exploration(Graph& graph, Vertex& v) {}

void DepthFirstGraphVisitor::visit(Graph& graph) {
    vector<Vertex>& vertices = graph.get_vertices();
    for (Vertex v: vertices) {
        int idx = v.get_index();
        parent[idx] = -1;
        d[idx] = 0;
        f[idx] = 0;
        color[idx] = WHITE;
    }

    time_ = 0;
    for(Vertex v: vertices) {
        if (color[v.get_index()] == WHITE) {
            visit_sub_graph(graph, v);
        }
    }
}

void DepthFirstGraphVisitor::visit(Graph& graph, int start) {
    vector<Vertex>& vertices = graph.get_vertices();
    for (Vertex v: vertices) {
        int idx = v.get_index();
        parent[idx] = -1;
        d[idx] = 0;
        f[idx] = 0;
        color[idx] = WHITE;
    }

    time_ = 0;
    visit_sub_graph(graph, graph.get_vertex(start));
}



void DepthFirstGraphVisitor::visit_sub_graph(Graph& graph, Vertex& src) {
    int si = src.get_index();
    d[si] = ++time_;
    color[si] = GREY;    
    before_exploration(graph, src);

    list<WeightedEdge>& edges = graph.get_edges(src);
    for (WeightedEdge& edge: edges) {
        Vertex dest = edge.get_to();
        int di = dest.get_index();
        if (color[di] == WHITE) {
            parent[di] = si;
            visit_sub_graph(graph, dest);
        }
    }
    color[si] = BLACK;
    f[si] = ++time_;
    after_exploration(graph, src);
}
