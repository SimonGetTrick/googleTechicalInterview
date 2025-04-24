//
//  BFS.hpp
//  GoogleCPP_Examples
//
//  Created by Simon Getrik on 24.04.2025.
//

#ifndef BFS_H
#define BFS_H

#include <vector>
#include <queue>
#include <iostream>

namespace BFS {
    class Graph {
    public:
        int V;  // Number of vertices
        std::vector<std::vector<int>> adj;  // Adjacency list

        Graph(int V);  // Constructor
        void addEdge(int u, int v);  // Add edge
        void BFS(int start);  // Breadth-First Search
        void demo();  // Demo of BFS algorithm
    };
}

#endif  // BFS_H
