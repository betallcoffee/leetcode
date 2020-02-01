//
//  main.cpp
//  Palindrome Partitioning
//
//  Created by liang on 31/1/2020.
//  Copyright © 2020 liang. All rights reserved.
// https://leetcode.com/problems/palindrome-partitioning/
/**
 Given a string s, partition s such that every substring of the partition is a palindrome.

 Return all possible palindrome partitioning of s.

 Example:

 Input: "aab"
 Output:
 [
   ["aa","b"],
   ["a","a","b"]
 ]
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<bool> line(s.size(), false);
        vector<vector<bool>> palindromeMatrix(s.size(), line);
        
        size_t count = s.size();
        /// 初始化 S_i_i 单字符为 true, S_i_i+1 双字符
        for (size_t i = 0; i < count; i++) {
            palindromeMatrix[i][i] = true;
            if (i + 1 < count) {
                if (s[i] == s[i + 1]) {
                    palindromeMatrix[i][i+1] = true;
                }
            }
        }
        
        /// 从  3 - count 个字符字串依次计算是否回文串
        for (size_t size = 2; size < count; size++) {
            for (size_t start = 0; start < count; start++) {
                size_t end = start + size;
                if (end >= count) {
                    break;
                }
                size_t ii = start + 1;
                size_t jj = end - 1;
                if (ii <= jj && ii < count && jj >= 0) {
                    if (s[start] == s[end] && palindromeMatrix[ii][jj]) {
                        palindromeMatrix[start][end] = true;
                    }
                }
            }
        }
        
//        for (size_t i = 0; i < count; i++) {
//            for (size_t j = 0; j < count; j++) {
//                printf("%d ", static_cast<int>(palindromeMatrix[i][j]));
//            }
//            printf("\n");
//        }
        
        vector<vector<string>> resultMatrix;
        vector<string> resultLine;
        dfsPalindromeMatrix(palindromeMatrix, s, 0, resultLine, resultMatrix);
        return resultMatrix;
    }
    
    void dfsPalindromeMatrix(vector<vector<bool>>& palindromeMatrix, string& s, size_t curIndex, vector<string> &line, vector<vector<string>>& resultMatrix) {
        size_t count = palindromeMatrix.size();
        if (curIndex >= count) {
            resultMatrix.push_back(line);
            return;
        }
        
        for (size_t size = 0; size < count - curIndex; size++) {
            if (palindromeMatrix[curIndex][curIndex + size]) {
                line.push_back(s.substr(curIndex, size + 1));
                dfsPalindromeMatrix(palindromeMatrix, s, curIndex + size + 1, line, resultMatrix);
                line.pop_back();
            }
        }
    }
};

void printfResultMatrix(vector<vector<string>> resultMatrix) {
    auto it = resultMatrix.begin();
    while (it != resultMatrix.end()) {
        printf("[");
        auto jt = it->begin();
        while (jt != it->end()) {
            printf("\"%s\",", jt->c_str());
            jt++;
        }
        printf("]\n");
        it++;
    }
    printf("\n");
}

void test0() {
    Solution s;
    printfResultMatrix(s.partition("bananas"));
}

void test1() {
    Solution s;
    printfResultMatrix(s.partition("aab"));
}

int main(int argc, const char * argv[]) {
    // insert code here...
    test0();
    test1();
    return 0;
}
