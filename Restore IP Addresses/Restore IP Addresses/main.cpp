//
//  main.cpp
//  Restore IP Addresses
//
//  Created by liang on 14/10/17.
//  Copyright © 2017年 liang. All rights reserved.
//  https://leetcode.com/problems/restore-ip-addresses/description/
/**
 Given a string containing only digits, restore it by returning all possible valid IP address combinations.
 
 For example:
 Given "25525511135",
 
 return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ips;
        vector<int> st;
        st.push_back(0);
        while (!st.empty()) {
            int n = st[st.size()-1];
            if (st.size() == 4) {
                string ip("");
                int pos = 0;
                int len = 0;
                int comp = 0;
                bool flag = true;
                for (int i = 0; i < 4; i++) {
                    if (pos + st[i] <= s.size()) {
                        if (st[i] == 1 ||
                            (st[i] > 1 && s[pos] != '0')) {
                            string sub = s.substr(pos, st[i]);
                            int num = atoi(sub.c_str());
                            if (num <= 255) {
                                len += sub.size();
                                ip.append(sub);
                                comp++;
                                if (i != 3) {
                                    ip.append(".");
                                }
                            } else {
                                flag = false;
                            }
                        } else {
                            flag = false;
                        }
                    }
                    pos += st[i];
                }
                
                if (len == s.size() && comp == 4 && flag) {
                    ips.push_back(ip);
                }
            }
            st.pop_back();
            if (n < 3) {
                st.push_back(n+1);
                if (st.size() < 4) {
                    st.push_back(0);
                }
            }
        }
        return ips;
    }
};

void test1() {
    Solution s;
    vector<string> ips = s.restoreIpAddresses("25525511135");
    for_each(ips.begin(), ips.end(), [&](string ip) {
        printf("%s ", ip.c_str());
    });
    printf("\n");
}

void test2() {
    Solution s;
    vector<string> ips = s.restoreIpAddresses("0000");
    for_each(ips.begin(), ips.end(), [&](string ip) {
        printf("%s ", ip.c_str());
    });
    printf("\n");
}

void test3() {
    Solution s;
    vector<string> ips = s.restoreIpAddresses("1111");
    for_each(ips.begin(), ips.end(), [&](string ip) {
        printf("%s ", ip.c_str());
    });
    printf("\n");
}

int main(int argc, const char * argv[]) {
    test1();
    test2();
    test3();
    return 0;
}
