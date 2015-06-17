//
//  main.cpp
//  Longest Palindromic Substring
//
//  Created by liang on 6/16/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  Problem: https://leetcode.com/problems/longest-palindromic-substring/
//Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string result;
        int ss = 0;
        int len = 0;
        int i = 0;
        int size = (int)s.size();
        for_each(s.begin(), s.end(), [&](char c){
            for (int j = 1; i - j >= 0 && i + j < size; j++) {
                int ccc = s[i-j];
                int cc = s[i+j];
                if (ccc == cc) {
                    if (len < 2*j + 1) {
                        ss = i - j;
                        len = 2*j + 1;
                    }
                } else {
                    break;
                }
            }
            
            for (int j = 1; i - j >= 0 && i + j - 1 < size; j++) {
                int ccc = s[i - j];
                int cc = s[i + j - 1];
                if (ccc == cc) {
                    if (len < 2*j) {
                        ss = i - j;
                        len = 2*j;
                    }
                } else {
                    break;
                }
            }
            
            for (int j = 1; i - j + 1 >= 0 && i + j < size; j++) {
                int ccc = s[i - j + 1];
                int cc = s[i + j];
                if (ccc == cc) {
                    if (len < 2*j) {
                        ss = i - j + 1;
                        len = 2*j;
                    }
                } else {
                    break;
                }
            }
            if (len == 0) {
                ss = 0;
                len = 1;
            }
            i++;
        });
        return s.substr(ss, len);
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    cout << s.longestPalindrome("bananas") << endl;
    
    cout << s.longestPalindrome("") << endl;
    
    cout << s.longestPalindrome("a") << endl;
    
    cout << s.longestPalindrome("aa") << endl;
    
    cout << s.longestPalindrome("aaa") << endl;
    
    cout << s.longestPalindrome("aaaa") << endl;
    
    cout << s.longestPalindrome("aaaaa") << endl;
    
    cout << s.longestPalindrome("aaaaaa") << endl;
    
    cout << s.longestPalindrome("aaaaaaa") << endl;
    
    cout << s.longestPalindrome("aaaaaaaa") << endl;
    
    cout << s.longestPalindrome("aaaaaaaaa") << endl;
    
    cout << s.longestPalindrome("aaaaaaaaaa") << endl;
    
    cout << s.longestPalindrome("abbaccd") << endl;
    
    cout << s.longestPalindrome("abdbaccd") << endl;
    
    cout << s.longestPalindrome("dbhadsfjabbajaadkfha") << endl;
    
    cout << s.longestPalindrome("dbhadsfjabdbajadadkfha") << endl;
    
    return 0;
}
