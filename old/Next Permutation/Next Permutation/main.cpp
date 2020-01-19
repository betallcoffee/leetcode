//
//  main.cpp
//  Next Permutation
//
//  Created by liang on 6/23/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  Problem: https://leetcode.com/problems/next-permutation/
//Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
//
//If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
//
//The replacement must be in-place, do not allocate extra memory.
//
//Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
//1,2,3 → 1,3,2
//3,2,1 → 1,2,3
//1,1,5 → 1,5,1

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = (int)nums.size();
        
        for (int i = size - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                int left = i + 1;
                int right = size - 1;
                while (left < right) {
                    int t = nums[left];
                    nums[left] = nums[right];
                    nums[right] = t;
                    left++;
                    right--;
                }
                for (int j = i + 1; j < size; j++) {
                    if (nums[i] < nums[j]) {
                        int t = nums[i];
                        nums[i] = nums[j];
                        nums[j] = t;
                        return;
                    }
                }
            } else if (i == 0) {
                int left = i;
                int right = size - 1;
                while (left < right) {
                    int t = nums[left];
                    nums[left] = nums[right];
                    nums[right] = t;
                    left++;
                    right--;
                }
                return;
            }
        }
    }
};

void printVector(vector<int> &nums) {
    for_each(nums.begin(), nums.end(), [](int num) {
        cout << num << " ";
    });
    cout << endl;
}

int main(int argc, const char * argv[]) {
    Solution s;
    
    int case2[] = {3, 2, 1};
    vector<int> v2(case2, case2 + sizeof(case2) / sizeof(int));
    s.nextPermutation(v2);
    printVector(v2);
    
    int case1[] = {1, 3, 2};
    vector<int> v1(case1, case1 + sizeof(case1) / sizeof(int));
    s.nextPermutation(v1);
    printVector(v1);
    
    return 0;
}
