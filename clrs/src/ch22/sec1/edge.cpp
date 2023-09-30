#include "edge.h"

Edge::Edge(Vertex from, Vertex to) : from(from), to(to) {}

Vertex Edge::get_to() {
    return to;
}

Vertex Edge::get_from() {
    return from;
}
