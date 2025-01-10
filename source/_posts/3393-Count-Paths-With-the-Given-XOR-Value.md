---
title: 3393. Count Paths With the Given XOR Value
categories: Leetcode
date: 2025-01-10 00:51:18
tags:
    - Array
    - Dynamic Programming
    - Bit Manipulation
    - Matrix
---

[3393. Count Paths With the Given XOR Value](https://leetcode.com/problems/count-paths-with-the-given-xor-value/description/)

## Description

You are given a 2D integer array `grid` with size `m x n`. You are also given an integer `k`.

Your task is to calculate the number of paths you can take from the top-left cell `(0, 0)` to the bottom-right cell `(m - 1, n - 1)` satisfying the following **constraints**:

- You can either move to the right or down. Formally, from the cell `(i, j)` you may move to the cell `(i, j + 1)` or to the cell `(i + 1, j)` if the target cell exists.
- The `XOR` of all the numbers on the path must be **equal**  to `k`.

Return the total number of such paths.

Since the answer can be very large, return the result **modulo**  `10^9 + 7`.

**Example 1:**

```bash
Input: grid = [[2, 1, 5], [7, 10, 0], [12, 6, 4]], k = 11

Output: 3
```

Explanation:

The 3 paths are:

- `(0, 0) → (1, 0) → (2, 0) → (2, 1) → (2, 2)`
- `(0, 0) → (1, 0) → (1, 1) → (1, 2) → (2, 2)`
- `(0, 0) → (0, 1) → (1, 1) → (2, 1) → (2, 2)`

**Example 2:**

```bash
Input: grid = [[1, 3, 3, 3], [0, 3, 3, 2], [3, 0, 1, 1]], k = 2

Output: 5
```

Explanation:

The 5 paths are:

- `(0, 0) → (1, 0) → (2, 0) → (2, 1) → (2, 2) → (2, 3)`
- `(0, 0) → (1, 0) → (1, 1) → (2, 1) → (2, 2) → (2, 3)`
- `(0, 0) → (1, 0) → (1, 1) → (1, 2) → (1, 3) → (2, 3)`
- `(0, 0) → (0, 1) → (1, 1) → (1, 2) → (2, 2) → (2, 3)`
- `(0, 0) → (0, 1) → (0, 2) → (1, 2) → (2, 2) → (2, 3)`

**Example 3:**

```bash
Input: grid = [[1, 1, 1, 2], [3, 0, 3, 2], [3, 0, 2, 2]], k = 10

Output: 0
```

**Constraints:**

- `1 <= m == grid.length <= 300`
- `1 <= n == grid[r].length <= 300`
- `0 <= grid[r][c] < 16`
- `0 <= k < 16`

## Hints/Notes

- 2025/01/10
- dp
- [0x3F's solution](https://leetcode.cn/problems/count-paths-with-the-given-xor-value/solutions/3026905/wang-ge-tu-dpcong-ji-yi-hua-sou-suo-dao-k1bpm/)(checked)
- Biweekly Contest 146

## Solution

Language: **C++**

```C++
class Solution {
public:
    const int MOD = 1e9 + 7;
    int m, n, k;
    vector<vector<vector<int>>> dp;

    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        m = grid.size(); n = grid[0].size(); this->k = k;
        dp.resize(m, vector<vector<int>>(n, vector<int>(16, -1)));
        int res = dfs(0, 0, 0, grid);
        return res;
    }

    int dfs(int x, int y, int cur, vector<vector<int>>& grid) {
        if (x == m - 1 && y == n - 1) {
            return (cur ^ grid[x][y]) == k;
        }
        if (dp[x][y][cur] != -1) {
            return dp[x][y][cur];
        }
        long res = 0;
        if (x + 1 < m) {
            res = (res + dfs(x + 1, y, cur ^ grid[x][y], grid)) % MOD;
        }
        if (y + 1 < n) {
            res = (res + dfs(x, y + 1, cur ^ grid[x][y], grid)) % MOD;
        }
        dp[x][y][cur] = res;
        return res;
    }
};
```
