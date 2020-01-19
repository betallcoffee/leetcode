//
//  main.cpp
//  Rotate Image
//
//  Created by liang on 8/23/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  Problem: https://leetcode.com/problems/rotate-image/
//You are given an n x n 2D matrix representing an image.
//
//Rotate the image by 90 degrees (clockwise).
//
//Follow up:
//Could you do this in-place?

#include <iostream>
#include <vector>

using namespace std;

void printff(vector<vector<int>> &matrix) {
    for_each(matrix.begin(), matrix.end(), [&](vector<int> vect){
        for_each(vect.begin(), vect.end(), [&](int item){
            printf("%d ", item);
        });
        printf("\n");
    });
}

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = (int)matrix.size();
        for (int i = 0; i < n / 2; i++) {
            for (int j = i; j < n - 1 - i; j++) {
                int a = matrix[i][j];
                
                int size = n - (i * 2);
                int row = j;
                int col = size - 1 + i;
                int b = matrix[row][col];
                matrix[row][col] = a;
                
                col = n - 1 - j;
                row = size - 1 + i;
                int c = matrix[row][col];
                matrix[row][col] = b;
                
                row = n - 1 - j;
                col = i;
                int d = matrix[row][col];
                matrix[row][col] = c;
                
                matrix[i][j] = d;
            }
        }
    }
};

void test1() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    printff(matrix);
    Solution s;
    s.rotate(matrix);
    printff(matrix);
}

void test2() {
    vector<vector<int>> matrix = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    printff(matrix);
    Solution s;
    s.rotate(matrix);
    printff(matrix);
}

int main(int argc, const char * argv[]) {
//    test1();
    test2();
    return 0;
}
