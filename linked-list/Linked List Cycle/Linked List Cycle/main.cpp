//
//  main.cpp
//  Linked List Cycle
//
//  Created by liang on 2/2/2020.
//  Copyright © 2020 liang. All rights reserved.
// https://leetcode.com/problems/linked-list-cycle/
/**
 Given a linked list, determine if it has a cycle in it.

 To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

  

 Example 1:

 Input: head = [3,2,0,-4], pos = 1
 Output: true
 Explanation: There is a cycle in the linked list, where tail connects to the second node.


 Example 2:

 Input: head = [1,2], pos = 0
 Output: true
 Explanation: There is a cycle in the linked list, where tail connects to the first node.


 Example 3:

 Input: head = [1], pos = -1
 Output: false
 Explanation: There is no cycle in the linked list.


  

 Follow up:

 Can you solve it using O(1) (i.e. constant) memory?
 */

#include <iostream>


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (slow != nullptr && fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                return true;
            }
        }
        
        return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
