---
title: 1796D. Maximum Subarray
categories: Leetcode
date: 2024-06-02 17:12:33
tags:
  - data structures
  - dp
  - greedy
  - two pointers
---

[D. Maximum Subarray](https://codeforces.com/problemset/problem/1796/D)

## Description

输入 T(≤1e4) 表示 T 组数据。所有数据的 n 之和 ≤2e5。
每组数据输入 n(1≤n≤2e5) k(0≤k≤min(20,n)) x(-1e9≤x≤1e9) 和长为 n 的数组 a(-1e9≤a[i]≤1e9)。

你需要把 a 中恰好 k 个数增加 x，其余数减少 x。
该操作必须恰好执行一次。
在最优操作下，a 的最大连续子数组和的最大值是多少？
注意子数组可以是空的，元素和为 0。

进阶：你能做到 O(n) 吗？复杂度和 k 无关。

## Hints/Notes

- two cases: the subarray's length is bigger than k or the subarray's length is less than k

## Solution

Language: **C++**

```C++
#include <iostream>
#include <utility>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <climits>

#include <fstream>

using namespace std;

istream &in = cin;
ostream &out = cout;

void solve(int n, vector<int>& nums, int k, int x) {
    if (x < 0) {
        x = -x;
        k = n - k;
    }
    for (auto& num : nums) {
        num -= x;
    }
    // the case subarray is bigger than k
    // we need to find a minimum of k numbers to add value to
    vector<long long> preSum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        preSum[i + 1] = preSum[i] + nums[i];
    }
    deque<long long> minQ;
    int left = 0, right = 0;
    long long res = LLONG_MIN;
    while (right < preSum.size()) {
        if (right - k >= 0) {
            while (!minQ.empty() && preSum[right - k] < minQ.back()) {
                minQ.pop_back();
            }
            minQ.push_back(preSum[right - k]);
            res = max(res, preSum[right] - minQ.front());
        }
        right++;
    }
    res += 2 * (long long) k * x;

    // the case subarray size is less than or equal to k
    for (auto& num: nums) {
        num += 2 * x;
    }
    preSum[0] = 0;
    for (int i = 0; i < n; i++) {
        preSum[i + 1] = preSum[i] + nums[i];
    }
    left = 0, right = 0;
    minQ.clear();
    while (right < preSum.size()) {
        while (!minQ.empty() && preSum[right] < minQ.back()) {
            minQ.pop_back();
        }
        minQ.push_back(preSum[right++]);
        if (right - left > k) {
            if (minQ.front() == preSum[left]) {
                minQ.pop_front();
            }
            left++;
        }
        if (!minQ.empty()) {
            res = max(res, minQ.back() - minQ.front());
        }
    }
    out << (res < 0 ? 0 : res) << endl;
}

int main() {
    int tc;
    in >> tc;
    for (int t = 1; t <= tc; t++) {
        int n, k, x;
        in >> n >> k >> x;
        vector<int> nums;
        for (int i = 0; i < n; i++) {
            int num;
            in >> num;
            nums.push_back(num);
        }
        solve(n, nums, k, x);
    }
    return 0;
}
```
