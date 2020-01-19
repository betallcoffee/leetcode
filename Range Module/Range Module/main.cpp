//
//  main.cpp
//  Range Module
//
//  Created by liang on 22/10/18.
//  Copyright © 2018年 liang. All rights reserved.
//  https://leetcode.com/problems/range-module/
/**
 A Range Module is a module that tracks ranges of numbers. Your task is to design and implement the following interfaces in an efficient manner.
 
 addRange(int left, int right) Adds the half-open interval [left, right), tracking every real number in that interval. Adding an interval that partially overlaps with currently tracked numbers should add any numbers in the interval [left, right) that are not already tracked.
 queryRange(int left, int right) Returns true if and only if every real number in the interval [left, right) is currently being tracked.
 removeRange(int left, int right) Stops tracking every real number currently being tracked in the interval [left, right).
 Example 1:
 addRange(10, 20): null
 removeRange(14, 16): null
 queryRange(10, 14): true (Every number in [10, 14) is being tracked)
 queryRange(13, 15): false (Numbers like 14, 14.03, 14.17 in [13, 15) are not being tracked)
 queryRange(16, 17): true (The number 16 in [16, 17) is still being tracked, despite the remove operation)
 Note:
 
 A half open interval [left, right) denotes all real numbers left <= x < right.
 0 < left < right < 10^9 in all calls to addRange, queryRange, removeRange.
 The total number of calls to addRange in a single test case is at most 1000.
 The total number of calls to queryRange in a single test case is at most 5000.
 The total number of calls to removeRange in a single test case is at most 1000.
 */

#include <map>
#include <functional>

class RangeModule {
public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        auto it = ranges.lower_bound(right);
        while (it != ranges.end() && it->second >= left) {
            left = std::min(left, it->first);
            right = std::max(right, it->second);
            it++;
            ranges.erase(prev(it));
        }
        ranges[left] = right;
    }
    
    bool queryRange(int left, int right) {
        auto it = ranges.lower_bound(left);
        if (it == ranges.end()) {
            return false;
        }
        
        if (it->second >= right) {
            return true;
        } else {
            return false;
        }
    }
    
    void removeRange(int left, int right) {
        auto it = ranges.upper_bound(right);
        while (it != ranges.end() && it->second > left) {
            auto nextIt = next(it);
            if (it->second > right) {
                ranges[right] = it->second;
            }
            
            if (it->first >= left) {
                ranges.erase(it);
            } else {
                it->second = left;
            }
            it = nextIt;
        }
    }
private:
    std::map<int, int, std::greater<int>> ranges;
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */

void test0() {
/**
 addRange(10, 20): null
 removeRange(14, 16): null
 queryRange(10, 14): true (Every number in [10, 14) is being tracked)
 queryRange(13, 15): false (Numbers like 14, 14.03, 14.17 in [13, 15) are not being tracked)
 queryRange(16, 17): true (The number 16 in [16, 17) is still being tracked, despite the remove operation)
 */
    RangeModule obj;
    obj.addRange(10, 20);
    obj.removeRange(14, 16);
    printf("%d\n", obj.queryRange(10, 14));
    printf("%d\n", obj.queryRange(13, 15));
    printf("%d\n", obj.queryRange(16, 17));
}

int main(int argc, const char * argv[]) {
    // insert code here...
    test0();
    return 0;
}
