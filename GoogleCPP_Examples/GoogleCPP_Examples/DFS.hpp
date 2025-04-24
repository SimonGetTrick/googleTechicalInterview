//
//  DFS.hpp
//  GoogleCPP_Examples
//
//  Created by Simon Getrik on 24.04.2025.
//

#ifndef DFS_H
#define DFS_H

#include <vector>
#include <iostream>

namespace DFS {
    class Graph {
    public:
        int V;  // Number of vertices
        std::vector<std::vector<int>> adj;  // Adjacency list

        Graph(int V);  // Constructor
        void addEdge(int u, int v);  // Add edge
        void DFS(int start, std::vector<bool>& visited);  // Depth-First Search
        void demo();  // Demo of DFS algorithm
    };
}

#endif  // DFS_H

