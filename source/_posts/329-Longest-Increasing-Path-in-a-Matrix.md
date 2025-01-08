---
title: 329. Longest Increasing Path in a Matrix
categories: Leetcode
date: 2025-01-08 00:41:25
tags:
    - Array
    - Dynamic Programming
    - Depth-First Search
    - Breadth-First Search
    - Graph
    - Topological Sort
    - Memoization
    - Matrix
---

[329. Longest Increasing Path in a Matrix](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/?envType=problem-list-v2&envId=plakya4j)

## Description

Given an `m x n` integers `matrix`, return the length of the longest increasing path in `matrix`.

From each cell, you can either move in four directions: left, right, up, or down. You **may not**  move **diagonally**  or move **outside the boundary**  (i.e., wrap-around is not allowed).

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/01/05/grid1.jpg" style="width: 242px; height: 242px;">

```bash
Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is `[1, 2, 6, 9]`.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/01/27/tmp-grid.jpg" style="width: 253px; height: 253px;">

```bash
Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is `[3, 4, 5, 6]`. Moving diagonally is not allowed.
```

**Example 3:**

```bash
Input: matrix = [[1]]
Output: 1
```

**Constraints:**

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 200`
- `0 <= matrix[i][j] <= 2^31 - 1`

## Hints/Notes

- 2025/01/06
- dfs
- No solution from 0x3F

## Solution

Language: **C++**

```C++
class Solution {
public:
    static constexpr int DIRs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> steps;
    int m, n;

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        steps.resize(m, vector<int>(n, -1));
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, dfs(i, j, matrix));
            }
        }
        return res;
    }

    int dfs(int i, int j, vector<vector<int>>& matrix) {
        if (steps[i][j] != -1) {
            return steps[i][j];
        }
        int& val = steps[i][j];
        val = 1;
        for (int k = 0; k < 4; k++) {
            int dx = i + DIRs[k][0], dy = j + DIRs[k][1];
            if (dx >= 0 && dx < m && dy >= 0 && dy < n && matrix[dx][dy] < matrix[i][j]) {
                    steps[i][j] = max(steps[i][j], dfs(dx, dy, matrix) + 1);
            }
        }
        return val;
    }
};
```
