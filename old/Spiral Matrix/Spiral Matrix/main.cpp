//
//  main.cpp
//  Spiral Matrix
//
//  Created by liang on 12/10/17.
//  Copyright © 2017年 liang. All rights reserved.
//  https://leetcode.com/problems/spiral-matrix/description/
/**
 Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 
 For example,
 Given the following matrix:
 
 [
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
 ]
 You should return [1,2,3,6,9,8,7,4,5].
 [
 [ 1, 2, 3, 4 ],
 [ 5, 6, 7, 8 ],
 [ 9, 10, 11, 12 ]
 ]
 */

#include <iostream>
#include <vector>

using namespace std;

void printfV(vector<int> &array) {
    for_each(array.begin(), array.end(), [&] (int n) {
        printf("%d ", n);
    });
    printf("\n");
}

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> array;
        int row = matrix.size();
        if (row == 0) return array;
        int col  = matrix[0].size();
        if (col == 0) return array;
        int r = 0;
        int c = 0;
        while (row > r && col > c) {
            for (int i = c; i < col && row > r; i++) {
                array.push_back(matrix[r][i]);
            }
            r++;
            for (int i = r; i < row && col > c; i++) {
                array.push_back(matrix[i][col - 1]);
            }
            col--;
            for (int i = col - 1; i >= c && row > r; i--) {
                array.push_back(matrix[row - 1][i]);
            }
            row--;
            for (int i = row - 1; i >= r && col > c; i--) {
                array.push_back(matrix[i][c]);
            }
            c++;
        }
        return array;
    }
};

void test1() {
    Solution s;
    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};
    vector<int> array = s.spiralOrder(matrix);
    printfV(array);
}

void test2() {
    Solution s;
    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}, {10, 11, 12}};
    vector<int> array = s.spiralOrder(matrix);
    printfV(array);
}

void test3() {
    Solution s;
    vector<vector<int>> matrix = {{1,2,3,4}, {5,6,7,8}, {9, 10, 11, 12}};
    vector<int> array = s.spiralOrder(matrix);
    printfV(array);
}

void test4() {
    Solution s;
    vector<vector<int>> matrix;
    vector<int> array = s.spiralOrder(matrix);
    printfV(array);
}

int main(int argc, const char * argv[]) {
    test1();
    test2();
    test3();
    return 0;
}
