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

You are given two integers, `n` and `threshold`, as well as a **directed**  weighted graph of `n` nodes numbered from 0 to `n - 1`. The graph is represented by a **2D**  integer array `edges`, where edges[i] = [A<sub>i</sub>, B<sub>i</sub>, W<sub>i</sub>] indicates that there is an edge going from node A<sub>i</sub> to node B<sub>i</sub> with weight W<sub>i</sub>.

You have to remove some edges from this graph (possibly **none** ), so that it satisfies the following conditions:

- Node 0 must be reachable from all other nodes.
- The **maximum**  edge weight in the resulting graph is **minimized** .
- Each node has **at most**  `threshold` outgoing edges.

Return the **minimum**  possible value of the **maximum**  edge weight after removing the necessary edges. If it is impossible for all conditions to be satisfied, return -1.

**Example 1:**

```bash
Input: n = 5, edges = [[1,0,1],[2,0,2],[3,0,1],[4,3,1],[2,1,1]], threshold = 2

Output: 1
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/12/09/s-1.png" style="width: 300px; height: 233px;">

Remove the edge `2 -> 0`. The maximum weight among the remaining edges is 1.

**Example 2:**

```bash
Input: n = 5, edges = [[0,1,1],[0,2,2],[0,3,1],[0,4,1],[1,2,1],[1,4,1]], threshold = 1

Output: -1
```

Explanation:

It is impossible to reach node 0 from node 2.

**Example 3:**

```bash
Input: n = 5, edges = [[1,2,1],[1,3,3],[1,4,5],[2,3,2],[3,4,2],[4,0,1]], threshold = 1

Output: 2
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/12/09/s2-1.png" style="width: 300px; height: 267px;">

Remove the edges `1 -> 3` and `1 -> 4`. The maximum weight among the remaining edges is 2.

**Example 4:**

```bash
Input: n = 5, edges = [[1,2,1],[1,3,3],[1,4,5],[2,3,2],[4,0,1]], threshold = 1

Output: -1
```

**Constraints:**

- `2 <= n <= 10^5`
- `1 <= threshold <= n - 1`
- `1 <= edges.length <= min(10^5, n * (n - 1) / 2).`
- `edges[i].length == 3`
- 0 <= A<sub>i</sub>, B<sub>i</sub> < n
- A<sub>i</sub> != B<sub>i</sub>
- 1 <= W<sub>i</sub> <= 10^6
- There **may be**  multiple edges between a pair of nodes, but they must have unique weights.

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
