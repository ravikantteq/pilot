#include <queue>
#include <bits/stdc++.h>
#include "prims_minimum_spanning_tree_finder.h"

using namespace std;

bool vertex_compare(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

Graph PrimsMinimumSpanningTreeFinder::find(Graph& graph) {
    int v = graph.get_vertices_count();
    vector<int> parent(v, -1);
    vector<bool> processed(v, false);
    vector<int> key(v, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&vertex_compare)> pq(vertex_compare);
    vector<Vertex>& vertices = graph.get_vertices();
    pq.push(make_pair(0, INT_MAX));

    while(!pq.empty()) {
        pair<int, int> p = pq.top();
        pq.pop();
        int ui = p.first;
        Vertex& u = graph.get_vertex(ui);
        processed[ui] = true;
        for (auto edge: graph.get_edges(u)) {
            int vi = edge.get_to().get_index();
            if (processed[vi] == false && key[vi] > edge.get_weight()) {
                parent[vi] = ui;
                key[vi] = edge.get_weight();
                pq.push(make_pair(vi, edge.get_weight()));
            }
        }
    }

    Graph mst(v);
    for (int i = 0; i < v; i++) {
        if (parent[i] == -1) continue;
        Vertex u = mst.get_vertex(parent[i]); 
        Vertex v = mst.get_vertex(i);
        mst.add_edge(u, v, key[i]);
    }
    return mst;
}
