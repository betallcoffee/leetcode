//
//  main.cpp
//  Word Break II
//
//  Created by liang on 1/2/2020.
//  Copyright © 2020 liang. All rights reserved.
// https://leetcode.com/problems/word-break-ii/
/**
 Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

 Note:

 The same word in the dictionary may be reused multiple times in the segmentation.
 You may assume the dictionary does not contain duplicate words.
 Example 1:

 Input:
 s = "catsanddog"
 wordDict = ["cat", "cats", "and", "sand", "dog"]
 Output:
 [
   "cats and dog",
   "cat sand dog"
 ]
 Example 2:

 Input:
 s = "pineapplepenapple"
 wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
 Output:
 [
   "pine apple pen apple",
   "pineapple pen apple",
   "pine applepen apple"
 ]
 Explanation: Note that you are allowed to reuse a dictionary word.
 Example 3:

 Input:
 s = "catsandog"
 wordDict = ["cats", "dog", "sand", "and", "cat"]
 Output:
 []
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        map<string, bool> wordMap;
        for_each(wordDict.begin(), wordDict.end(), [&wordMap](string& item) {
            wordMap[item] = true;
        });
        
        size_t count = s.size();
        vector<bool> line(count + 1, false);
        line[0] = true;
        vector<string> wordLine;
        vector<vector<string>> wordMatrix(count + 1, wordLine);
        for (int32_t size = 1; size <= count; size++) {
            for (int32_t i = size - 1; i >= 0; i--) {
                auto subStr = s.substr(i, size - i);
                auto it = wordMap.find(subStr);
                if (it != wordMap.end()) {
                    if (line[i]) {
                        line[size] = true;
                        if (i == 0 || wordMatrix[i].empty()) {
                            wordMatrix[size].push_back(subStr);
                        } else {
                            for_each(wordMatrix[i].begin(), wordMatrix[i].end(), [&](string& item) {
                                string sentense = item + " " + subStr;
                                wordMatrix[size].push_back(sentense);
                            });
                        }
                    }
                }
            }
        }
        
        return wordMatrix[count];
    }
};

void test0() {
    Solution s;
    vector<string> wordDict = {"apple", "pen"};
    auto result = s.wordBreak("applepenapple", wordDict);
    cout << "applepenapple: " << endl;
    for_each(result.begin(), result.end(), [](string& item) {
        cout << item << endl;
    });
    cout << endl;
}

void test1() {
    Solution s;
    vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};
    
    auto result = s.wordBreak("catsandog", wordDict);
    cout << "catsandog: " << endl;
    for_each(result.begin(), result.end(), [](string& item) {
        cout << item << endl;
    });
    cout << endl;
}

void test2() {
    Solution s;
    vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};
    
    auto result = s.wordBreak("catsanddog", wordDict);
    cout << "catsanddog: " << endl;
    for_each(result.begin(), result.end(), [](string& item) {
        cout << item << endl;
    });
    cout << endl;
}

void test3() {
    Solution s;
    vector<string> wordDict = {"apple", "pen", "applepen", "pine", "pineapple"};
    
    auto result = s.wordBreak("pineapplepenapple", wordDict);
    cout << "pineapplepenapple: " << endl;
    for_each(result.begin(), result.end(), [](string& item) {
        cout << item << endl;
    });
    cout << endl;
}

void test4() {
    Solution s;
    vector<string> wordDict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    
    auto result = s.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", wordDict);
    cout << "test4: " << endl;
    for_each(result.begin(), result.end(), [](string& item) {
        cout << item << endl;
    });
    cout << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    test0();
    test1();
    test2();
    test3();
    test4();
    return 0;
}
