//
//  DFS.cpp
//  GoogleCPP_Examples
//
//  Created by Simon Getrik on 24.04.2025.
//

#include "DFS.hpp"

namespace DFS {
    // Constructor
    Graph::Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // Add edge
    void Graph::addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // For undirected graph
    }

    // Depth-First Search (recursive)
    void Graph::DFS(int start, std::vector<bool>& visited) {
        visited[start] = true;
        std::cout << start << " ";  // Print the node

        // Recursively traverse neighbors
        for (int neighbor : adj[start]) {
            if (!visited[neighbor]) {
                DFS(neighbor, visited);
            }
        }
    }

    // Demo of DFS
    void Graph::demo() {
        Graph g(6);  // Create graph with 6 vertices
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 3);
        g.addEdge(1, 4);
        g.addEdge(2, 5);

        std::vector<bool> visited(6, false);
        std::cout << "DFS starting from vertex 0: ";
        g.DFS(0, visited);
        std::cout << std::endl;
    }
}
