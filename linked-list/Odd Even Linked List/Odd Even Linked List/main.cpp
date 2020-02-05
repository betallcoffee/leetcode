//
//  main.cpp
//  Odd Even Linked List
//
//  Created by liang on 5/2/2020.
//  Copyright © 2020 liang. All rights reserved.
// https://leetcode.com/problems/odd-even-linked-list/
/**
 Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

 You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

 Example 1:

 Input: 1->2->3->4->5->NULL
 Output: 1->3->5->2->4->NULL
 Example 2:

 Input: 2->1->3->5->6->4->7->NULL
 Output: 2->3->6->7->1->5->4->NULL
 Note:

 The relative order inside both the even and odd groups should remain as it was in the input.
 The first node is considered odd, the second node even and so on ...
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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* oddTail = head;
        ListNode* evenTail = nullptr;
        ListNode* evenHead = nullptr;
        
        int count = 1;
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* next = cur->next;
            cur->next = nullptr;
            if (count % 2 == 1) {
                oddTail->next = cur;
                oddTail = oddTail->next;
            } else {
                if (evenHead == nullptr) {
                    evenHead = cur;
                }
                if (evenTail == nullptr) {
                    evenTail = cur;
                } else {
                    evenTail->next = cur;
                    evenTail = evenTail->next;
                }
            }
            count++;
            cur = next;
        }
        
        if (oddTail != nullptr) {
            oddTail->next = evenHead;
        }
        
        return head;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
