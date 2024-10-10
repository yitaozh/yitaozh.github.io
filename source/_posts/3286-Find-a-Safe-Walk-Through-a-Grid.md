---
title: 3286. Find a Safe Walk Through a Grid
categories: Leetcode
date: 2024-10-10 00:08:44
tags:
    - Array
    - Breadth-First Search
    - Graph
    - Heap (Priority Queue)
    - Matrix
    - Shortest Path
---

[3286. Find a Safe Walk Through a Grid](https://leetcode.com/problems/find-a-safe-walk-through-a-grid/description/)

## Description

You are given an `m x n` binary matrix `grid` and an integer `health`.

You start on the upper-left corner `(0, 0)` and would like to get to the lower-right corner `(m - 1, n - 1)`.

You can move up, down, left, or right from one cell to another adjacent cell as long as your health remains **positive** .

Cells `(i, j)` with `grid[i][j] = 1` are considered **unsafe**  and reduce your health by 1.

Return `true` if you can reach the final cell with a health value of 1 or more, and `false` otherwise.

**Example 1:**

```bash
Input: grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]], health = 1

Output: true
```

Explanation:

The final cell can be reached safely by walking along the gray cells below.

<img alt="" src="https://assets.leetcode.com/uploads/2024/08/04/3868_examples_1drawio.png" style="width: 301px; height: 121px;">

**Example 2:**

```bash
Input: grid = [[0,1,1,0,0,0],[1,0,1,0,0,0],[0,1,1,1,0,1],[0,0,1,0,1,0]], health = 3

Output: false
```

Explanation:

A minimum of 4 health points is needed to reach the final cell safely.

<img alt="" src="https://assets.leetcode.com/uploads/2024/08/04/3868_examples_2drawio.png" style="width: 361px; height: 161px;">

**Example 3:**

```bash
Input: grid = [[1,1,1],[1,0,1],[1,1,1]], health = 5

Output: true
```

Explanation:

The final cell can be reached safely by walking along the gray cells below.

<img alt="" src="https://assets.leetcode.com/uploads/2024/08/04/3868_examples_3drawio.png" style="width: 181px; height: 121px;">

Any path that does not go through the cell `(1, 1)` is unsafe since your health will drop to 0 when reaching the final cell.

**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 50`
- `2 <= m * n`
- `1 <= health <= m + n`
- `grid[i][j]` is either 0 or 1.

## Hints/Notes

- BFS
- Biweekly Contest 139

## Solution

Language: **C++**

```C++
class Solution {
public:
    array<array<int, 2>, 4> DIRs = {{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};
    vector<vector<bool>> visited;

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        visited.resize(m, vector<bool>(n, false));
        deque<vector<int>> q;
        q.push_back({0, 0, health});
        visited[0][0] = true;
        while (!q.empty()) {
            auto p = q.front();
            q.pop_front();
            int x = p[0], y = p[1], h = p[2] - grid[x][y];
            if (x == m - 1 && y == n - 1) {
                return h > 0;
            }
            for (auto d : DIRs) {
                int x1 = x + d[0];
                int y1 = y + d[1];
                if (x1 >= 0 && x1 < m && y1 >= 0 && y1 < n && !visited[x1][y1]) {
                    visited[x1][y1] = true;
                    if (grid[x1][y1]) {
                        q.push_back({x1, y1, h});
                    } else {
                        q.push_front({x1, y1, h});
                    }
                }
            }
        }
        return false;
    }
};
```
