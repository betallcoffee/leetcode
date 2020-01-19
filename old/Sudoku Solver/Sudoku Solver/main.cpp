//
//  main.cpp
//  Sudoku Solver
//
//  Created by liang on 7/1/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  Problem: https://leetcode.com/problems/sudoku-solver/
//Write a program to solve a Sudoku puzzle by filling the empty cells.
//
//Empty cells are indicated by the character '.'.
//
//You may assume that there will be only one unique solution.

#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<vector<char>> &vv) {
    for_each(vv.begin(), vv.end(), [](vector<char> v){
        for_each(v.begin(), v.end(), [](char c) {
            cout << c << " ";
        });
        cout << endl;
    });
    cout << endl;
}

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board, 0);
    }
    
    bool dfs(vector<vector<char>> &board, int index) {
        if (index >= 81) {
            return true;
        }
    
        int i = index / 9;
        int j = index % 9;
        
        vector<char> row = board[i];
        char c = row[j];
        int n = c - '0';
        if (n > 0 && n < 10) {
            return dfs(board, index + 1);
        } else {
            for (int k = 1; k < 10; k++) {
                row[j] = '0' + k;
                board[i] = row;
                bool valid = isValidSudoku(board);
                if (valid) {
                    bool ret = dfs(board, index + 1);
                    if (ret) {
                        return true;
                    }
                }
            }
            row[j] = '0';
            board[i] = row;
            return false;
        }
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        int rowhash[9][9];
        int columnhash[9][9];
        int subhash[9][9];
        memset(rowhash, 0, sizeof(rowhash));
        memset(columnhash, 0, sizeof(columnhash));
        memset(subhash, 0, sizeof(subhash));
        
        for (int i = 0; i < 9; i++) {
            vector<char> row = board[i];
            for (int j = 0; j < 9; j++) {
                int n = row[j] - '1';
                if (n > 8 || n < 0) {
                    continue;
                }
                if (rowhash[i][n]) {
                    return false;
                } else {
                    rowhash[i][n] = 1;
                }
                
                if (columnhash[j][n]) {
                    return false;
                } else {
                    columnhash[j][n] = 1;
                }
                
                int row = i / 3 * 3 + j / 3;
                if (subhash[row][n]) {
                    return false;
                } else {
                    subhash[row][n] = 1;
                }
            }
        }
        
        return true;
    }
};

vector<char> stringToVC(string str) {
    vector<char> vc;
    for_each(str.begin(), str.end(), [&](char c) {
        vc.push_back(c);
    });
    return vc;
}

void fillVector(string strs[], int count, vector<vector<char>> &v) {
    for (int i = 0; i < count; i++) {
        v.push_back(stringToVC(strs[i]));
    }
}

int main(int argc, const char * argv[]) {
    Solution s;
    
    string case1[] = {"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};
    vector<vector<char>> v1;
    fillVector(case1, sizeof(case1) / sizeof(string), v1);
    printVector(v1);
    s.solveSudoku(v1);
    printVector(v1);
    
    return 0;
}

