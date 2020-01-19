//
//  main.cpp
//  Merge Intervals
//
//  Created by liang on 12/10/17.
//  Copyright © 2017年 liang. All rights reserved.
//  https://leetcode.com/problems/merge-intervals/description/
/**
 Given a collection of intervals, merge all overlapping intervals.
 
 For example,
 Given [1,3],[2,6],[8,10],[15,18],
 return [1,6],[8,10],[15,18].
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for an interval.
 */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

void printfIntervals(vector<Interval> &intervals) {
    for_each(intervals.begin(), intervals.end(), [&] (Interval elm){
        printf("[%d, %d] ", elm.start, elm.end);
    });
    printf("\n");
}

class CompareClass {
public:
    bool operator() (Interval &l, Interval &r) {
        return l.start < r.start;
    }
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> array;
        if (intervals.empty()) {
            return array;
        }
        
        CompareClass cmp;
        sort(intervals.begin(), intervals.end(), cmp);
        
        vector<Interval>::iterator cur = intervals.begin();
        vector<Interval>::iterator it = intervals.begin();
        for (; it != intervals.end(); it++) {
            if (cur->end < it->start) {
                array.push_back(*cur);
                cur = it;
            } else {
                cur->end = cur->end > it->end ? cur->end : it->end;
            }
        }
        array.push_back(*cur);
        
        return array;
    }
};

void test1() {
    Solution s;
    vector<Interval> intervals = {Interval(1, 3), Interval(2, 6), Interval(8, 10), Interval(15, 18)};
    vector<Interval> array = s.merge(intervals);
    printfIntervals(array);
}

void test2() {
    Solution s;
    vector<Interval> intervals;
    vector<Interval> array = s.merge(intervals);
    printfIntervals(array);
}

void test3() {
    Solution s;
    vector<Interval> intervals = {Interval(1, 4), Interval(2, 3)};
    vector<Interval> array = s.merge(intervals);
    printfIntervals(array);
}

int main(int argc, const char * argv[]) {
    test1();
    test2();
    test3();
    return 0;
}
