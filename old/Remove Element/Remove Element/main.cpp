//
//  main.cpp
//  Remove Element
//
//  Created by liang on 6/22/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  Problem: https://leetcode.com/problems/remove-element/
//Given an array and a value, remove all instances of that value in place and return the new length.
//
//The order of elements can be changed. It doesn't matter what you leave beyond the new length.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = (int)nums.size();
        for (int i = 0; i < size; i++) {
            while (i < size && nums[i] == val) {
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
    cout << s.removeElement(v1, 1) << endl;
    
    int case2[] = {};
    vector<int> v2(case2, case2 + sizeof(case2) / sizeof(int));
    cout << s.removeElement(v2, 1) << endl;
    
    int case3[] = {1,1,1};
    vector<int> v3(case3, case3 + sizeof(case3) / sizeof(int));
    cout << s.removeElement(v3, 1) << endl;
    
    return 0;
}
