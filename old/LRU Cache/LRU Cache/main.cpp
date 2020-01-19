//
//  main.cpp
//  LRU Cache
//
//  Created by liang on 11/5/14.
//  Copyright (c) 2014 Tina. All rights reserved.
//  Problem: https://oj.leetcode.com/problems/lru-cache/
//Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.
//
//get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
//set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

#include <iostream>
#include <map>

class LRUCache{
public:
    LRUCache(int capacity) {
        _capacity = capacity;
        _size = 0;
        _head = NULL;
        _tail = NULL;
    }
    
    int get(int key) {
        CacheItem *item = _caches[key];
        if (item == NULL) {
            return -1;
        } else {
            moveToTail(item);
            return item->value();
        }
    }
    
    void set(int key, int value) {
        // 如果已经缓存，则更新缓存值。 case9
        CacheItem *item = _caches[key];
        if (item != NULL) {
            item->setValue(value);
            moveToTail(item);
            return;
        }
        // 添加新的缓存到列尾。
        if (_size >= _capacity) {
            if (_size == 1) {
                std::cout << _head->value();
                _caches.erase(_head->key());
                delete _head;
                _head = NULL;
                _tail = NULL;
            } else {
                item = _head;
                _head = item->next();
                _head->setPre(NULL);
                std::cout << item->value();
                _caches.erase(item->key());
                delete item;
            }
            _size--;
        }
        item = new CacheItem(key, value);
        if (_head == NULL) {
            _head = item;
            _tail = item;
        } else {
            item->setPre(_tail);
            _tail->setNext(item);
            _tail = item;
        }
        _caches[key] = item;
        _size++;
    }
    
private:
    /** @brief
     *
     */
    class CacheItem {
    public:
        CacheItem(int key, int value) : _key(key), _value(value) {
            _pre = NULL;
            _next = NULL;
        }
        
        int key() {
            return _key;
        }
        
        int value() {
            return _value;
        }
        
        void setValue(int value) {
            _value = value;
        }
        
        CacheItem *pre() {
            return _pre;
        }
        
        void setPre(CacheItem *pre) {
            _pre = pre;
        }
        
        CacheItem *next() {
            return _next;
        }
        
        void setNext(CacheItem *next) {
            _next = next;
        }
        
    private:
        int _key;
        int _value;
        
        CacheItem *_pre;
        CacheItem *_next;
    };
    
    CacheItem *_head;
    CacheItem *_tail;
    int _capacity;
    int _size;
    
    std::map<int, CacheItem *> _caches;
    
    void moveToTail(CacheItem *item) {
        if (_tail != item) {
            // case10
            if (item->pre()) {
                item->pre()->setNext(item->next());
            }
            if (item->next()) {
                item->next()->setPre(item->pre());
            }
            if (_head == item) {
                _head = item->next();
            }
            item->setPre(_tail);
            item->setNext(NULL);
            _tail->setNext(item);
            _tail = item;
        }
    }
};

class Case {
public:
    Case() {
        _cache = NULL;
        _capacity = 0;
        _key = 0;
        _value = 0;
        _isKey = false;
        _isValue = false;
        _isSet = false;
        _isGet = false;
    }
    void operator()(char c) {
        if (_cache == NULL) {
            if (c >= '0' && c <= '9') {
                _capacity = _capacity * 10 + (c - '0');
            } else {
                _cache = new LRUCache(_capacity);
            }
        } else {
            if (c == 's') {
                _isKey = false;
                _isValue = false;
                _isSet = true;
                _isGet = false;
            } else if (c == 'g') {
                _isKey = false;
                _isValue = false;
                _isSet = false;
                _isGet = true;
            } else if (_isSet) {
                if (c == '(') {
                    _isKey = true;
                } else if (c == ',') {
                    _isKey = false;
                    _isValue = true;
                } else if (c >= '0' && c <= '9' && _isKey) {
                    _key = _key * 10 + (c - '0');
                } else if (c >= '0' && c <= '9' && _isValue) {
                    _value = _value * 10 + (c - '0');
                } else if (c == ')'){
                    _isKey = false;
                    _isValue = false;
                    _isSet = false;
                    _cache->set(_key, _value);
                    _key = 0;
                    _value = 0;
                    
                }
            } else if (_isGet) {
                if (c >= '0' && c <= '9') {
                    _key = _key * 10 + (c - '0');
                } else if (c == ')') {
                    _isGet = false;
                    std::cout << _cache->get(_key);
                    _key = 0;
                }
            }
        }
    }
private:
    LRUCache *_cache;
    int _capacity;
    int _key;
    int _value;
    bool _isKey;
    bool _isValue;
    bool _isSet;
    bool _isGet;
    
};

int main(int argc, const char * argv[])
{
    
    // insert code here...
    std::cout << "Hello, World!\n";
    //Input: 1,[set(2,1),get(2),set(3,2),get(2),get(3)]
    //Expected: [1,-1,2]
    std::string case5 = std::string("1,[set(2,1),get(2),set(3,2),get(2),get(3)]");
    std::for_each(case5.begin(), case5.end(), Case());
    std::cout << std::endl;
    //Input: 2,[set(2,1),set(1,1),get(2),set(4,1),get(1),get(2)]
    //Expected: [1,-1,1]
    std::string case7 = std::string("2,[set(2,1),set(1,1),get(2),set(4,1),get(1),get(2)]");
    std::for_each(case7.begin(), case7.end(), Case());
    std::cout << std::endl;
    //Input: 2,[get(2),set(2,6),get(1),set(1,5),set(1,2),get(1),get(2)]
    //Expected: [-1,-1,2,6]
    std::string case9 = std::string("2,[get(2),set(2,6),get(1),set(1,5),set(1,2),get(1),get(2)]");
    std::for_each(case9.begin(), case9.end(), Case());
    std::cout << std::endl;
    //Input: 3,[set(1,1),set(2,2),set(3,3),set(4,4),get(4),get(3),get(2),get(1),set(5,5),get(1),get(2),get(3),get(4),get(5)]
    //Expected: [4,3,2,-1,-1,2,3,-1,5]
    std::string case10 = std::string("3,[set(1,1),set(2,2),set(3,3),set(4,4),get(4),get(3),get(2),get(1),set(5,5),get(1),get(2),get(3),get(4),get(5)]");
    std::for_each(case10.begin(), case10.end(), Case());
    std::cout << std::endl;
    return 0;
}


