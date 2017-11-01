//
//  main.cpp
//  Gray Code
//
//  Created by liang on 29/10/17.
//  Copyright © 2017年 liang. All rights reserved.
//  https://leetcode.com/problems/gray-code/description/
/**
 The gray code is a binary numeral system where two successive values differ in only one bit.
 
 Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
 
 For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
 
 00 - 0
 01 - 1
 11 - 3
 10 - 2
 Note:
 For a given n, a gray code sequence is not uniquely defined.
 
 For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
 
 For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
 
 [0,1,3,2,6,7,5,4]
 000
 001
 011
 010
 110
 111
 101
 100
 1100
 1101
 1111
 1110
 1010
 1011
 1001
 1000
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> seqs = {0};
        for (int i = 0; i < n; i++) {
            int size = (int)seqs.size();
            for (int j = size - 1; j >= 0; j--) {
                int k = seqs[j];
                k ^= (1 << i);
                seqs.push_back(k);
            }
        }
        return seqs;
    }
};

void test(int n) {
    Solution s;
    vector<int> seqs = s.grayCode(n);
    for_each(seqs.begin(), seqs.end(), [&](int n) {
        printf("%d ", n);
    });
    printf("\n");
}

int main(int argc, const char * argv[]) {
    // insert code here...
    test(2);
    
    test(3);
    
    test(4);
    
    return 0;
}
