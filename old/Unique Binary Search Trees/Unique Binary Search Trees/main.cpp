//
//  main.cpp
//  Unique Binary Search Trees
//
//  Created by liang on 13/10/17.
//  Copyright © 2017年 liang. All rights reserved.
//  https://leetcode.com/problems/unique-binary-search-trees/description/
/**
 Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
 
 For example,
 Given n = 3, there are a total of 5 unique BST's.
 
 1         3     3      2      1
 \       /     /      / \      \
 3     2     1      1   3      2
 /     /       \                 \
 2     1         2                 3
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> array(n+1, 0);
        array[0] = 1;
        array[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                array[i] += array[j - 1] * array[i - j];
            }
        }
        
        return array[n];
    }
};

void test1() {
    Solution s;
    printf("%d\n", s.numTrees(1));
}

void test2() {
    Solution s;
    printf("%d\n", s.numTrees(2));
}

void test3() {
    Solution s;
    printf("%d\n", s.numTrees(3));
}

void test4() {
    Solution s;
    printf("%d\n", s.numTrees(4));
}

void test5() {
    Solution s;
    printf("%d\n", s.numTrees(5));
}

int main(int argc, const char * argv[]) {
    // insert code here...
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}
