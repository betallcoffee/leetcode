//
//  main.cpp
//  Search in Rotated Sorted Array
//
//  Created by liang on 6/27/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  Problem: https://leetcode.com/problems/search-in-rotated-sorted-array/
//Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//You are given a target value to search. If found in the array return its index, otherwise return -1.
//
//You may assume no duplicate exists in the array.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ret = -1;
        
        int index = -1;
        int size = (int)nums.size();
        for (int i = 1; i < size; i++) {
            if (nums[i] < nums[i - 1]) {
                index = i;
                break;
            }
        }
        
        int left = 0;
        int right = size;
        if (index != -1) {
            if (target >= nums[0]) {
                right = index;
            }
            else {
                left = index;
            }
        }
        
        while (left < right) {
            int mid = (left + right) / 2;
            if (target == nums[mid]) {
                ret = mid;
                break;
            } else if (target < nums[mid]) {
                right = mid;
            } else if (target > nums[mid]) {
                left = mid + 1;
            }
        }
        
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    int case1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v1(case1, case1 + sizeof(case1) / sizeof(int));
    cout << s.search(v1, 3) << endl;
    
    int case2[] = {4, 5, 6, 7, 0, 1, 2};
    vector<int> v2(case2, case2 + sizeof(case2) / sizeof(int));
    cout << s.search(v2, 6) << endl;
    
    return 0;
}
