---
title: 934. Shortest Bridge
categories: Leetcode
date: 2025-01-30 22:59:44
tags:
    - Array
    - Depth-First Search
    - Breadth-First Search
    - Matrix
---

[934. Shortest Bridge](https://leetcode.com/problems/shortest-bridge/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

You are given an `n x n` binary matrix `grid` where `1` represents land and `0` represents water.

An **island**  is a 4-directionally connected group of `1`'s not connected to any other `1`'s. There are **exactly two islands**  in `grid`.

You may change `0`'s to `1`'s to connect the two islands to form **one island** .

Return the smallest number of `0`'s you must flip to connect the two islands.

**Example 1:**

```bash
Input: grid = [[0,1],[1,0]]
Output: 1
```

**Example 2:**

```bash
Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2
```

**Example 3:**

```bash
Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1
```

**Constraints:**

- `n == grid.length == grid[i].length`
- `2 <= n <= 100`
- `grid[i][j]` is either `0` or `1`.
- There are exactly two islands in `grid`.

## Hints/Notes

- 2025/01/30
- dfs + bfs
- [Leetcode solution](https://leetcode.com/problems/shortest-bridge/editorial/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    static constexpr int DIRs[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

    int shortestBridge(vector<vector<int>>& grid) {
        // find one island, then bfs
        queue<pair<int, int>> islandOne;
        int m = grid.size(), n = grid[0].size();
        bool not_marked = true;
        for (int i = 0; i < m && not_marked; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    queue<pair<int, int>> q;
                    q.emplace(i, j);
                    islandOne.emplace(i, j);
                    grid[i][j] = -1;
                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int dx = x + DIRs[k][0], dy = y + DIRs[k][1];
                            if (dx >= 0 && dx < m && dy >= 0 && dy < n && grid[dx][dy] == 1) {
                                grid[dx][dy] = -1;
                                q.emplace(dx, dy);
                                islandOne.emplace(dx, dy);
                            }
                        }
                    }
                    not_marked = false;
                    break;
                }
            }
        }
        int step = 0;
        while (!islandOne.empty()) {
            int size = islandOne.size();
            for (int i = 0; i < size; i++) {
                auto [x, y] = islandOne.front();
                islandOne.pop();
                for (int k = 0; k < 4; k++) {
                    int dx = x + DIRs[k][0], dy = y + DIRs[k][1];
                    if (dx >= 0 && dx < m && dy >= 0 && dy < n) {
                        if (grid[dx][dy] == 1) {
                            return step;
                        } else if (grid[dx][dy] == 0) {
                            grid[dx][dy] = -1;
                            islandOne.emplace(dx, dy);
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
