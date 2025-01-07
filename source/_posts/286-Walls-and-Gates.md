---
title: 286. Walls and Gates
categories: Leetcode
date: 2025-01-07 17:24:51
tags:
    - Array
    - Breadth-First Search
    - Matrix
---

[286. Walls and Gates](https://leetcode.com/problems/walls-and-gates/description/?envType=problem-list-v2&envId=plakya4j)

## Description

You are given an `m x n` grid `rooms`initialized with these three possible values.

- `-1`A wall or an obstacle.
- `0` A gate.
- `INF` Infinity means an empty room. We use the value `2^31 - 1 = 2147483647` to represent `INF` as you may assume that the distance to a gate is less than `2147483647`.

Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with `INF`.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/01/03/grid.jpg" style="width: 500px; height: 223px;">

```bash
Input: rooms = [[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
Output: [[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]]
```

**Example 2:**

```bash
Input: rooms = [[-1]]
Output: [[-1]]
```

**Constraints:**

- `m == rooms.length`
- `n == rooms[i].length`
- `1 <= m, n <= 250`
- `rooms[i][j]` is `-1`, `0`, or `2^31 - 1`.

## Hints/Notes

- 2025/01/05
- bfs
- premium

## Solution

Language: **C++**

```C++
class Solution {
public:
    static constexpr int DIRs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size(), n = rooms[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        int cur = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
                for (int j = 0; j < 4; j++) {
                    int dx = x + DIRs[j][0], dy = y + DIRs[j][1];
                    if (dx >= 0 && dx < m && dy >= 0 && dy < n && rooms[dx][dy] == INT_MAX) {
                        q.push({dx, dy});
                        rooms[dx][dy] = cur;
                    }
                }
            }
            cur++;
        }
    }
};
```
