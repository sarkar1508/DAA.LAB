
#include <iostream>
#include <vector>
using namespace std;

const int INF = 99999;

int main() {
    int V;

    // Input the number of vertices
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> dist(V, vector<int>(V));

    // Input the adjacency matrix
    // Enter 99999 if there is no edge between vertices
    cout << "Enter adjacency matrix (99999 for no edge):\n";

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> dist[i][j];
        }
    }

    // Floyd-Warshall algorithm
    // k is the intermediate vertex
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {

                // Update distance if a shorter path is found
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {

                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Display the shortest distance matrix
    cout << "\nAll-Pairs Shortest Distance Matrix:\n";

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
