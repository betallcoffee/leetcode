//
//  main.cpp
//  Jump Game
//
//  Created by liang on 12/10/17.
//  Copyright © 2017年 liang. All rights reserved.
//  https://leetcode.com/problems/jump-game/description/
/**
 Given an array of non-negative integers, you are initially positioned at the first index of the array.
 
 Each element in the array represents your maximum jump length at that position.
 
 Determine if you are able to reach the last index.
 
 For example:
 A = [2,3,1,1,4], return true.
 
 A = [3,2,1,0,4], return false.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = (int)nums.size();
        if (size == 1) {
            return true;
        }
        int maxPos = 0;
        for (int i = 0; i < size && maxPos >= i; i++) {
            int pos = i + nums[i];
            maxPos = max(pos, maxPos);
        }
        return maxPos >= size - 1;
    }
};

void test1() {
    Solution s;
    vector<int> nums = {2, 3, 1, 1, 4};
    printf("%d\n", s.canJump(nums));
}

void test2() {
    Solution s;
    vector<int> nums = {3, 2, 1, 0, 4};
    printf("%d\n", s.canJump(nums));
}

void test3() {
    Solution s;
    vector<int> nums = {2, 0, 0};
    printf("%d\n", s.canJump(nums));
}

int main(int argc, const char * argv[]) {
//    test1();
//    test2();
    test3();
    return 0;
}
