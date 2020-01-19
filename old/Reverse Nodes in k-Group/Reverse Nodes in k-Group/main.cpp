//
//  main.cpp
//  Reverse Nodes in k-Group
//
//  Created by liang on 6/22/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  Problem: https://leetcode.com/problems/reverse-nodes-in-k-group/
//Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//
//If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
//
//You may not alter the values in the nodes, only nodes itself may be changed.
//
//Only constant memory is allowed.
//
//For example,
//Given this linked list: 1->2->3->4->5
//
//For k = 2, you should return: 2->1->4->3->5
//
//For k = 3, you should return: 3->2->1->4->5

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1) {
            return head;
        }
        
        ListNode *p = head;
        ListNode h(0);
        ListNode *f = nullptr;
        h.next = head;
        while (p) {
            int count = k;
            ListNode *q = nullptr;
            ListNode *l = nullptr;
            while (count) {
                ListNode *t = p;
                p = p->next;
                t->next = q;
                q = t;
                if (l == nullptr) {
                    l = q;
                }
                count--;
                if (count && p == nullptr) {
                    while (q) {
                        t = q->next;
                        q->next = p;
                        p = q;
                        q = t;
                    }
                    q = p;
                    p = nullptr;
                    l = nullptr;
                    break;
                }
            }
            
            if (f == nullptr) {
                h.next = q;
            } else {
                f->next = q;
            }
            f = l;
        }
        
        return h.next;
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
    printList(s.reverseKGroup(createList(case1, sizeof(case1) / sizeof(int)), 3));
    
    int case2[] = {3, 5, 8, 9, 10};
    printList(s.reverseKGroup(createList(case2, sizeof(case2) / sizeof(int)), 2));
    
    return 0;
}

