//
//  main.cpp
//  Permutation Sequence
//
//  Created by liang on 12/10/17.
//  Copyright © 2017年 liang. All rights reserved.
//  https://leetcode.com/problems/permutation-sequence/description/
/**
 The set [1,2,3,…,n] contains a total of n! unique permutations.
 
 By listing and labeling all of the permutations in order,
 We get the following sequence (ie, for n = 3):
 
 "123"
 "132"
 "213"
 "231"
 "312"
 "321"
 Given n and k, return the kth permutation sequence.
 
 123456
 123465
 123546
 123564
 123645
 123654
 
 Note: Given n will be between 1 and 9 inclusive.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        if (k <= 0) {
            return "";
        }
        vector<int> array;
        for (int i = 1; i <= n; i++) {
            array.push_back(i);
        }
        
        int size = (int)array.size();
        k--;
        while (k) {
            for (int i = size - 1; i > 0; i--) {
                if (array[i] > array[i-1]) {
                    int l = i;
                    int r = size - 1;
                    while (l < r) {
                        swap(array[l], array[r]);
                        l++;
                        r--;
                    }
                    for (int j = i; j < size; j++) {
                        if (array[j] > array[i-1]) {
                            swap(array[j], array[i-1]);
                            break;
                        }
                    }
                    break;
                }
            }
            k--;
        }
        
        string s = "";
        for (int i = 0; i < n; i++) {
            s.append(1, '0' + array[i]);
        }
        return s;
    }
    
    // 康托逆扩展
    string getPermutationFromCantor(int n, int k) {
        k--;
        if (k < 0) {
            return "";
        }
        
        int fact = 1;
        for (int i = 1; i < n; i++) {
            fact *= i;
        }
        
        vector<int> array(n + 1, 0);
        string s = "";
        int dividend = k;
        int divisor = fact;
        int quot = 0;
        int remainder = 0;
        for (int i = n - 1; i > 0; i--) {
            quot = dividend / divisor;
            remainder = dividend % divisor;
            int num = quot + 1;
            while (array[num]) {
                num++;
            }
            s.append(1, '0' + num);
            array[num] = 1;
            dividend = remainder;
            divisor /= i;
        }
        
        for (int i = 1; i <= n; i++) {
            if (array[i] == 0) {
                s.append(1, '0' + i);
            }
        }
        
        return s;
    }
};

void test1() {
    Solution s;
    printf("%s\n", s.getPermutation(6, 0).c_str());
}

void test2() {
    Solution s;
    printf("%s\n", s.getPermutation(3, 2).c_str());
}

int main(int argc, const char * argv[]) {
    test1();
    test2();
    return 0;
}
