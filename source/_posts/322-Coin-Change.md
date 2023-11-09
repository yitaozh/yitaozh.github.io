---
title: 322. Coin Change
categories: Leetcode
date: 2023-11-08 23:55:35
tags:
    - Array
    - Dynamic Programming
    - Breadth-First Search
---

# [322\. Coin Change](https://leetcode.com/problems/coin-change/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Dynamic Programming](https://leetcode.com/tag/https://leetcode.com/tag/dynamic-programming//), [Breadth-First Search](https://leetcode.com/tag/https://leetcode.com/tag/breadth-first-search//)

You are given an integer array `coins` representing coins of different denominations and an integer `amount` representing a total amount of money.

Return _the fewest number of coins that you need to make up that amount_. If that amount of money cannot be made up by any combination of the coins, return `-1`.

You may assume that you have an infinite number of each kind of coin.

**Example 1:**

```bash
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
```

**Example 2:**

```bash
Input: coins = [2], amount = 3
Output: -1
```

**Example 3:**

```bash
Input: coins = [1], amount = 0
Output: 0
```

**Constraints:**

* `1 <= coins.length <= 12`
* 1 <= coins[i] <= 2<sup>31</sup> - 1
* 0 <= amount <= 10<sup>4</sup>

## Hints/Notes

* dp

## Solution

Language: **C++**

```C++
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> res(amount + 1, amount + 1);
        res[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i - coin >= 0 && res[i - coin] != amount + 1) {
                    res[i] = min(res[i], res[i - coin] + 1);
                }
            }
        }
        return res[amount] == amount + 1 ? -1 : res[amount];
    }
};
```
