//
//  main.cpp
//  Scramble String
//
//  Created by liang on 9/12/17.
//  Copyright © 2017年 liang. All rights reserved.
//  https://leetcode.com/problems/scramble-string/description/
/**
 Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
 
 Below is one possible representation of s1 = "great":
 
 great
 /    \
 gr    eat
 / \    /  \
 g   r  e   at
 / \
 a   t
 To scramble the string, we may choose any non-leaf node and swap its two children.
 
 For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
 
 rgeat
 /    \
 rg    eat
 / \    /  \
 r   g  e   at
 / \
 a   t
 We say that "rgeat" is a scrambled string of "great".
 
 Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
 
 rgtae
 /    \
 rg    tae
 / \    /  \
 r   g  ta  e
 / \
 t   a
 We say that "rgtae" is a scrambled string of "great".
 
 Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        size_t len1 = s1.length();
        size_t len2 = s2.length();
        if (len1 != len2) {
            return false;
        }
        
        int t = 0;
        for (int i = 0; i < len1; i++) {
            t ^= s1[i];
            t ^= s2[i];
        }
        
        if (t) {
            return false;
        } else if (len1 == 1) {
            return true;
        }
        
        for (int i = 1; i < len1; i++) {
            if (isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i))) {
                return true;
            }
            if (isScramble(s1.substr(0,i), s2.substr(len2-i)) && isScramble(s1.substr(i), s2.substr(0,len2-i))) {
                return true;
            }
        }
        
        return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    Solution s;
    
    cout << s.isScramble("great", "") << endl;
    
    cout << s.isScramble("great", "rgtae") << endl;
    
    cout << s.isScramble("great", "rgeat") << endl;
    
    cout << s.isScramble("abb", "bab") << endl;
    
    cout << s.isScramble("abab", "aabb") << endl;
    
    return 0;
}
