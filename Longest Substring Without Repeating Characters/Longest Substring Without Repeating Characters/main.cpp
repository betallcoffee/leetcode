//
//  main.cpp
//  Longest Substring Without Repeating Characters
//
//  Created by liang on 6/15/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  Problem: https://leetcode.com/problems/longest-substring-without-repeating-characters/
//Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        int preLength = 0;
        int index = 0;
        map<char, int> isExist;
        for_each(s.begin(), s.end(), [&](char c){
            const map<char, int>::iterator iter = isExist.find(c);
            int length = 0;
            if (iter == isExist.end()) {
                length = preLength + 1;
                isExist[c] = index;
            } else {
                length = index - isExist[c];
                length = length < preLength + 1 ? length : preLength + 1;
                isExist[c] = index;
            }
            result = result > length ? result : length;
            preLength = length;
            index++;
        });
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    string case1 = "abcabcbb";
    cout << s.lengthOfLongestSubstring(case1) << endl;
    
    string case2 = "bbbbb";
    cout << s.lengthOfLongestSubstring(case2) << endl;
    
    string case3 = "abcabcdbb";
    cout << s.lengthOfLongestSubstring(case3) << endl;
    
    string case4 = "abba";
    cout << s.lengthOfLongestSubstring(case4) << endl;
    
    return 0;
}
