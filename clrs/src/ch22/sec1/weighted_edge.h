#ifndef __WEIGHTED_EDGE_H__
#define __WEIGHTED_EDGE_H__

#include "edge.h"

class WeightedEdge : public Edge {
    int weight;

    public:

    WeightedEdge(Vertex from, Vertex to, int weight);
    int get_weight();
    int set_weight();
};

#endif
