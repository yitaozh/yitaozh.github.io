---
title: 976C. Nested Segments
categories: Leetcode
date: 2024-06-19 00:56:15
tags:
    - greedy
    - implementation
    - sortings
---

[C. Nested Segments](https://codeforces.com/problemset/problem/976/C)

## Description

输入 n(1≤n≤3e5) 和 n 个闭区间，区间的左右端点在 [1,1e9] 内。

从这 n 个区间中，选出两个区间 [L[i], R[i]] 和 [L[j], R[j]]，
满足 i ≠ j 且 L[j] <= L[i] <= R[i] <= R[j]，也就是区间 j 包含区间 i。

输出 i 和 j（按照输入的顺序，下标从 1 开始）。
如果不存在这样的区间，输出两个 -1。

## Hints/Notes

- sorting

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

void solve(vector<vector<int>>& pairs) {
    auto cmp = [](vector<int>& lhs, vector<int>& rhs) {
        if (lhs[0] == rhs[0]) {
            return lhs[1] > rhs[1];
        }
        return lhs[0] < rhs[0];
    };
    sort(pairs.begin(), pairs.end(), cmp);
    int pre = -1, r = 0;
    for (int i = 0; i < pairs.size(); i++) {
        auto p = pairs[i];
        if (p[1] <= r) {
            out << p[2] + 1 << " " <<  pre + 1 << endl;
            return;
        } else {
            pre = p[2];
            r = p[1];
        }
    }
    out << -1 << " " << -1 << endl;
}

int main() {
    int n;
    in >> n;
    vector<vector<int>> pairs;
    for (int i = 0; i < n; i++) {
        int l, r;
        in >> l >> r;
        pairs.push_back({l, r, i});
    }
    solve(pairs);
    return 0;
}
```
