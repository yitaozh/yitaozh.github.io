---
title: 1077C. Good Array
categories: Leetcode
date: 2024-06-19 00:53:01
tags:
    - bitmasks
    - greedy
    - math
---

[C. Johnny and Another Rating Drop](https://codeforces.com/problemset/problem/1077/C)

## Description

输入 n(2≤n≤2e5) 和长为 n 的数组 a(1≤a[i]≤1e6)。

对于数组 b，如果 b 中存在一个数 x，使得 x = b 中其余元素之和，则称 b 为「好数组」。

如果删除 a[i] 可以使剩余元素组成好数组，则称 i 为「好下标」。
输出 a 的好下标的个数，以及所有好下标（任意顺序）。注意下标从 1 开始。

## Hints/Notes

- record the mx1 and mx2

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
    long long max1 = 0, max2 = 0, maxIdx = 0, sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > max1) {
            max2 = max1;
            max1 = nums[i];
            maxIdx = i;
        } else if (nums[i] > max2) {
            max2 = nums[i];
        }
        sum += nums[i];
    }
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        int mx = (i == maxIdx) ? max2 : max1;
        if (sum - nums[i] == 2 * mx) {
            res.push_back(i + 1);
        }
    }
    out << res.size() << endl;
    for (auto v : res) {
        out << v << " ";
    }
}

int main() {
    int n;
    in >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int num;
        in >> num;
        nums.push_back(num);
    }
    solve(nums);
    return 0;
}
```
