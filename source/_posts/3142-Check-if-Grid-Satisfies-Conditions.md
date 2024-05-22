---
title: 3142. Check if Grid Satisfies Conditions
categories: Leetcode
date: 2024-05-22 09:59:31
tags:
    - Array
    - Matrix
---

[3142. Check if Grid Satisfies Conditions](https://leetcode.com/problems/check-if-grid-satisfies-conditions/description/)

You are given a 2D matrix `grid` of size `m x n`. You need to check if each cell `grid[i][j]` is:

- Equal to the cell below it, i.e. `grid[i][j] == grid[i + 1][j]` (if it exists).
- Different from the cell to its right, i.e. `grid[i][j] != grid[i][j + 1]` (if it exists).

Return `true` if **all**  the cells satisfy these conditions, otherwise, return `false`.

**Example 1:**

```bash
Input: grid = [[1,0,2],[1,0,2]]

Output: true
```

Explanation:

**<img alt="" src="https://assets.leetcode.com/uploads/2024/04/15/examplechanged.png" style="width: 254px; height: 186px; padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor: #242729;" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="">**

All the cells in the grid satisfy the conditions.

**Example 2:**

```bash
Input: grid = [[1,1,1],[0,0,0]]

Output: false
```

Explanation:

**<img alt="" src="https://assets.leetcode.com/uploads/2024/03/27/example21.png" style="width: 254px; height: 186px; padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor: #242729;" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="">**

All cells in the first row are equal.

**Example 3:**

```bash
Input: grid = [[1],[2],[3]]

Output: false
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/03/31/changed.png" style="width: 86px; height: 277px; padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor: #242729;" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="">

Cells in the first column have different values.

**Constraints:**

- `1 <= n, m <= 10`
- `0 <= grid[i][j] <= 9`

## Hints/Notes

- N/A

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m - 1; i++) {
                if (grid[i][j] != grid[i + 1][j]) {
                    return false;
                }
            }
            if (j > 0 && grid[0][j] == grid[0][j - 1]) {
                return false;
            }
        }
        return true;
    }
};
```
