//
//  main.cpp
//  Longest Consecutive Sequence
//
//  Created by liang on 6/2/2020.
//  Copyright © 2020 liang. All rights reserved.
// https://leetcode.com/problems/longest-consecutive-sequence/
/**
 Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

 Your algorithm should run in O(n) complexity.

 Example:

 Input: [100, 4, 200, 1, 3, 2]
 Output: 4
 Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
 */

#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> numsSet;
        for (auto num : nums) {
            numsSet.insert(num);
        }
        
        int longestLength = 0;
        
        for (int num : numsSet) {
            auto it = numsSet.find(num - 1);
            if (it == numsSet.end()) {
                int currentNum = num;
                int currentLength = 1;
                
                while (numsSet.find(currentNum + 1) != numsSet.end()) {
                    currentNum += 1;
                    currentLength += 1;
                }
                
                longestLength = max(longestLength, currentLength);
            }
        }
        
        return longestLength;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    return 0;
}
