#include "graph.h"
#include <stdexcept>

using namespace std;

Graph::Graph(int V) : V(V), vertices(V), adj(V) {
    for (auto i = 0; i < V; i++) {
        vertices[i].set_index(i);
    }
}

void Graph::validate(int index) {
    if (index < 0 || index >= vertices.size()) {
        throw out_of_range("Invalid vertex index");
    }
}

int Graph::get_vertices_count() {
    return V;
}

vector<Vertex>& Graph::get_vertices() {
    return vertices;
}

Vertex& Graph::get_vertex(int index) {
    validate(index);
    return vertices[index];
}

void Graph::add_edge(Vertex& from, Vertex& to, int weight) {
    WeightedEdge edge = WeightedEdge(from, to, weight);
    int v = from.get_index();
    adj[v].push_front(edge);
}

list<WeightedEdge>& Graph::get_edges(Vertex& v) {
    int index  = v.get_index();
    validate(index);
    return adj[index];
}
