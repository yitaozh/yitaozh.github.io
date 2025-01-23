---
title: 317. Shortest Distance from All Buildings
categories: Leetcode
date: 2025-01-22 23:49:32
tags:
    - Array
    - Breadth-First Search
    - Matrix
---

[317. Shortest Distance from All Buildings](https://leetcode.com/problems/shortest-distance-from-all-buildings/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

You are given an `m x n` grid `grid` of values `0`, `1`, or `2`, where:

- each `0` marks **an empty land**  that you can pass by freely,
- each `1` marks **a building**  that you cannot pass through, and
- each `2` marks **an obstacle**  that you cannot pass through.

You want to build a house on an empty land that reaches all buildings in the **shortest total travel**  distance. You can only move up, down, left, and right.

Return the **shortest travel distance**  for such a house. If it is not possible to build such a house according to the above rules, return `-1`.

The **total travel distance**  is the sum of the distances between the houses of the friends and the meeting point.

The distance is calculated using <a href="http://en.wikipedia.org/wiki/Taxicab_geometry" target="_blank">Manhattan Distance</a>, where `distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|`.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/03/14/buildings-grid.jpg" style="width: 413px; height: 253px;">

```bash
Input: grid = [[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]
Output: 7
Explanation: Given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2).
The point (1,2) is an ideal empty land to build a house, as the total travel distance of 3+3+1=7 is minimal.
So return 7.
```

**Example 2:**

```bash
Input: grid = [[1,0]]
Output: 1
```

**Example 3:**

```bash
Input: grid = [[1]]
Output: -1
```

**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 50`
- `grid[i][j]` is either `0`, `1`, or `2`.
- There will be **at least one**  building in the `grid`.

## Hints/Notes

- 2025/01/22
- bfs
- [Leetcode solution](https://leetcode.com/problems/shortest-distance-from-all-buildings/editorial/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    static constexpr int DIRs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = INT_MAX, building = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    building++;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    continue;
                }
                vector<vector<bool>> visited(m, vector<bool>(n, false));
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;
                int reached = 0, step = 1, cur = 0;
                while (!q.empty() && reached < building) {
                    int size = q.size();
                    for (int i = 0; i < size; i++) {
                        auto [x, y] = q.front();
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int dx = x + DIRs[k][0], dy = y + DIRs[k][1];
                            if (dx >= 0 && dx < m && dy >= 0 && dy < n && !visited[dx][dy]) {
                                visited[dx][dy] = true;
                                if (grid[dx][dy] == 1) {
                                    reached++;
                                    cur += step;
                                } else if (grid[dx][dy] == 0) {
                                    q.push({dx, dy});
                                }
                            }
                        }
                    }
                    step++;
                }
                cur = reached == building ? cur : INT_MAX;
                res = min(res, cur);
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
```
