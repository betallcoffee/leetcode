//
//  main.cpp
//  Search for Range
//
//  Created by liang on 6/27/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  https://leetcode.com/problems/search-for-a-range/
//Given a sorted array of integers, find the starting and ending position of a given target value.
//
//Your algorithm's runtime complexity must be in the order of O(log n).
//
//If the target is not found in the array, return [-1, -1].
//
//For example,
//Given [5, 7, 7, 8, 8, 10] and target value 8,
//return [3, 4].

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret;
        int index = 0;
        
        int size = (int)nums.size();
        if (size <= 0) {
            ret.push_back(-1);
            ret.push_back(-1);
            return ret;
        }
        int left = 0;
        int right = size - 1;
        int mid = (left + right) / 2;
        
        while (left <= right) {
            mid = (left + right) / 2;
            if (target == nums[mid]) {
                index = mid;
                right = mid - 1;
            } else if (target < nums[mid]) {
                right = mid - 1;
            } else if (target > nums[mid]) {
                left = mid + 1;
            }
        }
        if (nums[index] == target) {
            ret.push_back(index);
        } else {
            ret.push_back(-1);
            ret.push_back(-1);
            return ret;
        }
        
        left = 0;
        right = size - 1;
        mid = (left + right) / 2;
        
        while (left <= right) {
            mid = (left + right) / 2;
            if (target == nums[mid]) {
                index = mid;
                left = mid + 1;
            } else if (target < nums[mid]) {
                right = mid - 1;
            } else if (target >= nums[mid]) {
                left = mid + 1;
            }
        }
        ret.push_back(index);
        
        return ret;
    }
};

void printVector(vector<int> nums) {
    for_each(nums.begin(), nums.end(), [](int n) {
        cout << n << " ";
    });
    cout << endl;
}

int main(int argc, const char * argv[]) {
    Solution s;
    
    int case3[] = {2, 2};
    vector<int> v3(case3, case3 + sizeof(case3) / sizeof(int));
    printVector(s.searchRange(v3, 2));
    
    int case1[] = {0, 1, 2, 3, 3, 3, 3, 7, 8, 9};
    vector<int> v1(case1, case1 + sizeof(case1) / sizeof(int));
    printVector(s.searchRange(v1, 3));
    
    int case2[] = {4, 5, 6, 6, 8, 8, 8, 9, 9, 10};
    vector<int> v2(case2, case2 + sizeof(case2) / sizeof(int));
    printVector(s.searchRange(v2, 8));
    
    return 0;
}
