---
title: 3212. Count Submatrices With Equal Frequency of X and Y
categories: Leetcode
date: 2024-07-11 14:47:11
tags:
    - Array
    - Matrix
    - Prefix Sum
---

[3212. Count Submatrices With Equal Frequency of X and Y](https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y/description/)

## Description

Given a 2D character matrix `grid`, where `grid[i][j]` is either `'X'`, `'Y'`, or `'.'`, return the number of submatrices that contain:

- `grid[0][0]`
- an **equal**  frequency of `'X'` and `'Y'`.
- **at least**  one `'X'`.

**Example 1:**

```bash
Input: grid = [["X","Y","."],["Y",".","."]]

Output: 3
```

Explanation:

**<img alt="" src="https://assets.leetcode.com/uploads/2024/06/07/examplems.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 175px; height: 350px; --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor: #242729;" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="">**

**Example 2:**

```bash
Input: grid = [["X","X"],["X","Y"]]

Output: 0
```

Explanation:

No submatrix has an equal frequency of `'X'` and `'Y'`.

**Example 3:**

```bash
Input: grid = [[".","."],[".","."]]

Output: 0
```

Explanation:

No submatrix has at least one `'X'`.

**Constraints:**

- `1 <= grid.length, grid[i].length <= 1000`
- `grid[i][j]` is either `'X'`, `'Y'`, or `'.'`.

## Hints/Notes

- N/A

## Solution

Language: **C++**

```C++
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<vector<int>> preSum(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> count(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int val = 0;
                if (grid[i][j] == 'X') {
                    val = 1;
                } else if (grid[i][j] == 'Y') {
                    val = -1;
                }
                preSum[i + 1][j + 1] =
                    preSum[i][j + 1] + preSum[i + 1][j] - preSum[i][j] + val;
                count[i + 1][j + 1] =
                    count[i][j + 1] + count[i + 1][j] - count[i][j] + abs(val);
                if (preSum[i + 1][j + 1] == 0 && count[i + 1][j + 1] > 0) {
                    res++;
                }
            }
        }
        return res;
    }
};
```
