#include "ch22/sec1/graph.h"

Graph sample_directed() {
    Graph graph(6);
    graph.add_edge(graph.get_vertex(0), graph.get_vertex(1), 1);
    graph.add_edge(graph.get_vertex(0), graph.get_vertex(3), 1);
    graph.add_edge(graph.get_vertex(1), graph.get_vertex(3), 1);
    graph.add_edge(graph.get_vertex(2), graph.get_vertex(0), 1);
    graph.add_edge(graph.get_vertex(3), graph.get_vertex(2), 1);
    graph.add_edge(graph.get_vertex(4), graph.get_vertex(5), 1);
    graph.add_edge(graph.get_vertex(0), graph.get_vertex(1), 1);
    return graph;
}
/*
Graph& sample_weighted_graph() {
    Graph graph(9);
    bi_direction_add_edge(graph, 0, 1, 4);
    bi_direction_add_edge(graph, 0, 7, 8);
    bi_direction_add_edge(graph, 1, 2, 8);
    bi_direction_add_edge(graph, 1, 7, 11);
    bi_direction_add_edge(graph, 2, 3, 7);
    bi_direction_add_edge(graph, 2, 5, 4);
    bi_direction_add_edge(graph, 2, 8, 2);
    bi_direction_add_edge(graph, 3, 4, 9);
    bi_direction_add_edge(graph, 3, 5, 14);
    bi_direction_add_edge(graph, 4, 5, 10);
    bi_direction_add_edge(graph, 4, 5, 10);
    bi_direction_add_edge(graph, 5, 6, 2);
    bi_direction_add_edge(graph, 6, 7, 1);
    bi_direction_add_edge(graph, 6, 8, 6);
    bi_direction_add_edge(graph, 7, 8, 7);
    return graph;
}

void bi_direction_add_edge(Graph& graph, int from, int to, int weight) {
    int v1 = graph.get_vertex(from);
    int v2 = graph.get_vertex(to);
    graph.add_edge(v1, v2, weight);
    graph.add_edge(v2, v1, weight);
}*/
