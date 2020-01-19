//
//  main.cpp
//  Palindrome Number
//
//  Created by liang on 6/19/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  Problem: https://leetcode.com/problems/palindrome-number/
//Determine whether an integer is a palindrome. Do this without extra space.
//
//click to show spoilers.
//Some hints:
//
//Could negative integers be palindromes? (ie, -1)
//
//If you are thinking of converting the integer to string, note the restriction of using extra space.
//
//You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
//
//There is a more generic way of solving this problem.


#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int t = x;
        int y = 0;
        while (t) {
            y = y * 10 + t%10;
            t = t / 10;
        }
        if (x == y) {
            return true;
        } else {
            return false;
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    cout << s.isPalindrome(0) << endl;
    
    cout << s.isPalindrome(123321) << endl;
    
    return 0;
}
