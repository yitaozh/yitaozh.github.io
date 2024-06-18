---
title: 264C. Choosing Balls
categories: Leetcode
date: 2024-06-14 00:13:31
tags:
    - dp
---

[C. Choosing Balls](https://codeforces.com/problemset/problem/264/C)

## Description

输入 n(1≤n≤1e5) q(1≤q≤500) 和长为 n 的数组 v(-1e5≤v[i]≤1e5)，长为 n 的数组 c(1≤c[i]≤n)。
有 n 个球排成一排，第 i 个球的价值为 v[i]，颜色为 c[i]。

然后输入 q 个询问，每个询问输入 a 和 b，范围 [-1e5,1e5]。
对每个询问，计算：
从这一排球中，从左到右，选出一个子序列，子序列的价值和为：

- 如果球不在序列开头，且球的颜色与前一个球的颜色相同，则加上球的值 * a。
- 否则，加上球的值 * b。

输出子序列的价值和的最大值。
子序列可以是空的，此时价值和为 0。

注：子序列不一定连续。

思路可以用到 2024.6.8 的双周 t4 上。

## Hints/Notes

- dp

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

void solve(int n, vector<int>& values, vector<int>& colors, int a, int b) {
    // define dp[c]: the max value we can get when ending with color c
    vector<long long> dp(n + 1, LLONG_MIN);
    long long mx1 = 0, mx2 = 0;
    int mc = -1;
    for (int i = 0; i < n; i++) {
        long long v = values[i];
        int c = colors[i];
        /*  how to get the maxValue ending with c, several possibilities:
            1. this is the first the value in the sequence, the result is b * v
            2. this is not the first value in the sequence, and the color is the same as the
            previous color, dp[c] + a * v
            3. this is not the first value in the sequence, we append the num as a successor to a different
            color. Which color? the color with the biggest dp[c]

            to make this happen, we need to record the color with the biggest dp[] value. if the color
            with biggest dp[] value is c, then we should do it with the second biggest dp[] value
        */
        long long firstOption = b * v;
        if (dp[c] != LLONG_MIN) {
            // can be dp[c]
            // can be b * v(as first value)
            // can be mx1 + a * v or mx2 + b * v if c == mx
            // can be mx1 + b * v or mx1 + a * v if c != mx
            long long zeroOption = dp[c];
            long long thirdOption;
            if (c == mc) {
                thirdOption = max(mx1 + a * v, mx2 + b * v);
            } else {
                thirdOption = max(mx1 + b * v, dp[c] + a * v);
            }
            dp[c] = max(zeroOption, max(firstOption, thirdOption));
        } else {
            // can be 0 <-- this is wrong, because we need to pick this item, cannot be zero
            // can be b * v
            // can be mx1 + b * v if mc != -1
            long long thirdOption = mx1 + b * v;
            dp[c] = max(firstOption, thirdOption);
        }
        if (dp[c] > mx1) {
            if (c != mc) {
                mc = c;
                mx2 = mx1;
            }
            mx1 = dp[c];
        } else if (dp[c] > mx2 && c != mc) {
            mx2 = dp[c];
        }
    }
    out << mx1 << endl;
}

int main() {
    int n, q;
    in >> n >> q;
    vector<int> values;
    vector<int> colors;
    for (int t = 1; t <= n; t++) {
        int value;
        in >> value;
        values.push_back(value);
    }
    for (int t = 1; t <= n; t++) {
        int color;
        in >> color;
        colors.push_back(color);
    }
    for (int t = 1; t <= q; t++) {
        int a, b;
        in >> a >> b;
        solve(n, values, colors, a, b);
    }
    return 0;
}
```
