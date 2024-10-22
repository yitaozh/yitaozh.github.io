---
title: 3197. Find the Minimum Area to Cover All Ones II
categories: Leetcode
date: 2024-06-27 23:49:26
tags:
    - Array
    - Matrix
    - Enumeration
---

[3197. Find the Minimum Area to Cover All Ones II](https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-ii/description/)

## Description

You are given a 2D **binary** array `grid`. You need to find 3 **non-overlapping** rectangles having **non-zero** areas with horizontal and vertical sides such that all the 1's in `grid` lie inside these rectangles.

Return the **minimum** possible sum of the area of these rectangles.

**Note** that the rectangles are allowed to touch.

**Example 1:**

```bash
Input: grid = [[1,0,1],[1,1,1]]

Output: 5
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/05/14/example0rect21.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 280px; height: 198px; --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor: #242729;" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="">

- The 1's at `(0, 0)` and `(1, 0)` are covered by a rectangle of area 2.
- The 1's at `(0, 2)` and `(1, 2)` are covered by a rectangle of area 2.
- The 1 at `(1, 1)` is covered by a rectangle of area 1.

**Example 2:**

```bash
Input: grid = [[1,0,1,0],[0,1,0,1]]

Output: 5
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/05/14/example1rect2.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 356px; height: 198px; --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor: #242729;" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="">

- The 1's at `(0, 0)` and `(0, 2)` are covered by a rectangle of area 3.
- The 1 at `(1, 1)` is covered by a rectangle of area 1.
- The 1 at `(1, 3)` is covered by a rectangle of area 1.

**Constraints:**

- `1 <= grid.length, grid[i].length <= 30`
- `grid[i][j]` is either 0 or 1.
- The input is generated such that there are at least three 1's in `grid`.

## Hints/Notes

- brutal force
- Weekly Contest 403

## Solution

Language: **C++**

```C++
class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        vector<vector<int>> grid2 = rotate(grid);
        return min(minimum(grid), minimum(grid2));
    }

    vector<vector<int>> rotate(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(n, vector<int>(m, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[j][i] = grid[m - 1 - i][j];
            }
        }
        return res;
    }

    int minimum(vector<vector<int>>& grid) {
        int res = INT_MAX;
        int m = grid.size(), n = grid[0].size();
        if (m >= 3) {
            // 3 horizontal rectangle
            for (int i = 1; i < m; i++) {
                for (int j = i + 1; j < m; j++) {
                    int area1 = minimumArea(grid, 0, i, 0, n);
                    int area2 = minimumArea(grid, i, j, 0, n);
                    int area3 = minimumArea(grid, j, m, 0, n);
                    res = min(res, area1 + area2 + area3);
                }
            }
        }
        if (m >= 2 && n >= 2) {
            for (int i = 1; i < m; i++) {
                for (int j = 1; j < n; j++) {
                    // one rectangle above, and 2 below
                    int area1 = minimumArea(grid, 0, i, 0, n);
                    int area2 = minimumArea(grid, i, m, 0, j);
                    int area3 = minimumArea(grid, i, m, j, n);
                    res = min(res, area1 + area2 + area3);
                }

                for (int j = 1; j < n; j++) {
                    // one rectangle below, and 2 above
                    int area1 = minimumArea(grid, i, m, 0, n);
                    int area2 = minimumArea(grid, 0, i, 0, j);
                    int area3 = minimumArea(grid, 0, i, j, n);
                    res = min(res, area1 + area2 + area3);
                }
            }
        }
        return res;
    }

    int minimumArea(vector<vector<int>>& grid, int i1, int i2, int j1, int j2) {
        int minI = INT_MAX, minJ = INT_MAX, maxI = INT_MIN, maxJ = INT_MIN;
        for (int i = i1; i < i2; i++) {
            for (int j = j1; j < j2; j++) {
                if (grid[i][j] == 1) {
                    minI = min(minI, i);
                    minJ = min(minJ, j);
                    maxI = max(maxI, i);
                    maxJ = max(maxJ, j);
                }
            }
        }
        return minI == INT_MAX ? 0 : (maxI - minI + 1) * (maxJ - minJ + 1);
    }
};
```
