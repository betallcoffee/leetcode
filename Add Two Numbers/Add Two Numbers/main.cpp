//
//  main.cpp
//  Add Two Numbers
//
//  Created by liang on 6/15/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  Problem: https://leetcode.com/problems/add-two-numbers/
//You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8

#include <iostream>
#include <stdlib.h>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *r = (ListNode *)calloc(sizeof(struct ListNode), 1);
        if (l1 && !l2) {
            return  l1;
        } else if (!l1 && l2) {
            return l2;
        } else if (!l1 && !l2) {
            r->val = 0;
            return r;
        } else {
            ListNode *t = r;
            int carry = 0;
            do {
                t->next = (ListNode *)calloc(sizeof(struct ListNode), 1);
                t = t->next;
                t->val = l1->val + l2->val + carry;
                carry = t->val / 10;
                t->val = t->val % 10;
                l1 = l1->next;
                l2 = l2->next;
            }while (l1 && l2);
            t->next = l1 ? l1 : l2;
            ListNode *p = t->next;
            while (p) {
                p->val += carry;
                carry = p->val / 10;
                p->val = p->val % 10;
                p = p->next;
                t = t->next;
            };
            // 最高位还要进一，新加一位。
            if (carry > 0) {
                t->next = (ListNode *)calloc(sizeof(struct ListNode), 1);
                t = t->next;
                t->val = carry;
            }
            return r->next;
        }
    }
};

ListNode *createList(int num[], int count) {
    ListNode *h = (ListNode *)calloc(sizeof(struct ListNode), 1);
    ListNode *t = h;
    for (int i = 0; i < count; i++) {
        t->next = (ListNode *)calloc(sizeof(struct ListNode), 1);
        t = t->next;
        t->val = num[i];
    }
    return h->next;
}

void printList(ListNode *l) {
    while (l) {
        std::cout << l->val << " ";
        l = l->next;
    }
    std::cout << std::endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    
    printList(s.addTwoNumbers(nullptr, nullptr));
    
    int case11[] = {2, 4, 3};
    int case12[] = {5, 6, 4};
    printList(s.addTwoNumbers(createList(case11, sizeof(case11)/sizeof(int)), createList(case12, sizeof(case12)/sizeof(int))));
    
    int case21[] = {2, 4, 3};
    printList(s.addTwoNumbers(createList(case21, sizeof(case11)/sizeof(int)), nullptr));
    
    int case32[] = {5, 6, 4};
    printList(s.addTwoNumbers(nullptr, createList(case32, sizeof(case32)/sizeof(int))));
    
    int case41[] = {2, 4};
    int case42[] = {5, 6};
    printList(s.addTwoNumbers(createList(case41, sizeof(case41)/sizeof(int)), createList(case42, sizeof(case42)/sizeof(int))));
    
    int case51[] = {2, 4};
    int case52[] = {5, 6, 3};
    printList(s.addTwoNumbers(createList(case51, sizeof(case51)/sizeof(int)), createList(case52, sizeof(case52)/sizeof(int))));
    
    int case61[] = {2, 4, 7, 4};
    int case62[] = {5, 6, 3};
    printList(s.addTwoNumbers(createList(case61, sizeof(case61)/sizeof(int)), createList(case62, sizeof(case62)/sizeof(int))));
    
    int case71[] = {4};
    int case72[] = {5};
    printList(s.addTwoNumbers(createList(case71, sizeof(case71)/sizeof(int)), createList(case72, sizeof(case72)/sizeof(int))));
    
    return 0;
}
