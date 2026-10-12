
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj; // Adjacency list

public:
    // Initialize graph with V vertices
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    // Add an undirected edge between two vertices
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Recursive helper function for DFS
    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;  // Mark vertex as visited
        cout << v << " ";

        // Visit all unvisited neighboring vertices
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    // Perform Depth First Search
    void DFS(int start) {
        vector<bool> visited(V, false);

        cout << "DFS Traversal: ";
        DFSUtil(start, visited);
        cout << endl;
    }

    // Perform Breadth First Search
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q; // Queue stores vertices to visit

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";

        // Continue until the queue becomes empty
        while (!q.empty()) {
            int v = q.front();
            q.pop();

            cout << v << " ";

            // Add unvisited neighbors to the queue
            for (int neighbor : adj[v]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        cout << endl;
    }
};

int main() {
    int V, E;

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    Graph g(V);

    // Input all edges
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    // Run both graph traversal algorithms
    g.DFS(start);
    g.BFS(start);

    return 0;
}
