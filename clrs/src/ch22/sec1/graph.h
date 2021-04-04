#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <vector>
#include <list>

#include "vertex.h"
#include "weighted_edge.h"

class Graph {
    private:
        int V;
        std::vector<std::list<WeightedEdge> > adj;
        std::vector<Vertex> vertices;
    public:
        Graph(int V);
        void validate(int index);
        int get_vertices_count();
        std::vector<Vertex>& get_vertices();
        Vertex& get_vertex(int index);
        bool is_connected(int from, int to);
        void add_edge(Vertex& from, Vertex& to, int weight);
        WeightedEdge get_edge(int from, int to);
        std::list<WeightedEdge>& get_edges(Vertex& v);
};

#endif
