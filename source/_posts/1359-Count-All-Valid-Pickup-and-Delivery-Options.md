---
title: 1359. Count All Valid Pickup and Delivery Options
categories: Leetcode
date: 2025-04-18 22:56:57
tags:
    - Math
    - Dynamic Programming
    - Combinatorics
---

[1359. Count All Valid Pickup and Delivery Options](https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/description/?envType=company&envId=doordash&favoriteSlug=doordash-more-than-six-months)

## Description

Given `n` orders, each order consists of a pickup and a delivery service.

Count all valid pickup/delivery possible sequences such that delivery(i) is always after ofpickup(i).

Since the answermay be too large,return it modulo10^9 + 7.

**Example 1:**

```bash
Input: n = 1
Output: 1
Explanation: Unique order (P1, D1), Delivery 1 always is after of Pickup 1.
```

**Example 2:**

```bash
Input: n = 2
Output: 6
Explanation: All possible orders:
(P1,P2,D1,D2), (P1,P2,D2,D1), (P1,D1,P2,D2), (P2,P1,D1,D2), (P2,P1,D2,D1) and (P2,D2,P1,D1).
This is an invalid order (P1,D2,P2,D1) because Pickup 2 is after of Delivery 2.
```

**Example 3:**

```bash
Input: n = 3
Output: 90
```

**Constraints:**

- `1 <= n <= 500`

## Hints/Notes

- 2025/04/14 Q3
- dp
- [0x3F's solution](https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/editorial/?envType=company&envId=doordash&favoriteSlug=doordash-more-than-six-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<int>> dp;
    const int MOD = 1e9 + 7;

    int countOrders(int n) {
        dp.resize(n + 1, vector<int>(n + 1, -1));
        int res = dfs(n, 0);
        return res;
    }

    int dfs(int num_p, int num_d) {
        if (num_p == 0 && num_d == 1) {
            return 1;
        }
        if (dp[num_p][num_d] != -1) {
            return dp[num_p][num_d];
        }
        long res = 0;
        // so we need to make some choices here
        // 1. if num_p is bigger than zero, then we can place any num_p here
        // 2. if num_d is bigger than zero, then we can place any num_d here
        if (num_p > 0) {
            res = ((long)num_p * dfs(num_p - 1, num_d + 1)) % MOD;
        }
        if (num_d > 0) {
            res = (res +(long) num_d * dfs(num_p, num_d - 1)) % MOD;
        }
        dp[num_p][num_d] = res;
        return res;
    }
};
```
