//
//  main.cpp
//  Range Sum Query - Mutable
//
//  Created by liang on 24/9/18.
//  Copyright © 2018年 liang. All rights reserved.
//  https://leetcode.com/problems/range-sum-query-mutable/
/**
 Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
 
 The update(i, val) function modifies nums by updating the element at index i to val.
 
 Example:
 
 Given nums = [1, 3, 5]
 
 sumRange(0, 2) -> 9
 update(1, 2)
 sumRange(0, 2) -> 8
 
 Note:
 
 The array is only modifiable by the update function.
 You may assume the number of calls to update and sumRange function is distributed evenly.
 */

#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    NumArray(vector<int> nums) {
        count = static_cast<int>(nums.size());
        root = build(nums, 0, count - 1);
    }
    
    void update(int i, int val) {
        if (i >= count || i < 0) {
            return;
        }
        struct Node *node = root;
        while (node != nullptr) {
            if (node->left == node->right) {
                if (node->right == i) {
                    node->sum = val;
                }
                break;
            } else {
                int mid = (node->left + node->right) / 2;
                if (i <= mid) {
                    node = node->leftChild;
                } else {
                    node = node->rightChild;
                }
            }
        }
        
        while (node != nullptr && node->parent != nullptr) {
            node->parent->sum = node->parent->leftChild->sum + node->parent->rightChild->sum;
            node = node->parent;
        }
    }
    
    int sumRange(int i, int j) {
        if (root == nullptr) {
            return 0;
        }
        return sumRange(root, i, j);
    }
    
private:
    struct Node {
        Node() {
            parent = nullptr;
            leftChild = nullptr;
            rightChild = nullptr;
            left = 0;
            right = 0;
            sum = 0;
        }
        struct Node *parent;
        struct Node *leftChild;
        struct Node *rightChild;
        
        int left;
        int right;
        int sum;
    };
    
    struct Node *build(vector<int> &nums, int left, int right) {
        if (0 == nums.size()) {
            return nullptr;
        }
        
        struct Node *node = new Node();
        node->left = left;
        node->right = right;
        if (left >= right) {
            node->sum = nums[right];
        } else {
            int mid = (left + right) / 2;
            node->leftChild = build(nums, left, mid);
            node->rightChild = build(nums, mid + 1, right);
            node->sum = node->leftChild->sum + node->rightChild->sum;
            node->leftChild->parent = node;
            node->rightChild->parent = node;
        }
        return node;
    }
    struct Node *root;
    int count;
    
    int sumRange(struct Node *node, int i, int j) {
        if (node == nullptr) {
            return 0;
        }
        
        if (node->left == i && node->right == j) {
            return node->sum;
        }
        
        int mid = (node->left + node->right) / 2;
        if (i > mid) {
            return sumRange(node->rightChild, i, j);
        } else if (j <= mid) {
            return sumRange(node->leftChild, i, j);
        } else {
            int leftSum = sumRange(node->leftChild, i, mid);
            int rightSum = sumRange(node->rightChild, mid + 1, j);
            return leftSum + rightSum;
        }
    }

};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */

void test1() {
    vector<int> nums({1, 3, 5});
    NumArray obj(nums);
    printf("%d\n", obj.sumRange(0, 2));
    obj.update(1, 2);
    printf("%d\n", obj.sumRange(0, 2));
}

void test2() {
    vector<int> nums({9, -8});
    NumArray obj(nums);
    printf("%d\n", obj.sumRange(0, 1));
    obj.update(0, 3);
    printf("%d\n", obj.sumRange(1, 1));
}

int main(int argc, const char * argv[]) {
    // insert code here...
    test1();
    test2();
    return 0;
}
