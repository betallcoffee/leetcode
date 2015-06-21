//
//  main.cpp
//  Letter Combinations of a Phone Number
//
//  Created by liang on 6/21/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  Problem: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
//Given a digit string, return all possible letter combinations that the number could represent.
//
//A mapping of digit to letters (just like on the telephone buttons) is given below.
//
//Input:Digit string "23"
//Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//Note:
//Although the above answer is in lexicographical order, your answer could be in any order you want.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string table[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        string letters;
        dfs(digits, 0, table, letters, result);
        return result;
    }
    
    void dfs(string &digits, int index, string table[], string &letters, vector<string> &result) {
        if (index < digits.size()) {
            char c = digits[index];
            string str = table[c - '2'];
            for_each(str.begin(), str.end(), [&](char c) {
                letters.push_back(c);
                dfs(digits, index + 1, table, letters, result);
                letters.pop_back();
            });
        } else if (index != 0){
            result.push_back(letters);
        }
    }
};

void printVectorString(vector<string> v) {
    for_each(v.begin(), v.end(), [](string s){
        cout << s << endl;
    });
}

int main(int argc, const char * argv[]) {
    Solution s;
    
//    printVectorString(s.letterCombinations("23"));
    
    printVectorString(s.letterCombinations(""));

//    printVectorString(s.letterCombinations("23456789"));
    
    return 0;
}
