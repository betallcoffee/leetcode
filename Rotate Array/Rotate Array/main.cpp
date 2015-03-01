//
//  main.cpp
//  Rotate Array
//
//  Created by liang on 3/1/15.
//  Copyright (c) 2015 tina. All rights reserved.
//

#include <iostream>

class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k = k % n;
        if (n/2 >= k) {
            rightRotate(nums, n, k);
        } else {
            leftRotate(nums, n, n - k);
        }
    }
    
private:
    void rightRotate(int nums[], int n, int k) {
        if (k == 0) return;
        if (n == 1) return;
        if (n/2 >= k) {
            swap(nums, n, k);
            if ((n - k)/2 >= k) {
                rightRotate(nums + k, n - k, k);
            } else {
                leftRotate(nums + k, n - k, n - k - k);
            }
        }
    }
    
    void leftRotate(int nums[], int n, int k) {
        if (k == 0) return;
        if (n == 1) return;
        if (n/2 >= k) {
            swap(nums, n, k);
            if ((n - k)/2 >= k) {
                leftRotate(nums, n - k, k);
            } else {
                rightRotate(nums, n - k, n - k - k);
            }
        }
    }
    
    void swap(int nums[], int n, int k) {
        for (int i = 0; i < k; i++) {
            int t = nums[i];
            nums[i] = nums[n - k + i];
            nums[n - k + i] = t;
        }
    }
};

void printArray(int nums[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution s;
    
    int case1[] = {1,2,3,4,5,6,7};
    s.rotate(case1, 7, 3);
    printArray(case1, 7);
    
    int case2[] = {1,2};
    s.rotate(case2, 2, 0);
    printArray(case2, 2);
    
    int case3[] = {1,2,3,4,5,6};
    s.rotate(case3, 6, 2);
    printArray(case3, 6);
    
    return 0;
}
