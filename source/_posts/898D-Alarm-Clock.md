---
title: 898D. Alarm Clock
categories: Leetcode
date: 2024-06-06 12:06:24
tags:
    - greedy
---

[898D. Alarm Clock](https://codeforces.com/problemset/problem/898/D)

## Description

输入 n(1≤n≤2e5) m(1≤m≤1e6) k(1≤k≤n) 和长为 n 的数组 a(1≤a[i]≤1e6)。

数轴上有 n 个点，要求任意长为 m-1 的闭区间不能包含 >= k 个点。
问：至少要去掉多少个点？

注：闭区间 [L,R] 的长度为 R-L。

## Hints/Notes

- sliding window

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

void solve(int n, int m, int k, vector<int>& alarms) {
    sort(alarms.begin(), alarms.end());
    deque<int> q;
    int right = 0, res = 0;
    while (right < n) {
        while (!q.empty() && (alarms[right] - q.front() >= m)) {
            q.pop_front();
        }
        if (q.size() >= k - 1) {
            alarms[right] = 0;
            res++;
        } else {
            q.push_back(alarms[right]);
        }
        right++;
    }
    out << res << endl;
}

int main() {
    int n, m, k;
    in >> n >> m >> k;
    vector<int> alarms;
    for (int t = 1; t <= n; t++) {
        int alarm;
        in >> alarm;
        alarms.push_back(alarm);
    }
    solve(n, m, k, alarms);
    return 0;
}
```
