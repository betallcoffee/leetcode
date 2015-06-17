//
//  main.cpp
//  ZigZag Conversion
//
//  Created by liang on 6/17/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  Problem: https://leetcode.com/problems/zigzag-conversion/
//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
//
//P   A   H   N
//A P L S I I G
//Y   I   R
//
//And then read line by line: "PAHNAPLSIIGYIR"
//
//Write the code that will take a string and make this conversion given a number of rows:
//
//string convert(string text, int nRows);
//
//convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string result;
        int unitNum = numRows * 2 - 2;
        int unitCount = ((int)s.size() + unitNum) / unitNum;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < unitCount; j++) {
                if (i + j * unitNum < s.size()) {
                    result.push_back(s[i + j * unitNum]);
                }
                if (i > 0 && i < numRows - 1) {
                    if (j * unitNum + unitNum - i > 0 && j * unitNum + unitNum - i < s.size()) {
                        result.push_back(s[j * unitNum + unitNum - i]);
                    }
                }
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    cout << s.convert("PAYPALISHIRING", 3) << endl;
    
    cout << s.convert("", 1) << endl;
    
    cout << s.convert("", 2) << endl;
    
    cout << s.convert("", 3) << endl;
    
    return 0;
}
