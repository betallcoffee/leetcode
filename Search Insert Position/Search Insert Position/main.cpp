//
//  main.cpp
//  Search Insert Position
//
//  Created by liang on 6/27/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  Problem: https://leetcode.com/problems/search-insert-position/
//Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
//
//You may assume no duplicates in the array.
//
//Here are few examples.
//[1,3,5,6], 5 → 2
//[1,3,5,6], 2 → 1
//[1,3,5,6], 7 → 4
//[1,3,5,6], 0 → 0

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ret = -1;
        
        int size = (int)nums.size();
        int left = 0;
        int right = size;
        int mid = 0;
        
        while (left < right) {
            mid = (left + right) / 2;
            if (nums[mid] == target) {
                ret = mid;
                break;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        if (ret == -1) {
            if (left < size && target < nums[left]) {
                ret = left;
            } else if (left < size && target > nums[left]) {
                ret = left + 1;
            } else if (left >= size) {
                ret = size;
            }
        }
        
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    int case1[] = {1, 3, 5, 6};
    vector<int> v1(case1, case1 + sizeof(case1) / sizeof(int));
    cout << s.searchInsert(v1, 5) << endl;
    cout << s.searchInsert(v1, 2) << endl;
    cout << s.searchInsert(v1, 7) << endl;
    cout << s.searchInsert(v1, 0) << endl;
    
    return 0;
}
