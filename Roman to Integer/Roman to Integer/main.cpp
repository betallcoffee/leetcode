//
//  main.cpp
//  Roman to Integer
//
//  Created by liang on 6/21/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  Problem: https://leetcode.com/problems/roman-to-integer/
//Given a roman numeral, convert it to an integer.
//
//Input is guaranteed to be within the range from 1 to 3999.

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int convert[26];
        convert['I' - 'A'] = 1;
        convert['V' - 'A'] = 5;
        convert['X' - 'A'] = 10;
        convert['L' - 'A'] = 50;
        convert['C' - 'A'] = 100;
        convert['D' - 'A'] = 500;
        convert['M' - 'A'] = 1000;
        
        vector<int> nums;
        for_each(s.rbegin(), s.rend(), [&](char c) {
            nums.push_back(convert[c - 'A']);
        });
        
        int result = 0;
        int size = (int)nums.size();
        for (int i = 0; i < size; i++) {
            int n = nums[i];
            if (i > 0) {
                int m = nums[i - 1];
                if (m > n) {
                    n = -n;
                }
            }
            result += n;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    cout << s.romanToInt("MMMCMXCIX") << endl;
    
    cout << s.romanToInt("MM") << endl;
    
    cout << s.romanToInt("MCMXC") << endl;
    
    cout << s.romanToInt("CMXCIX") << endl;
    
    cout << s.romanToInt("CD") << endl;
    
    cout << s.romanToInt("XCIX") << endl;
    
    cout << s.romanToInt("XCVIII") << endl;
    
    cout << s.romanToInt("VI") << endl;
    
    cout << s.romanToInt("IX") << endl;
    
    return 0;
}
