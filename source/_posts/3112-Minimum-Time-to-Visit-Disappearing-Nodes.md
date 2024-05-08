---
title: 3112. Minimum Time to Visit Disappearing Nodes
categories: Leetcode
date: 2024-05-08 13:43:26
tags:
    - Array
    - Graph
    - Heap (Priority Queue)
    - Shortest Path
---

[3112. Minimum Time to Visit Disappearing Nodes](https://leetcode.com/problems/minimum-time-to-visit-disappearing-nodes/description/)

## Description

There is an undirected graph of `n` nodes. You are given a 2D array `edges`, where `edges[i] = [ui, vi, lengthi]` describes an edge between node `ui` and node `vi` with a traversal time of `lengthi` units.

Additionally, you are given an array `disappear`, where `disappear[i]` denotes the time when the node `i` disappears from the graph and you won't be able to visit it.

**Notice**  that the graph might be disconnected and might contain multiple edges.

Return the array `answer`, with `answer[i]` denoting the **minimum**  units of time required to reach node `i` from node 0. If node `i` is **unreachable**  from node 0 then `answer[i]` is `-1`.

**Example 1:**

<img alt="" padding:="" src="https://assets.leetcode.com/uploads/2024/03/09/example1.png" style="width: 350px; height: 210px;">

```bash
Input:  n = 3, edges = [[0,1,2],[1,2,1],[0,2,4]], disappear = [1,1,5]

Output:  [0,-1,4]

Explanation:

We are starting our journey from node 0, and our goal is to find the minimum time required to reach each node before it disappears.

- For node 0, we don't need any time as it is our starting point.
- For node 1, we need at least 2 units of time to traverse `edges[0]`. Unfortunately, it disappears at that moment, so we won't be able to visit it.
- For node 2, we need at least 4 units of time to traverse `edges[2]`.
```

**Example 2:**

<img alt="" padding:="" src="https://assets.leetcode.com/uploads/2024/03/09/example2.png" style="width: 350px; height: 210px;">

```bash
Input:  n = 3, edges = [[0,1,2],[1,2,1],[0,2,4]], disappear = [1,3,5]

Output:  [0,2,3]

Explanation:

We are starting our journey from node 0, and our goal is to find the minimum time required to reach each node before it disappears.

- For node 0, we don't need any time as it is the starting point.
- For node 1, we need at least 2 units of time to traverse `edges[0]`.
- For node 2, we need at least 3 units of time to traverse `edges[0]` and `edges[1]`.
```

**Example 3:**

```bash
Input: n = 2, edges = [[0,1,1]], disappear = [1,1]

Output: [0,-1]

Explanation:

Exactly when we reach node 1, it disappears.
```

**Constraints:**

- `1 <= n <= 5 * 10^4`
- `0 <= edges.length <= 10^5`
- `edges[i] == [ui, vi, lengthi]`
- `0 <= ui, vi <= n - 1`
- `1 <= lengthi <= 10^5`
- `disappear.length == n`
- `1 <= disappear[i] <= 10^5`

## Hints/Notes

- dijkstra's algorithm

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<vector<int>>> graph;
    vector<int> res;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        graph = vector<vector<vector<int>>>(n, vector<vector<int>>());
        buildGraph(edges);
        res = vector<int>(n, INT_MAX);
        pq.push({0, 0});
        while (!pq.empty() && n > 0) {
            auto edge = pq.top();
            pq.pop();
            int cur = edge[0];
            int v = edge[1];
            if (res[v] <= cur) {
                continue;
            }
            res[v] = cur;
            n--;
            cut(v, cur, disappear);
        }
        for (int i = 0; i < res.size(); i++) {
            if (res[i] == INT_MAX) {
                res[i] = -1;
            }
        }
        return res;
    }

    void buildGraph(vector<vector<int>>& edges) {
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
    }

    void cut(int u, int cur, vector<int>& disappear) {
        for (auto edge : graph[u]) {
            int v = edge[0];
            int w = edge[1];
            if (w + cur < disappear[v] && w + cur < res[v]) {
                pq.push({w + cur, v});
            }
        }
    }
};
```
