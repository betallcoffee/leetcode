//
//  main.cpp
//  Length of Last Word
//
//  Created by liang on 12/10/17.
//  Copyright © 2017年 liang. All rights reserved.
//  https://leetcode.com/problems/length-of-last-word/description/
/**
 Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 
 If the last word does not exist, return 0.
 
 Note: A word is defined as a character sequence consists of non-space characters only.
 
 For example,
 Given s = "Hello World",
 return 5.
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int size = (int)s.size() - 1;
        for (; size >= 0; size--) {
            char c = s[size];
            if ('a' <= c && c <= 'z') {
                break;
            } else if ('A' <= c && c <= 'Z') {
                break;
            }
        }
        for (int i = size; i >= 0; i--) {
            char c = s[i];
            if ('a' <= c && c <= 'z') {
                len++;
            } else if ('A' <= c && c <= 'Z') {
                len++;
            } else {
                break;
            }
        }
        return len;
    }
};

void test1()  {
    Solution s;
    printf("%d\n", s.lengthOfLastWord("Hello World"));
}

void test2()  {
    Solution s;
    printf("%d\n", s.lengthOfLastWord("World  "));
}

int main(int argc, const char * argv[]) {
    test1();
    test2();
    return 0;
}
