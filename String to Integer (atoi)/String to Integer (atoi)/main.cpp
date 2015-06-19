//
//  main.cpp
//  String to Integer (atoi)
//
//  Created by liang on 6/18/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  Problem: https://leetcode.com/problems/string-to-integer-atoi/

//Implement atoi to convert a string to an integer.
//
//Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
//
//Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
//
//Update (2015-02-10):
//The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button to reset your code definition.
//
//spoilers alert... click to show requirements for atoi.
//Requirements for atoi:
//
//The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
//
//The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
//
//If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
//
//If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        bool isValid = true;
        bool isOverflow = false;
        bool isNegative = false;
        bool isDigit = false;
        bool isIgnore = false;
        long integer = 0;
        int result;
        int index = 0;
        
        for_each(str.begin(), str.end(), [&](char c){
            if (c < '0' || c > '9') {
                if('-' == c && !isDigit) {
                    isDigit = true;
                    isNegative = true;
                } else if('+' == c && !isDigit) {
                    isDigit = true;
                    isNegative = false;
                } else if (' ' == c && !isDigit) {
                    isValid = true;
                } else {
                    if (isDigit) {
                        isValid = true;
                        isIgnore = true;
                    } else {
                        isValid = false;
                    }
                }
            } else if (!isIgnore){
                isDigit = true;
                integer = integer * 10 + (c - '0');
                if (!isNegative && integer > INT_MAX) {
                    isOverflow = true;
                    result = INT_MAX;
                }
                if (isNegative && -integer < INT_MIN)  {
                    isOverflow = true;
                    result = INT_MIN;
                }
            }
            index++;
        });
        
        if (!isValid) {
            result = 0;
        } else if (isOverflow) {

        } else {
            result = (int)integer;
            if (isNegative) {
                result = -result;
            }
        }
        
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    cout << s.myAtoi("  -0012a42") << endl;
    
    cout << s.myAtoi("+-2") << endl;
    
    cout << s.myAtoi("   +-2") << endl;
    
    cout << s.myAtoi("-+2") << endl;
    
    cout << s.myAtoi("   -+2") << endl;
    
    cout << s.myAtoi("    +0004500") << endl;
    
    cout << s.myAtoi("     010") << endl;
    
    cout << s.myAtoi("1234") << endl;
    
    cout << s.myAtoi("+1") << endl;
    
    cout << s.myAtoi("-153234") << endl;
    
    cout << s.myAtoi("-2147483648") << endl;
    
    cout << s.myAtoi("2147483647") << endl;
    
    cout << s.myAtoi("2147483649") << endl;
    
    cout << s.myAtoi("-2147483649") << endl;
    
    cout << s.myAtoi("") << endl;
    
    cout << s.myAtoi("0") << endl;
    
    return 0;
}
