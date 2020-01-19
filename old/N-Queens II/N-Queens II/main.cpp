//
//  main.cpp
//  N-Queens II
//
//  Created by liang on 4/10/17.
//  Copyright © 2017年 liang. All rights reserved.
//  https://leetcode.com/problems/n-queens-ii/description/
/**
 Follow up for N-Queens problem.
 
 Now, instead outputting board configurations, return the total number of distinct solutions.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printfQ(vector<vector<string>> &solves) {
    for_each(solves.begin(),solves.end() , [&] (vector<string> queens) {
        for_each(queens.begin(), queens.end(), [&] (string queen) {
            printf("%s\n", queen.c_str());
        });
        printf("\n");
    });
}

class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<string>> res;
        vector<string> queens(n, string(n, '.'));
        vector<int> flags(n * 5, 0);
        solveNQueens(res, queens, flags, 0, n);
        return (int)res.size();
    }
    
private:
    void solveNQueens(vector<vector<string>> &res, vector<string> &queens, vector<int> &flags, int row, int n) {
        if (row == n) {
            res.push_back(queens);
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (flags[col] == 0 &&
                flags[n + row + col] == 0 &&
                flags[n * 4 - 2 - row + col] == 0) {
                flags[col] = 1;
                flags[n + row + col] = 1;
                flags[n * 4 - 2 - row + col] = 1;
                queens[row][col] = 'Q';
                solveNQueens(res, queens, flags, row + 1, n);
                flags[col] = 0;
                flags[n + row + col] = 0;
                flags[n * 4 - 2 - row + col] = 0;
                queens[row][col] = '.';
            }
        }
    }
};

void test(int n) {
    Solution s;
    printf("%d\n", s.totalNQueens(n));
}
int main(int argc, const char * argv[]) {
    // insert code here...
    test(3);
    test(4);
    return 0;
}
