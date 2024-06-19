---
title: 1873F. Money Trees
categories: Leetcode
date: 2024-06-03 23:35:19
tags:
    - binary search
    - greedy
    - math
    - two pointers
---

[F. Money Trees](https://codeforces.com/problemset/problem/1873/F)

## Description

输入 T(≤1e3) 表示 T 组数据。所有数据的 n 之和 ≤2e5。
每组数据输入 n(1≤n≤2e5) k(1≤k≤1e9) 和长为 n 的数组 a(1≤a[i]≤1e4)，长为 n 的数组 h(1≤h[i]≤1e9)。

选一个子区间 [L,R]，对于 [L,R-1] 内的 i，满足 h[i] 是 h[i+1] 的倍数，且 a[L] + a[L+1] + ... + a[R] 不超过 k。
输出子区间长度 R-L+1 的最大值。
如果没有这样的子区间，输出 0。

## Hints/Notes

- 分组循环 + sliding window

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

void solve(vector<int>& fruits, vector<int>& heights, int k) {
    int left = 0, maxLength = 0;
    while (left < fruits.size()) {
        int curFruit = 0;
        int curHeight = heights[left];
        int right = left;
        while (right < fruits.size() && (curHeight % heights[right] == 0)) {
            curFruit += fruits[right];
            curHeight = heights[right++];
            while (curFruit > k && left < right) {
                curFruit -= fruits[left++];
            }
            maxLength = max(maxLength, right - left);
        }
        left = right;
    }
    out << maxLength << endl;
}

int main() {
    int tc;
    in >> tc;
    for (int t = 1; t <= tc; t++) {
        int n, k;
        in >> n >> k;
        vector<int> fruits, heights;
        for (int i = 0; i < n; i++) {
            int fruit;
            in >> fruit;
            fruits.push_back(fruit);
        }
        for (int i = 0; i < n; i++) {
            int height;
            in >> height;
            heights.push_back(height);
        }
        solve(fruits, heights, k);
    }
    return 0;
}
```
