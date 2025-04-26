//
//  xanoiTowers.cpp
//  GoogleCPP_Examples
//
//  Created by Simon Getrik on 26.04.2025.
//

#include "xanoiTowers.hpp"
#include <iostream>
#include <vector>

using namespace std;

// Function to display the state of the towers
void printTowers(const vector<vector<int>>& towers) {
    cout << "Towers state:" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "Tower " << i + 1 << ": ";
        for (int disk : towers[i]) {
            cout << disk << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Recursive function to solve the Tower of Hanoi problem
void hanoi(int n, vector<vector<int>>& towers, int source, int auxiliary, int target) {
    if (n > 0) {
        // Move n-1 disks from source to auxiliary
        hanoi(n - 1, towers, source, target, auxiliary);
        
        // Move the largest disk from source to target
        towers[target].push_back(towers[source].back());
        towers[source].pop_back();
        
        cout << "Move disk " << n << " from Tower " << source + 1 << " to Tower " << target + 1 << endl;
        printTowers(towers);
        
        // Move n-1 disks from auxiliary to target
        hanoi(n - 1, towers, auxiliary, source, target);
    }
}

int main_demo_Towers() {
    int n;
    // Prompt user for the number of disks
    cout << "Enter number of disks: ";
    cin >> n;
    
    // Initialize three towers
    vector<vector<int>> towers(3);
    
    // Fill the first tower with disks (from largest to smallest)
    for (int i = n; i >= 1; --i) {
        towers[0].push_back(i);
    }
    
    // Display initial state
    cout << "Initial state:" << endl;
    printTowers(towers);
    
    // Solve the Tower of Hanoi problem
    hanoi(n, towers, 0, 1, 2);
    
    return 0;
}
