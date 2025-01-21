---
title: 1091. Shortest Path in Binary Matrix
categories: Leetcode
date: 2025-01-21 02:17:03
tags:
    - Array
    - Breadth-First Search
    - Matrix
---

[1091. Shortest Path in Binary Matrix](https://leetcode.com/problems/shortest-path-in-binary-matrix/description/)

## Description

Given an `n x n` binary matrix `grid`, return the length of the shortest **clear path**  in the matrix. If there is no clear path, return `-1`.

A **clear path**  in a binary matrix is a path from the **top-left**  cell (i.e., `(0, 0)`) to the **bottom-right**  cell (i.e., `(n - 1, n - 1)`) such that:

- All the visited cells of the path are `0`.
- All the adjacent cells of the path are **8-directionally**  connected (i.e., they are different and they share an edge or a corner).

The **length of a clear path**  is the number of visited cells of this path.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/02/18/example1_1.png" style="width: 500px; height: 234px;">

```bash
Input: grid = [[0,1],[1,0]]
Output: 2
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/02/18/example2_1.png" style="height: 216px; width: 500px;">

```bash
Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4
```

**Example 3:**

```bash
Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1
```

**Constraints:**

- `n == grid.length`
- `n == grid[i].length`
- `1 <= n <= 100`
- `grid[i][j] is 0 or 1`

## Hints/Notes

- 2025/01/19
- bfs
- No solution from 0x3F

## Solution

Language: **C++**

```C++
class Solution {
public:
    static constexpr int DIRs[8][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0},
                                       {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) {
            return -1;
        }
        int n = grid.size();
        queue<pair<int, int>> q;
        int cur = 1;
        q.push({0, 0});
        grid[0][0] = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
                if (x == n - 1 && y == n - 1) {
                    return cur;
                }
                for (int j = 0; j < 8; j++) {
                    int dx = x + DIRs[j][0], dy = y + DIRs[j][1];
                    if (dx >= 0 && dx < n && dy >= 0 && dy < n && grid[dx][dy] == 0) {
                        q.push({dx, dy});
                        grid[dx][dy] = 1;
                    }
                }
            }
            cur++;
        }
        return -1;
    }
};
```
