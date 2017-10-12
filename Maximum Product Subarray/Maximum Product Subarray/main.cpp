//
//  main.cpp
//  Maximum Product Subarray
//
//  Created by liang on 12/10/17.
//  Copyright © 2017年 liang. All rights reserved.
//  https://leetcode.com/problems/maximum-subarray/description/
/**
 Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 
 For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
 the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 
 More practice:
 If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int nmax = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            nmax = max(nmax + nums[i], nums[i]);
        }
        return nmax;
    }
};

void test1() {
    Solution s;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    printf("%d\n", s.maxSubArray(nums));
}

int main(int argc, const char * argv[]) {
    test1();
    return 0;
}
