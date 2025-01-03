---
title: 200. Number of Islands
categories: Leetcode
date: 2025-01-02 23:52:34
tags:
    - Array
    - Depth-First Search
    - Breadth-First Search
    - Union Find
    - Matrix
---

[200. Number of Islands](https://leetcode.com/problems/number-of-islands/description/?envType=problem-list-v2&envId=plakya4j)

## Description

Given an `m x n` 2D binary grid `grid` which represents a map of `'1'`s (land) and `'0'`s (water), return the number of islands.

An **island**  is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

**Example 1:**

```bash
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
```

**Example 2:**

```bash
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
```

**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 300`
- `grid[i][j]` is `'0'` or `'1'`.

## Hints/Notes

- 2025/01/01
- bfs
- No solution from 0x3F

## Solution

Language: **C++**

```C++
class Solution {
public:
    static constexpr int DIRs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = '0';
                    while (!q.empty()) {
                        auto& [x, y] = q.front();
                        for (int i = 0; i < 4; i++) {
                            int dx = x + DIRs[i][0], dy = y + DIRs[i][1];
                            if (dx >= 0 && dx < m && dy >= 0 && dy < n && grid[dx][dy] == '1') {
                                grid[dx][dy] = '0';
                                q.push({dx, dy});
                            }
                        }
                        q.pop();
                    }
                    res++;
                }
            }
        }
        return res;
    }
};
```
