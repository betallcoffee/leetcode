//
//  main.cpp
//  First Missing Positive
//
//  Created by liang on 7/1/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  Problem: https://leetcode.com/problems/first-missing-positive/
//Given an unsorted integer array, find the first missing positive integer.
//
//For example,
//Given [1,2,0] return 3,
//and [3,4,-1,1] return 2.
//
//Your algorithm should run in O(n) time and uses constant space.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = (int)nums.size();

        for (int i = 0; i < size;) {
            int n = nums[i];
            if (n > 0 && n - 1 < size && n != nums[n - 1]) {
                nums[i] = nums[n - 1];
                nums[n - 1] = n;
                if (nums[i] == i + 1) {
                    i++;
                }
            } else {
                i++;
            }
        }
        
        int ret = size + 1;
        for (int i = 0; i < size; i++) {
            if (i + 1 != nums[i]) {
                ret = i + 1;
                break;
            }
        }
        
        return ret;
    }
    
    int firstMissingPositive(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(NULL==A || n<1)
            return 1;
        int pos=0;
        while(pos<n)
        {
            if(A[pos]>0 && A[pos] != pos+1 && A[pos]-1<n && A[pos]!=A[A[pos]-1])
            {
                swap(A[pos],A[A[pos]-1]);
            }
            else
                ++pos;
        }
        for(int i=0;i<n;++i)
        {
            if(i+1 != A[i])
                return i+1;
        }
        return n+1;
    }
    void swap(int &a,int &b)
    {
        int tmp = a;
        a = b;
        b= tmp;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    int case7[] = {0,2,2,1,1};
    vector<int> v7(case7, case7 + sizeof(case7)/sizeof(int));
    cout << s.firstMissingPositive(v7) << endl;
    cout << s.firstMissingPositive(case7, 5) << endl;
    
    int case6[] = {-10,-3,-100,-1000,-239,1};
    vector<int> v6(case6, case6 + sizeof(case6)/sizeof(int));
    cout << s.firstMissingPositive(v6) << endl;
    
    int case5[] = {2, 2, 2, 2, 2};
    vector<int> v5(case5, case5 + sizeof(case5)/sizeof(int));
    cout << s.firstMissingPositive(v5) << endl;
//    cout << s.firstMissingPositive(case5, 5) << endl;
    
    int case4[] = {3, 4, -1, 1};
    vector<int> v4(case4, case4 + sizeof(case4)/sizeof(int));
    cout << s.firstMissingPositive(v4) << endl;
    
    int case3[] = {2,2};
    vector<int> v3(case3, case3 + sizeof(case3)/sizeof(int));
    cout << s.firstMissingPositive(v3) << endl;
    
    int case2[] = {};
    vector<int> v2(case2, case2 + sizeof(case2)/sizeof(int));
    cout << s.firstMissingPositive(v2) << endl;
    
    int case1[] = {1,1};
    vector<int> v1(case1, case1 + sizeof(case1)/sizeof(int));
    cout << s.firstMissingPositive(v1) << endl;
    
    return 0;
}
