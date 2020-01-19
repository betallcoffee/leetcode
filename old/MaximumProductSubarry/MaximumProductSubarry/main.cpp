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
//Let us denote that:
//
//f(k) = Largest product subarray, from index 0 up to k.
//
//Similarly,
//
//g(k) = Smallest product subarray, from index 0 up to k.
//
//Then,
//
//f(k) = max( f(k-1) * A[k], A[k], g(k-1) * A[k] )
//g(k) = min( g(k-1) * A[k], A[k], f(k-1) * A[k] )


#include <iostream>
#include <vector>

class Solution {
public:
    int maxProduct(int A[], int n) {
        int res = A[0];
        std::vector<int> max(n);
        std::vector<int> min(n);
        max[0] = A[0];
        min[0] = A[0];
        for (int i = 1; i < n ; ++i) {
            int a, b, c;
            a = max[i-1] * A[i];
            b = A[i];
            c = min[i-1] * A[i];
            max[i] = std::max(std::max(a, b), c);
            min[i] = std::min(std::min(a, b), c);
            if (res < max[i]) {
                res = max[i];
            }
        }
        return res;
    }
};

class Solution1 {
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
    int a1[] = {3, 2, 0, 4, 5, 9, 0, 10, 10, 10};
    std::cout << s->maxProduct(a1, 10) << std::endl;
    int a2[] = {-2, 0, -1};
    std::cout << s->maxProduct(a2, 3) << std::endl;
    int a3[] = {0, -2, 0};
    std::cout << s->maxProduct(a3, 3) << std::endl;
    int a4[] = {-2,3,-4};
    std::cout << s->maxProduct(a4, 3) << std::endl;
    return 0;
}





