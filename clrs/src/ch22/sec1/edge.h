#include "vertex.h"

class Edge {
    Vertex from;
    Vertex to;

    public:
    Edge(Vertex from, Vertex to);
    Vertex get_to();
    Vertex get_from();
};

