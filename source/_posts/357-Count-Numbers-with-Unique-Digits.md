---
title: 357. Count Numbers with Unique Digits
categories: Leetcode
date: 2024-11-30 12:28:15
tags:
    - Math
    - Dynamic Programming
    - Backtracking
---

[357. Count Numbers with Unique Digits](https://leetcode.com/problems/count-numbers-with-unique-digits/description/)

## Description

Given an integer `n`, return the count of all numbers with unique digits, `x`, where `0 <= x < 10^n`.

**Example 1:**

```bash
Input: n = 2
Output: 91
Explanation: The answer should be the total numbers in the range of 0 ≤ x < 100, excluding 11,22,33,44,55,66,77,88,99
```

**Example 2:**

```bash
Input: n = 0
Output: 1
```

**Constraints:**

- `0 <= n <= 8`

## Hints/Notes

- 2024/11/20
- digit dp with is_num
- No solution from 0x3F

## Solution

Language: **C++**

```C++
class Solution {
public:
    string s;
    vector<vector<int>> dp;

    int countNumbersWithUniqueDigits(int n) {
        s = string(n, '9');
        dp.resize(s.size(), vector<int>(1024, -1));
        int res = dfs(0, 0, false);
        return res;
    }

    int dfs(int index, int mask, bool is_num) {
        if (index == s.size()) {
            return 1;
        }
        if (is_num && dp[index][mask] != -1) {
            return dp[index][mask];
        }
        int res = is_num ? 0 : dfs(index + 1, mask, false);
        for (int i = 1 - is_num; i <= 9; i++) {
            if ((mask >> i & 1) == 0) {
                res += dfs(index + 1, mask | (1 << i), true);
            }
        }
        if (is_num) {
            dp[index][mask] = res;
        }
        return res;
    }
};
```
