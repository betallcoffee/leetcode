//
//  main.cpp
//  Insert Interval
//
//  Created by liang on 12/10/17.
//  Copyright © 2017年 liang. All rights reserved.
//  https://leetcode.com/problems/insert-interval/description/
/**
 Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 
 You may assume that the intervals were initially sorted according to their start times.
 
 Example 1:
 Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 
 Example 2:
 Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
 
 This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
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

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> array;
        if (intervals.empty()) {
            array.push_back(newInterval);
            return array;
        }
        bool flag = true;
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i].end < newInterval.start) {
                array.push_back(intervals[i]);
            } else if (intervals[i].start <= newInterval.end) {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            } else {
                if (flag) {
                    array.push_back(newInterval);
                    flag = false;
                }
                array.push_back(intervals[i]);
            }
        }
        if (flag) {
            array.push_back(newInterval);
            flag = false;
        }
        return array;
    }
};

void test1() {
    Solution s;
    vector<Interval> intervals = {Interval(1, 3), Interval(6, 9)};
    vector<Interval> array = s.insert(intervals, Interval(2, 5));
    printfIntervals(array);
}

void test2() {
    Solution s;
    vector<Interval> intervals = {Interval(1, 2), Interval(3, 5), Interval(6, 7), Interval(8, 10), Interval(12, 16)};
    vector<Interval> array = s.insert(intervals, Interval(4, 9));
    printfIntervals(array);
}

void test3() {
    Solution s;
    vector<Interval> intervals = {Interval(1, 5)};
    vector<Interval> array = s.insert(intervals, Interval(2, 3));
    printfIntervals(array);
}

void test4() {
    Solution s;
    vector<Interval> intervals = {Interval(1, 5)};
    vector<Interval> array = s.insert(intervals, Interval(0, 1));
    printfIntervals(array);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    test1();
    test2();
    test3();
    test4();
    return 0;
}
