---
title: 1879D. Sum of XOR Functions
categories: Leetcode
date: 2024-06-17 23:33:25
tags:
    - bitmasks
    - combinatorics
    - divide and conquer
    - dp
    - math
---

[D. Sum of XOR Functions](https://codeforces.com/problemset/problem/1879/D)

## Description

输入 n(1≤n≤3e5) 和长为 n 的数组 a(0≤a[i]≤1e9)。

定义 f(L,R) 为连续子数组 a[L] 到 a[R] 的异或和。
计算所有 f(L,R)*(R-L+1) 的和，其中 L <= R。
输出答案模 998244353 的结果。

## Hints/Notes

- preXor

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

// use one number pxor to mark all xor
// for one xor value, assume it has 30 bits, one the ith bits
// if the bit is 1, we should check all previous 0 occurances << i
// the question is how to get the r - l
// so we need two array, one for the count of 0/1 at bit i
// one for the sum of index at bit i
int main() {
    int n;
    in >> n;
    long long count[30][2] = {0};
    long long sum[30][2] = {0};
    long long x = 0;
    for (int i = 0; i < 30; i++) {
        count[i][0] = 1;
    }
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        int num;
        in >> num;
        x ^= num;
        for (int j = 0; j < 30; j++) {
            int bit = (x >> j) & 1;
            res = (res + ((count[j][1 - bit] * i - sum[j][1 - bit]) % 998244353 << j) % 998244353) % 998244353;
            sum[j][bit] += i;
            count[j][bit]++;
        }
    }
    out << res << endl;
    return 0;
}
```
