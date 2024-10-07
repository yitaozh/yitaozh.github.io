---
title: 3276. Select Cells in Grid With Maximum Score
categories: Leetcode
date: 2024-10-06 21:53:28
tags:
    - Array
    - Dynamic Programming
    - Bit Manipulation
    - Matrix
    - Bitmask
---

[3276. Select Cells in Grid With Maximum Score](https://leetcode.com/problems/select-cells-in-grid-with-maximum-score/description/)

## Description

You are given a 2D matrix `grid` consisting of positive integers.

You have to select one or more cells from the matrix such that the following conditions are satisfied:

- No two selected cells are in the **same**  row of the matrix.
- The values in the set of selected cells are **unique** .

Your score will be the **sum**  of the values of the selected cells.

Return the **maximum**  score you can achieve.

**Example 1:**

```bash
Input: grid = [[1,2,3],[4,3,2],[1,1,1]]

Output: 8
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/07/29/grid1drawio.png">

We can select the cells with values 1, 3, and 4 that are colored above.

**Example 2:**

```bash
Input: grid = [[8,7,6],[8,3,2]]

Output: 15
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/07/29/grid8_8drawio.png" style="width: 170px; height: 114px;">

We can select the cells with values 7 and 8 that are colored above.

**Constraints:**

- `1 <= grid.length, grid[i].length <= 10`
- `1 <= grid[i][j] <= 100`

## Hints/Notes

- state compression dp
- Weekly Contest 413

## Solution

Language: **C++**

```C++
class Solution {
public:
    // the meaning of dp[i][j]:
    //  with maxVal of i, and we can choose from the rows
    //  not marked by j, what's the maximum value we can get
    vector<vector<int>> dp;
    vector<unordered_set<int>> valToRow;

    int maxScore(vector<vector<int>>& grid) {
        int maxVal = 0, m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                maxVal = max(maxVal, grid[i][j]);
            }
        }
        dp.resize(maxVal + 1, vector<int>(2 << m, -1));
        // valToRow is to avoid duplication and simplify the iteration
        valToRow.resize(maxVal + 1);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                valToRow[grid[i][j]].insert(i);
            }
        }
        int res = dfs(maxVal, 0);
        return res;
    }

    int dfs(int maxVal, int k) {
        if (maxVal <= 0) {
            return 0;
        }
        if (dp[maxVal][k] != -1) {
            return dp[maxVal][k];
        }
        int res = dfs(maxVal - 1, k);
        for (int row : valToRow[maxVal]) {
            if (!(k >> row & 1)) {
                res = max(res, dfs(maxVal - 1, k | 1 << row) + maxVal);
            }
        }
        dp[maxVal][k] = res;
        return res;
    }
};
```
