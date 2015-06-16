//
//  main.cpp
//  Median of Two Sorted Arrays
//
//  Created by liang on 6/16/15.
//  Copyright (c) 2015 tina. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merge;
        int i = 0;
        int j = 0;
        for (; i < nums1.size(); i++) {
            int a = nums1[i];
            for (; j < nums2.size(); j++) {
                int b = nums2[j];
                if (b < a) {
                    merge.push_back(b);
                } else {
                    break;
                }
            }
            merge.push_back(a);
        }
        for (; j < nums2.size(); j++) {
            merge.push_back(nums2[j]);
        }
        
        float k = merge.size() / 2.0;
        int nk = (int)k;
        if (nk < 1){
            return merge[0];
        } else if (nk == k) {
            return (merge[nk - 1] + merge[nk]) / 2.0;
        } else
        {
            return merge[nk];
        }
    }
};

vector<int> arrayToVector(int num[], int count) {
    return vector<int>(num, num + count);
}

int main(int argc, const char * argv[]) {
    Solution s;
    
    int case11[] = {1,3,4,5};
    int case12[] = {8, 9, 10, 22, 30, 40, 45};
    vector<int> nums11 = vector<int>(case11, case11 + sizeof(case11)/sizeof(int));
    vector<int> nums12 = vector<int>(case12, case12 + sizeof(case12)/sizeof(int));
    cout << s.findMedianSortedArrays(nums11, nums12) << endl;
    
    int case21[] = {1,3,4,5,7};
    int case22[] = {8, 9, 10, 22, 30, 40, 45};
    vector<int> nums21 = vector<int>(case21, case21 + sizeof(case21)/sizeof(int));
    vector<int> nums22 = vector<int>(case22, case22 + sizeof(case22)/sizeof(int));
    cout << s.findMedianSortedArrays(nums21, nums22) << endl;
    
    int case31[] = {};
    int case32[] = {1};
    vector<int> nums31 = vector<int>(case31, case31 + sizeof(case31)/sizeof(int));
    vector<int> nums32 = vector<int>(case32, case32 + sizeof(case32)/sizeof(int));
    cout << s.findMedianSortedArrays(nums31, nums32) << endl;
    
    int case41[] = {};
    int case42[] = {2, 3};
    vector<int> nums41 = vector<int>(case41, case41 + sizeof(case41)/sizeof(int));
    vector<int> nums42 = vector<int>(case42, case42 + sizeof(case42)/sizeof(int));
    cout << s.findMedianSortedArrays(nums41, nums42) << endl;
    
    return 0;
}
