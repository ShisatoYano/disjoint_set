#include <bits/stdc++.h>
using namespace std;

// edge in graph
class Edge {
public:
    int src, dst;
};

// graph
class Graph {
public:
    int V, E; // num of vertices, edges

    Edge* edge;
};

// create a graph
Graph* create_graph(int V, int E) {
    Graph* graph = new Graph();
    graph->V = V;
    graph->E = E;

    graph->edge = new Edge[graph->E * sizeof(Edge)];

    return graph;
}

// find subset of element i
int find(int parent[], int i) {
    if (parent[i] == -1) {
        return i;
    }
    return find(parent, parent[i]);
}

// do union of two subsets
void union_set(int parent[], int x, int y) {
    parent[x] = y;
}

// check whether given graph contains cycle or not
int is_cycle(Graph* graph) {
    // allocate memory for creating V subsets
    int* parent = new int[graph->V * sizeof(int)];

    // initialize all subsets as single element sets
    memset(parent, -1, sizeof(int) * graph->V);

    // iterate through all edges of graph
    // find subset of both vertices of every edge
    for (int i = 0; i < graph->E; ++i) {
        int x = find(parent, graph->edge[i].src);
        int y = find(parent, graph->edge[i].dst);

        if (x == y) {
            return 1;
        }

        union_set(parent, x, y);
    }

    return 0;
}

int main() {
    int V = 3, E = 3;
    Graph* graph = create_graph(V, E);

    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dst = 1;

    // add edge 1-2
    graph->edge[1].src = 1;
    graph->edge[1].dst = 2;

    // add edge 0-2
    graph->edge[2].src = 0;
    graph->edge[2].dst = 2;

    if (is_cycle(graph)) {
        cout << "graph contains cycle";
    }else {
        cout << "graph doesn't contain cycle";
    }

    return 0;
}
