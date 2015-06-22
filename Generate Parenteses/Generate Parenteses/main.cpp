//
//  main.cpp
//  Generate Parenteses
//
//  Created by liang on 6/22/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  Problem: https://leetcode.com/problems/generate-parentheses/
//Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
//
//For example, given n = 3, a solution set is:
//
//"((()))", "(()())", "(())()", "()(())", "()()()"

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string parenteses;
        dfs(parenteses, 2*n, 0, 0, result);
        return result;
    }
    
    void dfs(string &parenteses, int n, int left, int right, vector<string> &result) {
        if (n == 0) {
            result.push_back(parenteses);
            return;
        }
        if (left > right) {
            parenteses.push_back(')');
            dfs(parenteses, n - 1, left, right + 1, result);
            parenteses.pop_back();
        }
        if (n - 2 >= left - right) {
            parenteses.push_back('(');
            dfs(parenteses, n - 1, left + 1, right, result);
            parenteses.pop_back();
        }
    }
};

void printVector(vector<string> v) {
    for_each(v.begin(), v.end(), [](string s) {
        cout << s << endl;
    });
}

int main(int argc, const char * argv[]) {
    Solution s;
    
    printVector(s.generateParenthesis(3));
    
    printVector(s.generateParenthesis(4));
    
    return 0;
}
