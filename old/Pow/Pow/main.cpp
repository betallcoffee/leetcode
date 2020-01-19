//
//  main.cpp
//  Pow
//
//  Created by liang on 3/10/17.
//  Copyright © 2017年 liang. All rights reserved.
//  https://leetcode.com/problems/powx-n/description/
/**
 Implement pow(x, n).
 */

#include <iostream>
#include <math.h>

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;
        else if (n == 0) return 1;
        else if (n == 1) return x;
        else if (n < 0) return 1 / (x * myPow(x, -(n + 1)));
        
        double t = myPow(x, n/2);
        t *= t;
        if (n % 2) {
            t *= x;
        }
        return t;
    }
};

void test1() {
    Solution s;
    printf("%lf %lf\n", s.myPow(2, 3), pow(2, 3));
}

void test2() {
    Solution s;
    printf("%lf %lf\n", s.myPow(8.88023, 3), pow(8.88023, 3));
}

void test3() {
    Solution s;
    printf("%lf %lf\n", s.myPow(34.00515, -3), pow(34.00515, -3));
}

int main(int argc, const char * argv[]) {
    // insert code here...
    test1();
    test2();
    test3();
    return 0;
}
