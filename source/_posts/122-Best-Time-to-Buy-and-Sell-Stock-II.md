---
title: 122. Best Time to Buy and Sell Stock II
categories: Leetcode
date: 2025-01-08 00:29:57
tags:
    - Array
    - Dynamic Programming
    - Greedy
---

[122. Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/)

## Description

You are given an integer array `prices` where `prices[i]` is the price of a given stock on the `i^th` day.

On each day, you may decide to buy and/or sell the stock. You can only hold **at most one**  share of the stock at any time. However, you can buy it then immediately sell it on the **same day**.

Find and return the **maximum**  profit you can achieve.

**Example 1:**

```bash
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
```

**Example 2:**

```bash
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
```

**Example 3:**

```bash
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
```

**Constraints:**

- `1 <= prices.length <= 3 * 10^4`
- `0 <= prices[i] <= 10^4`

## Hints/Notes

- 2025/01/05
- dp
- [0x3F's solution](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/solutions/2201406/shi-pin-jiao-ni-yi-bu-bu-si-kao-dong-tai-o3y4/)(checked)

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
        if (index == prices.size()) {
            return 0;
        }
        if (dp[index][hold] != -1) {
            return dp[index][hold];
        }
        int& res = dp[index][hold];
        res = dfs(index + 1, hold, prices);
        if (hold) {
            res = max(res, dfs(index + 1, false, prices) + prices[index]);
        } else {
            res = max(res, dfs(index + 1, true, prices) - prices[index]);
        }
        return res;
    }
};
```
