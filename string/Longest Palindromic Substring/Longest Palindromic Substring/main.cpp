//
//  main.cpp
//  Longest Palindromic Substring
//
//  Created by liang on 6/16/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  Problem: https://leetcode.com/problems/longest-palindromic-substring/
/**
 Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 Example 1:

 Input: "babad"
 Output: "bab"
 Note: "aba" is also a valid answer.
 Example 2:

 Input: "cbbd"
 Output: "bb"
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution0 {
public:
    string longestPalindrome(string s) {
        string result;
        int ss = 0;
        int len = 0;
        int i = 0;
        int size = (int)s.size();
        for_each(s.begin(), s.end(), [&](char c){
            for (int j = 1; i - j >= 0 && i + j < size; j++) {
                int ccc = s[i-j];
                int cc = s[i+j];
                if (ccc == cc) {
                    if (len < 2*j + 1) {
                        ss = i - j;
                        len = 2*j + 1;
                    }
                } else {
                    break;
                }
            }
            
            for (int j = 1; i - j >= 0 && i + j - 1 < size; j++) {
                int ccc = s[i - j];
                int cc = s[i + j - 1];
                if (ccc == cc) {
                    if (len < 2*j) {
                        ss = i - j;
                        len = 2*j;
                    }
                } else {
                    break;
                }
            }
            
            for (int j = 1; i - j + 1 >= 0 && i + j < size; j++) {
                int ccc = s[i - j + 1];
                int cc = s[i + j];
                if (ccc == cc) {
                    if (len < 2*j) {
                        ss = i - j + 1;
                        len = 2*j;
                    }
                } else {
                    break;
                }
            }
            if (len == 0) {
                ss = 0;
                len = 1;
            }
            i++;
        });
        return s.substr(ss, len);
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }
        
        Node* root = new Node();
        for (int i = 0; i < s.size(); i++) {
            createSuffixTree(root, s.substr(i, string::npos), i);
        }
        string sr(s.rbegin(), s.rend());
        string palindrome = findLongestPalindrome(root, s, sr);
        
        if (palindrome.empty()) {
            return s.substr(0, 1);
        }
        
        return palindrome;
    }
    
    
private:
    struct Node {
        map<char, Node*> children;
        int start = -1;
//        char value = 0;
//        int treeHeight = 0;
    };
    
    void createSuffixTree(Node* node, string s, int start) {
        if (s.empty()) {
            node->start = start;
            return;
        }
        
        auto it = node->children.find(s[0]);
        if (it == node->children.end()) {
            Node* newNode = new Node();
//            newNode->value = s[0];
//            newNode->treeHeight = node->treeHeight + 1;
            node->children[s[0]] = newNode;
        }
        it = node->children.find(s[0]);
        
        createSuffixTree(it->second, s.substr(1, string::npos), start);
    }
    
    string findLongestPalindrome(Node* node, string &origStr, string &revStr) {
        Node* cur = node;
        size_t start = 0;
        size_t size = 0;
        for (int i = 0; i < revStr.size(); i++) {
            cur = node;
            for (int j = i; j < revStr.size(); j++) {
                auto it = cur->children.find(revStr[j]);
                if (it != cur->children.end()) {
                    cur = it->second;
                    size_t endIndex = revStr.size() - i - 1;
                    size_t midIndex = revStr.size() - j;
                    size_t rightCount = endIndex - midIndex + 1;
                    size_t leftCount = rightCount;
                    size_t startIndex = midIndex - leftCount;
                    /// 长度必须比之前的大
                    if (leftCount + rightCount < size) {
                        continue;
                    }
                    
                    /// 回文串长度偶数
                    if (leftCount > 0 && checkValidPalindrome(cur, startIndex)) {
                        if (size < leftCount + rightCount) {
                            size = leftCount + rightCount;
                            start = startIndex;
                        }
                        continue;
                    }
                    
                    /// 回文串长度奇数， leftCount 多计算了一个中间字符
                    startIndex = midIndex - (leftCount - 1);
                    if (leftCount > 1 && checkValidPalindrome(cur, startIndex)) {
                        if (size < leftCount + rightCount - 1) {
                            size = leftCount + rightCount - 1;
                            start = startIndex;
                        }
                    }
                } else {
                    break;
                }
            }
        }
        
        return origStr.substr(start, size);
    }
    
    bool checkValidPalindrome(Node* node, size_t startIndex) {
        if (node->children.empty()) {
            if (node->start == startIndex) {
                return true;
            }
        }
        
        auto it = node->children.begin();
        while (it != node->children.end()) {
            if (checkValidPalindrome(it->second, startIndex)) {
                return true;
            }
            it++;
        }
        
        return false;
    }
    
    void printfSuffixTree(Node* node) {
        if (node->children.empty()) {
            printf("A suffix start:%d\n", node->start);
        } else {
            auto it = node->children.begin();
            while (it != node->children.end()) {
                printfSuffixTree(it->second);
                it++;
            }
        }
    }
};

void oldTest() {
    Solution s;
    
    cout << s.longestPalindrome("bananas") << endl;
    
    cout << s.longestPalindrome("") << endl;
    
    cout << s.longestPalindrome("a") << endl;
    
    cout << s.longestPalindrome("ac") << endl;
    
    cout << s.longestPalindrome("aa") << endl;
    
    cout << s.longestPalindrome("aaa") << endl;
    
    cout << s.longestPalindrome("aaaa") << endl;
    
    cout << s.longestPalindrome("aaaaa") << endl;
    
    cout << s.longestPalindrome("aaaaaa") << endl;
    
    cout << s.longestPalindrome("aaaaaaa") << endl;
    
    cout << s.longestPalindrome("aaaaaaaa") << endl;
    
    cout << s.longestPalindrome("aaaaaaaaa") << endl;
    
    cout << s.longestPalindrome("aaaaaaaaaa") << endl;
    
    cout << s.longestPalindrome("abbaccd") << endl;
    
    cout << s.longestPalindrome("abdbaccd") << endl;
    
    cout << s.longestPalindrome("dbhadsfjabbajaadkfha") << endl;
    
    cout << s.longestPalindrome("dbhadsfjabdbajadadkfha") << endl;
}

void test0() {
    Solution s;
    cout << s.longestPalindrome("bananas") << endl;
}

void test1() {
    Solution s;
    cout << s.longestPalindrome("aacdefcaa") << endl;
}

void test2() {
    Solution s;
    cout << s.longestPalindrome("dbhadsfjabbajaadkfha") << endl;
}

void test3() {
    Solution s;
    cout << s.longestPalindrome("aaaa") << endl;
}

void test4() {
    Solution s;
    cout << s.longestPalindrome("bsnetpqmwhqjunkooftuosgkmkxpmvuehtlpwpktltwlvpdaycnhewdbdrhluyjldecezujgxixehsmjjuyerpllrvzqskizkulqzowzfvqcdsllvgupndbaiuzihcxklvxbodpnrymwobhlvllybdlfabfvnizjpriapuzszdhohfgezayokrivbgbgingspoxsridokhwekawchjdcpylvefubulvxneuizglrjktfcdirwnpqztdpsicslzaeiaibrepifxpxfkczwoumkkuaqkbjhxvasxflmrctponwwenvmtdaqaavubyrzbqjbjxpejmucwunanxwpomqyondyjuzxmzpevxqmbkrwcpdiiph") << endl;
}

int main(int argc, const char * argv[]) {
//    oldTest();
//    test0();
//    test1();
//    test2();
//    test3();
    test4();
    return 0;
}
