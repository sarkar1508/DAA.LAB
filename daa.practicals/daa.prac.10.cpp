
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to store an edge and its weight
struct Edge {
    int u, v, weight;
};

// Sort edges in increasing order of weight
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

class DSU {
    vector<int> parent, rank;

public:
    // Initially, every vertex belongs to its own set
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Find the representative of a set
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    // Merge two sets; return false if they are already connected
    bool unite(int u, int v) {
        u = find(u);
        v = find(v);

        // Same set means adding this edge creates a cycle
        if (u == v) {
            return false;
        }

        // Merge smaller-rank tree into larger-rank tree
        if (rank[u] < rank[v]) {
            swap(u, v);
        }

        parent[v] = u;

        // Increase rank when both ranks are equal
        if (rank[u] == rank[v]) {
            rank[u]++;
        }

        return true;
    }
};

int main() {
    int V, E;

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);

    // Input each edge and its weight
    cout << "Enter edges (u v weight):" << endl;
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u
            >> edges[i].v
            >> edges[i].weight;
    }

    // Sort edges from smallest to largest weight
    sort(edges.begin(), edges.end(), compare);

    DSU dsu(V);

    int totalWeight = 0;
    int selected = 0;

    cout << "Edges in Minimum Spanning Tree:" << endl;

    // Select the smallest edges without creating cycles
    for (Edge e : edges) {
        if (dsu.unite(e.u, e.v)) {
            cout << e.u << " - " << e.v
                 << " : " << e.weight << endl;

            totalWeight += e.weight;
            selected++;

            // An MST contains exactly V - 1 edges
            if (selected == V - 1) {
                break;
            }
        }
    }

    // Check whether all vertices are connected
    if (selected != V - 1) {
        cout << "Graph is disconnected; MST does not exist."
             << endl;
    } else {
        cout << "Total weight: " << totalWeight << endl;
    }

    return 0;
}
