---
title: 309. Best Time to Buy and Sell Stock with Cooldown
categories: Leetcode
date: 2025-01-07 23:40:33
tags:
    - Array
    - Dynamic Programming
---

[309. Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/?envType=problem-list-v2&envId=plakya4j)

## Description

You are given an array `prices` where `prices[i]` is the price of a given stock on the `i^th` day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

- After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).

**Note:**  You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

**Example 1:**

```bash
Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
```

**Example 2:**

```bash
Input: prices = [1]
Output: 0
```

**Constraints:**

- `1 <= prices.length <= 5000`
- `0 <= prices[i] <= 1000`

## Hints/Notes

- 2025/01/05
- dp
- [0x3F's solution](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<array<int, 2>> dp;

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.resize(n, array<int, 2>{-1, -1});
        int res = dfs(0, false, prices);
        return res;
    }

    int dfs(int index, int hold, vector<int>& prices) {
        if (index >= prices.size()) {
            return 0;
        }
        if (dp[index][hold] != -1) {
            return dp[index][hold];
        }
        int& res = dp[index][hold];
        res = dfs(index + 1, hold, prices);
        if (hold) {
            res = max(res, dfs(index + 2, false, prices) + prices[index]);
        } else {
            res = max(res, dfs(index + 1, true, prices) - prices[index]);
        }
        return res;
    }
};
```
