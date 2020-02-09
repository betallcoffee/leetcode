//
//  main.cpp
//  Find Minimum in Rotated Sorted Array II
//
//  Created by liang on 8/2/2020.
//  Copyright © 2020 liang. All rights reserved.
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
/**
 Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

 (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

 Find the minimum element.

 The array may contain duplicates.

 Example 1:

 Input: [1,3,5]
 Output: 1
 Example 2:

 Input: [2,2,2,0,1]
 Output: 0
 Note:

 This is a follow up problem to Find Minimum in Rotated Sorted Array.
 Would allow duplicates affect the run-time complexity? How and why?
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
        size_t right = nums.size() - 1;
        while (left + 1 < right) {
            if (nums[left + 1] == nums[0]) {
                left++;
            } else {
                break;
            }
        }
        
        while (left < right) {
            if (nums[right] == nums[0]) {
                right--;
            } else {
                break;
            }
        }
        
        if (nums[left] < nums[right]) {
            return nums[0];
        }
        
        do {
            size_t mid = (left + right) / 2;
            if (nums[0] <= nums[mid]) {
                left = mid;
            } else {
                right = mid;
            }
        } while (left + 1 < right);
        
        if (nums[left] < nums[right]) {
            return nums[left];
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
    cout << "test2 expected 3: " << s.findMin(nums) << endl;
}

void test3() {
    vector<int> nums = {4,3};
    Solution s;
    cout << "test3 expected 3: " << s.findMin(nums) << endl;
}

void test4() {
    vector<int> nums = {1,3,5};
    Solution s;
    cout << "test4 expected 1: " << s.findMin(nums) << endl;
}

void test5() {
    vector<int> nums = {2,2,2,0,1};
    Solution s;
    cout << "test5 expected 0: " << s.findMin(nums) << endl;
}

void test6() {
    vector<int> nums = {1,1};
    Solution s;
    cout << "test6 expected 1: " << s.findMin(nums) << endl;
}

void test7() {
    vector<int> nums = {3,1,3,3};
    Solution s;
    cout << "test7 expected 1: " << s.findMin(nums) << endl;
}

void test8() {
    vector<int> nums = {1,2,1};
    Solution s;
    cout << "test8 expected 1: " << s.findMin(nums) << endl;
}

void test9() {
    vector<int> nums = {0,0,1,1,2,0};
    Solution s;
    cout << "test9 expected 0: " << s.findMin(nums) << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    test0();
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    return 0;
}
