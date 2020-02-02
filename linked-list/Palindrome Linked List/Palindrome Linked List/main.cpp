//
//  main.cpp
//  Palindrome Linked List
//
//  Created by liang on 2/2/2020.
//  Copyright © 2020 liang. All rights reserved.
// https://leetcode.com/problems/palindrome-linked-list/
/**
 Given a singly linked list, determine if it is a palindrome.

 Example 1:

 Input: 1->2
 Output: false
 Example 2:

 Input: 1->2->2->1
 Output: true
 Follow up:
 Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
        int count = 0;
        ListNode* cur = head;
        while (cur != nullptr) {
            count++;
            cur = cur->next;
        }
        
        if (count == 1) {
            return true;
        }
        
        int i = count / 2;
        ListNode reverseHead(0);
        cur = head;
        while (i > 0 && cur != nullptr) {
            ListNode* next = cur->next;
            cur->next = reverseHead.next;
            reverseHead.next = cur;
            i--;
            cur = next;
        }
        if (count % 2 > 0) {
            cur = cur->next;
        }
        
        ListNode* revCur = reverseHead.next;
        while (cur != nullptr && revCur != nullptr) {
            if (cur->val != revCur->val) {
                break;
            }
            cur = cur->next;
            revCur = revCur->next;
        }
        
        if (cur == nullptr && revCur == nullptr) {
            return true;
        } else {
            return false;
        }
    }
};

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

void test0() {
    Solution s;
    vector<int> nums = {1,0,1};
    ListNode *root = createList(nums);
    cout << "test0: " << s.isPalindrome(root) << endl;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    test0();
    return 0;
}
