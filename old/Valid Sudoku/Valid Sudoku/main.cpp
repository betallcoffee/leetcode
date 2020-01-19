//
//  main.cpp
//  Valid Sudoku
//
//  Created by liang on 6/28/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  Problem: https://leetcode.com/problems/valid-sudoku/
//Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
//
//The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
//
//
//A partially filled sudoku which is valid.
//
//Note:
//A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
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
    
    string case1[] = {".87654321","2........","3........","4........","5........","6........","7........","8........","9........"};
    vector<vector<char>> v1;
    fillVector(case1, sizeof(case1) / sizeof(string), v1);
    cout << s.isValidSudoku(v1) << endl;
    
    return 0;
}
