//
//  main.cpp
//  Merge Sorted Array
//
//  Created by liang on 1/11/17.
//  Copyright © 2017年 liang. All rights reserved.
//  https://leetcode.com/problems/merge-sorted-array/description/
/**
 Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 
 Note:
 You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
 */

#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.erase(nums1.begin()+m, nums1.end());
        nums2.erase(nums2.begin()+n, nums2.end());
        int left = 0;
        int right = (int)nums1.size();
        for (int i = 0; i < nums2.size(); i++) {
            int k = nums2[i];
            if (k < nums1.back()) {
                right = (int)nums1.size();
                int j = find(nums1, left, right, k);
                if (nums1[j] < k) {
                    nums1.insert(nums1.begin()+j+1, k);
                } else {
                    nums1.insert(nums1.begin()+j, k);
                }
                left = j;
            } else {
                nums1.push_back(k);
            }
        }
    }
    
    int find(vector<int>& nums, int left, int right, int value) {
        while (left < right) {
            int min = (left + right) / 2;
            if (nums[min] == value) {
                return min;
            } else if (nums[min] < value) {
                left = min + 1;
            } else if (nums[min] > value) {
                right = min - 1;
            }
        }
        return left;
    }
};

void test1() {
    vector<int> nums1 = {};
    vector<int> nums2 = {};
    Solution s;
    s.merge(nums1, (int)nums1.size(), nums2, (int)nums2.size());
    for_each(nums1.begin(), nums1.end(), [&](int n) {
        printf("%d ", n);
    });
    printf("\n");
}

void test2() {
    vector<int> nums1 = {1, 5, 6, 9, 10, 11};
    vector<int> nums2 = {2, 3, 7, 8, 12};
    Solution s;
    s.merge(nums1, (int)nums1.size(), nums2, (int)nums2.size());
    for_each(nums1.begin(), nums1.end(), [&](int n) {
        printf("%d ", n);
    });
    printf("\n");
}

void test3() {
    vector<int> nums1 = {0};
    vector<int> nums2 = {1};
    Solution s;
    s.merge(nums1, 0, nums2, (int)nums2.size());
    for_each(nums1.begin(), nums1.end(), [&](int n) {
        printf("%d ", n);
    });
    printf("\n");
}

void test4() {
    vector<int> nums1 = {1, 0};
    vector<int> nums2 = {2};
    Solution s;
    s.merge(nums1, 1, nums2, 1);
    for_each(nums1.begin(), nums1.end(), [&](int n) {
        printf("%d ", n);
    });
    printf("\n");
}

int main(int argc, const char * argv[]) {
    // insert code here...
    test1();
    
    test2();
    
    test3();
    
    test4();
    
    return 0;
}
