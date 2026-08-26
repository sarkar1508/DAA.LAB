#include <iostream>
#include <vector>
#include <queue>
#include <chrono>

using namespace std;
using namespace chrono;

// Graph class
class Graph
{
    int vertices;

    // Adjacency list to store graph connections
    vector<vector<int>> graph;

public:

    // Constructor
    Graph(int v)
    {
        vertices = v;
        graph.resize(vertices);
    }

    // Add an edge between two vertices
    void addEdge(int a, int b)
    {
        graph[a].push_back(b);
        graph[b].push_back(a);   // Remove this for a directed graph
    }

    // DFS helper function
    void DFSHelper(int node, vector<bool>& visited)
    {
        // Mark the current node as visited
        visited[node] = true;

        // Print the current node
        cout << node << " ";

        // Visit all connected nodes
        for (int next : graph[node])
        {
            if (!visited[next])
            {
                DFSHelper(next, visited);
            }
        }
    }

    // DFS traversal
    void DFS(int start)
    {
        // Initially, no vertex is visited
        vector<bool> visited(vertices, false);

        // Start DFS from the given vertex
        DFSHelper(start, visited);
    }

    // BFS traversal
    void BFS(int start)
    {
        // Initially, no vertex is visited
        vector<bool> visited(vertices, false);

        // Queue is used in BFS
        queue<int> q;

        // Mark starting vertex as visited
        visited[start] = true;

        // Insert starting vertex into queue
        q.push(start);

        // Continue until queue becomes empty
        while (!q.empty())
        {
            // Get the first element from queue
            int current = q.front();
            q.pop();

            // Print current vertex
            cout << current << " ";

            // Visit all connected vertices
            for (int next : graph[current])
            {
                if (!visited[next])
                {
                    // Mark vertex as visited
                    visited[next] = true;

                    // Add vertex to queue
                    q.push(next);
                }
            }
        }
    }
};

int main()
{
    int vertices, edges;

    // Take number of vertices
    cout << "Enter number of vertices: ";
    cin >> vertices;

    // Create graph
    Graph g(vertices);

    // Take number of edges
    cout << "Enter number of edges: ";
    cin >> edges;

    // Take edges from user
    cout << "Enter edges (u v):\n";

    for (int i = 0; i < edges; i++)
    {
        int u, v;

        cin >> u >> v;

        // Add edge to graph
        g.addEdge(u, v);
    }

    // Take starting vertex
    int start;

    cout << "Enter starting vertex: ";
    cin >> start;


    // =================================================
    //                 DFS TRAVERSAL
    // =================================================

    // Start timer for DFS
    auto dfsStart = high_resolution_clock::now();

    cout << "\nDFS Traversal: ";

    // Perform DFS
    g.DFS(start);

    // Stop timer
    auto dfsEnd = high_resolution_clock::now();

    // Calculate DFS execution time
    auto dfsTime =
        duration_cast<nanoseconds>(dfsEnd - dfsStart).count();


    // =================================================
    //                 BFS TRAVERSAL
    // =================================================

    // Start timer for BFS
    auto bfsStart = high_resolution_clock::now();

    cout << "\nBFS Traversal: ";

    // Perform BFS
    g.BFS(start);

    // Stop timer
    auto bfsEnd = high_resolution_clock::now();

    // Calculate BFS execution time
    auto bfsTime =
        duration_cast<nanoseconds>(bfsEnd - bfsStart).count();


    // =================================================
    //                 DISPLAY RESULT
    // =================================================

    cout << "\n\n===== Execution Time =====";

    // Display DFS time
    cout << "\nDFS Time: " << dfsTime << " nanoseconds";

    // Display BFS time
    cout << "\nBFS Time: " << bfsTime << " nanoseconds";


    // Compare execution times
    cout << "\n\n===== Comparison =====";

    if (dfsTime < bfsTime)
        cout << "\nDFS was faster for this input.";

    else if (bfsTime < dfsTime)
        cout << "\nBFS was faster for this input.";

    else
        cout << "\nBoth took approximately the same time.";

    // Time complexity of both algorithms
    cout << "\n\nTime Complexity:";
    cout << "\nDFS: O(V + E)";
    cout << "\nBFS: O(V + E)";

    return 0;
}