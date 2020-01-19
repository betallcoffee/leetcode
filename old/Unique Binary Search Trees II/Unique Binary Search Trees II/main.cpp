//
//  main.cpp
//  Unique Binary Search Trees II
//
//  Created by liang on 15/9/18.
//  Copyright © 2018年 liang. All rights reserved.
//  https://leetcode.com/problems/unique-binary-search-trees-ii/description/
/**
 Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.
 
 Example:
 
 Input: 3
 Output:
 [
 [1,null,3,2],
 [3,2,null,1],
 [3,1,null,null,2],
 [2,1,3],
 [1,null,2,null,3]
 ]
 Explanation:
 The above output corresponds to the 5 unique BST's shown below:
 
 1         3     3      2      1
 \       /     /      / \      \
 3     2     1      1   3      2
 /     /       \                 \
 2     1         2                 3
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
private:
    vector<TreeNode *> generateTrees(int min, int max) {
        vector<TreeNode *> array;
        if (min == max) {
            TreeNode *node = new TreeNode(min);
            node->left = node->right = nullptr;
            array.push_back(node);
            return array;
        }
        for (int i = min; i <= max; i++) {
            int left = i - 1;
            int right = i + 1;
            vector<TreeNode *> leftArray = generateTrees(min, left);
            vector<TreeNode *> rightArray = generateTrees(right, max);
            size_t leftCount = leftArray.size();
            size_t rightCount = rightArray.size();
            if (leftCount > 0 && rightCount > 0) {
                for (size_t j = 0; j < leftCount; j++) {
                    for (size_t k = 0; k < rightCount; k++) {
                        TreeNode *node = new TreeNode(i);
                        node->left = leftArray[j];
                        node->right = rightArray[k];
                        array.push_back(node);
                    }
                }
            } else if (leftCount > 0) {
                for (size_t j = 0; j < leftCount; j++) {
                    TreeNode *node = new TreeNode(i);
                    node->left = leftArray[j];
                    node->right = nullptr;
                    array.push_back(node);
                }
            } else if (rightCount > 0) {
                for (size_t j = 0; j < rightCount; j++) {
                    TreeNode *node = new TreeNode(i);
                    node->left = nullptr;
                    node->right = rightArray[j];
                    array.push_back(node);
                }
            }
        }
        return array;
    }
    
public:
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1, n);
    }
};

void print(TreeNode *node) {
    if (node) {
        if (node->left) {
            printf("%d,", node->left->val);
        } else {
            printf("null,");
        }
        if (node->right) {
            printf("%d,", node->right->val);
        } else {
            printf("null,");
        }
        print(node->left);
        print(node->right);
    }
}

void test(int n) {
    Solution s;
    vector<TreeNode *> array = s.generateTrees(n);
    size_t count = array.size();
    printf("[");
    for (size_t i = 0; i < count; i++) {
        printf("[");
        if (array[i]) {
            printf("%d,", array[i]->val);
        }
        print(array[i]);
        printf("]\n");
    }
    printf("]\n");
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    test(1);
    test(0);
    test(2);
    test(3);
    return 0;
}
