//
//  main.cpp
//  Longest Common Prefix
//
//  Created by liang on 6/21/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  Problem: https://leetcode.com/problems/longest-common-prefix/
//Write a function to find the longest common prefix string amongst an array of strings. 


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        int len = longestCommonPrefixLen(strs);
        return strs[0].substr(0, len);
    }
    
    int longestCommonPrefixLen(vector<string>& strs) {
        int len = 0;
        int size = (int)strs.size();
        do {
            if (strs[0].size() <= len) {
                return len;
            }
            int c = strs[0][len];
            for (int i = 1; i < size; i++) {
                if (c != strs[i][len]) {
                    return len;
                }
                if (strs[i].size() <= len) {
                    return len;
                }
            }
            len++;
        } while (true);
        return len;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    string case21 = "";
    vector<string> strs2;
    strs2.push_back(case21);
    cout << s.longestCommonPrefix(strs2) << endl;
    
    string case11 = "abbcd";
    string case12 = "abbcdaadsreg";
    string case13 = "abbdahga";
    vector<string> strs1;
    strs1.push_back(case11);
    strs1.push_back(case12);
    strs1.push_back(case13);
    cout << s.longestCommonPrefix(strs1) << endl;
    
    return 0;
}
