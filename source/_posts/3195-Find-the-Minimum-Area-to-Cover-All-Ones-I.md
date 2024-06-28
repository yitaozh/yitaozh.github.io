---
title: 3195. Find the Minimum Area to Cover All Ones I
categories: Leetcode
date: 2024-06-27 23:44:45
tags:
    - Array
    - Matrix
---

[3195. Find the Minimum Area to Cover All Ones I](https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/description/)

## Description

You are given a 2D **binary**  array `grid`. Find a rectangle with horizontal and vertical sides with the **smallest** area, such that all the 1's in `grid` lie inside this rectangle.

Return the **minimum** possible area of the rectangle.

**Example 1:**

```bash
Input: grid = [[0,1,0],[1,0,1]]

Output: 6
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/05/08/examplerect0.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 279px; height: 198px; --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor: #242729;" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="">

The smallest rectangle has a height of 2 and a width of 3, so it has an area of `2 * 3 = 6`.

**Example 2:**

```bash
Input: grid = [[1,0],[0,0]]

Output: 1
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/05/08/examplerect1.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 204px; height: 201px; --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor: #242729;" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="">

The smallest rectangle has both height and width 1, so its area is `1 * 1 = 1`.

**Constraints:**

- `1 <= grid.length, grid[i].length <= 1000`
- `grid[i][j]` is either 0 or 1.
- The input is generated such that there is at least one 1 in `grid`.

## Hints/Notes

- Weekly Contest 403

## Solution

Language: **C++**

```C++
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minI = INT_MAX, minJ = INT_MAX, maxI = INT_MIN, maxJ = INT_MIN;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    minI = min(minI, i);
                    minJ = min(minJ, j);
                    maxI = max(maxI, i);
                    maxJ = max(maxJ, j);
                }
            }
        }
        return (maxI - minI + 1) * (maxJ - minJ + 1);
    }
};
```
