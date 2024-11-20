---
title: 3342. Find Minimum Time to Reach Last Room II
categories: Leetcode
date: 2024-11-20 15:13:53
tags:
    - Array
    - Graph
    - Heap (Priority Queue)
    - Matrix
    - Shortest Path
---

[3342. Find Minimum Time to Reach Last Room II](https://leetcode.com/problems/find-minimum-time-to-reach-last-room-ii/description/)

## Description

There is a dungeon with `n x m` rooms arranged as a grid.

You are given a 2D array `moveTime` of size `n x m`, where `moveTime[i][j]` represents the **minimum**  time in seconds when you can **start moving**  to that room. You start from the room `(0, 0)` at time `t = 0` and can move to an **adjacent**  room. Moving between **adjacent**  rooms takes one second for one move and two seconds for the next, **alternating**  between the two.

Return the **minimum**  time to reach the room `(n - 1, m - 1)`.

Two rooms are **adjacent**  if they share a common wall, either horizontally or vertically.

**Example 1:**

```bash
Input: moveTime = [[0,4],[4,4]]

Output: 7
```

Explanation:

The minimum time required is 7 seconds.

- At time `t == 4`, move from room `(0, 0)` to room `(1, 0)` in one second.
- At time `t == 5`, move from room `(1, 0)` to room `(1, 1)` in two seconds.

**Example 2:**

```bash
Input: moveTime = [[0,0,0,0],[0,0,0,0]]

Output: 6
```

Explanation:

The minimum time required is 6 seconds.

- At time `t == 0`, move from room `(0, 0)` to room `(1, 0)` in one second.
- At time `t == 1`, move from room `(1, 0)` to room `(1, 1)` in two seconds.
- At time `t == 3`, move from room `(1, 1)` to room `(1, 2)` in one second.
- At time `t == 4`, move from room `(1, 2)` to room `(1, 3)` in two seconds.

**Example 3:**

```bash
Input: moveTime = [[0,1],[1,2]]

Output: 4
```

**Constraints:**

- `2 <= n == moveTime.length <= 750`
- `2 <= m == moveTime[i].length <= 750`
- `0 <= moveTime[i][j] <= 10^9`

## Hints/Notes

- 2024/11/08
- Dijkstra
- [0x3F's solution](https://leetcode.cn/problems/find-minimum-time-to-reach-last-room-ii/solution/dijkstra-zui-duan-lu-pythonjavacgo-by-en-alms/)
- Weekly Contest 422

## Solution

Language: **C++**

```C++
class Solution {
public:
    array<array<int, 2>, 4> DIRs = {{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};
    vector<vector<int>> dp;

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        dp.resize(n, vector<int>(m, INT_MAX / 2));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;
        pq.push({0, 0, 0, 1});
        while (!pq.empty()) {
            auto v = pq.top();
            pq.pop();
            int t = v[0], x = v[1], y = v[2], move = v[3];
            if (dp[x][y] < t) {
                continue;
            }
            if (x == n - 1 && y == m - 1) {
                return t;
            }
            for (auto dir : DIRs) {
                int x1 = x + dir[0], y1 = y + dir[1];
                if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m) {
                    int t1 = max(moveTime[x1][y1], t) + (2 - move % 2);
                    if (t1 < dp[x1][y1]) {
                        dp[x1][y1] = t1;
                        pq.push({t1, x1, y1, (move + 1) % 2});
                    }
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};
```
