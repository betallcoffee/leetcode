//
//  main.cpp
//  Reverse Linked List
//
//  Created by liang on 14/10/17.
//  Copyright © 2017年 liang. All rights reserved.
//  https://leetcode.com/problems/reverse-linked-list/description/
/**
 Reverse a singly linked list.
 
 click to show more hints.
 
 Hint:
 A linked list can be reversed either iteratively or recursively. Could you implement both?
 */

#include <iostream>
#include <vector>

using namespace std;

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
    ListNode* reverseList(ListNode* head) {
        ListNode node(0);
        node.next = head;
        
        ListNode *first = NULL;
        ListNode *second = NULL;
        ListNode *third = NULL;
        
        first = &node;
        if (first) {
            second = first->next;
        }
        if (second) {
            third = second->next;
        }
        
        ListNode *last = second;
        while (third) {
            ListNode *temp = third->next;
            first->next = third;
            third->next = second;
            second = first->next;
            third = temp;
            last->next = third;
        }
        
        return node.next;
    }
    
    ListNode *createList(vector<int> &nums) {
        ListNode *p = nullptr;
        ListNode *head = nullptr;
        for (int i = 0; i < nums.size(); i++) {
            if (p) {
                p->next = (ListNode *)calloc(sizeof(ListNode), 1);
                p = p->next;
            } else {
                p = (ListNode *)calloc(sizeof(ListNode), 1);
                head = p;
            }
            p->val = nums[i];
        }
        return head;
    }
    
    void printList(ListNode *head) {
        while (head) {
            cout << head->val << "->";
            head = head->next;
        }
        cout << endl;
    }
};

void test1() {
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5};
    ListNode *root = s.createList(nums);
    s.printList(root);
    root = s.reverseList(root);
    s.printList(root);
}

void test2() {
    Solution s;
    vector<int> nums = {1};
    ListNode *root = s.createList(nums);
    s.printList(root);
    root = s.reverseList(root);
    s.printList(root);
}

void test3() {
    Solution s;
    vector<int> nums = {1, 2};
    ListNode *root = s.createList(nums);
    s.printList(root);
    root = s.reverseList(root);
    s.printList(root);
}

int main(int argc, const char * argv[]) {
    test1();
    test2();
    test3();
    return 0;
}
