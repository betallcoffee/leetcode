//
//  main.cpp
//  Group Anagrams
//
//  Created by liang on 1/10/17.
//  Copyright © 2017年 liang. All rights reserved.
//  Problem: https://leetcode.com/problems/group-anagrams/description/
/**
 Given an array of strings, group anagrams together.
 
 For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
 Return:
 
 [
 ["ate", "eat","tea"],
 ["nat","tan"],
 ["bat"]
 ]
 Note: All inputs will be in lower-case.
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

void printff(vector<vector<string>> &matrix) {
    for_each(matrix.begin(), matrix.end(), [&](vector<string> vect){
        for_each(vect.begin(), vect.end(), [&](string item){
            printf("%s ", item.c_str());
        });
        printf("\n");
    });
}

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        map<string, size_t> keys;
        for_each(strs.begin(), strs.end(), [&] (string str) {
            string key = hash(str);
            map<string, size_t>::iterator it = keys.find(key);
            if (it == keys.end()) {
                keys[key] = result.size();
                vector<string> tmp;
                tmp.push_back(str);
                result.push_back(tmp);
            } else {
                size_t i = it->second;
                result[i].push_back(str);
            }
        });
        
        vector<vector<string>> sorted;
        for_each(result.begin(), result.end(), [&] (vector<string> strs) {
            sort(strs.begin(), strs.end());
            sorted.push_back(strs);
        });
        
        return sorted;
    }
private:
    string hash(string &value) {
        int count[26] = {0};
        for_each(value.begin(), value.end(), [&] (const char ch) {
            int i = ch - 'a';
            count[i]++;
        });
        string key = "";
        for (int i = 0; i < 26; i++) {
            do {
                int t = count[i] % 10;
                key.push_back(t + '0');
                count[i] = count[i] / 10;
            } while(count[i]);
        }
        return key;
    }
};

void test1() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution s;
    vector<vector<string>> result = s.groupAnagrams(strs);
    printff(result);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    test1();
    
    return 0;
}
