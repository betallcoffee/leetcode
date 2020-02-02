//
//  main.cpp
//  Sort List
//
//  Created by liang on 2/2/2020.
//  Copyright © 2020 liang. All rights reserved.
// https://leetcode.com/problems/sort-list/
/**
 Sort a linked list in O(n log n) time using constant space complexity.

 Example 1:

 Input: 4->2->1->3
 Output: 1->2->3->4
 Example 2:

 Input: -1->5->3->4->0
 Output: -1->0->3->4->5
 */

#include <iostream>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        } else {
            ListNode* rightHead = nullptr;
            ListNode* leftHead = nullptr;
            ListNode* right = nullptr;
            ListNode* left = nullptr;
            ListNode* cur = head->next;
            ListNode* leftMax = nullptr;
            head->next = nullptr;
            while (cur != nullptr) {
                ListNode* next = cur->next;
                if (cur->val < head->val) {
                    if (left == nullptr) {
                        left = cur;
                        leftHead = left;
                        leftMax = left;
                    } else {
                        left->next = cur;
                        left = cur;
                        if (leftMax->val < left->val) {
                            leftMax = left;
                        }
                    }
                } else {
                    if (right == nullptr) {
                        right = cur;
                        rightHead = right;
                    } else {
                        right->next = cur;
                        right = cur;
                    }
                }
                cur->next = nullptr;
                cur = next;
            }
            rightHead = sortList(rightHead);
            head->next = rightHead;
            leftHead = sortList(leftHead);
            if (leftHead != nullptr) {
                if (leftMax != nullptr) {
                    ListNode* cur = leftMax;
                    while (cur->next != nullptr) {
                        cur = cur->next;
                    }
                    cur->next = head;
                } else {
                    leftHead->next = head;
                }
                head = leftHead;
            }
            
            return head;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
