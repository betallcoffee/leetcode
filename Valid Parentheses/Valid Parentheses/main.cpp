//
//  main.cpp
//  Valid Parentheses
//
//  Created by liang on 6/22/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  Problem: https://leetcode.com/problems/valid-parentheses/
//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
//The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for_each(s.begin(), s.end(), [&](char c) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            } else if (stack.empty()) {
                stack.push(c);
            } else {
                char t = stack.top();
                if (c == ')' && t == '(') {
                    stack.pop();
                } else if (c == ']' && t== '[') {
                    stack.pop();
                } else if (c == '}' && t == '{') {
                    stack.pop();
                } else {
                    stack.push(c);
                }
            }
        });
        if (stack.empty()) {
            return true;
        } else {
            return false;
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    cout << s.isValid("()[]{}") << endl;
    
    cout << s.isValid("([)]") << endl;
    
    return 0;
}
