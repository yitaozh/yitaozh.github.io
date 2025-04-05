---
title: 694. Number of Distinct Islands
categories: Leetcode
date: 2025-04-05 11:40:04
tags:
    - Hash Table
    - Depth-First Search
    - Breadth-First Search
    - Union Find
    - Hash Function
---

[694. Number of Distinct Islands](https://leetcode.com/problems/number-of-distinct-islands/description/?envType=company&envId=oracle&favoriteSlug=oracle-six-months)

## Description

You are given an `m x n` binary matrix `grid`. An island is a group of `1`'s (representing land) connected **4-directionally**  (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.

Return the number of <b>distinct</b> islands.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/05/01/distinctisland1-1-grid.jpg" style="width: 413px; height: 334px;">

```bash
Input: grid = [[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]
Output: 1
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/05/01/distinctisland1-2-grid.jpg" style="width: 413px; height: 334px;">

```bash
Input: grid = [[1,1,0,1,1],[1,0,0,0,0],[0,0,0,0,1],[1,1,0,1,1]]
Output: 3
```

**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 50`
- `grid[i][j]` is either `0` or `1`.

## Hints/Notes

- 2025/03/31 Q2
- dfs/bfs + encoding
- [Leetcode solution](https://leetcode.com/problems/number-of-distinct-islands/editorial)

## Solution

Language: **C++**

```C++
class Solution {
public:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        unordered_set<string> islands;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    string island;
                    dfs(grid, i, j, i, j, island);
                    islands.insert(island);
                }
            }
        }
        return islands.size();
    }

    void dfs(vector<vector<int>>& grid, int x, int y, int i, int j, string& island) {
        for (int k = 0; k < 4; k++) {
            int dx = x + dirs[k][0], dy = y + dirs[k][1];
            if (dx >= 0 && dx < grid.size() && dy >= 0 && dy < grid[0].size() && grid[dx][dy]) {
                island += to_string(i - dx) + to_string(j - dy);
                grid[dx][dy] = 0;
                dfs(grid, dx, dy, i, j, island);
            }
        }
    }
};
```
