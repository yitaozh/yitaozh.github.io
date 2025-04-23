---
title: 1293. Shortest Path in a Grid with Obstacles Elimination
categories: Leetcode
date: 2025-03-18 21:41:47
tags:
    - Array
    - Breadth-First Search
    - Matrix
---

[1293. Shortest Path in a Grid with Obstacles Elimination](https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/description/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Description

You are given an `m x n` integer matrix `grid` where each cell is either `0` (empty) or `1` (obstacle). You can move up, down, left, or right from and to an empty cell in **one step** .

Return the minimum number of **steps**  to walk from the upper left corner `(0, 0)` to the lower right corner `(m - 1, n - 1)` given that you can eliminate **at most**  `k` obstacles. If it is not possible to find such walk return `-1`.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/09/30/short1-grid.jpg" style="width: 244px; height: 405px;">

```bash
Input: grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1
Output: 6
Explanation:
The shortest path without eliminating any obstacle is 10.
The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> **(3,2)**  -> (4,2).
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/09/30/short2-grid.jpg" style="width: 244px; height: 245px;">

```bash
Input: grid = [[0,1,1],[1,1,1],[1,0,0]], k = 1
Output: -1
Explanation: We need to eliminate at least two obstacles to find such a walk.
```

**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 40`
- `1 <= k <= m * n`
- `grid[i][j]` is either `0` **or**  `1`.
- `grid[0][0] == grid[m - 1][n - 1] == 0`

## Hints/Notes

- 2025/02/18 Q3
- bfs
- [Leetcode solution](https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/editorial/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(k + 1, false)));
        queue<vector<int>> q;
        q.push({0, 0, k});
        visited[0][0][k] = true;
        int step = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto tri = q.front();
                q.pop();
                int x = tri[0], y = tri[1], remain = tri[2];
                if (x == m - 1 && y == n - 1) {
                    return step;
                }
                for (int k = 0; k < 4; k++) {
                    int dx = x + dirs[k][0], dy = y + dirs[k][1];
                    if (dx >= 0 && dx < m && dy >= 0 && dy < n) {
                        if (grid[dx][dy] == 0 && !visited[dx][dy][remain]) {
                            visited[dx][dy][remain] = true;
                            q.push({dx, dy, remain});
                        }
                        if (grid[dx][dy] == 1 && remain > 0 && !visited[dx][dy][remain - 1]) {
                            visited[dx][dy][remain - 1] = true;
                            q.push({dx, dy, remain - 1});
                        }
                    }
                }
            }
            step++;
        }
        return -1;
    }
};
```

A* algorithm:

```C++
class Solution {
public:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(k + 1, false)));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({m + n - 1, 0, 0, k, 0});
        visited[0][0][k] = true;
        while (!pq.empty()) {
            int size = pq.size();
            for (int i = 0; i < size; i++) {
                auto v = pq.top();
                pq.pop();
                int x = v[1], y = v[2], remain = v[3], step = v[4];
                if (x == m - 1 && y == n - 1) {
                    return step;
                }
                for (int k = 0; k < 4; k++) {
                    int dx = x + dirs[k][0], dy = y + dirs[k][1];
                    if (dx >= 0 && dx < m && dy >= 0 && dy < n) {
                        if (grid[dx][dy] == 0 && !visited[dx][dy][remain]) {
                            visited[dx][dy][remain] = true;
                            pq.push({abs(dx - m + 1) + abs(dy - n + 1) + step + 1, dx, dy, remain, step + 1});
                        }
                        if (grid[dx][dy] == 1 && remain > 0 && !visited[dx][dy][remain - 1]) {
                            visited[dx][dy][remain - 1] = true;
                            pq.push({abs(dx - m + 1) + abs(dy - n + 1) + step + 1, dx, dy, remain - 1, step + 1});
                        }
                    }
                }
            }
        }
        return -1;
    }
};
```
