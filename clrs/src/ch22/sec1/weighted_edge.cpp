#include "weighted_edge.h"

WeightedEdge::WeightedEdge(Vertex from, Vertex to, int w) : Edge(from, to) {
    weight = w;
}

int WeightedEdge::get_weight() {
    return weight;
}
