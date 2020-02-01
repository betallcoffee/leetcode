//
//  main.cpp
//  Word Break
//
//  Created by liang on 1/2/2020.
//  Copyright © 2020 liang. All rights reserved.
// https://leetcode.com/problems/word-break/
/**
 Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

 Note:

 The same word in the dictionary may be reused multiple times in the segmentation.
 You may assume the dictionary does not contain duplicate words.
 Example 1:

 Input: s = "leetcode", wordDict = ["leet", "code"]
 Output: true
 Explanation: Return true because "leetcode" can be segmented as "leet code".
 Example 2:

 Input: s = "applepenapple", wordDict = ["apple", "pen"]
 Output: true
 Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
              Note that you are allowed to reuse a dictionary word.
 Example 3:

 Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 Output: false
 */

#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string, bool> wordMap;
        for_each(wordDict.begin(), wordDict.end(), [&wordMap](string& item) {
            wordMap[item] = true;
        });
        
        size_t count = s.size();
        vector<bool> line(count + 1, false);
        line[0] = true;
        for (int32_t size = 1; size <= count; size++) {
            for (int32_t i = size - 1; i >= 0; i--) {
                if (line[i]) {
                    auto subStr = s.substr(i, size - i);
                    auto it = wordMap.find(subStr);
                    if (it != wordMap.end()) {
                        line[size] = true;
                        break;
                    }
                }
            }
        }
        
        return line[count];
    }
};

void test0() {
    Solution s;
    vector<string> wordDict = {"leet", "code"};
    cout << "leetcode:" << s.wordBreak("leetcode", wordDict) << endl;
}

void test1() {
    Solution s;
    vector<string> wordDict = {"apple", "pen"};
    cout << "applepenapple: " << s.wordBreak("applepenapple", wordDict) << endl;
}

void test2() {
    Solution s;
    vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};
    cout << "catsandog: " << s.wordBreak("catsandog", wordDict) << endl;
}

void test3() {
    Solution s;
    vector<string> wordDict = {"a"};
    cout << "a: " << s.wordBreak("a", wordDict) << endl;
}

void test4() {
    Solution s;
    vector<string> wordDict = {"aaaa", "aaa"};
    cout << "aaaaaaa: " << s.wordBreak("aaaaaaa", wordDict) << endl;
}

void test5() {
    Solution s;
    vector<string> wordDict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    cout << "test5: " << s.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", wordDict) << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    test0();
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}
