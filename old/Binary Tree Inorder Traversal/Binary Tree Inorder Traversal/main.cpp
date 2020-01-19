//
//  main.cpp
//  Binary Tree Inorder Traversal
//
//  Created by liang on 14/10/17.
//  Copyright © 2017年 liang. All rights reserved.
//  https://leetcode.com/problems/binary-tree-inorder-traversal/description/
/**
 Given a binary tree, return the inorder traversal of its nodes' values.
 
 For example:
 Given binary tree [1,null,2,3],
 1
 \
 2
 /
 3
 return [1,3,2].
 
 Note: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> array;
        TreeNode *cur = root;
        TreeNode *pre = NULL;
        
        while (cur != NULL) {
            if (cur->left == NULL) {
                array.push_back(cur->val);
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
                    array.push_back(cur->val);
                    pre->right = NULL;
                    pre = cur;
                    cur = cur->right;
                }
            }
        }
        
        return array;
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
};

void test1() {
    vector<int> array = {1, -1, 2, 3};
    Solution s;
    int index;
    TreeNode *root = s.createTreePre(array, index);
    array = s.inorderTraversal(root);
    for_each(array.begin(), array.end(), [](int num) {
        printf("%d ", num);
    });
    printf("\n");
}

int main(int argc, const char * argv[]) {
    test1();
    return 0;
}
