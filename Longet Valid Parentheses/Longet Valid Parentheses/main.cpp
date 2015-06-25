//
//  main.cpp
//  Longet Valid Parentheses
//
//  Created by liang on 6/24/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  Problem: https://leetcode.com/problems/longest-valid-parentheses/
//Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
//
//For "(()", the longest valid parentheses substring is "()", which has length = 2.
//
//Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> nums;
        stack<char> stack;
        int index = 0;
        for_each(s.begin(), s.end(), [&](char c) {
            if (')' == c && stack.size() > 0) {
                char top = stack.top();
                if ('(' == top) {
                    stack.pop();
                    nums.pop_back();
                    index++;
                    return;
                }
            }
            stack.push(c);
            nums.push_back(index);
            index++;
        });
        
        int max = 0;
        index = -1;
        for_each(nums.begin(), nums.end(), [&](int n) {
            int t = n - index - 1;
            max = max > t ? max : t;
            index = n;
        });
        int size = (int)s.size();
        if (index < size - 1) {
            int t = size - 1 - index;
            max = max > t ? max : t;
        }
       
        return max;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    cout << s.longestValidParentheses(")()())") << endl;
    
    cout << s.longestValidParentheses("()()") << endl;
    
    cout << s.longestValidParentheses("())()(") << endl;
    
    cout << s.longestValidParentheses("(()") << endl;
    
    cout << s.longestValidParentheses("()(()") << endl;
    
    return 0;
}
