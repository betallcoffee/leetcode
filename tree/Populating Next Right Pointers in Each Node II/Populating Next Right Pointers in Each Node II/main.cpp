//
//  main.cpp
//  Populating Next Right Pointers in Each Node II
//
//  Created by liang on 23/1/2020.
//  Copyright © 2020 liang. All rights reserved.
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
/**
 Given a binary tree

 struct Node {
   int val;
   Node *left;
   Node *right;
   Node *next;
 }
 Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

 Initially, all next pointers are set to NULL.

  

 Follow up:

 You may only use constant extra space.
 Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.
  

 Example 1:



 Input: root = [1,2,3,4,5,null,7]
 Output: [1,#,2,3,#,4,5,7,#]
 Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
  

 Constraints:

 The number of nodes in the given tree is less than 6000.
 -100 <= node.val <= 100
 */

#include <vector>
#include <queue>

/*
// Definition for a Node.
 */
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        Node header1;
        Node header2;
        header1.next = root;
        Node* curHeader= &header1;
        Node* nextHeader = &header2;
        Node* end = nextHeader;
        
        while (curHeader->next != nullptr) {
            Node* cur = curHeader->next;
            
            if (cur->left != nullptr) {
                end->next = cur->left;
                end = end->next;
            }
            
            if (cur->right != nullptr) {
                end->next = cur->right;
                end = end->next;
            }
            
            
            curHeader->next = curHeader->next->next;
            if (curHeader->next == nullptr) {
                if (curHeader == &header1) {
                    curHeader = &header2;
                    nextHeader = &header1;
                    end = nextHeader;
                } else {
                    curHeader = &header1;
                    nextHeader = &header2;
                    end = nextHeader;
                }
                continue;
            }
            
        }
        
        return root;
    }
};


Node* createATree(std::vector<int> list) {
    Node* root = new Node(list[0]);
    std::queue<Node*> queue;
    queue.push(root);
    int i = 0;
    while (!queue.empty()) {
        Node* node = queue.front();
        queue.pop();
        if (node != nullptr) {
            int left = i * 2 + 1;
            int right = i * 2 + 2;
            if (left < list.size() && list[left] != 0) {
                node->left = new Node(list[left]);
                queue.push(node->left);
            }
            if (right < list.size() && list[right] != 0) {
                node->right = new Node(list[right]);
                queue.push(node->right);
            }
        }
        i++;
    }
    
    return root;
}

void test0() {
    std::vector<int> list = {1,2,3,4,5,0,7};
    Node* tree = createATree(list);
    Solution s;
    s.connect(tree);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    test0();
    return 0;
}
