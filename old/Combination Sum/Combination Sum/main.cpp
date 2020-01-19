//
//  main.cpp
//  Combination Sum
//
//  Created by liang on 7/1/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  Problem: https://leetcode.com/problems/combination-sum/
//Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
//
//The same repeated number may be chosen from C unlimited number of times.
//
//Note:
//
//All numbers (including target) will be positive integers.
//Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
//The solution set must not contain duplicate combinations.
//
//For example, given candidate set 2,3,6,7 and target 7,
//A solution set is:
//[7]
//[2, 2, 3]

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> com;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, 0, com, ret);
        return ret;
    }
    
    void dfs(vector<int> &candidates, int target, int sum, int last, vector<int> &com, vector<vector<int>> &ret) {
        int size = (int)candidates.size();
        for (int i = last; i < size; i++) {
            int can = candidates[i];
            if (can + sum == target) {
                com.push_back(can);
                ret.push_back(com);
                com.pop_back();
            } else if (can + sum < target) {
                com.push_back(can);
                dfs(candidates, target, can + sum, i, com, ret);
                com.pop_back();
            } else {
                break;
            }
        }
    }
};

void printVector(vector<vector<int>> vv) {
    for_each(vv.begin(), vv.end(), [](vector<int> v){
        for_each(v.begin(), v.end(), [](int n) {
           cout << n << " ";
        });
        cout << endl;
    });
    cout << endl;
}

int main(int argc, const char * argv[]) {
    Solution s;
    
    int case1[] = {2, 3, 6, 7};
    vector<int> v1(case1, case1 + sizeof(case1)/sizeof(int));
    printVector(s.combinationSum(v1, 7));
    
    int case2[] = {8, 7, 4, 3};
    vector<int> v2(case2, case2 + sizeof(case2)/sizeof(int));
    printVector(s.combinationSum(v2, 11));
    
    return 0;
}
