---
title: 1067. Digit Count in Range
categories: Leetcode
date: 2024-11-30 11:52:20
tags:
    - Math
    - Dynamic Programming
---

[1067. Digit Count in Range](https://leetcode.com/problems/digit-count-in-range/description/)

## Description

Given a single-digit integer `d` and two integers `low` and `high`, return the number of times that `d` occurs as a digit in all integers in the inclusive range `[low, high]`.

**Example 1:**

```bash
Input: d = 1, low = 1, high = 13
Output: 6
Explanation: The digit d = 1 occurs 6 times in 1, 10, 11, 12, 13.
Note that the digit d = 1 occurs twice in the number 11.
```

**Example 2:**

```bash
Input: d = 3, low = 100, high = 250
Output: 35
Explanation: The digit d = 3 occurs 35 times in 103,113,123,130,131,...,238,239,243.
```

**Constraints:**

- `0 <= d <= 9`
- `1 <= low <= high <= 2 * 10^8`

## Hints/Notes

- 2024/11/19
- digit dp with lower bound and is_num
- premium

## Solution

Language: **C++**

```C++
class Solution {
public:
    int d;
    string lowStr, highStr;
    vector<vector<int>> dp;

    int digitsCount(int d, int low, int high) {
        this->d = d;
        highStr = to_string(high);
        lowStr = to_string(low);
        int n = highStr.size();
        dp.resize(n, vector<int>(n, -1));
        lowStr = string(n - lowStr.size(), '0') + lowStr;
        int res = dfs(0, 0, true, true, false);
        return res;
    }

    int dfs(int index, int count, bool limit_low, bool limit_high, bool is_num) {
        if (index == highStr.size()) {
            return is_num ? count : 0;
        }

        int res = 0;
        if (!is_num && lowStr[index] -'0' == 0)
            res += dfs(index + 1, count, true, false, false);

        if (!limit_low && !limit_high && dp[index][count] != -1) {
            return dp[index][count];
        }
        int lo = limit_low ? lowStr[index] - '0' : 0;
        int hi = limit_high ? highStr[index] - '0' : 9;
        for (int i = max(lo, 1 - is_num); i <= hi; i++) {
            res += dfs(index + 1, count + (i == d), limit_low && i == lo, limit_high && i == hi, true);
        }
        if (!limit_low && !limit_high) {
            dp[index][count] = res;
        }
        return res;
    }
};
```
