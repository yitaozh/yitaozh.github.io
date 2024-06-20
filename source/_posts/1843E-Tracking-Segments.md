---
title: 1843E. Tracking Segments
categories: Leetcode
date: 2024-06-02 13:03:18
tags:
    - binary search
    - brute force
    - data structures
    - two pointers
---

[E. Tracking Segments](https://codeforces.com/problemset/problem/1843/E)

## Description

输入 T(≤1e4) 表示 T 组数据。所有数据的 n 之和 ≤1e5。
对于每组数据：
一开始，有一个长为 n 的全 0 数组 a，下标从 1 开始。
输入 n m(1≤m≤n≤1e5) 以及 m 个非空连续子数组的左右端点 L R。
然后输入 q(1≤q≤n) 和 q 个操作，每个操作输入一个下标 p，表示把 a[p] 变成 1。保证所有 p 互不相同。

如果一个子数组中的 1 的个数比 0 多，则称这个子数组是优美的。
输入的 q 个操作，按照输入顺序一个一个地执行。
至少执行多少个操作，可以使 m 个子数组中有优美子数组？
如果执行完了也没有优美子数组，输出 -1。

## Hints/Notes

- binary search and preSum

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

#include <fstream>

using namespace std;

istream &in = cin;
ostream &out = cout;

bool beautiful(int n, int mid, vector<pair<int, int>>& segments, vector<int>& ops) {
    vector<int> nums(n, 0);
    for (int i = 0; i <= mid; i++) {
        nums[ops[i] - 1] = 1;
    }
    vector<int> preSum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        preSum[i + 1] = preSum[i] + nums[i];
    }
    for (auto& s : segments) {
        int l = s.first - 1;
        int r = s.second;
        int length = r - l;
        if (2 * (preSum[r] - preSum[l]) > length) {
            return true;
        }
    }
    return false;
}

void solve(int n, vector<pair<int, int>>& segments, vector<int>& ops) {
    int left = 0, right = ops.size();
    while (left < right) {
        int mid = (right - left) / 2 + left;
        if (beautiful(n, mid, segments, ops)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    out << (left == ops.size() ? -1 : left + 1) << endl;
}

int main() {
    int tc;
    in >> tc;
    for (int t = 1; t <= tc; t++) {
        int m, n;
        in >> n >> m;
        vector<pair<int, int>> segments;
        for (int i = 0; i < m; i++) {
            int l, r;
            in >> l >> r;
            segments.push_back({l, r});
        }
        int q;
        in >> q;
        vector<int> ops;
        for (int i = 0; i < q; i++) {
            int x;
            in >> x;
            ops.push_back(x);
        }
        solve(n, segments, ops);
    }
    return 0;
}
```
