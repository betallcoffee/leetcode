//
//  main.cpp
//  Reverse Words in a String
//
//  Created by liang on 11/3/14.
//  Copyright (c) 2014 Tina. All rights reserved.
//  Problem: https://oj.leetcode.com/problems/reverse-words-in-a-string/
//Given an input string, reverse the string word by word.
//
//For example,
//Given s = "the sky is blue",
//return "blue is sky the".
//
//Update (2015-02-12):
//For C programmers: Try to solve it in-place in O(1) space.

#include <iostream>
#include <algorithm>

using namespace std;

template <class T> class ReverseWords : public unary_function<T, void> {
    public :
    ReverseWords(string &o, string &word) : _o(o), _word(word) {}
    void operator() (T x) {
        if (x == ' ' && !_word.empty()) {
            _o.append(_word.rbegin(), _word.rend());
            _o.push_back(' ');
            _word.clear();
        } else if (x != ' ') {
            _word.push_back(x);
        }
    }
    void outEndWord() {
        if (!_word.empty()) {
            _o.append(_word.rbegin(), _word.rend());
        } else if (_o.size() > 1 && _o.back() == ' ') {
            _o.erase(--_o.end());
        }
    }
    private :
    string &_o;
    string &_word;
};

class Solution {
public:
    void reverseWords(string &s) {
        string o;
        string word;
        ReverseWords<string::value_type> r = ReverseWords<string::value_type>(o, word);
        for_each(s.rbegin(), s.rend(), r);
        r.outEndWord();
        s.swap(o);
    }
};

int main(int argc, const char * argv[])
{
    // insert code here...
    std::cout << "Hello, World!\n";
//    string str = "   the sky is   blue   ";
//    string str = " 1";
    string str = "";
    cout << str << endl;
    Solution *s = new Solution();
    s->reverseWords(str);
    cout << str << endl;
    return 0;
}

