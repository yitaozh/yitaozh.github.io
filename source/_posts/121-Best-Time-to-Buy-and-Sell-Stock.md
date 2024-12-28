---
title: 121. Best Time to Buy and Sell Stock
categories: Leetcode
date: 2024-12-28 15:54:56
tags:
    - Array
    - Dynamic Programming
---

[121. Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/?envType=problem-list-v2&envId=plakya4j)

## Description

You are given an array `prices` where `prices[i]` is the price of a given stock on the `i^th` day.

You want to maximize your profit by choosing a **single day**  to buy one stock and choosing a **different day in the future**  to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return `0`.

**Example 1:**

```bash
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
```

**Example 2:**

```bash
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
```

**Constraints:**

- `1 <= prices.length <= 10^5`
- `0 <= prices[i] <= 10^4`

## Hints/Notes

- 2024/12/28
- N/A
- [0x3F's solution](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/solutions/2464650/mei-ju-mai-chu-jie-ge-wei-hu-mai-ru-de-z-02ud/)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mi = INT_MAX / 2;
        int res = 0;
        for (auto& p : prices) {
            res = max(res, p - mi);
            mi = min(p, mi);
        }
        return res;
    }
};
```
