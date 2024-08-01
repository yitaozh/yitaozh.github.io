---
title: 64. Minimum Path Sum
categories: Leetcode
date: 2024-07-31 23:45:19
tags:
    - Array
    - Dynamic Programming
    - Matrix
---

[64. Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/description/)

## Description

Given a `m x n` `grid` filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

**Note:**  You can only move either down or right at any point in time.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/11/05/minpath.jpg" style="width: 242px; height: 242px;">

```bash
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
```

**Example 2:**

```bash
Input: grid = [[1,2,3],[4,5,6]]
Output: 12
```

**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 200`
- `0 <= grid[i][j] <= 200`

## Hints/Notes

- dp

## Solution

Language: **C++**

```C++
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!i && !j) {
                    dp[i][j] = grid[i][j];
                    continue;
                }
                int top = i ? dp[i - 1][j] : INT_MAX;
                int left = j ? dp[i][j - 1] : INT_MAX;
                dp[i][j] = min(top, left) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};
```
