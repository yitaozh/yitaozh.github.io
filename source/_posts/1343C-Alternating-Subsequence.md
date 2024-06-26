---
title: 1343C. Alternating Subsequence
categories: Leetcode
date: 2024-05-29 00:00:03
tags:
  - dp
  - Greedy
  - Two Pointers
---

[C. Alternating Subsequence](https://codeforces.com/problemset/problem/1343/C)

## Description

输入 T(≤1e4) 表示 T 组数据。所有数据的 n 之和 ≤2e5。
每组数据输入 n(1≤n≤2e5) 和长为 n 的数组 a(-1e9≤a[i]≤1e9 且 a[i]≠0)。

选一个 a 的子序列，要求:

1. 子序列是交替的（相邻元素一正一负）。
2. 在满足 1 的前提下，子序列尽量长。
3. 在满足 2 的前提下，子序列元素和尽量大。
   输出元素和的最大值。

注：子序列不一定连续。

## Hints/Notes

- 分组循环

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

void solve(vector<int>& nums) {
    long long pos_size = 0, pos_res = 0;
    for (int i = 0; i < nums.size(); ) {
        if (nums[i] < 0) {
            i++;
            continue;
        }
        int tmp = INT_MIN;
        pos_size++;
        for (; i < nums.size() && nums[i] > 0; i++) {
            tmp = max(tmp, nums[i]);
        }
        pos_res += tmp;
        tmp = INT_MIN;
        for (; i < nums.size() && nums[i] < 0; i++) {
            tmp = max(tmp, nums[i]);
        }
        if (tmp != INT_MIN) {
            pos_size++;
            pos_res += tmp;
        }
    }

    long long neg_size = 0, neg_res = 0;
    for (int i = 0; i < nums.size(); ) {
        if (nums[i] > 0) {
            i++;
            continue;
        }
        int tmp = INT_MIN;
        neg_size++;
        for (; i < nums.size() && nums[i] < 0; i++) {
            tmp = max(tmp, nums[i]);
        }
        neg_res += tmp;
        tmp = INT_MIN;
        for (; i < nums.size() && nums[i] > 0; i++) {
            tmp = max(tmp, nums[i]);
        }
        if (tmp != INT_MIN)  {
            neg_size++;
            neg_res += tmp;
        }
    }
    if (pos_size > neg_size) {
        out << pos_res << endl;
    } else if (pos_size < neg_size) {
        out << neg_res << endl;
    } else {
        out << max(pos_res, neg_res) << endl;
    }

}

int main() {
    int tc;
    in >> tc;
    for (int t = 1; t <= tc; t++) {
        int size;
        in >> size;
        vector<int> nums;
        for (int i = 0; i < size; i++) {
            int num;
            in >> num;
            nums.push_back(num);
        }
        solve(nums);
    }
    return 0;
}
```
