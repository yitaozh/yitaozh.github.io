---
title: 778. Swim in Rising Water
categories: Leetcode
date: 2025-01-07 17:20:28
tags:
    - Array
    - Binary Search
    - Depth-First Search
    - Breadth-First Search
    - Union Find
    - Heap (Priority Queue)
    - Matrix
---

[778. Swim in Rising Water](https://leetcode.com/problems/swim-in-rising-water/description/?envType=problem-list-v2&envId=plakya4j)

## Description

You are given an `n x n` integer matrix `grid` where each value `grid[i][j]` represents the elevation at that point `(i, j)`.

The rain starts to fall. At time `t`, the depth of the water everywhere is `t`. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most `t`. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.

Return the least time until you can reach the bottom right square `(n - 1, n - 1)` if you start at the top left square `(0, 0)`.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/06/29/swim1-grid.jpg" style="width: 164px; height: 165px;">

```bash
Input: grid = [[0,2],[1,3]]
Output: 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
You cannot reach point (1, 1) until time 3.
When the depth of water is 3, we can swim anywhere inside the grid.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/06/29/swim2-grid-1.jpg" style="width: 404px; height: 405px;">

```bash
Input: grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation: The final route is shown.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
```

**Constraints:**

- `n == grid.length`
- `n == grid[i].length`
- `1 <= n <= 50`
- `0 <= grid[i][j] <n^2`
- Each value `grid[i][j]` is **unique** .

## Hints/Notes

- 2025/01/04
- Dijkstra's algorithm
- No solution from 0x3F

## Solution

Language: **C++**

```C++
class Solution {
public:
    static constexpr int DIRs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int m = grid.size(), n = grid[0].size();
        pq.push({grid[0][0], 0, 0});
        grid[0][0] = -1;
        int time = 0;
        while (!pq.empty()) {
            auto tri = pq.top();
            pq.pop();
            int elevation = tri[0], x = tri[1], y = tri[2];
            time = max(elevation, time);
            if (x == m - 1 && y == n - 1) {
                return time;
            }
            for (int i = 0; i < 4; i++) {
                int dx = x + DIRs[i][0], dy = y + DIRs[i][1];
                if (dx >= 0 && dx < m && dy >= 0 && dy < n && grid[dx][dy] >= 0) {
                    pq.push({grid[dx][dy], dx, dy});
                    grid[dx][dy] = -1;
                }
            }
        }
        return -1;
    }
};
```
