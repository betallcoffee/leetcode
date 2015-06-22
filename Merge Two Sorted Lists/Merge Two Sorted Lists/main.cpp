//
//  main.cpp
//  Merge Two Sorted Lists
//
//  Created by liang on 6/22/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  Problem: https://leetcode.com/problems/merge-two-sorted-lists/
//Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr;
        ListNode *p = nullptr;
        while (l1 && l2) {
            ListNode *q;
            if (l1->val < l2->val) {
                q = l1;
                l1 = l1->next;
            } else {
                q = l2;
                l2 = l2->next;
            }
            if (p) {
                p->next = q;
                p = q;
            } else {
                p = q;
                head = p;
            }
        }
        ListNode *q = nullptr;
        if (l1) {
            q = l1;
        } else if (l2) {
            q = l2;
        }
        
        if (p && q) {
            p->next = q;
        } else if (q) {
            head = q;
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
    
    int case11[] = {1, 3, 5, 23, 87};
    int case12[] = {3, 5, 8, 9, 10};
    printList(s.mergeTwoLists(createList(case11, sizeof(case11) / sizeof(int)), createList(case12, sizeof(case12) / sizeof(int))));
    
    int case21[] = {};
    int case22[] = {1,3,4,5,9};
    printList(s.mergeTwoLists(createList(case21, sizeof(case21) / sizeof(int)), createList(case22, sizeof(case22) / sizeof(int))));
    
    int case31[] = {1,3,4,5,9};
    int case32[] = {};
    printList(s.mergeTwoLists(createList(case31, sizeof(case31) / sizeof(int)), createList(case32, sizeof(case32) / sizeof(int))));
    
    return 0;
}
