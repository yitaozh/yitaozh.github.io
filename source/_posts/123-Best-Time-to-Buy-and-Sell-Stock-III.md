---
title: 123. Best Time to Buy and Sell Stock III
categories: Leetcode
date: 2025-03-16 22:57:31
tags:
    - Array
    - Dynamic Programming
---

[123. Best Time to Buy and Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Description

You are given an array `prices` where `prices[i]` is the price of a given stock on the `i^th` day.

Find the maximum profit you can achieve. You may complete **at most two transactions** .

**Note:**  You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

**Example 1:**

```bash
Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.```

**Example 2:**

```absh
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
```

**Example 3:**

```bash
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
```

**Constraints:**

- `1 <= prices.length <= 10^5`
- `0 <= prices[i] <= 10^5`

## Hints/Notes

- 2025/02/11 Q2
- dp
- [0x3F's solution](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/solutions/2974681/188-ti-k2-de-qing-kuang-pythonjavacgojsr-sg1z/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<array<int, 2>>> dp;
    int n;

    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.resize(n, vector<array<int, 2>>(3, {-1, -1}));
        int res = dfs(0, 2, false, prices);
        return res;
    }

    int dfs(int index, int remaining, bool hold, vector<int>& prices) {
        if (index == n) {
            return 0;
        }
        if (dp[index][remaining][hold] != -1) {
            return dp[index][remaining][hold];
        }
        int res = 0;
        if (hold) {
            res = max(dfs(index + 1, remaining, false, prices) + prices[index], dfs(index + 1, remaining, true, prices));
        } else {
            if (remaining > 0) {
                res = max(dfs(index + 1, remaining - 1, true, prices) - prices[index], dfs(index + 1, remaining, false, prices));
            }
        }
        dp[index][remaining][hold] = res;
        return res;
    }
};
```
