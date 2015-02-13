//
//  main.cpp
//  MaximumProductSubarry
//
//  Created by liang on 10/26/14.
//  Copyright (c) 2014 Tina. All rights reserved.
//  Problem: https://oj.leetcode.com/problems/maximum-product-subarray/
//Find the contiguous subarray within an array (containing at least one number) which has the largest product.
//
//For example, given the array [2,3,-2,4],
//the contiguous subarray [2,3] has the largest product = 6.

#include <iostream>

class Solution {
public:
    int maxProduct(int A[], int n) {
        int max = 0;
        int max1 = 1;
        int max2 = 1;
        int negative = 0;
        if (n == 1) {
            return A[0];
        }
        for (int i = 0; i < n; i++ ) {
            if (A[i] == 0) {
                int maxr = 0;
                if (i > 0) {
                    maxr = this->maxProduct(A, i);;
                }
                int maxl = 0;
                if ((n - i - 1) > 0) {
                    maxl =this->maxProduct(A + i + 1, n - i - 1);
                }
                if (maxr > maxl) {
                    max = maxr;
                } else {
                    max = maxl;
                }
                if (max < 0) {
                    max = 0;
                }
                return max;
            }
            max1 *= A[i];
            if (negative > 0) {
                max2 *= A[i];
            }
            if (A[i] < 0) {
                negative++;
            }
        }
        if (negative%2 == 0 && max1 > max) {
            max = max1;
        } else {
            int max3 = 1;
            negative = 0;
            for (int i = n -1; i >= 0; i-- ) {
                if (negative > 0) {
                    max3 *= A[i];
                }
                if (A[i] < 0) {
                    negative++;
                }
            }
            if (max2 > max3 && max2 > max) {
                max = max2;
            } else if (max3 > max) {
                max = max3;
            }
        }
        return max;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    Solution *s = new Solution();
    int a[] = {3, 2, 0, 4, 5, 9, 0, 10, 10, 10};
//    int a[] = {-2, 0, -1};
//    int a[] = {0, -2, 0};
    std::cout << s->maxProduct(a, 10);
    return 0;
}





