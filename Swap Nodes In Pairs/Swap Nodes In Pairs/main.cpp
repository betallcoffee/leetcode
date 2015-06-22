//
//  main.cpp
//  Swap Nodes In Pairs
//
//  Created by liang on 6/22/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  Problem: https://leetcode.com/problems/swap-nodes-in-pairs/
//Given a linked list, swap every two adjacent nodes and return its head.
//
//For example,
//Given 1->2->3->4, you should return the list as 2->1->4->3.
//
//Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

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
    ListNode* swapPairs(ListNode* head) {
        ListNode *p = head;
        ListNode *q = nullptr;
        while (p) {
            ListNode *t = p->next;
            if (t) {
                p->next = t->next;
                t->next = p;
                if (q) {
                    q->next = t;
                }
                q = p;
                p = p->next;
                if (t->next == head) {
                    head = t;
                }
            } else {
                p = t;
            }
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
    
    int case1[] = {1, 3, 5, 23, 87};
    printList(s.swapPairs(createList(case1, sizeof(case1) / sizeof(int))));
    
    int case2[] = {3, 5, 8, 9, 10};
    printList(s.swapPairs(createList(case2, sizeof(case2) / sizeof(int))));

    return 0;
}
