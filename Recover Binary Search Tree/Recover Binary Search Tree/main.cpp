//
//  main.cpp
//  Recover Binary Search Tree
//
//  Created by liang on 13/10/17.
//  Copyright © 2017年 liang. All rights reserved.
//  https://leetcode.com/problems/recover-binary-search-tree/description/
/**
 Two elements of a binary search tree (BST) are swapped by mistake.
 
 Recover the tree without changing its structure.
 
 Note:
 A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
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
    void recoverTree(TreeNode* root) {
        if (root == NULL) {
            return ;
        }
        
        TreeNode *elm1 = NULL;
        TreeNode *elm2 = NULL;
        preorder(root, NULL, &elm1, &elm2);
        
        if (elm1 && elm2) {
            int t = elm1->val;
            elm1->val = elm2->val;
            elm2->val = t;
        }
    }
    
    TreeNode *preorder(TreeNode *root, TreeNode *last, TreeNode **elm1, TreeNode **elm2) {
        TreeNode *pre;
        if (root->left == NULL) {
            pre = last;
        } else if (root->left) {
            pre = preorder(root->left, last, elm1, elm2);
        }
        
        if (pre && pre->val > root->val) {
            if (*elm1 == NULL) {
                *elm1 = pre;
            }
            if (*elm1) {
                *elm2 = root;
            }
        }
        
        if (root->right) {
            return preorder(root->right, root, elm1, elm2);
        } else {
            return root;
        }
    }
    
    void printTree(TreeNode *root) {
        if (root->left) {
            printTree(root->left);
        }
        printf("%d, ", root->val);
        if (root->right) {
            printTree(root->right);
        }
    }
};

void test1() {
    TreeNode node0(0), node1(1);
    node0.left = &node1;
    Solution s;
    s.printTree(&node0);
    printf("\n");
    s.recoverTree(&node0);
    s.printTree(&node0);
    printf("\n");
}

int main(int argc, const char * argv[]) {
    test1();
    return 0;
}
