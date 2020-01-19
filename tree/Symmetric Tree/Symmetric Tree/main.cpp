//
//  main.m
//  Symmetric Tree
//
//  Created by liang on 19/1/20.
//  Copyright © 2020年 liang. All rights reserved.
// https://leetcode.com/problems/symmetric-tree/
/**
 Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 
 For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 
 1
 / \
 2   2
 / \ / \
 3  4 4  3
 
 
 But the following [1,2,2,null,3,null,3] is not:
 
 1
 / \
 2   2
 \   \
 3    3
 
 
 Note:
 Bonus points if you could solve it both recursively and iteratively.
 */


 // Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        } else {
            return isSymmetric(root->left, root->right);
        }
    }
    
private:
    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) {
            return true;
        } else if (left == nullptr || right == nullptr) {
            return false;
        }
        
        if (left->val != right->val) {
            return false;
        } else {
            return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
        }
    }
};

void test0() {
    
}

int main(int argc, const char * argv[]) {
    test0();
    return 0;
}
