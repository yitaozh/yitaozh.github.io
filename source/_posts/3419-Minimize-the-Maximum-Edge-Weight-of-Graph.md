---
title: 3419. Minimize the Maximum Edge Weight of Graph
categories: Leetcode
date: 2025-01-17 00:13:29
tags:
    - Binary Search
    - Depth-First Search
    - Breadth-First Search
    - Graph
    - Shortest Path
---

[3419. Minimize the Maximum Edge Weight of Graph](https://leetcode.com/problems/minimize-the-maximum-edge-weight-of-graph/)

## Description

You are given an `m x n` grid. A robot starts at the top-left corner of the grid `(0, 0)` and wants to reach the bottom-right corner `(m - 1, n - 1)`. The robot can move either right or down at any point in time.

The grid contains a value `coins[i][j]` in each cell:

- If `coins[i][j] >= 0`, the robot gains that many coins.
- If `coins[i][j] < 0`, the robot encounters a robber, and the robber steals the **absolute**  value of `coins[i][j]` coins.

The robot has a special ability to **neutralize robbers**  in at most **2 cells**  on its path, preventing them from stealing coins in those cells.

**Note:**  The robot's total coins can be negative.

Return the **maximum**  profit the robot can gain on the route.

**Example 1:**

```bash
Input: coins = [[0,1,-1],[1,-2,3],[2,-3,4]]

Output: 8
```

Explanation:

An optimal path for maximum coins is:

- Start at `(0, 0)` with `0` coins (total coins = `0`).
- Move to `(0, 1)`, gaining `1` coin (total coins = `0 + 1 = 1`).
- Move to `(1, 1)`, where there's a robber stealing `2` coins. The robot uses one neutralization here, avoiding the robbery (total coins = `1`).
- Move to `(1, 2)`, gaining `3` coins (total coins = `1 + 3 = 4`).
- Move to `(2, 2)`, gaining `4` coins (total coins = `4 + 4 = 8`).

**Example 2:**

```bash
Input: coins = [[10,10,10],[10,10,10]]

Output: 40
```

Explanation:

An optimal path for maximum coins is:

- Start at `(0, 0)` with `10` coins (total coins = `10`).
- Move to `(0, 1)`, gaining `10` coins (total coins = `10 + 10 = 20`).
- Move to `(0, 2)`, gaining another `10` coins (total coins = `20 + 10 = 30`).
- Move to `(1, 2)`, gaining the final `10` coins (total coins = `30 + 10 = 40`).

**Constraints:**

- `m == coins.length`
- `n == coins[i].length`
- `1 <= m, n <= 500`
- `-1000 <= coins[i][j] <= 1000`

## Hints/Notes

- 2025/01/16
- Dijkstra's algorithm
- [0x3F's solution](https://leetcode.cn/problems/minimize-the-maximum-edge-weight-of-graph/solutions/3045060/liang-chong-fang-fa-er-fen-da-an-dijkstr-eb7d/)(checked)
- Weekly Contest 432

## Solution

Language: **C++**

```C++
class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<vector<pair<int, int>>> graph(n);
        vector<int> distances(n, INT_MAX);
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[v].push_back({w, u});
        }
        int res = 0;
        pq.push({0, 0});
        distances[0] = 0;
        while (!pq.empty() && n > 0) {
            auto [w1, u] = pq.top();
            pq.pop();
            if (distances[u] < w1) {
                continue;
            }
            res = max(res, w1);
            n--;
            for (auto& [w2, v] : graph[u]) {
                if (distances[v] > max(res, w2)) {
                    distances[v] = max(res, w2);
                    pq.push({w2, v});
                }
            }
        }
        return n ? -1 : res;
    }
};
```
