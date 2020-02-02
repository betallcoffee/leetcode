//
//  main.cpp
//  Linked List Cycle II
//
//  Created by liang on 2/2/2020.
//  Copyright © 2020 liang. All rights reserved.
// https://leetcode.com/problems/linked-list-cycle-ii/
/**
 Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

 To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

 Note: Do not modify the linked list.

  

 Example 1:

 Input: head = [3,2,0,-4], pos = 1
 Output: tail connects to node index 1
 Explanation: There is a cycle in the linked list, where tail connects to the second node.


 Example 2:

 Input: head = [1,2], pos = 0
 Output: tail connects to node index 0
 Explanation: There is a cycle in the linked list, where tail connects to the first node.


 Example 3:

 Input: head = [1], pos = -1
 Output: no cycle
 Explanation: There is no cycle in the linked list.


  

 Follow-up:
 Can you solve it without using extra space?
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool isCycle = false;
        while (slow != nullptr && fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                isCycle = true;
                break;
            }
        }
        
        if (!isCycle) {
            return nullptr;
        } else {
            ListNode* temp = head;
            while (temp != nullptr) {
                if (temp == slow) {
                    break;
                }
                temp = temp->next;
                slow = slow->next;
            }
            return temp;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
