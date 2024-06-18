---
title: 1364B. Most socially-distanced subsequence
categories: Leetcode
date: 2024-06-17 23:29:44
tags:
    - greedy
    - two pointers
---

[B. Most socially-distanced subsequence](https://codeforces.com/problemset/problem/1364/B)

## Description

输入 T(≤2e4) 表示 T 组数据。所有数据的 n 之和 ≤1e5。
每组数据输入 n(2≤n≤1e5) 和一个 1~n 的排列 p。

选一个 p 的长度至少为 2 的子序列 b，最大化 b 的所有相邻元素的绝对差的和。
即 S=|b1-b2|+|b2-b3|+...
在 S 最大的前提下，b 的长度尽量小。
输出任意一个符合要求的 b。

注：子序列不一定连续。

## Hints/Notes

- only the peaks matter

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

void solve(vector<int>& nums, int size) {
    vector<int> peaks;
    for (int i = 1; i < nums.size() - 1; i++) {
        if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
            peaks.push_back(nums[i]);
        }
        if (nums[i] < nums[i - 1] && nums[i] < nums[i + 1]) {
            peaks.push_back(nums[i]);
        }
    }
    out << 2 + peaks.size() << endl;
    out << nums[0] << " ";
    peaks.push_back(nums[size - 1]);
    for (int i = 0; i < peaks.size(); i++) {
        out << peaks[i] << " ";
    }
    out << endl;
}

int main() {
    int tc;
    in >> tc;
    for (int i = 0; i < tc; i++) {
        int size;
        in >> size;
        vector<int> nums;
        for (int i = 0; i < size; i++) {
            int num;
            in >> num;
            nums.push_back(num);
        }
        solve(nums, size);
    }
    return 0;
}
```
