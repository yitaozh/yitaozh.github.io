---
title: 994. Rotting Oranges
categories: Leetcode
date: 2024-12-19 01:07:01
tags:
    - Array
    - Breadth-First Search
    - Matrix
---

[994. Rotting Oranges](https://leetcode.com/problems/rotting-oranges/description/?envType=problem-list-v2&envId=plakya4j)

## Description

You are given an `m x n` `grid` where each cell can have one of three values:

- `0` representing an empty cell,
- `1` representing a fresh orange, or
- `2` representing a rotten orange.

Every minute, any fresh orange that is **4-directionally adjacent**  to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return `-1`.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2019/02/16/oranges.png" style="width: 650px; height: 137px;">

```bash
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
```

**Example 2:**

```bash
Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
```

**Example 3:**

```bash
Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
```

**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 10`
- `grid[i][j]` is `0`, `1`, or `2`.

## Hints/Notes

- 2024/12/18
- bfs
- [0x3F's solution](https://leetcode.cn/problems/rotting-oranges/solutions/2773461/duo-yuan-bfsfu-ti-dan-pythonjavacgojsrus-yfmh/)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        array<array<int, 2>, 4> DIRs = {{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};
        int m = grid.size(), n = grid[0].size(), left = m * n;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.emplace(i, j);
                    left--;
                }
                if (grid[i][j] == 0) {
                    left--;
                }
            }
        }
        if (!left) {
            return 0;
        }
        int cur = 0;
        while (!q.empty() && left) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto p = q.front();
                q.pop();
                int x = p.first, y = p.second;
                for (auto DIR : DIRs) {
                    int dx = x + DIR[0], dy = y + DIR[1];
                    if (dx >= 0 && dy >= 0 && dx < m && dy < n && grid[dx][dy] == 1) {
                        grid[dx][dy] = 2;
                        q.emplace(dx, dy);
                        left--;
                    }
                }
            }
            cur++;
        }
        return left == 0 ? cur : -1;
    }
};
```
