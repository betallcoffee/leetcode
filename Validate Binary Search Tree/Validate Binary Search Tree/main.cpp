//
//  main.cpp
//  Validate Binary Search Tree
//
//  Created by liang on 13/10/17.
//  Copyright © 2017年 liang. All rights reserved.
//  https://leetcode.com/problems/validate-binary-search-tree/description/
/**
 Given a binary tree, determine if it is a valid binary search tree (BST).
 
 Assume a BST is defined as follows:
 
 The left subtree of a node contains only nodes with keys less than the node's key.
 The right subtree of a node contains only nodes with keys greater than the node's key.
 Both the left and right subtrees must also be binary search trees.
 Example 1:
 2
 / \
 1   3
 Binary tree [2,1,3], return true.
 Example 2:
 1
 / \
 2   3
 Binary tree [1,2,3], return false.
 */

#include <iostream>
#include <vector>

using namespace std;

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
    bool isValidBSTRecu(TreeNode *root, TreeNode *minNode, TreeNode *maxNode) {
        if (root == NULL) return true;
        if (minNode != NULL && root->val <= minNode->val) {
            return false;
        } else if (maxNode != NULL && root->val >= maxNode->val) {
            return false;
        } else {
            return isValidBSTRecu(root->left, minNode, root) && isValidBSTRecu(root->right, root, maxNode);
        }
        
    }
    bool isValidBST(TreeNode *root) {
        return isValidBSTRecu(root, NULL, NULL);
    }
    
    // Runtime error
    bool isValidBST1(TreeNode* root) {
        bool flag = true;
        TreeNode *cur = root;
        TreeNode *pre = NULL;
        TreeNode *last = NULL;
        
        while (cur != NULL) {
            if (cur->left == NULL) {
                if (last != NULL && last->val >= cur->val) {
                    flag = false;
                    break;
                }
                last = cur;
                // 不是子树，就是回溯点
                pre = cur;
                cur = cur->right;
            } else {
                pre = cur->left;
                
                while (pre->right != NULL && pre->right != cur) {
                    pre = pre->right;
                }
                
                if (pre->right == NULL) {
                    // 建立回溯点
                    pre->right = cur;
                    cur = cur->left;
                } else {
                    // 恢复回溯点为空指针
                    pre->right = NULL;
                    if (last != NULL && last->val >= cur->val) {
                        flag = false;
                        break;
                    }
                    last = cur;
                    pre = cur;
                    cur = cur->right;
                }
            }
        }
        
        return flag;
    }
    
    TreeNode *createTreePre(vector<int> &array, int &index) {
        if (index >= array.size()) {
            return NULL;
        } else {
            if (array[index] < 0) {
                index++;
                return NULL;
            }
            TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
            node->val = array[index];
            index++;
            node->left = createTreePre(array, index);
            node->right = createTreePre(array, index);
            return node;
        }
    }
    
    TreeNode *createListFromArray(vector<int> &array) {
        vector<TreeNode *> nodes(array.size(), NULL);
        nodes[0] = (TreeNode *)malloc(sizeof(TreeNode));
        nodes[0]->val = array[0];
        nodes[0]->left = nodes[0]->right = NULL;
        for (int i = 0; i < array.size(); i++) {
            if (nodes[i]) {
                if (i*2+1 < array.size() && array[i*2+1] >= 0) {
                    nodes[i]->left = (TreeNode *)malloc(sizeof(TreeNode));
                    nodes[i]->left->left = nodes[i]->left->right = NULL;
                    nodes[i*2+1] = nodes[i]->left;
                    nodes[i*2+1]->val = array[i*2+1];
                }
                if (i*2+2 < array.size() && array[i*2+2] >= 0) {
                    nodes[i]->right = (TreeNode *)malloc(sizeof(TreeNode));
                    nodes[i]->right->left = nodes[i]->right->right = NULL;
                    nodes[i*2+2] = nodes[i]->right;
                    nodes[i*2+2]->val = array[i*2+2];
                }
            }
        }
        return nodes[0];
    }
    
    void printPreTree(TreeNode *root) {
        printf("%d, ", root->val);
        if (root->left) {
            printPreTree(root->left);
        }
        if (root->right) {
            printPreTree(root->right);
        }
    }
    
    void printInTree(TreeNode *root) {
        if (root->left) {
            printInTree(root->left);
        }
        printf("%d, ", root->val);
        if (root->right) {
            printInTree(root->right);
        }
    }
};

void test1() {
    vector<int> array = {3, -1, 30, 10, -1, -1, 15, -1, 45};
    Solution s;
    TreeNode *root = s.createListFromArray(array);
    s.printPreTree(root);
    printf("\n");
    s.printInTree(root);
    printf("\n");
    printf("%d\n", s.isValidBST(root));
}

void test2() {
    vector<int> array = {10, 5, 15, -1, -1, 6, 20};
    Solution s;
    TreeNode *root = s.createListFromArray(array);
    s.printPreTree(root);
    printf("\n");
    s.printInTree(root);
    printf("\n");
    printf("%d\n", s.isValidBST(root));
}


int main(int argc, const char * argv[]) {
    // insert code here...
    test1();
    test2();
    return 0;
}
