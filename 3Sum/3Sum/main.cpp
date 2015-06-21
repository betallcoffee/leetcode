//
//  main.cpp
//  3Sum
//
//  Created by liang on 6/21/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  Problem: https://leetcode.com/problems/3sum/
//Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
//Note:
//
//Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
//The solution set must not contain duplicate triplets.
//
//For example, given array S = {-1 0 1 2 -1 -4},
//
//A solution set is:
//(-1, 0, 1)
//(-1, -1, 2)


#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = (int)nums.size();
        vector<vector<int>> result;
        vector<int> triplet;
        for (int i = 0; i < size; i++) {
            while (i < size && i > 0 && nums[i] == nums[i - 1]) {
                i++;
            }
            int left = i + 1;
            int right = size - 1;
            while (left < size && right >= 0 && left < right) {
                if (nums[i] + nums[left] + nums[right] == 0) {
                    triplet.push_back(nums[i]);
                    triplet.push_back(nums[left]);
                    triplet.push_back(nums[right]);
                    result.push_back(triplet);
                    triplet.clear();
                    do {
                        left++;
                    } while (left < right && nums[left] == nums[left-1]);
                    do {
                        right--;
                    } while (right > left && nums[right] == nums[right + 1]);
                } else if (nums[i] + nums[left] + nums[right] < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return result;
    }
};

void printVector(vector<vector<int>> solution) {
    for_each(solution.begin(), solution.end(), [](vector<int> v) {
        cout << '(';
        for_each(v.begin(), v.end(), [](int n) {
            cout << n << ',';
        });
        cout << ')' << endl;
    });
}

int main(int argc, const char * argv[]) {
    Solution s;
    
    int case5[] = {0, 0, 0};
    vector<int> v5(case5, case5 + sizeof(case5) / sizeof(int));
    printVector(s.threeSum(v5));
    
    int case1[] = {-1, 0, 1, 2, -1, -4};
    vector<int> v1(case1, case1 + sizeof(case1) / sizeof(int));
    printVector(s.threeSum(v1));
    
    int case2[] = {-1,-12,14,-6,4,-11,2,-7,13,-15,-1,11,-15,-15,13,-9,-11,-10,-7,-13,7,9,-13,-3,10,1,-5,12,11,-9,2,-4,-6,-7,5,5,-2,14,13,-12,14,-3,14,14,-11,5,12,-6,10,-9,-4,-6,-15,-9,-1,2,-1,9,-9,-5,-15,8,-2,-6,9,10,7,14,9,5,-13,9,-12,8,8,-8,-2,-2,1,-15,-4,5,-13,-4,3,1,5,-13,-13,11,-11,10,5,3,11,-9,-2,3,-10,-7,-6,14,9,-11,7,2,-4,13,7,5,13,-12,-13,7,-9,5,-7,11,-1,-12,8,3,13,-10,13,1,-4};
    
    vector<int> v2(case2, case2 + sizeof(case2) / sizeof(int));
//    printVector(s.threeSum(v2));
    
    int case3[] = {-5,1,-10,2,-7,-13,-3,-8,2,-15,9,-3,-15,13,-6,-10,5,6,11,1,13,-12,14,6,11,4,13,-14,0,11,1,10,-11,6,-11,-10,8,2,-3,-13,-6,-9,-9,-6,11,-8,-9,1,13,9,9,3,13,0,-6,1,-10,-15,3,5,3,11,-8,0,2,-11,5,-13,6,9,-11,7,8,-13,8,4,-6,14,13,-15,1,7,-5,-1,-7,5,7,-2,-3,-13,10,7,13,9,-8,-8,13,12,-6,4,7,-10,-12,-8,-8,11,11,-6,3,9,-14,-11,2,-4,-5,10,8,-13,-7,12,-10,10};
    vector<int> v3(case3, case3 + sizeof(case3) / sizeof(int));
//    printVector(s.threeSum(v3));
    
    int case4[] = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
    vector<int> v4(case4, case4 + sizeof(case4) / sizeof(int));
//    printVector(s.threeSum(v4));
    
    return 0;
}
