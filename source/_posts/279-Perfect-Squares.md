---
title: 279. Perfect Squares
categories: Leetcode
date: 2025-03-14 02:27:40
tags:
    - Math
    - Dynamic Programming
    - Breadth-First Search
---

[279. Perfect Squares](https://leetcode.com/problems/perfect-squares/description/)

## Description

Given an integer `n`, return the least number of perfect square numbers that sum to `n`.

A **perfect square**  is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, `1`, `4`, `9`, and `16` are perfect squares while `3` and `11` are not.

**Example 1:**

```bash
Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
```

**Example 2:**

```bash
Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
```

**Constraints:**

- `1 <= n <= 10^4`

## Hints/Notes

- 2025/03/09 Q2
- dp
- [0x3F's solution](https://leetcode.cn/problems/perfect-squares/solutions/2830762/dong-tai-gui-hua-cong-ji-yi-hua-sou-suo-3kz1g/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> coins;
    vector<int> dp;

    int numSquares(int n) {
        for (int i = 1; i * i <= n; i++) {
            coins.push_back(i * i);
        }
        dp.resize(n + 1, -1);
        int res = dfs(n);
        return res;
    }

    int dfs(int n) {
        if (n == 0) {
            return 0;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        int res = INT_MAX;
        for (int i = coins.size() - 1; i >= 0; i--) {
            if (coins[i] > n) {
                continue;
            }
            res = min(res, 1 + dfs(n - coins[i]));
        }
        dp[n] = res;
        return res;
    }
};
```
