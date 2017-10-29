//
//  main.cpp
//  Subsets II
//
//  Created by liang on 29/10/17.
//  Copyright © 2017年 liang. All rights reserved.
//  https://leetcode.com/problems/subsets-ii/description/
/**
 Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
 
 Note: The solution set must not contain duplicate subsets.
 
 For example,
 If nums = [1,2,2], a solution is:
 
 [
 [2],
 [1],
 [1,2,2],
 [2,2],
 [1,2],
 []
 ]
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> sets = {{}};
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); ) {
            int count = 0;
            while (count + i < nums.size() && nums[i] == nums[i + count]) {
                count++;
            }
            
            int size = sets.size();
            for (int j = 0; j < size; j++) {
                vector<int> set = sets[j];
                for (int k = 0; k < count; k++) {
                    set.push_back(nums[i]);
                    sets.push_back(set);
                }
            }
            
            i += count;
        }
        
        return sets;
    }
    
    void printfVV(vector<vector<int>> &sets) {
        for_each(sets.begin(), sets.end(), [&](vector<int> &nums) {
            for_each(nums.begin(), nums.end(), [&](int num) {
                printf("%d ", num);
            });
            printf("\n");
        });
    }
};

void test1() {
    Solution s;
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> sets = s.subsetsWithDup(nums);
    s.printfVV(sets);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    test1();
    return 0;
}
