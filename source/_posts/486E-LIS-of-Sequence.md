---
title: 486E. LIS of Sequence
categories: Leetcode
date: 2024-06-03 23:33:09
tags:
    - data structures
    - dp
    - greedy
    - hashing
    - math
---

[E. LIS of Sequence](https://codeforces.com/problemset/problem/486/E)

## Description

输入 n(1≤n≤1e5) 和长为 n 的数组 a(1≤a[i]≤1e5)。

定义 LIS 为 a 的最长严格递增子序列，注意可能有多个 LIS。
对于每个 i：
如果 a[i] 不在任何 LIS 中，输出 1。
如果 a[i] 在至少一个 LIS 中，但不在所有 LIS 中，输出 2。
如果 a[i] 在所有 LIS 中，输出 3。
输出在同一行，不要加空格。

注意，a=[1,2,2,3] 有两个相同的 LIS [1,2,3]，其中 1 和 3 都在这两个 LIS 中，但 2 只在其中一个 LIS 不在另一个 LIS 中，所以输出 3223。

## Hints/Notes

- binary research to solve LIS

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

int binary_search(vector<int>& LIS, int target) {
    int left = 0, right = LIS.size();
    while (left < right) {
        int mid = (right - left) / 2 + left;
        if (LIS[mid] >= target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

void solve(vector<int>& nums) {
    vector<int> LIS;
    vector<int> dp1;
    int longest = 0;
    for (int num : nums) {
        int targetIndex = binary_search(LIS, num);
        if (targetIndex == LIS.size()) {
            LIS.push_back(num);
            dp1.push_back(LIS.size());
        } else {
            dp1.push_back(targetIndex + 1);
            LIS[targetIndex] = num;
        }
        longest = max(longest, (int)LIS.size());
    }
    for (int& num : nums) {
        num = -num;
    }
    LIS.clear();
    vector<int> dp2(nums.size(), 0);
    for (int i = nums.size() - 1; i >= 0; i--) {
        int num = nums[i];
        int targetIndex = binary_search(LIS, num);
        if (targetIndex == LIS.size()) {
            LIS.push_back(num);
            dp2[i] = LIS.size();
        } else {
            dp2[i] = targetIndex + 1;
            LIS[targetIndex] = num;
        }
    }
    vector<int> res(nums.size(), 0);
    map<int, int> cnt;
    for (int i = 0; i < nums.size(); i++) {
        if (dp1[i] + dp2[i] - 1 != longest) {
            res[i] = 1;
            continue;
        }
        cnt[dp1[i]]++;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (res[i] == 1) {
            continue;
        } else if (cnt[dp1[i]] > 1) {
            res[i] = 2;
        } else {
            res[i] = 3;
        }
    }
    for (int i = 0; i < res.size(); i++) {
        out << res[i];
    }
    out << endl;
}

int main() {
    int n;
    in >> n;
    vector<int> nums;
    for (int t = 1; t <= n; t++) {
        int num;
        in >> num;
        nums.push_back(num);
    }
    solve(nums);
    return 0;
}
```
