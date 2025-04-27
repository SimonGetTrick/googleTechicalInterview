//
//  GroupSum.cpp
//  GoogleCPP_Examples
//
//  Created by Simon Getrik on 27.04.2025.
//

#include "GroupSum.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>

using namespace std;

// Custom hash function for vector<int>
struct VectorHash {
    size_t operator()(const vector<int>& v) const {
        size_t seed = v.size();
        for (auto& i : v) {
            seed ^= hash<int>()(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};
// Helper function to create a string key for quadruplet
string createKey(int a, int b, int c, int d) {
    return to_string(a) + "," + to_string(b) + "," + to_string(c) + "," + to_string(d);
}

// Solution class with the fourSum method
class Solution {
    int o1 = 0;
    int o2 = 0;
    int o3 = 0;
public:
    
    void print_statistics() {
        cout << "o1 = " << o1 <<  "\no2 = " << o2 << "\no3 =  " << o3 << endl;
    }
    vector<vector<int>> fourSum3(vector<int>& nums, int target) {
            vector<vector<int>> result;
            set<string> seen;
            size_t n = nums.size();
            
            // Sort the array to make duplicate skipping easier
            sort(nums.begin(), nums.end());

            // First loop
            for (int i = 0; i < n - 3; i++) {
                // Second loop
                for (int j = i + 1; j < n - 2; j++) {
                    int left = j + 1;
                    int right = int(n)- 1;

                    while (left < right) {
                        o3++;
                        long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                        if (sum == target) {
                            string key = createKey(nums[i], nums[j], nums[left], nums[right]);
                            // Only add unique quadruplets
                            if (seen.find(key) == seen.end()) {
                                result.push_back({nums[i], nums[j], nums[left], nums[right]});
                                seen.insert(key);
                            }
                            left++;
                            right--;
                        } else if (sum < target) {
                            left++; // Need a bigger sum
                        } else {
                            right--; // Need a smaller sum
                        }
                    }
                }
            }

            return result;
        }
    vector<vector<int>> fourSum2(vector<int>& nums, int target) {
        unordered_set<vector<int>, VectorHash> seen;
        vector<vector<int>> result;
        size_t n = nums.size();
        
        // Sort the array to make duplicate handling easier
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {
                int left = j + 1;
                int right = int(n)- 1;

                while (left < right) {
                    o2++;
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        vector<int> quad = {nums[i], nums[j], nums[left], nums[right]};
                        if (seen.find(quad) == seen.end()) {
                            result.push_back(quad);
                            seen.insert(quad);
                        }
                        left++;
                        right--;
                    } else if (sum < target) {
                        left++; // Need a bigger sum
                    } else {
                        right--; // Need a smaller sum
                    }
                }
            }
        }

        return result;
    }
    vector<vector<int>> fourSum1(vector<int>& nums, int target) {
        vector<vector<int>> result;
        size_t n = nums.size();
        
        // Sort the array to make it easier to skip duplicates
        sort(nums.begin(), nums.end());

        // First loop for the first number
        for (int i = 0; i < n - 3; i++) {
            // Skip duplicates for the first number
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Second loop for the second number
            for (int j = i + 1; j < n - 2; j++) {
                // Skip duplicates for the second number
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int left = j + 1;
                int right = int(n)- 1;

                // Two pointers for the third and fourth numbers
                while (left < right) {
                    o1++;
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        // Found a valid quadruplet
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        // Move left and right to skip duplicates
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;

                        left++;
                        right--;
                    } else if (sum < target) {
                        left++; // Need a bigger sum
                    } else {
                        right--; // Need a smaller sum
                    }
                }
            }
        }
        
        return result;
    }
};

// Function to print the 2D vector nicely
void printResult(const vector<vector<int>>& quadruplets) {
    for (const auto& quad : quadruplets) {
        cout << "[";
        for (size_t i = 0; i < quad.size(); i++) {
            cout << quad[i];
            if (i < quad.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
}

vector<int> generateRandomArray() {
    srand((unsigned int)time(0)); // Seed the random number generator
    int size = rand() % 200 + 1; // Random size between 1 and 200
    vector<int> nums(size);

    for (int i = 0; i < size; ++i) {
        nums[i] = rand() % 401 - 200; // Random number between -200 and 200
    }

    return nums;
}
int demo_GroupSun() {
    Solution solution;

    // Example 1
    vector<int> nums1 = generateRandomArray();
    int target1 = 0;
    cout << "Example 1:" << endl;
    vector<vector<int>> result1 = solution.fourSum1(nums1, target1);
    printResult(result1);
    vector<vector<int>> result2 = solution.fourSum2(nums1, target1);
    printResult(result2);
    vector<vector<int>> result3 = solution.fourSum3(nums1, target1);
    printResult(result3);

//    // Example 2 doulicates
//    vector<int> nums2 = {1, 0, -1, 0, -2, 2, 3, 6, -4, -5, 128, -127, 14, -13,2, 2, 2, 2, 2, 3, 6, -4, -5, 128, -127, 14, -13, 3, 6, -4, -5, 128, -127, 14, -13,
//        3, 6, -4, -5, 128, -127, 14, -13,3, 6, -4, -5, 128, -127, 14, -13};
//    int target2 = 8;
//    cout << "\nExample 2:" << endl;
//    vector<vector<int>> result = solution.fourSum1(nums2, target2);
//    printResult(result);
    solution.print_statistics();
    return 0;
}
/*
 array of all the unique quadruplets 
 */
