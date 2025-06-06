//
//  main.cpp
//  GoogleCPP_Examples
//
//  Created by Simon Getrik on 24.04.2025.
//

#include <iostream>
#include "BFS.hpp"
#include "DFS.hpp"
#include "maxFarmArea.hpp"
#include "xanoiTowers.hpp"
#include "GroupSum.hpp"

int main() {
    // Demonstrating BFS
    BFS::Graph bfsGraph(6);
    bfsGraph.demo();

    // Demonstrating DFS
    DFS::Graph dfsGraph(6);
    dfsGraph.demo();
    
//    main_maxFarmArea();
//    main_demo_Towers();
    demo_GroupSun();
    
    return 0;
}
