//
//  main.m
//  Binary Tree Level Order Traversal
//
//  Created by liang on 19/1/20.
//  Copyright © 2020年 liang. All rights reserved.
// https://leetcode.com/problems/binary-tree-level-order-traversal/
/**
 Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 
 For example:
 Given binary tree [3,9,20,null,null,15,7],
 3
 / \
 9  20
 /  \
 15   7
 return its level order traversal as:
 [
 [3],
 [9,20],
 [15,7]
 ]
 */

#include <vector>
#include <queue>

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
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::queue<TreeNode*> queue;
        queue.push(root);
        TreeNode sepNode(0);
        sepNode.left = root;
        sepNode.right = root;
        if (!queue.empty()) {
            queue.push(&sepNode);
        }
        
        std::vector<std::vector<int>> result;
        std::vector<int> line;
        while (!queue.empty()) {
            TreeNode* node = queue.front();
            queue.pop();
            if (node) {
                if (node->left == root &&
                    node->right == root) {
                    if (!line.empty()) {
                        result.push_back(line);
                    }
                    line.clear();
                    if (!queue.empty()) {
                        queue.push(node);
                    }
                } else {
                    line.push_back(node->val);
                    if (node->left != nullptr) {
                        queue.push(node->left);
                    }
                    if (node->right != nullptr) {
                        queue.push(node->right);
                    }
                }
            }
        }
        
        return result;
    }
};

TreeNode* createATree(std::vector<int> list) {
    TreeNode* root = new TreeNode(list[0]);
    std::queue<TreeNode*> queue;
    queue.push(root);
    int i = 0;
    while (!queue.empty()) {
        TreeNode* node = queue.front();
        queue.pop();
        if (node != nullptr) {
            int left = i * 2 + 1;
            int right = i * 2 + 2;
            if (left < list.size() && list[left] != 0) {
                node->left = new TreeNode(list[left]);
                queue.push(node->left);
            }
            if (right < list.size() && list[right] != 0) {
                node->right = new TreeNode(list[right]);
                queue.push(node->right);
            }
        }
        i++;
    }
    
    return root;
}

void test0() {
    std::vector<int> list = {3,9,20,0,0,15,7};
    TreeNode* tree = createATree(list);
    Solution s;
    std::vector<std::vector<int>> result = s.levelOrder(tree);
}

int main(int argc, const char * argv[]) {
    test0();
    return 0;
}
