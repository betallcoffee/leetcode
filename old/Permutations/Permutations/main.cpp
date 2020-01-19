//
//  main.cpp
//  Permutations
//
//  Created by liang on 8/23/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  Problem: https://leetcode.com/problems/permutations/
//Given a collection of numbers, return all possible permutations.
//
//For example,
//[1,2,3] have the following permutations:
//[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

#include <iostream>
#include <vector>

using namespace std;

template <typename T, size_t n>
size_t sizeOfArray(T (&array)[n]) {
    return n;
}

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> all;
        sort(nums.begin(), nums.end());
        all.push_back(nums);
        vector<int>& pre = nums;
        bool ret;
        do {
            vector<int> next;
            ret = nextPermute(pre, next);
            if (ret) {
                all.push_back(next);
            }
            pre = next;
        } while (ret);
        return all;
    }
    
    bool nextPermute(vector<int>& nums, vector<int> &next) {
        size_t size = nums.size();
        size_t tailSize = invertTail(nums, next);
        if (size <= tailSize) {
            return false;
        } else {
            size_t sep = size - tailSize - 1;
            int num = nums[sep];
            int minIndex = -1;
            for (int i = 0; i < tailSize; i++) {
                if (next[i] > num && (minIndex == -1 || next[i] < next[minIndex])) {
                    minIndex = i;
                }
            }
            int temp = next[minIndex];
            next[minIndex] = num;
            next.insert(next.begin(), temp);
            next.insert(next.begin(), nums.begin(), nums.begin() + sep);
            return  true;
        }
    }
    
    size_t invertTail(vector<int> &nums, vector<int> &next) {
        size_t size = nums.size();
        int preIndex = -1;
        for (int i = (int)size - 1; i >= 0; i--) {
            if (preIndex == -1 || nums[preIndex] <= nums[i]) {
                preIndex = i;
                next.push_back(nums[i]);
            } else {
                break;
            }
        }
        return next.size();
    }
};

void print(vector<vector<int>> vv) {
    for_each(vv.begin(), vv.end(), [=](vector<int> v){
        for_each(v.begin(), v.end(), [=](int n){
           cout << n << " ";
        });
        cout << endl;
    });
}

int main(int argc, const char * argv[]) {
    Solution s;
    
    int nums5[] = {1, 1, 2};
    vector<int> v5(nums5, nums5 + sizeOfArray(nums5));
    print(s.permute(v5));
    
    int nums4[] = {0,-1,1};
    vector<int> v4(nums4, nums4 + sizeOfArray(nums4));
    print(s.permute(v4));
    
    int nums3[] = {1};
    vector<int> v3(nums3, nums3 + sizeOfArray(nums3));
    print(s.permute(v3));
    
    int nums2[] = {1, 2, 3};
    vector<int> v2(nums2, nums2 + sizeOfArray(nums2));
    print(s.permute(v2));
    
    return 0;
}
