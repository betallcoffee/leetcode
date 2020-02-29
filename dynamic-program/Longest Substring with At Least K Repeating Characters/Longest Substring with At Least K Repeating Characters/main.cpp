//
//  main.cpp
//  Longest Substring with At Least K Repeating Characters
//
//  Created by liang on 29/2/2020.
//  Copyright © 2020 liang. All rights reserved.
//  https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/
/**
 Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less than k times.

 Example 1:

 Input:
 s = "aaabb", k = 3

 Output:
 3

 The longest substring is "aaa", as 'a' is repeated 3 times.
 Example 2:

 Input:
 s = "ababbc", k = 2

 Output:
 5

 The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
 */

#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    /**
     * @param s 字符串
     * @param k 重复次数
     * @param countRecord 字符串中各个字符出现的次数
     */
    int longestSubstringRecur(string s, int k, map<char, int>& countRecord) {
        if (s.empty()) {
            return 0;
        }
        
        int maxLength = 0;
        int curLength = 0;
        int startIndex = 0;
        map<char, int> curCountRecord;
        for (int i = 0; i < s.size(); i++) {
            auto ch = s[i];
            auto it = countRecord.find(ch);
            if (it == countRecord.end()) {
                // 异常，不可能出现的情况
                continue;
            } else {
                if (it->second >= k) {
                    // 该字符在整个字符串的重复次数满足要求，在子串中可能满足重复次数
                    curLength++;
                    auto iit = curCountRecord.find(ch);
                    if (iit == curCountRecord.end()) {
                        curCountRecord[ch] = 1;
                    } else {
                        curCountRecord[ch] = iit->second + 1;
                    }
                } else {
                    // 一定不满足重复次数的字符
                    bool isValid = true;
                    auto jit = curCountRecord.begin();
                    while (jit != curCountRecord.end()) {
                        // 检查 [startIndex, i) 子串是否满足重复次数，
                        // 并且计算后续子串的字符重复次数
                        if (jit->second < k) {
                            isValid = false;
                        }
                        auto kit = countRecord.find(jit->first);
                        if (kit != countRecord.end()) {
                            int count = kit->second - jit->second;
                            kit->second = count;
                        }
                        jit++;
                    }
                    
                    if (!isValid) {
                        // 不满足要求，递归计算 [startIndex, i) 子串中满足要求的子串最大长度
                        string subStr = s.substr(startIndex, i - startIndex);
                        curLength = longestSubstringRecur(subStr, k, curCountRecord);
                    }
                    
                    if (curLength > maxLength) {
                        //记录最大值
                        maxLength = curLength;
                    }
                    
                    // 清理状态，继续遍历后续子串
                    curLength = 0;
                    startIndex = i + 1;
                    curCountRecord.clear();
                }
            }
        }
        
        // 最后一个子串的处理
        bool isValid = true;
        auto jit = curCountRecord.begin();
        while (jit != curCountRecord.end()) {
            if (jit->second < k) {
                isValid = false;
            }
            jit++;
        }
        if (!isValid) {
            string subStr = s.substr(startIndex, s.size() - startIndex);
            curLength = longestSubstringRecur(subStr, k, curCountRecord);
        }
        if (curLength > maxLength) {
            maxLength = curLength;
        }
        
        return maxLength;
    }
    
    int longestSubstring(string s, int k) {
        map<char, int> countRecord;
        // 统计字符出现的次数。
        for (auto ch : s) {
            auto it = countRecord.find(ch);
            if (it == countRecord.end()) {
                countRecord[ch] = 1;
            } else {
                countRecord[ch] = it->second + 1;
            }
        }
        int maxLength = longestSubstringRecur(s, k, countRecord);
        return maxLength;
    }
};

void test0() {
    Solution s;
    cout << s.longestSubstring("aaabb", 3) << endl;
}

void test1() {
    Solution s;
    cout << s.longestSubstring("ababbc", 2) << endl;
}

void test2() {
    Solution s;
    cout << s.longestSubstring("ababacb", 3) << endl;
}

void test3() {
    Solution s;
    cout << s.longestSubstring("bbaaacbd", 3) << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    test0();
    test1();
    test2();
    test3();
    return 0;
}
