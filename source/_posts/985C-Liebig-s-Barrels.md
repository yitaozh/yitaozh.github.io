---
title: 985C. Liebig's Barrels
categories: Leetcode
date: 2024-06-06 12:04:19
tags:
    - greedy
---

[C. Liebig's Barrels](https://codeforces.com/problemset/problem/985/C)

## Description

输入 n k(1≤n,k≤1e5 且 1≤n*k≤1e5) L(0≤L≤1e9) 和长为 n*k 的数组 a(1≤a[i]≤1e9)，表示 n*k 条木板的长度。

你要制作 n 个木桶，每个木桶需要 k 条木板。
你可以使用任意 k 条木板来组装一个木桶，每条木板必须恰好属于一个木桶。
一个木桶的体积，等于其最短木板的长度。

要求：任意一对木桶的体积差都不能超过 L。
输出所有木桶体积和的最大值。
如果无法满足，输出 0。

## Hints/Notes

- Math

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

void solve(int n, int k, int l, vector<int>& lengths) {
    sort(lengths.begin(), lengths.end());
    int minLength = lengths[0];
    int target = minLength + l;
    int left = 0, right = n * k;
    while (left < right) {
        int mid = (right - left) / 2 + left;
        if (lengths[mid] == target) {
            left = mid + 1;
        } else if (lengths[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    if (left < n) {
        out << 0 << endl;
        return;
    }
    int x = 0;
    if (k > 1) {
        x = (left - n + k - 2) / (k - 1);
    }
    long long res = 0;
    for (int i = 0; i < x * k; i += k) {
        res += lengths[i];
    }
    for (int i = left - n + x; i < left; i++) {
        res += lengths[i];
    }
    out << res << endl;
}

int main() {
    int n, k, l;
    in >> n >> k >> l;
    vector<int> lengths;
    for (int t = 1; t <= n * k; t++) {
        int length;
        in >> length;
        lengths.push_back(length);
    }
    solve(n, k, l, lengths);
    return 0;
}
```
