//
//  main.cpp
//  Multiply Strings
//
//  Created by liang on 8/1/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  Problem: https://leetcode.com/problems/multiply-strings/
//Given two numbers represented as strings, return multiplication of the numbers as a string.
//
//Note: The numbers can be arbitrarily large and are non-negative.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.length() == 0 || num2.length() == 0) {
            return "0";
        }
        
        vector<char> multiply;
        vector<char> temp;
        
        int digit1 = 1;
        string::reverse_iterator iter1 = num1.rbegin();
        for (; iter1 != num1.rend(); iter1++) {
            char c1 = *iter1;
            int multiplier = (c1 - '0');
            temp.clear();
            for (int i = 1; i < digit1; i++) {
                temp.push_back('0');
            }
            
            int result = 0;
            int carry = 0;
            int digit2 = 1;
            string::reverse_iterator iter2 = num2.rbegin();
            for (; iter2 != num2.rend(); iter2++) {
                char c2 = *iter2;
                int multipicand = (c2 - '0');
                result = multipicand * multiplier + carry;
                int remainder = result % 10;
                carry = result / 10;
                temp.push_back('0' + remainder);
                digit2++;
            }
            
            while (carry) {
                int remainder = carry % 10;
                carry = carry / 10;
                temp.push_back('0' + remainder);
            }
            multiply = add(multiply, temp);
            digit1++;
        }
        
        return removeZero(multiply);
    }
    
    string removeZero(vector<char> num) {
        string ret;
        if (num.size() > 1) {
            vector<char>::reverse_iterator iter = num.rbegin();
            while (iter != num.rend() && *iter == '0') {
                iter++;
            }
            if (iter == num.rend()) {
                ret = "0";
            } else {
                ret.assign(iter, num.rend());
            }
        } else {
            ret.assign(num.rbegin(), num.rend());
        }
        return ret;
    }
    
    vector<char> add(vector<char> num1, vector<char> num2) {
        string n1;
        n1.assign(num1.rbegin(), num1.rend());
        string n2;
        n2.assign(num2.rbegin(), num2.rend());
        string str = add(n1, n2);
        vector<char> ret;
        ret.assign(str.rbegin(), str.rend());
        return ret;
    }
    
    string add(string num1, string num2) {
        vector<char> add;
        int carry = 0;
        string max;
        string min;
        if (num1.length() >= num2.length()) {
            max = std::move(num1);
            min = std::move(num2);
        } else {
            max = std::move(num2);
            min = std::move(num1);
        }
        
        int length1 = (int)min.length();
        int length2 = (int)max.length();
        for (int i = 0; i < length1; i++) {
            char c1 = min[length1 - 1 - i];
            int n1 = (c1 - '0');
            char c2 = max[length2 - 1 - i];
            int n2 = (c2 - '0');
            int temp = n1 + n2 + carry;
            int remainder = temp % 10;
            carry = temp / 10;
            add.push_back('0' + remainder);
        }
        
        for (int i = length1; i < length2; i++) {
            char c2 = max[length2 - 1 - i];
            int n2 = (c2 - '0');
            int temp = n2 + carry;
            int remainder = temp % 10;
            carry = temp / 10;
            add.push_back('0' + remainder);
        }
        
        while (carry) {
            int remainder = carry % 10;
            carry = carry / 10;
            add.push_back('0' + remainder);
        }
        string ret;
        ret.assign(add.rbegin(), add.rend());
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    cout << s.multiply("9", "99") << endl;
    
    cout << s.multiply("99", "9") << endl;
    
    cout << s.multiply("1", "12") << endl;
    
    cout << s.multiply("0", "13") << endl;
    
    cout << s.multiply("1000", "44") << endl;
    
    cout << s.multiply("444", "100000") << endl;
    
    cout << s.multiply("", "44") << endl;
    
    return 0;
}
