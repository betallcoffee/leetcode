//
//  main.cpp
//  Combination Sum II
//
//  Created by liang on 7/1/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  Problem: https://leetcode.com/problems/combination-sum-ii/
//Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
//
//Each number in C may only be used once in the combination.
//
//Note:
//
//All numbers (including target) will be positive integers.
//Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
//The solution set must not contain duplicate combinations.
//
//For example, given candidate set 10,1,2,7,6,1,5 and target 8,
//A solution set is:
//[1, 7]
//[1, 2, 5]
//[2, 6]
//[1, 1, 6]

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> com;
        map<vector<int>, bool> hash;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, 0, com, ret, hash);
        return ret;
    }
    
    void dfs(vector<int> &candidates, int target, int sum, int last, vector<int> &com, vector<vector<int>> &ret, map<vector<int>, bool> &hash) {
        int size = (int)candidates.size();
        for (int i = last; i < size; i++) {
            int can = candidates[i];
            if (can + sum == target) {
                com.push_back(can);
                map<vector<int>, bool>::iterator iter = hash.find(com);
                if (iter == hash.end()) {
                    ret.push_back(com);
                    hash[com] = true;
                }
                com.pop_back();
            } else if (can + sum < target) {
                com.push_back(can);
                dfs(candidates, target, can + sum, i+1, com, ret, hash);
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
    printVector(s.combinationSum2(v1, 7));
    
    int case2[] = {8, 7, 4, 3};
    vector<int> v2(case2, case2 + sizeof(case2)/sizeof(int));
    printVector(s.combinationSum2(v2, 11));
    
    int case3[] = {10,1,2,7,6,1,5};
    vector<int> v3(case3, case3 + sizeof(case3)/sizeof(int));
    printVector(s.combinationSum2(v3, 8));
    
    return 0;
}
