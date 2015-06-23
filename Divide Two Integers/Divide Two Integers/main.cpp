//
//  main.cpp
//  Divide Two Integers
//
//  Created by liang on 6/22/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  Problem: https://leetcode.com/problems/divide-two-integers/
//Divide two integers without using multiplication, division and mod operator.
//
//If it is overflow, return MAX_INT.

#include <iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) {
            return INT_MAX;
        }
        
        bool isNegatvie = false;
        if ((dividend < 0 && divisor < 0) ||
            (dividend >= 0 && divisor > 0)) {
            isNegatvie = false;
        } else {
            isNegatvie = true;
        }
        
        long ldividend = dividend;
        ldividend = ldividend < 0 ? -ldividend : ldividend;
        long ldivisor = divisor;
        ldivisor = ldivisor < 0 ? -ldivisor : ldivisor;
        long count = 0;
        while (ldivisor <= ldividend) {
            ldivisor <<= 1;
            count++;
        }
        
        long result = 0;
        while (count >= 0) {
            if (ldividend >= ldivisor) {
                ldividend -= ldivisor;
                result += (long)1 << count;
            }
            ldivisor >>= 1;
            count--;
        }
        
        if (isNegatvie) {
            return -(int)result;
        } else {
            if (result >= 2147483648) {
                result = 2147483647;
            }
            return (int)result;
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    cout << s.divide(-2147483648, 1) << endl;
    
    cout << s.divide(-2147483648, -1) << endl;
    
    cout << s.divide(-1010369383, -2147483648) << endl;
    
    cout << s.divide(2147483647, 1) << endl;
    
    cout << s.divide(10, 2) << endl;
    
    cout << s.divide(10, 3) << endl;
    
    cout << s.divide(1, -1) << endl;
    
    return 0;
}
