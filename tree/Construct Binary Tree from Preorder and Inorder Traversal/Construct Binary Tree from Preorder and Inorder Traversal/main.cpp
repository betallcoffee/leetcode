//
//  main.cpp
//  Construct Binary Tree from Preorder and Inorder Traversal
//
//  Created by liang on 19/1/20.
//  Copyright © 2020年 liang. All rights reserved.
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

/**
 Given preorder and inorder traversal of a tree, construct the binary tree.
 
 Note:
 You may assume that duplicates do not exist in the tree.
 
 For example, given
 
 preorder = [3,9,20,15,7]
 inorder = [9,3,15,20,7]
 Return the following binary tree:
 
 3
 / \
 9  20
 /  \
 15   7
 */

#include <vector>
#include <stack>

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
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0) {
            return nullptr;
        } else if (preorder.size() != inorder.size()) {
            return nullptr;
        }
        std::stack<std::pair<int, int>> stack;
        std::stack<TreeNode*> nodeStack;
        auto it = preorder.begin();
        TreeNode* root = new TreeNode(*it);
        nodeStack.push(root);
        stack.push(std::make_pair(0, inorder.size() - 1));
        while (!stack.empty()) {
            auto item = stack.top();
            stack.pop();
            
            auto node = nodeStack.top();
            nodeStack.pop();
            node->val = *it;
            for (int i = item.first; i <= item.second; i++) {
                if (*it == inorder[i]) {
                    if (i < item.second) {
                        TreeNode* right = new TreeNode(0);
                        node->right = right;
                        nodeStack.push(right);
                        stack.push(std::make_pair(i + 1, item.second));
                    }
                    if (i > item.first) {
                        TreeNode* left = new TreeNode(0);
                        node->left = left;
                        nodeStack.push(left);
                        stack.push(std::make_pair(item.first, i - 1));
                    }
                    break;
                }
            }
            it++;
        }
        return root;
    }
};

void test0() {
    std::vector<int> preorder;
    std::vector<int> inorder;
    Solution s;
    TreeNode* tree = s.buildTree(preorder, inorder);
}

void test1() {
    std::vector<int> preorder = {3,9,20,15,7};
    std::vector<int> inorder = {9,3,15,20,7};
    Solution s;
    TreeNode* tree = s.buildTree(preorder, inorder);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    test0();
    return 0;
}
