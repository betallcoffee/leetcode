//
//  main.cpp
//  3Sum Closest
//
//  Created by liang on 6/21/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  Problem: https://leetcode.com/problems/3sum-closest/
//Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
//
//For example, given array S = {-1 2 1 -4}, and target = 1.
//
//The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int size = (int)nums.size();
        int diff = INT_MAX;
        int result = 0;
        for (int i = 0; i < size; i++) {
            while (i < size && i > 0 && nums[i] == nums[i - 1]) {
                i++;
            }
            int left = i + 1;
            int right = size - 1;
            while (left < size && right >= 0 && left < right) {
                int d = nums[i] + nums[left] + nums[right] - target;
                d = d > 0 ? d : -d;
                if (d < diff) {
                    result = nums[i] + nums[left] + nums[right];
                    diff = d;
                }
                if (nums[i] + nums[left] + nums[right] < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    int case1[] = {-1, 2, 1, -4};
    vector<int> v1(case1, case1 + sizeof(case1)/sizeof(int));
    cout << s.threeSumClosest(v1, 1) << endl;
    
    int case2[] = {0, 2, 1, -3};
    vector<int> v2(case2, case2 + sizeof(case2)/sizeof(int));
    cout << s.threeSumClosest(v2, 1) << endl;
    
    int case3[] = {1,1,-1,-1,3};
    vector<int> v3(case3, case3 + sizeof(case3)/sizeof(int));
    cout << s.threeSumClosest(v3, -1) << endl;
    
    return 0;
}
