
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int V;

    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    // Input the weighted adjacency matrix
    cout << "Enter adjacency matrix (0 for no edge):" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    // key[v] stores the minimum edge weight to connect vertex v
    vector<int> key(V, INT_MAX);

    // Track vertices already included in the MST
    vector<bool> inMST(V, false);

    // parent[v] stores the MST parent of vertex v
    vector<int> parent(V, -1);

    key[0] = 0; // Start from vertex 0

    // Select V vertices for the Minimum Spanning Tree
    for (int count = 0; count < V; count++) {
        int u = -1;

        // Find the unvisited vertex with minimum key
        for (int v = 0; v < V; v++) {
            if (!inMST[v] &&
                (u == -1 || key[v] < key[u])) {
                u = v;
            }
        }

        // Check whether the graph is connected
        if (u == -1 || key[u] == INT_MAX) {
            cout << "Graph is disconnected." << endl;
            return 0;
        }

        inMST[u] = true; // Include vertex in the MST

        // Update keys of neighboring vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 &&
                !inMST[v] &&
                graph[u][v] < key[v]) {

                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    int totalWeight = 0;

    // Display MST edges and calculate total weight
    cout << "Edges in Minimum Spanning Tree:" << endl;

    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i
             << " : " << key[i] << endl;

        totalWeight += key[i];
    }

    cout << "Total weight: " << totalWeight << endl;

    return 0;
}

