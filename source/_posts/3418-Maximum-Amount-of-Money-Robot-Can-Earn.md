---
title: 3418. Maximum Amount of Money Robot Can Earn
categories: Leetcode
date: 2025-01-17 00:10:57
tags:
    - Array
    - Dynamic Programming
    - Matrix
---

[3418. Maximum Amount of Money Robot Can Earn](https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/)

## Description

You are given an `m x n` grid. A robot starts at the top-left corner of the grid `(0, 0)` and wants to reach the bottom-right corner `(m - 1, n - 1)`. The robot can move either right or down at any point in time.

The grid contains a value `coins[i][j]` in each cell:

- If `coins[i][j] >= 0`, the robot gains that many coins.
- If `coins[i][j] < 0`, the robot encounters a robber, and the robber steals the **absolute**  value of `coins[i][j]` coins.

The robot has a special ability to **neutralize robbers**  in at most **2 cells**  on its path, preventing them from stealing coins in those cells.

**Note:**  The robot's total coins can be negative.

Return the **maximum**  profit the robot can gain on the route.

**Example 1:**

```bash
Input: coins = [[0,1,-1],[1,-2,3],[2,-3,4]]

Output: 8
```

Explanation:

An optimal path for maximum coins is:

- Start at `(0, 0)` with `0` coins (total coins = `0`).
- Move to `(0, 1)`, gaining `1` coin (total coins = `0 + 1 = 1`).
- Move to `(1, 1)`, where there's a robber stealing `2` coins. The robot uses one neutralization here, avoiding the robbery (total coins = `1`).
- Move to `(1, 2)`, gaining `3` coins (total coins = `1 + 3 = 4`).
- Move to `(2, 2)`, gaining `4` coins (total coins = `4 + 4 = 8`).

**Example 2:**

```bash
Input: coins = [[10,10,10],[10,10,10]]

Output: 40
```

Explanation:

An optimal path for maximum coins is:

- Start at `(0, 0)` with `10` coins (total coins = `10`).
- Move to `(0, 1)`, gaining `10` coins (total coins = `10 + 10 = 20`).
- Move to `(0, 2)`, gaining another `10` coins (total coins = `20 + 10 = 30`).
- Move to `(1, 2)`, gaining the final `10` coins (total coins = `30 + 10 = 40`).

**Constraints:**

- `m == coins.length`
- `n == coins[i].length`
- `1 <= m, n <= 500`
- `-1000 <= coins[i][j] <= 1000`

## Hints/Notes

- 2025/01/16
- dp
- [0x3F's solution](https://leetcode.cn/problems/maximum-amount-of-money-robot-can-earn/solutions/3045103/wang-ge-tu-dp-by-endlesscheng-g96j/)(checked)
- Weekly Contest 432

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<array<int, 3>>> dp;
    int m, n;
    int maximumAmount(vector<vector<int>>& coins) {
        m = coins.size(); n = coins[0].size();
        dp.resize(m, vector<array<int, 3>>(n, {INT_MIN, INT_MIN, INT_MIN}));
        int res = dfs(0, 0, 2, coins);
        return res;
    }

    int dfs(int i, int j, int remain, vector<vector<int>>& coins) {
        if (i >= m || j >= n) {
            return INT_MIN;
        }
        if (i == m - 1 && j == n - 1) {
            return (coins[i][j] >= 0 || remain <= 0) ? coins[i][j] : 0;
        }
        if (dp[i][j][remain] != INT_MIN) {
            return dp[i][j][remain];
        }
        int& res = dp[i][j][remain];
        res = max(dfs(i + 1, j, remain, coins), dfs(i, j + 1, remain, coins)) + coins[i][j];
        if (coins[i][j] < 0 && remain > 0) {
            res = max({res, dfs(i + 1, j, remain - 1, coins), dfs(i, j + 1, remain - 1, coins)});
        }
        return res;
    }
};
```
