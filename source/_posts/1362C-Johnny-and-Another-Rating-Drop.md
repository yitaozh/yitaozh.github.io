---
title: 1362C. Johnny and Another Rating Drop
categories: Leetcode
date: 2024-06-17 23:31:40
tags:
    - bitmasks
    - greedy
    - math
---

[C. Johnny and Another Rating Drop](https://codeforces.com/problemset/problem/1362/C)

## Description

输入 T(≤1e4) 表示 T 组数据。
每组数据输入 n(1≤n≤1e18)。

定义 popcount(x) 为 x 二进制中的 1 的个数。
输出 popcount(0^1) + popcount(1^2) + popcount(2^3) + ... + popcount((n-1)^n)。
其中 ^ 表示异或。

变形：异或改成【或】怎么做？改成【与】怎么做？

## Hints/Notes

- think about how each bit contribute the result

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

void solve(long long n) {
    long long res = 0;
    while (n > 0) {
        res += n;
        n /= 2;
    }
    out << res << endl;
}

int main() {
    int tc;
    in >> tc;
    for (int i = 0; i < tc; i++) {
        long long n;
        in >> n;
        solve(n);
    }
    return 0;
}
```
