//
//  main.cpp
//  Merge k Sorted Lists
//
//  Created by liang on 6/22/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  Problem: https://leetcode.com/problems/merge-k-sorted-lists/
//Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity. 

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    struct node {
        int index;
        int val;
    };
    bool operator()(const node &l, const node &r) {
        return l.val > r.val;
    }
    
    ListNode* mergeKLists1(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        } else if (lists.size() == 1) {
            return lists[0];
        }
        
        ListNode *head = nullptr;
        ListNode *p = nullptr;
        
        
        int size = (int)lists.size();
        priority_queue<node, vector<node>, Solution> heap;
        for (int i = 0; i < size; i++) {
            if (lists[i]) {
                node n;
                n.index = i;
                n.val = lists[i]->val;
                heap.push(n);
            }
        }
        
        while (true) {
            if (!heap.empty()) {
                node top = heap.top();
                heap.pop();
                int index = top.index;
                ListNode *q = lists[index];
                
                if (q) {
                    lists[index] = q->next;
                    if (lists[index]) {
                        node n;
                        n.index = index;
                        n.val = lists[index]->val;
                        heap.push(n);
                    }
                }
                
                if (q && p) {
                    p->next = q;
                    p = q;
                } else if (q && p == nullptr) {
                    p = q;
                    head = p;
                }
            }
            else {
                break;
            }
        }
        
        return head;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        } else if (lists.size() == 1) {
            return lists[0];
        }
        
        int size = (int)lists.size();
        while (size > 1) {
            for (int i = 0; i < size;) {
                if (i + 1 < size) {
                    lists[i/2] = mergeTwoLists(lists[i], lists[i + 1]);
                } else {
                    lists[i/2] = lists[i];
                }
                i += 2;
            }
            size = size/2 + size%2;
        }
        
        return lists[0];
    }
    
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
    
    int case41[] = {1};
    int case42[] = {0};
    vector<ListNode *> v4;
    v4.push_back(createList(case41, sizeof(case41) / sizeof(int)));
    v4.push_back(createList(case42, sizeof(case42) / sizeof(int)));
    printList(s.mergeKLists(v4));

    int case11[] = {1, 3, 5, 23, 87};
    int case12[] = {3, 5, 8, 9, 10};
    vector<ListNode *> v1;
    v1.push_back(createList(case11, sizeof(case11) / sizeof(int)));
    v1.push_back(createList(case12, sizeof(case12) / sizeof(int)));
    printList(s.mergeKLists(v1));
    
    int case21[] = {};
    int case22[] = {1,3,4,5,9};
    vector<ListNode *> v2;
    v2.push_back(createList(case21, sizeof(case21) / sizeof(int)));
    v2.push_back(createList(case22, sizeof(case22) / sizeof(int)));
    printList(s.mergeKLists(v2));
    
    int case31[] = {1,3,4,5,9};
    int case32[] = {};
    vector<ListNode *> v3;
    v3.push_back(createList(case31, sizeof(case31) / sizeof(int)));
    v3.push_back(createList(case32, sizeof(case32) / sizeof(int)));
    printList(s.mergeKLists(v3));
    
    return 0;
}

