//
//  main.cpp
//  Reverse Linked List II
//
//  Created by liang on 14/10/17.
//  Copyright © 2017年 liang. All rights reserved.
//  https://leetcode.com/problems/reverse-linked-list-ii/description/
/**
 Reverse a linked list from position m to n. Do it in-place and in one-pass.
 
 For example:
 Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 
 return 1->4->3->2->5->NULL.
 
 Note:
 Given m, n satisfy the following condition:
 1 ≤ m ≤ n ≤ length of list.
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n || head == nullptr) {
            return head;
        }
        
        ListNode node(0);
        ListNode* tail = nullptr;
        
        ListNode* pre = nullptr;
        ListNode* cur = nullptr;
        do {
            m--;
            n--;
            pre = cur;
            if (cur == nullptr) {
                cur = head;
            } else {
                cur = cur->next;
            }
        } while (m > 0 && cur != nullptr);
        
        while (cur != nullptr && n >= 0) {
            ListNode* next = cur->next;
            if (tail == nullptr) {
                tail = cur;
            }
            cur->next = node.next;
            node.next = cur;
            n--;
            cur = next;
        }
        
        tail->next = cur;
        if (pre != nullptr) {
            pre->next = node.next;
        } else {
            head = node.next;
        }
        
        return head;
    }
    
    ListNode* reverseBetween1(ListNode* head, int m, int n) {
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
        
        for (int i = 1; i < m; i++) {
            if (first) {
                first = first->next;
            }
            if (second) {
                second = second->next;
            }
            if (third) {
                third = third->next;
            }
        }
        
        ListNode *last = second;
        for (int i = m; i < n; i++) {
            if (third == NULL) {
                break;
            }
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
    root = s.reverseBetween(root, 2, 4);
    s.printList(root);
}

void test2() {
    Solution s;
    vector<int> nums = {1};
    ListNode *root = s.createList(nums);
    s.printList(root);
    root = s.reverseBetween(root, 1, 1);
    s.printList(root);
}

void test3() {
    Solution s;
    vector<int> nums = {3,5};
    ListNode *root = s.createList(nums);
    s.printList(root);
    root = s.reverseBetween(root, 1, 1);
    s.printList(root);
}

void test4() {
    Solution s;
    vector<int> nums = {3,5};
    ListNode *root = s.createList(nums);
    s.printList(root);
    root = s.reverseBetween(root, 1, 2);
    s.printList(root);
}

void test5() {
    Solution s;
    vector<int> nums = {1,2,3};
    ListNode *root = s.createList(nums);
    s.printList(root);
    root = s.reverseBetween(root, 1, 2);
    s.printList(root);
}

int main(int argc, const char * argv[]) {
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}
