//
//  main.cpp
//  Implement strStr
//
//  Created by liang on 6/22/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  Problem: https://leetcode.com/problems/implement-strstr/
//Implement strStr().
//
//Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
//
//Update (2014-11-02):
//The signature of the function had been updated to return the index instead of the pointer. If you still see your function signature returns a char * or String, please click the reload button to reset your code definition.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> next;
        next.push_back(0);
        int size = (int)needle.size();
        for (int i = 1; i < size; i++) {
            int j = next[i - 1];
            if (needle[j] == needle[i]) {
                next.push_back(j + 1);
            } else {
                do {
                    j = next[j - 1];
                } while (j != 0 && needle[j] != needle[i]);
                if (needle[j] == needle[i]) {
                    next.push_back(j + 1);
                } else {
                    next.push_back(0);
                }
                
            }
        }

        int len = (int)haystack.size();
        int offset = 0;
        int i = 0;
        for (i = 0; i < size;) {
            if (i + offset >= len) {
                break;
            }
            
            if (needle[i] != haystack[i + offset]) {
                if (i == 0) {
                    offset++;
                } else {
                    offset = offset + i - next[i-1];
                    i = next[i - 1];
                }
            } else {
                i++;
            }
        }
        if (i == size) {
            return offset;
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    cout << s.strStr("babba", "bbcbbb") << endl;
    
    cout << s.strStr("babba", "bbb") << endl;
    
    cout << s.strStr("mississippi", "issipi") << endl;
    
    cout << s.strStr("abacasdfb", "cas") << endl;
    
    return 0;
}
