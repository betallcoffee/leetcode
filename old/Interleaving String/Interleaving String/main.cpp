//
//  main.cpp
//  Interleaving String
//
//  Created by liang on 13/10/17.
//  Copyright © 2017年 liang. All rights reserved.
//  https://leetcode.com/problems/interleaving-string/description/
/**
 Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
 
 For example,
 Given:
 s1 = "aabcc",
 s2 = "dbbca",
 
 When s3 = "aadbbcbcac", return true.
 When s3 = "aadbbbaccc", return false.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int size1 = (int)s1.size();
        int size2 = (int)s2.size();
        int size3 = (int)s3.size();
        
        if (size1 + size2 != size3) {
            return false;
        }
        
        vector<vector<int>> array(size1 + 1, vector<int>(size2 + 1, 0));
        for (int i = 0; i <= size1; i++) {
            for (int j = 0; j <= size2; j++) {
                if (i == 0 && j == 0) {
                    array[i][j] = true;
                } else if (i == 0) {
                    if (array[0][j-1] && s2[j-1] == s3[j-1]) {
                        array[i][j] = true;
                    }
                } else if (j == 0) {
                    if (array[i-1][0] && s1[i-1] == s3[i-1]) {
                        array[i][j] = true;
                    }
                }
                else {
                    if (array[i-1][j] && s1[i-1] == s3[i+j-1]) {
                        array[i][j] = true;
                    } else if (array[i][j-1] && s2[j-1] == s3[i+j-1]) {
                        array[i][j] = true;
                    }
                }
            }
        }
        
        return array[size1][size2];
    }
};

void test1() {
    Solution s;
    printf("%d\n", s.isInterleave("aabcc", "dbbca", "aadbbcbcac"));
}

void test2() {
    Solution s;
    printf("%d\n", s.isInterleave("aabcc", "dbbca", "aadbbbaccc"));
}

void test3() {
    Solution s;
    printf("%d\n", s.isInterleave("a", "", "a"));
}

void test4() {
    Solution s;
    printf("%d\n", s.isInterleave("db", "b", "cbb"));
}

int main(int argc, const char * argv[]) {
    test1();
    test2();
    test3();
    test4();
    return 0;
}
