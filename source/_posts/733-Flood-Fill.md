---
title: 733. Flood Fill
categories: Leetcode
date: 2025-04-08 14:09:27
tags:
    - Array
    - Depth-First Search
    - Breadth-First Search
    - Matrix
---

[733. Flood Fill](https://leetcode.com/problems/flood-fill/description/)

## Description

You are given `row x col` `grid` representing a map where `grid[i][j] = 1` represents land and `grid[i][j] = 0` represents water.

Grid cells are connected **horizontally/vertically**  (not diagonally). The `grid` is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

**Example 1:**

<img src="https://assets.leetcode.com/uploads/2018/10/12/island.png" style="width: 221px; height: 213px;">

```bash
Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.
```

**Example 2:**

```bash
Input: grid = [[1]]
Output: 4
```

**Example 3:**

```bash
Input: grid = [[1,0]]
Output: 4
```

**Constraints:**

- `row == grid.length`
- `col == grid[i].length`
- `1 <= row, col <= 100`
- `grid[i][j]` is `0` or `1`.
- There is exactly one island in `grid`.

## Hints/Notes

- 2025/04/07 Q2
- dfs
- [Leetcode solution](https://leetcode.com/problems/flood-fill/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        dfs(image, sr, sc, originalColor, color);
        return image;
    }

    void dfs(vector<vector<int>>& image, int x, int y, int color, int newColor) {
        int m = image.size(), n = image[0].size();
        if (x < 0 || x >= m || y < 0 || y >= n || image[x][y] == newColor || image[x][y] != color) {
            return;
        }
        image[x][y] = newColor;
        dfs(image, x + 1, y, color, newColor);
        dfs(image, x - 1, y, color, newColor);
        dfs(image, x, y + 1, color, newColor);
        dfs(image, x, y - 1, color, newColor);
    }
};
```
