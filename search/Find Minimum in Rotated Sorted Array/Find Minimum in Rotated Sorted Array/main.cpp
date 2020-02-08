//
//  main.cpp
//  Find Minimum in Rotated Sorted Array
//
//  Created by liang on 8/2/2020.
//  Copyright © 2020 liang. All rights reserved.
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
/**
 Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

 (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

 Find the minimum element.

 You may assume no duplicate exists in the array.

 Example 1:

 Input: [3,4,5,1,2]
 Output: 1
 Example 2:

 Input: [4,5,6,7,0,1,2]
 Output: 0
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        if (nums.size() == 1) {
            return nums[0];
        }
        
        if (nums.front() < nums.back()) {
            return nums[0];
        }
        
        size_t left = 0;
        size_t right = nums.size();
        while (left < right - 1) {
            size_t mid = (left + right) / 2;
            if (nums[0] < nums[mid]) {
                left = mid;
            } else {
                right = mid;
            }
        }
        
        return nums[right];
    }
};

void test0() {
    vector<int> nums = {4,5,6,7,0,1,2};
    Solution s;
    cout << "test0 expected 0: " << s.findMin(nums) << endl;
}

void test1() {
    vector<int> nums = {3,4,5,1,2};
    Solution s;
    cout << "test1 expected 1: " << s.findMin(nums) << endl;
}

void test2() {
    vector<int> nums = {3,4};
    Solution s;
    cout << "test1 expected 3: " << s.findMin(nums) << endl;
}

void test3() {
    vector<int> nums = {4,3};
    Solution s;
    cout << "test1 expected 3: " << s.findMin(nums) << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    test0();
    test1();
    test2();
    test3();
    return 0;
}
