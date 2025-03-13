---
title: 2658. Maximum Number of Fish in a Grid
categories: Leetcode
date: 2025-03-13 13:11:16
tags:
    - Array
    - Depth-First Search
    - Breadth-First Search
    - Union Find
    - Matrix
---

[2658. Maximum Number of Fish in a Grid](https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/description/)

## Description

You are given a **0-indexed**  2D matrix `grid` of size `m x n`, where `(r, c)` represents:

- A **land**  cell if `grid[r][c] = 0`, or
- A **water**  cell containing `grid[r][c]` fish, if `grid[r][c] > 0`.

A fisher can start at any **water**  cell `(r, c)` and can do the following operations any number of times:

- Catch all the fish at cell `(r, c)`, or
- Move to any adjacent **water**  cell.

Return the **maximum**  number of fish the fisher can catch if he chooses his starting cell optimally, or `0` if no water cell exists.

An **adjacent**  cell of the cell `(r, c)`, is one of the cells `(r, c + 1)`, `(r, c - 1)`, `(r + 1, c)` or `(r - 1, c)` if it exists.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2023/03/29/example.png" style="width: 241px; height: 161px;">

```bash
Input: grid = [[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]
Output: 7
Explanation: The fisher can start at cell `(1,3)` and collect 3 fish, then move to cell `(2,3)`and collect 4 fish.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2023/03/29/example2.png">

```bash
Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,1]]
Output: 1
Explanation: The fisher can start at cells (0,0) or (3,3) and collect a single fish.
```

**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 10`
- `0 <= grid[i][j] <= 10`

## Hints/Notes

- 2025/03/02 Q2
- dfs
- [0x3F's solution](https://leetcode.cn/problems/maximum-number-of-fish-in-a-grid/solutions/2250953/wang-ge-tu-dfs-mo-ban-pythonjavacgo-by-e-lykw/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int m, n;

    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    int curRes = dfs(grid, i, j);
                    res = max(res, curRes);
                }
            }
        }
        return res;
    }

    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return 0;
        }
        int res = grid[i][j];
        grid[i][j] = 0;
        return res + dfs(grid, i + 1, j) + dfs(grid, i - 1, j) + dfs(grid, i, j + 1) + dfs(grid, i, j - 1);
    }
};
```
