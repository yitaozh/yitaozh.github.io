---
title: 695. Max Area of Island
categories: Leetcode
date: 2025-01-02 23:31:02
tags:
    - Array
    - Depth-First Search
    - Breadth-First Search
    - Union Find
    - Matrix
---

[695. Max Area of Island](https://leetcode.com/problems/max-area-of-island/description/?envType=problem-list-v2&envId=plakya4j)

## Description

You are given an `m x n` binary matrix `grid`. An island is a group of `1`'s (representing land) connected **4-directionally**  (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The **area**  of an island is the number of cells with a value `1` in the island.

Return the maximum **area**  of an island in `grid`. If there is no island, return `0`.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/05/01/maxarea1-grid.jpg" style="width: 500px; height: 310px;">

```bash
Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.
```

**Example 2:**

```bash
Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0
```

**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 50`
- `grid[i][j]` is either `0` or `1`.

## Hints/Notes

- 2024/12/31
- dfs
- No solution from 0x3F

## Solution

Language: **C++**

```C++
class Solution {
public:
    static constexpr int DIRs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int cur = 0;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = 0;
                    while (!q.empty()) {
                        auto& [x, y] = q.front();
                        cur++;
                        for (int i = 0; i < 4; i++) {
                            int dx = x + DIRs[i][0], dy = y + DIRs[i][1];
                            if (dx >= 0 && dx < m && dy >= 0 && dy < n && grid[dx][dy] == 1) {
                                grid[dx][dy] = 0;
                                q.push({dx, dy});
                            }
                        }
                        q.pop();
                    }
                    res = max(res, cur);
                }
            }
        }
        return res;
    }
};
```
