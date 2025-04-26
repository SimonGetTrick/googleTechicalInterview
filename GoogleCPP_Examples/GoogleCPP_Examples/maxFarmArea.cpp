//
//  maxFarmArea.cpp
//  GoogleCPP_Examples
//
//  Created by Simon Getrik on 25.04.2025.
//

#include "maxFarmArea.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate the maximum farm area and the top-left and bottom-right coordinates
tuple<int, int, int, int, int> locatioMaxFarmArea(const vector<vector<int>>& land) {
    size_t m = land.size();
    size_t n = land[0].size();
    
    // DP table to store the side length of the largest square ending at each position
    vector<vector<int>> dp(m, vector<int>(n, 0));
    
    int maxSide = 0; // To keep track of the maximum side length of the square
    int topLeftX = 0, topLeftY = 0; // Coordinates of the top-left corner of the square
    
    // Traverse each cell in the matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (land[i][j] == 1) { // Only consider the cells with good land (1)
                if (i == 0 || j == 0) {
                    // If it's in the first row or first column, the largest square is just 1x1
                    dp[i][j] = 1;
                } else {
                    // Calculate the side length of the square that ends at (i, j)
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                }
                
                // Update the maximum side and store the top-left corner coordinates if this is the largest square
                if (dp[i][j] > maxSide) {
                    maxSide = dp[i][j];
                    topLeftX = i - maxSide + 1; // Top-left X coordinate
                    topLeftY = j - maxSide + 1; // Top-left Y coordinate
                }
            }
        }
    }
    
    // Return the area of the largest square, along with top-left and bottom-right coordinates
    int bottomRightX = topLeftX + maxSide - 1; // Bottom-right X coordinate
    int bottomRightY = topLeftY + maxSide - 1; // Bottom-right Y coordinate
    return make_tuple(maxSide * maxSide, topLeftX, topLeftY, bottomRightX, bottomRightY);
}

int maxFarmArea(vector<vector<int>>& land) {
    size_t m = land.size();
    size_t n = land[0].size();

    // Create a DP table to store the largest square's side length at each position
    vector<vector<int>> dp(m, vector<int>(n, 0));

    int maxSide = 0;  // To keep track of the maximum side of the square

    // Loop through each cell in the matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (land[i][j] == 1) {
                if (i == 0 || j == 0) {
                    // If it's on the first row or first column, it's just a 1x1 square
                    dp[i][j] = 1;
                } else {
                    // Take the minimum of the three neighboring squares + 1
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                }
                // Update the maximum side found
                maxSide = max(maxSide, dp[i][j]);
            }
        }
    }

    // The area of the largest square
    return maxSide * maxSide;
}

int main_maxFarmArea() {
    // Example input: A matrix of land
    vector<vector<int>> land = {
        {1, 0, 1, 0, 0},
        {1, 1, 1, 1, 0},
        {1, 1, 1, 1, 0},
        {0, 1, 0, 0, 0},
        {1, 1, 0, 0, 0}
    };

    // Calling the function that returns only the area
    int area = maxFarmArea(land);
    cout << "Maximum farm area (area only): " << area << endl;
    
    // Calling the function that returns the area and coordinates
    auto [areaWithCoords, topLeftX, topLeftY, bottomRightX, bottomRightY] = locatioMaxFarmArea(land);
    cout << "Maximum farm area (with coordinates): " << areaWithCoords << endl;
    cout << "Top-left coordinates: (" << topLeftX << ", " << topLeftY << ")" << endl;
    cout << "Bottom-right coordinates: (" << bottomRightX << ", " << bottomRightY << ")" << endl;
    
    
    return 0;
}

/*
 origin:
 1 0 1 0 0
 1 1 1 1 0
 1 1 1 1 0
 0 1 0 0 0
 1 1 0 0 0
 dp:
 1 0 1 0 0
 1 1 1 1 0
 1 1 2 2 0
 0 1 1 1 0
 1 1 0 0 0
 */
