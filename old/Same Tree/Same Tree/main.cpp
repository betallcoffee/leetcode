//
//  main.cpp
//  Same Tree
//
//  Created by liang on 13/10/17.
//  Copyright © 2017年 liang. All rights reserved.
//  https://leetcode.com/problems/same-tree/description/
/**
 Given two binary trees, write a function to check if they are equal or not.
 
 Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
 */

#include <iostream>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == q) {
            return true;
        } else if (p == NULL || q == NULL) {
            return false;
        } else if (p->val != q->val) {
            return false;
        } else if (!isSameTree(p->left, q->left)) {
            return false;
        } else if (!isSameTree(p->right, q->right)) {
            return false;
        } else {
            return true;
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
