//
//  main.cpp
//  Remove Duplicates from Sorted Array
//
//  Created by liang on 6/22/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  Problem: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
//Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
//
//Do not allocate extra space for another array, you must do this in place with constant memory.
//
//For example,
//Given input array nums = [1,1,2],
//
//Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = (int)nums.size();
        for (int i = 0; i < size; i++) {
            while (i + 1 < size && nums[i + 1] == nums[i]) {
                nums.erase(nums.begin() + i);
                size = (int)nums.size();
            }
        }
        return (int)nums.size();
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    int case1[] = {1,1,2};
    vector<int> v1(case1, case1 + sizeof(case1) / sizeof(int));
    cout << s.removeDuplicates(v1) << endl;
    
    int case2[] = {};
    vector<int> v2(case2, case2 + sizeof(case2) / sizeof(int));
    cout << s.removeDuplicates(v2) << endl;
    
    int case3[] = {1,1,1};
    vector<int> v3(case3, case3 + sizeof(case3) / sizeof(int));
    cout << s.removeDuplicates(v3) << endl;
    
    return 0;
}
