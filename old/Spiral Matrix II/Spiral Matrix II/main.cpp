//
//  main.cpp
//  Spiral Matrix II
//
//  Created by liang on 12/10/17.
//  Copyright © 2017年 liang. All rights reserved.
//  https://leetcode.com/problems/spiral-matrix-ii/description/
/**
 Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
 
 For example,
 Given n = 3,
 
 You should return the following matrix:
 [
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
 ]
 */

#include <iostream>
#include <vector>

using namespace std;

void printfM(vector<vector<int>> &matrix) {
    for_each(matrix.begin(), matrix.end(), [&](vector<int> vect){
        for_each(vect.begin(), vect.end(), [&](int item){
            printf("%d ", item);
        });
        printf("\n");
    });
    printf("\n");
}

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        if (n <= 0) {
            return matrix;
        }
        
        int row = n;
        int col = n;
        int r = 0;
        int c = 0;
        int count = 1;
        while (row > r && col > c) {
            for (int i = c; i < col && row > r; i++) {
                matrix[r][i] = count;
                count++;
            }
            r++;
            for (int i = r; i < row && col > c; i++) {
                matrix[i][col - 1] = count;
                count++;
            }
            col--;
            for (int i = col - 1; i >= c && row > r; i--) {
                matrix[row - 1][i] = count;
                count++;
            }
            row--;
            for (int i = row - 1; i >= r && col > c; i--) {
                matrix[i][c] = count;
                count++;
            }
            c++;
        }

        return matrix;
    }
};

void test1() {
    Solution s;
    vector<vector<int>> matrix = s.generateMatrix(0);
    printfM(matrix);
}

void test2() {
    Solution s;
    vector<vector<int>> matrix = s.generateMatrix(1);
    printfM(matrix);
}

void test3() {
    Solution s;
    vector<vector<int>> matrix = s.generateMatrix(2);
    printfM(matrix);
}

void test4() {
    Solution s;
    vector<vector<int>> matrix = s.generateMatrix(3);
    printfM(matrix);
}

void test5() {
    Solution s;
    vector<vector<int>> matrix = s.generateMatrix(4);
    printfM(matrix);
}

int main(int argc, const char * argv[]) {
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}
