---
title: 600. Non-negative Integers without Consecutive Ones
categories: Leetcode
date: 2024-11-28 15:07:22
tags:
    - Dynamic Programming
---

[600. Non-negative Integers without Consecutive Ones](https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/description/)

## Description

Given a positive integer `n`, return the number of the integers in the range `[0, n]` whose binary representations **do not**  contain consecutive ones.

**Example 1:**

```bash
Input: n = 5
Output: 5
Explanation:
Here are the non-negative integers <= 5 with their corresponding binary representations:
0 : 0
1 : 1
2 : 10
3 : 11
4 : 100
5 : 101
Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy the rule.
```

**Example 2:**

```bash
Input: n = 1
Output: 2
```

**Example 3:**

```bash
Input: n = 2
Output: 3
```

**Constraints:**

- `1 <= n <= 10^9`

## Hints/Notes

- 2024/11/17
- digit dp
- [0x3F's solution](https://leetcode.cn/problems/non-negative-integers-without-consecutive-ones/solutions/1750941/by-endlesscheng-1egu/)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int n_, m;
    vector<vector<int>> dp;

    int findIntegers(int n) {
        n_ = n; m = __lg(n);
        dp.resize(m + 1, vector<int>(2, -1));
        int res = dfs(0, 0, true);
        return res;
    }

    int dfs(int index, int prev, bool isLimit) {
        if (index == m + 1) {
            return 1;
        }
        if (!isLimit && dp[index][prev] != -1) {
            return dp[index][prev];
        }
        // if there's other constraint on the digit, only modify the for loop
        // condition, don't modify up here
        int up = isLimit ? n_ >> (m - index) & 1 : 1;
        int res = 0;
        for (int i = 0; i <= up; i++) {
            if (prev && i) {
                continue;
            }
            res += dfs(index + 1, i, isLimit && i == up);
        }
        if (!isLimit) {
            dp[index][prev] = res;
        }
        return res;
    }
};
```
