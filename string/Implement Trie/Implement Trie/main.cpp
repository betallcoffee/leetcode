//
//  main.cpp
//  Implement Trie
//
//  Created by liang on 1/2/2020.
//  Copyright © 2020 liang. All rights reserved.
// https://leetcode.com/problems/implement-trie-prefix-tree/
/**
 Implement a trie with insert, search, and startsWith methods.

 Example:

 Trie trie = new Trie();

 trie.insert("apple");
 trie.search("apple");   // returns true
 trie.search("app");     // returns false
 trie.startsWith("app"); // returns true
 trie.insert("app");
 trie.search("app");     // returns true
 Note:

 You may assume that all inputs are consist of lowercase letters a-z.
 All inputs are guaranteed to be non-empty strings.
 */

#include <iostream>

#include <map>
#include <string>

using namespace std;
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* cur = root;
        for_each(word.begin(), word.end(), [&](char ch) {
            auto it = cur->children.find(ch);
            if (it == cur->children.end()) {
                Node* node = new Node();
                cur->children[ch] = node;
                cur = node;
            } else {
                cur = it->second;
            }
        });
        
        cur->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* cur = root;
        for (size_t i = 0; i < word.size(); i++) {
            char ch = word[i];
            auto it = cur->children.find(ch);
            if (it == cur->children.end()) {
                return false;
            } else {
                cur = it->second;
            }
        }
        
        return cur->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* cur = root;
        for (size_t i = 0; i < prefix.size(); i++) {
            char ch = prefix[i];
            auto it = cur->children.find(ch);
            if (it == cur->children.end()) {
                return false;
            } else {
                cur = it->second;
            }
        }
        return true;
    }
    
private:
    struct Node {
        map<char, Node*> children;
        bool isWord = false;
    };
    
    Node* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

void test0() {
    cout << "test0: " << endl;
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple") << endl;   // returns true
    cout << trie.search("app") << endl;     // returns false
    cout << trie.startsWith("app") << endl; // returns true
    trie.insert("app");
    cout << trie.search("app") << endl;     // returns true
    cout << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    test0();
    return 0;
}
