//
//  main.cpp
//  Valid Palindrome
//
//  Created by liang on 31/1/2020.
//  Copyright © 2020 liang. All rights reserved.
// https://leetcode.com/problems/valid-palindrome/
/**
 Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

 Note: For the purpose of this problem, we define empty string as valid palindrome.

 Example 1:

 Input: "A man, a plan, a canal: Panama"
 Output: true
 Example 2:

 Input: "race a car"
 Output: false
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() <= 1) {
            return true;
        }
        
        size_t start = 0;
        size_t end = s.size() - 1;
        while (start < end) {
            char cs = std::tolower(s[start]);
            if (!('a' <= cs && cs <= 'z') &&
                !('0' <= cs && cs <= '9')) {
                start++;
                continue;
            }

            char ce = std::tolower(s[end]);
            if (!('a' <= ce && ce <= 'z') &&
                !('0' <= ce && ce <= '9')) {
                end--;
                continue;
            }
            
            if (cs == ce) {
                start++;
                end--;
                continue;
            }
            
            return false;
        }
        return true;
    }
};

void test0() {
    Solution s;
    cout << s.isPalindrome("A man, a plan, a canal: Panama") << endl;
}

void test1() {
    Solution s;
    cout << s.isPalindrome("race a car") << endl;
}

void test2() {
    Solution s;
    cout << s.isPalindrome("0P") << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    test0();
    test1();
    test2();
    return 0;
}
