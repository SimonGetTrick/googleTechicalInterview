//
//  BFS.cpp
//  GoogleCPP_Examples
//
//  Created by Simon Getrik on 24.04.2025.
//

#include "BFS.hpp"

namespace BFS {
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

    // Breadth-First Search
    void Graph::BFS(int start) {
        std::vector<bool> visited(V, false);
        std::queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            std::cout << node << " ";  // Print the node

            // Traverse neighbors
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    // Demo of BFS
    void Graph::demo() {
        Graph g(6);  // Create graph with 6 vertices
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 3);
        g.addEdge(1, 4);
        g.addEdge(2, 5);

        std::cout << "BFS starting from vertex 0: ";
        g.BFS(0);
        std::cout << std::endl;
    }
}


