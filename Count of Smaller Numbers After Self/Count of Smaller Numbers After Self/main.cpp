//
//  main.cpp
//  Count of Smaller Numbers After Self
//
//  Created by liang on 7/10/18.
//  Copyright © 2018年 liang. All rights reserved.
//  https://leetcode.com/problems/count-of-smaller-numbers-after-self/

/**
 You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].
 
 Example:
 
 Input: [5,2,6,1]
 Output: [2,1,1,0]
 Explanation:
 To the right of 5 there are 2 smaller elements (2 and 1).
 To the right of 2 there is only 1 smaller element (1).
 To the right of 6 there is 1 smaller element (1).
 To the right of 1 there is 0 smaller element.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        count = static_cast<int>(nums.size());
        vector<int> smallers(count, 0);
        if (count <= 0) {
            return smallers;
        }
        
        max = nums.front();
        min = nums.front();
        for (int item : nums) {
            if (max < item) {
                max = item;
            }
            if (min > item) {
                min = item;
            }
        }
        // 构建 线段树, 构建以最小值和最大值为区间的线段树
        root = build(min, max);
        // 逆向遍历数组
        for (int i = count - 1; i >= 0; i--) {
            int val = nums[i];
            // 计算出现过小于 val 的数字个数
            smallers[i] = countSmaller(root, min, val - 1);
            // 遍历 val 所在路径
            traverseTree(root, val);
        }
        return smallers;
    }
    
private:
    struct Node {
        Node() {
            parent = nullptr;
            leftChild = nullptr;
            rightChild = nullptr;
            left = 0;
            right = 0;
            count = 0;
        }
        struct Node *parent;
        struct Node *leftChild;
        struct Node *rightChild;
        
        int left;
        int right;
        int count;
    };
    
    struct Node *build(int left, int right) {
        struct Node *node = new Node();
        node->left = left;
        node->right = right;
        if (left >= right) {
            return node;
        } else {
            int mid = (right - left + 1) / 2 + left;
            node->leftChild = build(left, mid - 1);
            node->rightChild = build(mid, right);
            node->leftChild->parent = node;
            node->rightChild->parent = node;
        }
        return node;
    }
    
    void traverseTree(struct Node *node, int val) {
        if (node == nullptr) {
            return;
        }
        
        if (node->left <= val || val <= node->right) {
            node->count++;
        } else {
            return;
        }
        
        if (node->leftChild == nullptr || node->rightChild == nullptr) {
            return;
        }
        
        if (node->leftChild->right >= val) {
            traverseTree(node->leftChild, val);
        } else {
            traverseTree(node->rightChild, val);
        }
    }
    
    int countSmaller(struct Node *node, int left, int right) {
        if (node == nullptr || left > right) {
            return 0;
        }
        
        if (node->left == left && node->right == right) {
            return node->count;
        }
        
        if (node->left == node->right && node->right == right) {
            return node->count;
        }
        
        if (node->leftChild->right < left) {
            return countSmaller(node->rightChild, left, right);
        } else if (node->rightChild->left > right) {
            return countSmaller(node->leftChild, left, right);
        } else {
            int leftCount = countSmaller(node->leftChild, left, node->leftChild->right);
            int rightCount = countSmaller(node->rightChild, node->rightChild->left, right);
            return leftCount + rightCount;
        }
    }
    
    struct Node *root;
    int count;
    int min, max;
};

//[10,27,10,35,12,22,28,8,19,2,12,2,9,6,12,5,17,9,19,12,14,6,12,5,12,3,0,10,0,7,8,4,0,0,4,3,2,0,1,0]
void test0() {
    Solution s;
    vector<int> nums({26,78,27,100,33,67,90,23,66,5,38,7,35,23,52,22,83,51,98,69,81,32,78,28,94,13,2,97,3,76,99,51,9,21,84,66,65,36,100,41});
    vector<int> smallerCount = s.countSmaller(nums);
    for (int item : smallerCount) {
        printf("%d ", item);
    }
    printf("\n");
}

void test1() {
    Solution s;
    vector<int> nums({5,2,6,1});
    vector<int> smallerCount = s.countSmaller(nums);
    for (int item : smallerCount) {
        printf("%d ", item);
    }
    printf("\n");
}

void test2() {
    Solution s;
    vector<int> nums({-1,-2});
    vector<int> smallerCount = s.countSmaller(nums);
    for (int item : smallerCount) {
        printf("%d ", item);
    }
    printf("\n");
}

void test3() {
    Solution s;
    vector<int> nums({1,-2});
    vector<int> smallerCount = s.countSmaller(nums);
    for (int item : smallerCount) {
        printf("%d ", item);
    }
    printf("\n");
}

void test4() {
    Solution s;
    vector<int> nums({-1,-1});
    vector<int> smallerCount = s.countSmaller(nums);
    for (int item : smallerCount) {
        printf("%d ", item);
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    // insert code here...
    test0();
    test1();
    test2();
    test3();
    test4();
    return 0;
}
