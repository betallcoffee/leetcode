//
//  main.cpp
//  Decode Ways II
//
//  Created by liang on 18/10/17.
//  Copyright © 2017年 liang. All rights reserved.
//  https://leetcode.com/problems/decode-ways-ii/description/
/**
 A message containing letters from A-Z is being encoded to numbers using the following mapping way:
 
 'A' -> 1
 'B' -> 2
 ...
 'Z' -> 26
 Beyond that, now the encoded string can also contain the character '*', which can be treated as one of the numbers from 1 to 9.
 
 Given the encoded message containing digits and the character '*', return the total number of ways to decode it.
 
 Also, since the answer may be very large, you should return the output mod 109 + 7.
 
 Example 1:
 Input: "*"
 Output: 9
 Explanation: The encoded message can be decoded to the string: "A", "B", "C", "D", "E", "F", "G", "H", "I".
 Example 2:
 Input: "1*"
 Output: 9 + 9 = 18
 Note:
 The length of the input string will fit in range [1, 105].
 The input string will only contain the character '*' and digits '0' - '9'.
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
        
        long long M = 1000000007;
        vector<long long> nums(s.size()+1, 0);
        if (s[0] == '*') {
            nums[0] = 1;
            nums[1] = 9;
        } else {
            nums[0] = 1;
            nums[1] = 1;
        }
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '*') {
                nums[i+1] = nums[i] * 9;
                
                if (s[i-1] == '1') {
                    nums[i+1] = (nums[i+1] + nums[i-1] * 9) % M;
                } else if (s[i-1] == '2') {
                    nums[i+1] = (nums[i+1] + nums[i-1] * 6) % M;
                } else if (s[i-1] == '*') {
                    nums[i+1] = (nums[i+1] + nums[i-1] * 15) % M;
                }
            } else if (s[i] != '*') {
                if (s[i] == '0') {
                    nums[i+1] = 0;
                } else {
                    nums[i+1] = nums[i];
                }

                if (s[i-1] == '1' || (s[i-1] == '2' && '0' <= s[i] && s[i] < '7')) {
                    nums[i+1] = (nums[i+1] + nums[i-1]) % M;
                } else if (s[i-1] == '*') {
                    int n = ('0' <= s[i] && s[i] < '7') ? 2 : 1;
                    nums[i+1] = (nums[i+1] + nums[i-1] * n) % M;
                }
            }
        }
        return nums[s.size()] % M;
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

void test6() {
    Solution s;
    printf("%d\n", s.numDecodings("*"));
}

void test7() {
    Solution s;
    printf("%d\n", s.numDecodings("1*"));
}

void test8() {
    /* 133236775 */
    Solution s;
    printf("%d\n", s.numDecodings("**********1111111111"));
}

int main(int argc, const char * argv[]) {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    return 0;
}
