//
//  main.cpp
//  Min Stack
//
//  Created by liang on 2/13/15.
//  Copyright (c) 2015 tina. All rights reserved.
//  Problem: https://oj.leetcode.com/problems/min-stack/
//Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
//push(x) -- Push element x onto stack.
//pop() -- Removes the element on top of the stack.
//top() -- Get the top element.
//getMin() -- Retrieve the minimum element in the stack.


#include <iostream>
#include <string>
#include <stack>

class MinStack1 {
public:
    void push(int x) {
        _stack.push(x);
        if (_min.empty()) {
            _min.push(x);
        } else if(_min.top() >= x){
            _min.push(x);
        }
    }
    
    void pop() {
        if (_stack.top() == _min.top()) {
            _min.pop();
        }
        _stack.pop();
    }
    
    int top() {
        return _stack.top();
    }
    
    int getMin() {
        return _min.top();
    }
    
private:
    std::stack<int> _stack;
    std::stack<int> _min;
};

class MinStack {
public:
    void push(int x) {
        StackItem *item = new StackItem(x);
        item->setNext(_head.next());
        _head.setNext(item);
        if (_min.next() == NULL) {
            item = new StackItem(x);
            _min.setNext(item);
        } else if (_min.next()->value() >= x){
            item = new StackItem(x);
            item->setNext(_min.next());
            _min.setNext(item);
        }
    }
    
    void pop() {
        StackItem *item = _head.next();
        if (item != NULL) {
            _head.setNext(item->next());
            if (item->value() == _min.next()->value()) {
                StackItem *min = _min.next();
                _min.setNext(min->next());
                delete min;
            }
            delete item;
        }
    }
    
    int top() {
        StackItem *item = _head.next();
        if (item != NULL) {
            return item->value();
        } else {
            return -1;
        }
    }
    
    int getMin() {
        return _min.next()->value();
    }
    
private:
    class StackItem {
    public:
        StackItem() : _value(0), _next(NULL) {}
        StackItem(int value) : _value(value), _next(NULL) {}
        
        int value() { return _value; }
        
        StackItem *next() {
            return _next;
        }
        
        void setNext(StackItem *next) {
            _next = next;
        }
        
    private:
        int _value;
        StackItem *_next;
    };
    
    StackItem _head;
    StackItem _min;
};

class Case : public std::unary_function<char, void> {
public:
    void operator()(char x) {
        if (x == ',') {
            parseToken();
            _token.clear();
        } else {
            _token.push_back(x);
        }
    }
    
private:
    MinStack _stack;
    std::string _token;
    
    void parseToken() {
        if (_token.find("push") != std::string::npos) {
            int n = extractInt(_token);
            _stack.push(n);
        } else if (_token.find("pop") != std::string::npos) {
            _stack.pop();
        } else if (_token.find("top") != std::string::npos) {
            std::cout << _stack.top() << " ";
        } else if (_token.find("getMin") != std::string::npos) {
            std::cout << _stack.getMin() << " ";
        }
    }
    
    int extractInt(const std::string &word) {
        std::string::const_iterator it;
        int n = 0;
        for (it = word.begin(); it != word.end(); it++) {
            if ('0' <= *it && *it <= '9') {
                n = n * 10 + (*it - '0');
            }
        }
        return n;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    // Inputs: push(2147483646),push(2147483646),push(2147483647),top,pop,getMin,pop,getMin,pop,push(2147483647),top,getMin,push(-2147483648),top,getMin,pop,getMin
    // Expected: 2147483647 2147483646 2147483646 2147483647 2147483647 -2147483648 -2147483648 2147483647
    std::string case1 = "push(2147483646),push(2147483646),push(2147483647),top,pop,getMin,pop,getMin,pop,push(2147483647),top,getMin,push(-2147483648),top,getMin,pop,getMin,";
    std::for_each(case1.begin(), case1.end(), Case());
    std::cout << std::endl;
    // Inputs: top
    // Expected:
    std::string case2 = "pop";
    std::for_each(case2.begin(), case2.end(), Case());
    std::cout << std::endl;
    
    return 0;
}
