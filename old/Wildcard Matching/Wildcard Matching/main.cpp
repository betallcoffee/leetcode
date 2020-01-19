//
//  main.cpp
//  Wildcard Matching
//
//  Created by liang on 8/2/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  Problem: https://leetcode.com/problems/wildcard-matching/
//Implement wildcard pattern matching with support for '?' and '*'.
//
//'?' Matches any single character.
//'*' Matches any sequence of characters (including the empty sequence).
//
//The matching should cover the entire input string (not partial).
//
//The function prototype should be:
//bool isMatch(const char *s, const char *p)
//
//Some examples:
//isMatch("aa","a") → false
//isMatch("aa","aa") → true
//isMatch("aaa","aa") → false
//isMatch("aa", "*") → true
//isMatch("aa", "a*") → true
//isMatch("ab", "?*") → true
//isMatch("aab", "c*a*b") → false

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        string::iterator siter = s.begin();
        string::iterator piter = p.begin();
        string::iterator nsiter = s.end();
        string::iterator npiter = p.end();
        
        while (siter != s.end()) {
            char sc = *siter;
            char pc = *piter;
            if (pc == '?' || pc == sc) {
                siter++;
                piter++;
            } else if (pc == '*') {
                do {
                    piter++;
                } while (piter != p.end() && *piter == '*');
                
                while (siter != s.end() && piter != p.end() &&  *piter != '?' && *siter != *piter) {
                    siter++;
                }
                
                nsiter = siter;
                npiter = piter;
            } else if (nsiter != s.end()) {
                siter = nsiter + 1;
                piter = npiter;
                while (siter != s.end() && piter != p.end() &&  *piter != '?' && *siter != *piter) {
                    siter++;
                }
                nsiter = siter;
            } else {
                return false;
            }
        }
        
        while (piter != p.end() && *piter == '*') {
            piter++;
        }
        
        if (siter == s.end() && piter == p.end()) {
            return true;
        }
        
        return false;
    }
    
//    bool isMatch(string s, string p) {
//        bool ret = false;
//        ret = dfs(s, s.begin(), p, p.begin());
//        return ret;
//    }
    
    bool dfs(const string &s, string::iterator siter, const string &p, string::iterator piter) {
        if (siter == s.end() && piter == p.end()) {
            return true;
        } else if (siter == s.end() || piter == p.end()) {
            return false;
        }
        
        char sc = *siter;
        char pc = *piter;
        if (pc == '?' || pc == sc) {
            return dfs(s, siter + 1, p, piter + 1);
        } else if (pc == '*') {
            do {
                piter++;
            } while (piter != p.end() && *piter == '*');
            bool ret = true;
            int i = -1;
            string::const_iterator end = s.end();
            do {
                i++;
                ret = dfs(s, siter + i, p, piter);
            } while(!ret && siter + i != end);
            return ret;
        }
        
        return false;
    }
};

//isMatch("aa","aa") → true
//isMatch("aaa","aa") → false
//isMatch("aa", "*") → true
//isMatch("aa", "a*") → true
//isMatch("ab", "?*") → true
//isMatch("aab", "c*a*b") → false

int main(int argc, const char * argv[]) {
    Solution s;
    
    // 1
    cout << "5: " << s.isMatch("hi", "*?") << endl;
    
    // 1
    cout << "4: " << s.isMatch("", "*") << endl;
    
    // 0
    cout << "3: " << s.isMatch("abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb", "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb") << endl;
    
    // 0
    cout << "2: " << s.isMatch("babbbbaabababaabbababaababaabbaabababbaaababbababaaaaaabbabaaaabababbabbababbbaaaababbbabbbbbbbbbbaabbb", "b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a") << endl;
    
    // 0
    cout << "1: " << s.isMatch("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", "a*******b") << endl;
    
    // 0
    cout << s.isMatch("b", "*?*?") << endl;
    
    // 0
    cout << s.isMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*c") << endl;
    
    // 1
    cout << s.isMatch("aab", "?*a*b") << endl;
    
    // 0
    cout << s.isMatch("aaa", "aa") << endl;
    
    // 1
    cout << s.isMatch("aa", "*") << endl;
    
    // 0
    cout << s.isMatch("aa", "a") << endl;
    
    // 1
    cout << s.isMatch("aa", "aa") << endl;
    
    // 1
    cout << s.isMatch("aa", "a*") << endl;
    
    // 1
    cout << s.isMatch("ab", "?*") << endl;
    
    // 0
    cout << s.isMatch("aab", "c*a*b") << endl;
    
    return 0;
}
