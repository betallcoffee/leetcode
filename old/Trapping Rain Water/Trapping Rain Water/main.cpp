//
//  main.cpp
//  Trapping Rain Water
//
//  Created by liang on 7/20/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  Problem: https://leetcode.com/problems/trapping-rain-water/
//Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
//
//For example,
//Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
//
//
//The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) {
            return 0;
        }

        size_t size = height.size();
        int sum = 0;
        int maxIndex = -1;
        int secIndex = -1;
        for (int i = 0; i < size; i++) {
            if (maxIndex == -1) {
                maxIndex = i;
            } else if (height[maxIndex] <= height[i]) {
                secIndex = maxIndex;
                maxIndex = i;
            } else if (secIndex == -1) {
                secIndex = i;
            } else if (height[secIndex] <= height[i]) {
                secIndex = i;
            }
        }
        
        int left = maxIndex > secIndex ? secIndex : maxIndex;
        int right = maxIndex > secIndex ? maxIndex : secIndex;
        for (int i = left + 1; i < right; i++) {
            sum += height[secIndex] - height[i];
        }
        
        sum += calculateMaxLeft(height, 0, left + 1);
        sum += calculateMaxRight(height, right, (int)height.size());
        
        return sum;
    }
    
    int calculateMaxLeft(vector<int> &height, int left, int right) {
        if (left == right - 1) {
            return 0;
        }
        
        int sum = 0;
        int maxIndex = -1;
        int secIndex = -1;
        for (int i = left; i < right; i++) {
            if (maxIndex == -1) {
                maxIndex = i;
            } else if (height[maxIndex] <= height[i]) {
                secIndex = maxIndex;
                maxIndex = i;
            } else if (secIndex == -1) {
                secIndex = i;
            } else if (height[secIndex] <= height[i]) {
                secIndex = i;
            }
        }
        
        left = maxIndex > secIndex ? secIndex : maxIndex;
        right = maxIndex > secIndex ? maxIndex : secIndex;
        for (int i = left + 1; i < right; i++) {
            sum += height[secIndex] - height[i];
        }
        
        sum += calculateMaxLeft(height, 0, left + 1);
        
        return sum;
    }
    
    int calculateMaxRight(vector<int> &height, int left, int right) {
        if (left == right - 1) {
            return 0;
        }
        
        int sum = 0;
        int maxIndex = -1;
        int secIndex = -1;
        for (int i = left; i < right; i++) {
            if (maxIndex == -1) {
                maxIndex = i;
            } else if (height[maxIndex] <= height[i]) {
                secIndex = maxIndex;
                maxIndex = i;
            } else if (secIndex == -1) {
                secIndex = i;
            } else if (height[secIndex] <= height[i]) {
                secIndex = i;
            }
        }
        
        left = maxIndex > secIndex ? secIndex : maxIndex;
        right = maxIndex > secIndex ? maxIndex : secIndex;
        for (int i = left + 1; i < right; i++) {
            sum += height[secIndex] - height[i];
        }
        
        sum += calculateMaxRight(height, right, (int)height.size());
        
        return sum;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    // 0
    int case8[] = {0};
    vector<int> v8(case8, case8 + sizeof(case8)/sizeof(int));
    cout << s.trap(v8) << endl;
    
    // 23
    int case7[] = {5,5,1,7,1,1,5,2,7,6};
    vector<int> v7(case7, case7 + sizeof(case7)/sizeof(int));
    cout << s.trap(v7) << endl;
    
    // 9
    int case6[] = {4,2,0,3,2,5};
    vector<int> v6(case6, case6 + sizeof(case6)/sizeof(int));
    cout << s.trap(v6) << endl;
    
    // 14
    int case5[] = {5,2,1,2,1,5};
    vector<int> v5(case5, case5 + sizeof(case5)/sizeof(int));
    cout << s.trap(v5) << endl;
    
    // 1
    int case4[] = {5,4,1,2};
    vector<int> v4(case4, case4 + sizeof(case4)/sizeof(int));
    cout << s.trap(v4) << endl;
    
    // 6
    int case1[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> v1(case1, case1 + sizeof(case1)/sizeof(int));
    cout << s.trap(v1) << endl;
    
    // 6
    int case2[] = {0,1,0,2,2,1,0,1,3,2,1,2,1};
    vector<int> v2(case2, case2 + sizeof(case2)/sizeof(int));
    cout << s.trap(v2) << endl;
    
    // 6
    int case3[] = {1,0,2,1,0,1,3,2,1,2,1};
    vector<int> v3(case3, case3 + sizeof(case3)/sizeof(int));
    cout << s.trap(v3) << endl;
    
    return 0;
}
