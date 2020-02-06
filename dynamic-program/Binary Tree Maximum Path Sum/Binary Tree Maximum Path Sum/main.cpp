//
//  main.cpp
//  Binary Tree Maximum Path Sum
//
//  Created by liang on 6/2/2020.
//  Copyright © 2020 liang. All rights reserved.
// https://leetcode.com/problems/binary-tree-maximum-path-sum/
/**
 Given a non-empty binary tree, find the maximum path sum.

 For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

 Example 1:

 Input: [1,2,3]

        1
       / \
      2   3

 Output: 6
 Example 2:

 Input: [-10,9,20,null,null,15,7]

    -10
    / \
   9  20
     /  \
    15   7

 Output: 42
 */

#include <iostream>
#include <vector>
#include <queue>

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
    int maxPathSum(TreeNode* root) {
        recursiveMaxPathSum(root);
        return _treeMaxSum;
    }
   
private:
    int _treeMaxSum = INT_MIN;
    int recursiveMaxPathSum(TreeNode* root) {
        if (root == nullptr) {
            return INT_MIN;
        } else if (root->left == nullptr && root->right == nullptr) {
            if (_treeMaxSum < root->val) {
                _treeMaxSum = root->val;
            }
            return root->val;
        }
        
        int leftMaxSum = recursiveMaxPathSum(root->left);
        int rightMaxSum = recursiveMaxPathSum(root->right);
        
        leftMaxSum = leftMaxSum < 0 ? 0 : leftMaxSum;
        rightMaxSum = rightMaxSum < 0 ? 0 : rightMaxSum;
                
        // 子节点只计算左右其中一条路径到父节点中。
        int singlePathSum = root->val + max(leftMaxSum, rightMaxSum);
        // 只有 root 节点同时计算左右两子节点的值
        int rootPathSum = root->val + leftMaxSum + rightMaxSum;

        if (_treeMaxSum < rootPathSum) {
            _treeMaxSum = rootPathSum;
        }
        return singlePathSum;
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
            if (left < list.size() && list[left] != INT_MIN) {
                node->left = new TreeNode(list[left]);
                queue.push(node->left);
            }
            if (right < list.size() && list[right] != INT_MIN) {
                node->right = new TreeNode(list[right]);
                queue.push(node->right);
            }
        }
        i++;
    }
    
    return root;
}

void test0() {
    std::vector<int> list = {-10,9,20,INT_MIN,INT_MIN,15,7};
    TreeNode* tree = createATree(list);
    Solution s;
    cout << "test0 expected 42: " << s.maxPathSum(tree) << endl;
}

/**
 5
 4                   8
 11     null       13              4
 7 2                null null     null 1
 */
void test1() {
    vector<int> list = {5,4,8,11,INT_MIN,13,4,7,2,INT_MIN,INT_MIN,INT_MIN,1};
    TreeNode* tree = createATree(list);
    Solution s;
    cout << "test1 expected 48: " << s.maxPathSum(tree) << endl;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    test0();
    test1();
    return 0;
}
