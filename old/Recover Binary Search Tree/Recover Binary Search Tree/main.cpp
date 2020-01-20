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
#include <queue>
#include <vector>

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
        inorder(root, NULL, &elm1, &elm2);
        
        if (elm1 && elm2) {
            int t = elm1->val;
            elm1->val = elm2->val;
            elm2->val = t;
        }
    }
    
    TreeNode *inorder(TreeNode *root, TreeNode *last, TreeNode **elm1, TreeNode **elm2) {
        TreeNode *pre = NULL;
        if (root->left == NULL) {
            pre = last;
        } else if (root->left != NULL) {
            pre = inorder(root->left, last, elm1, elm2);
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
            return inorder(root->right, root, elm1, elm2);
        } else {
            return root;
        }
    }
    
    void printTree(TreeNode *root) {
        printf("%d, ", root->val);
        if (root->left) {
            printTree(root->left);
        }
        if (root->right) {
            printTree(root->right);
        }
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

void test1() {
    std::vector<int> list = {1,3,0,0,2};
    TreeNode* tree = createATree(list);
    Solution s;
    s.printTree(tree);
    printf("\n");
    s.recoverTree(tree);
    s.printTree(tree);
    printf("\n");
}

int main(int argc, const char * argv[]) {
    test1();
    return 0;
}
