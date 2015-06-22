//
//  main.cpp
//  Remove Nth Node From End of List
//
//  Created by liang on 6/22/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  Problem: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
//Given a linked list, remove the nth node from the end of list and return its head.
//
//For example,
//
//Given linked list: 1->2->3->4->5, and n = 2.
//
//After removing the second node from the end, the linked list becomes 1->2->3->5.
//
//Note:
//Given n will always be valid.
//Try to do this in one pass.

#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode *> nodes;
        ListNode *p = head;
        while (p) {
            nodes.push_back(p);
            p = p->next;
        }
        
        n = (int)nodes.size() - n;
        if (n > 0 && n < nodes.size()) {
            p = nodes[n - 1];
            p->next = p->next->next;
        } else if (n == 0) {
            return head->next;
        }
        
        return head;
    }
};

ListNode *createList(int nums[], int count) {
    ListNode *p = nullptr;
    ListNode *head = nullptr;
    for (int i = 0; i < count; i++) {
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

int main(int argc, const char * argv[]) {
    Solution s;
    
    int case1[] = {1,2,3,4,5};
//    printList(s.removeNthFromEnd(createList(case1, sizeof(case1) / sizeof(int)), 2));
    
    int case2[] = {};
//    printList(s.removeNthFromEnd(createList(case2, sizeof(case2) / sizeof(int)), 2));
    
    int case3[] = {1,2,3,4,5};
//    printList(s.removeNthFromEnd(createList(case3, sizeof(case3) / sizeof(int)), 0));
    
    int case4[] = {1};
//    printList(s.removeNthFromEnd(createList(case4, sizeof(case4) / sizeof(int)), 1));
    
    int case5[] = {1,2};
    printList(s.removeNthFromEnd(createList(case5, sizeof(case5)/ sizeof(int)), 2));
    
    return 0;
}
