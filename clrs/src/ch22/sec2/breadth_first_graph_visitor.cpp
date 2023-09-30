#include <limits.h>
#include <queue>
#include "breadth_first_graph_visitor.h"

using namespace std;

BreadthFirstGraphVisitor::BreadthFirstGraphVisitor(int v) : parent(v), color(v), distance(v) {}

void BreadthFirstGraphVisitor::visit(Graph& graph) {
    vector<Vertex>& vertices = graph.get_vertices();

    for (auto vertex: vertices) {
        int idx = vertex.get_index();
        parent[idx] = -1;
        color[idx] = WHITE;
        distance[idx] = INT_MAX;
    }

    for (auto vertex: vertices) {
        int idx = vertex.get_index();
        if (color[idx] == WHITE) {
            visit_sub_graph(graph, vertex);
        }
    }
}

void BreadthFirstGraphVisitor::visit(Graph& graph, int start) {
    graph.validate(start);
    vector<Vertex>& vertices = graph.get_vertices();
    for (Vertex v: vertices) {
        int idx = v.get_index();
        parent[idx] = -1;
        color[idx] = WHITE;
        distance[idx] = INT_MAX;
    }

    Vertex src = vertices[start];
    visit_sub_graph(graph, src);
}

void BreadthFirstGraphVisitor::visit_sub_graph(Graph& graph, Vertex& vertex) {
    int idx = vertex.get_index();
    color[idx] = GREY;
    distance[idx] = 0;
    parent[idx] = -1;

    queue<Vertex> que;
    que.push(vertex);

    while(que.empty() == false) {
        Vertex& v = que.front();
        que.pop();
        list<WeightedEdge>& edges = graph.get_edges(v);
        for (WeightedEdge edge: edges) {
            Vertex to = edge.get_to();
            int i = to.get_index();
            if (color[i] == WHITE) {
                que.push(to);
                color[i] = GREY;
                parent[i] = v.get_index();
                distance[i] = distance[v.get_index()] + 1;
            }
        }
        color[v.get_index()] = BLACK;
    }
}
