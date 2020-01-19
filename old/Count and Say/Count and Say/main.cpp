//
//  main.cpp
//  Count and Say
//
//  Created by liang on 7/1/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  Problem: https://leetcode.com/problems/count-and-say/
//The count-and-say sequence is the sequence of integers beginning as follows:
//1, 11, 21, 1211, 111221, ...
//
//1 is read off as "one 1" or 11.
//11 is read off as "two 1s" or 21.
//21 is read off as "one 2, then one 1" or 1211.
//
//Given an integer n, generate the nth sequence.
//
//Note: The sequence of integers will be represented as a string.

#include <iostream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string ret = "1";
        for (int i = 1; i < n; i++) {
            string pre = ret;
            ret.clear();
            int size = (int)pre.size();
            int k = 0;
            for (int j = 1; j < size; j++) {
                if (pre[j] != pre[j-1]) {
                    int m = j - k;
                    ret.push_back(m + '0');
                    ret.push_back(pre[j-1]);
                    k = j;
                }
            }
            int m = size - k;
            ret.push_back(m + '0');
            ret.push_back(pre[size-1]);
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    cout << s.countAndSay(1) << endl;
    
    cout << s.countAndSay(2) << endl;
    
    cout << s.countAndSay(3) << endl;
    
    cout << s.countAndSay(4) << endl;
    
    cout << s.countAndSay(5) << endl;
    
    cout << s.countAndSay(6) << endl;
    
    cout << s.countAndSay(1000) << endl;
    
    return 0;
}
