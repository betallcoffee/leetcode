//
//  main.cpp
//  Longest Increasing Subsequence
//
//  Created by liang on 6/2/2020.
//  Copyright © 2020 liang. All rights reserved.
// https://leetcode.com/problems/longest-increasing-subsequence/
/**
 Given an unsorted array of integers, find the length of longest increasing subsequence.

 Example:

 Input: [10,9,2,5,3,7,101,18]
 Output: 4
 Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
 Note:

 There may be more than one LIS combination, it is only necessary for you to return the length.
 Your algorithm should run in O(n2) complexity.
 Follow up: Could you improve it to O(n log n) time complexity?
 */

#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        vector<int> lisList;
        for (auto num : nums) {
            auto it = lower_bound(lisList.begin(), lisList.end(), num);
            if (it == lisList.end()) {
                lisList.push_back(num);
            } else {
                *it = num;
            }
        }
        
        return static_cast<int>(lisList.size());
    }
};

void test0() {
    vector<int> nums = {10,9,2,5,3,7,101,18};
    Solution s;
    cout << "test0 expected 4: " << s.lengthOfLIS(nums) << endl;
}

void test1() {
    vector<int> nums = {0};
    Solution s;
    cout << "test1 expected 1: " << s.lengthOfLIS(nums) << endl;
}

void test2() {
    vector<int> nums = {-2,-1};
    Solution s;
    cout << "test2 expected 2: " << s.lengthOfLIS(nums) << endl;
}

void test3() {
    vector<int> nums = {10,9,2,5,3,4};
    Solution s;
    cout << "test3 expected 3: " << s.lengthOfLIS(nums) << endl;
}

void test4() {
    vector<int> nums = {3,5,6,2,5,4,19,5,6,7,12};
    Solution s;
    cout << "test4 expected 6: " << s.lengthOfLIS(nums) << endl;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    test0();
    test1();
    test2();
    test3();
    test4();
    return 0;
}
