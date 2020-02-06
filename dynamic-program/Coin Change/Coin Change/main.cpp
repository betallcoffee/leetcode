//
//  main.cpp
//  Coin Change
//
//  Created by liang on 6/2/2020.
//  Copyright © 2020 liang. All rights reserved.
// https://leetcode.com/problems/coin-change/
/**
 You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

 Example 1:

 Input: coins = [1, 2, 5], amount = 11
 Output: 3
 Explanation: 11 = 5 + 5 + 1
 Example 2:

 Input: coins = [2], amount = 3
 Output: -1
 Note:
 You may assume that you have an infinite number of each kind of coin.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> coinCount(amount + 1, INT_MAX);
        coinCount[0] = 0;
        for (int i = 1; i <= amount; i++) {
            int count = INT_MAX;
            for (auto coin : coins) {
                int remain = i - coin;
                if (remain >= 0 && coinCount[remain] < count) {
                    count = coinCount[remain];
                }
            }
            if (count != INT_MAX) {
                coinCount[i] = count + 1;
            }
        }
        
        if (coinCount[amount] == INT_MAX) {
            return -1;
        }
        
        return coinCount[amount];
    }
};

void test0() {
    vector<int> coins = {1,2,5};
    Solution s;
    cout << "test0: " << s.coinChange(coins, 11) << endl;
}

void test1() {
    vector<int> coins = {2};
    Solution s;
    cout << "test1: " << s.coinChange(coins, 3) << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    test0();
    test1();
    return 0;
}
