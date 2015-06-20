//
//  main.cpp
//  Regular Expression Matching
//
//  Created by liang on 6/20/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  Problem: https://leetcode.com/problems/regular-expression-matching/
//Implement regular expression matching with support for '.' and '*'.
//
//'.' Matches any single character.
//'*' Matches zero or more of the preceding element.
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
//isMatch("aa", "a*") → true
//isMatch("aa", ".*") → true
//isMatch("ab", ".*") → true
//isMatch("aab", "c*a*b") → true


#include <iostream>

using namespace std;

class Solution {
public:
    struct node {
        struct node *next;
        struct node *pre;
        char val;
        bool isAny;
        bool isZeroOrMore;
    };
    
    bool isMatch(string s, string p) {
        struct node head;
        struct node *t = &head;
        t->next = nullptr;
        for_each(p.begin(), p.end(), [&](char c) {
            if (c == '.') {
                t->next = (struct node*)calloc(sizeof(struct node), 1);
                t->next->pre = t;
                t = t->next;
                t->val = c;
                t->isAny = true;
                t->isZeroOrMore = false;
            } else if (c == '*') {
                t->isZeroOrMore = true;
            } else {
                t->next = (struct node*)calloc(sizeof(struct node), 1);
                t->next->pre = t;
                t = t->next;
                t->val = c;
                t->isAny = false;
                t->isZeroOrMore = false;
            }
        });
        
        return dfs(s, 0, head.next);
    }
    
    bool dfs(string s, int index, struct node *p) {
        if (index == s.size() && p == nullptr) {
            return true;
        } else if (p == nullptr) {
            return false;
        } else if (index == s.size()) {
            while (p) {
                if (!p->isZeroOrMore) {
                    return false;
                }
                p = p->next;
            }
            return true;
        }
        
        char c = s[index];
        if (p->isZeroOrMore) {
            while (p->isAny || c == p->val) {
                if (dfs(s, index, p->next)) {
                    return true;
                } else {
                    index++;
                    if (index < s.size()) c = s[index];
                    else break;
                }
            }
            return dfs(s, index, p->next);
        } else if (p->isAny || c == p->val) {
            return dfs(s, index + 1, p->next);
        } else {
            return false;
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    cout << s.isMatch("", "") << endl;
    
    cout << s.isMatch("", "") << endl;
    
    cout << s.isMatch("a", "ab*") << endl;
    
    cout << s.isMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*c") << endl;
    
    cout << s.isMatch("aab", ".*a*b") << endl;
    
    cout << s.isMatch("aab", "a*a*b") << endl;
    
    cout << s.isMatch("aab", "c*a*b") << endl;
    
    cout << s.isMatch("aa", "a*") << endl;
    
    cout << s.isMatch("aa", "a") << endl;
    
    cout << s.isMatch("aa", "aa") << endl;
    
    cout << s.isMatch("aaa", "aa") << endl;
    
    return 0;
}
