---
title: 463. Island Perimeter
categories: Leetcode
date: 2025-03-29 13:20:03
tags:
    - Array
    - Depth-First Search
    - Breadth-First Search
    - Matrix
---

[463. Island Perimeter](https://leetcode.com/problems/island-perimeter/description/?envType=company&envId=oracle&favoriteSlug=oracle-six-months)

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

- 2025/03/22 Q3
- bfs or easy counting
- [Leetcode solution](https://leetcode.com/problems/island-perimeter/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int res, m, n;
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int islandPerimeter(vector<vector<int>>& grid) {
        res = 0; m = grid.size(); n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(i, j, grid);
                }
            }
        }
        return res;
    }

    void dfs(int x, int y, vector<vector<int>>& grid) {
        grid[x][y] = 2;
        for (int k = 0; k < 4; k++) {
            int dx = x + dirs[k][0], dy = y + dirs[k][1];
            if (dx >= 0 && dx < m && dy >= 0 && dy < n) {
                if (grid[dx][dy] == 1) {
                    dfs(dx, dy, grid);
                } else if (grid[dx][dy] == 0) {
                    res++;
                }
            } else {
                res++;
            }
        }
    }
};
```
