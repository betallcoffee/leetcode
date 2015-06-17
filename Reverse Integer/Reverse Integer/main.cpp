//
//  main.cpp
//  Reverse Integer
//
//  Created by liang on 6/17/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  Problem: https://leetcode.com/problems/reverse-integer/
//Reverse digits of an integer.
//
//Example1: x = 123, return 321
//Example2: x = -123, return -321
//
//click to show spoilers.
//Have you thought about this?
//
//Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
//
//If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
//
//Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?
//
//For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
//
//Update (2014-11-10):
//Test cases had been added to test the overflow behavior.


#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long max = (1 << 31) - 1;
        int n = x >= 0 ? x : -x;
        long long r = 0;
        while (n) {
            int t = n % 10;
            r = r * 10 + t;
            n = n / 10;
        }
        r = r > max ? 0 : r;
        r = r < 0 ? 0 : r;
        r = x >= 0 ? r : -r;
        return (int)r;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    cout << s.reverse(1534236469) << endl;
    
    cout << s.reverse(-2147483648) << endl;
    
    cout << s.reverse(1000000003) << endl;
    
    cout << s.reverse(123) << endl;
    
    cout << s.reverse(-123) << endl;
    
    cout << s.reverse(0) << endl;
    
    cout << s.reverse(1) << endl;
    
    cout << s.reverse(-1) << endl;
    
    cout << s.reverse(100) << endl;
    
    cout << s.reverse(-100) << endl;
    
    return 0;
}
