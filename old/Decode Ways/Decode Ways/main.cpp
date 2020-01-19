//
//  main.cpp
//  Decode Ways
//
//  Created by liang on 18/10/17.
//  Copyright © 2017年 liang. All rights reserved.
//  https://leetcode.com/problems/decode-ways/description/
/**
 A message containing letters from A-Z is being encoded to numbers using the following mapping:
 
 'A' -> 1
 'B' -> 2
 ...
 'Z' -> 26
 Given an encoded message containing digits, determine the total number of ways to decode it.
 
 For example,
 Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 
 The number of ways decoding "12" is 2.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.size() <= 0) {
            return 0;
        } else if (s[0] == '0') {
            return 0;
        }
        vector<vector<int>> nums(2, vector<int>(s.size(), 0));
        nums[0][0] = 1;
        nums[1][0] = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '0') {
                nums[0][i] = 0;
            } else {
                nums[0][i] = nums[0][i-1] + nums[1][i-1];
            }
            int c1 = s[i-1] - '0';
            int c2 = s[i] - '0';
            if (c1 == 1 || (c1 == 2 && 0 <= c2 && c2 < 7)) {
                nums[1][i] = nums[0][i-1];
            } else {
                nums[1][i] = 0;
            }
        }
        return nums[0][s.size() - 1] + nums[1][s.size() - 1];
    }
};

void test1() {
    Solution s;
    printf("%d\n", s.numDecodings("12"));
}

void test2() {
    Solution s;
    printf("%d\n", s.numDecodings(""));
}

void test3() {
    Solution s;
    printf("%d\n", s.numDecodings("0"));
}

void test4() {
    Solution s;
    printf("%d\n", s.numDecodings("100"));
}

void test5() {
    Solution s;
    printf("%d\n", s.numDecodings("17"));
}

int main(int argc, const char * argv[]) {
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}
