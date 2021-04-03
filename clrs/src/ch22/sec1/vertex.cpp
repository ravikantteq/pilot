#include "vertex.h"

Vertex::Vertex() {}
Vertex::Vertex(int index) : index(index) {}

int Vertex::get_index() {
    return index;
}

void Vertex::set_index(int index) {
    this->index = index;
}
