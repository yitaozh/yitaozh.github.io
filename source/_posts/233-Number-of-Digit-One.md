---
title: 233. Number of Digit One
categories: Leetcode
date: 2024-11-26 22:57:02
tags:
    - Math
    - Dynamic Programming
    - Recursion
---

[233. Number of Digit One](https://leetcode.com/problems/number-of-digit-one/description/)

## Description

Given an integer `n`, count the total number of digit `1` appearing in all non-negative integers less than or equal to `n`.

**Example 1:**

```bash
Input: n = 13
Output: 6
```

**Example 2:**

```bash
Input: n = 0
Output: 0
```

**Constraints:**

- `0 <= n <= 10^9`

## Hints/Notes

- 2024/11/16
- digit dp
- [0x3F's solution](https://leetcode.cn/problems/number-of-digit-one/solutions/1750339/by-endlesscheng-h9ua/)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    string s;
    vector<vector<int>> dp;

    int countDigitOne(int n) {
        s = to_string(n);
        dp.resize(s.size(), vector<int>(s.size(), -1));
        int res = dfs(0, 0, true);
        return res;
    }

    // nums can have zeroes in between, no need for isNum
    int dfs(int index, int prev, bool isLimit) {
        if (index == s.size()) {
            return prev;
        }
        if (!isLimit && dp[index][prev] != -1) {
            return dp[index][prev];
        }
        int res = 0;
        int up = isLimit ? s[index] - '0' : 9;
        for (int i = 0; i <= up; i++) {
            res += dfs(index + 1, prev + (i == 1), isLimit && i == up);
        }
        // check status during read and write memo both
        if (!isLimit) {
            dp[index][prev] = res;
        }
        return res;
    }
};
```
