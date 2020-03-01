//
//  main.cpp
//  Find the Duplicate Number
//
//  Created by liang on 1/3/2020.
//  Copyright © 2020 liang. All rights reserved.
// https://leetcode.com/problems/find-the-duplicate-number/
/**
 Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

 Example 1:

 Input: [1,3,4,2,2]
 Output: 2
 Example 2:

 Input: [3,1,3,4,2]
 Output: 3
 Note:

 You must not modify the array (assume the array is read only).
 You must use only constant, O(1) extra space.
 Your runtime complexity should be less than O(n2).
 There is only one duplicate number in the array, but it could be repeated more than once.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        do {
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
        } while (slow != fast);
        
        slow = 0;
        do {
            slow = nums[slow];
            fast = nums[fast];
        } while (slow != fast);
        
        return slow;
    }
};

void test0() {
    Solution s;
    vector<int> nums = {1,3,4,2,2};
    cout << s.findDuplicate(nums) << endl;
}

void test1() {
    Solution s;
    vector<int> nums = {3,1,3,4,2};
    cout << s.findDuplicate(nums) << endl;
}

void test2() {
    Solution s;
    vector<int> nums = {2,5,9,6,9,3,8,9,7,1};
    cout << s.findDuplicate(nums) << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    test0();
    test1();
    test2();
    return 0;
}
