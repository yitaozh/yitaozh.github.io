---
title: 1245. Tree Diameter
categories: Leetcode
date: 2024-07-05 23:32:59
tags:
    - Tree
    - Depth-First Search
    - Breadth-First Search
    - Graph
    - Topological Sort
---

[1245. Tree Diameter](https://leetcode.com/problems/tree-diameter/description/)

## Description

The **diameter**  of a tree is **the number of edges**  in the longest path in that tree.

There is an undirected tree of `n` nodes labeled from `0` to `n - 1`. You are given a 2D array `edges` where `edges.length == n - 1` and edges[i] = [a<sub>i</sub>, b<sub>i</sub>] indicates that there is an undirected edge between nodes a<sub>i</sub> and b<sub>i</sub> in the tree.

Return the **diameter** of the tree.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2022/01/19/tree1.jpg" style="width: 224px; height: 145px;">

```bash
Input: edges = [[0,1],[0,2]]
Output: 2
Explanation: The longest path of the tree is the path 1 - 0 - 2.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2022/01/19/tree2.jpg" style="width: 224px; height: 225px;">

```bash
Input: edges = [[0,1],[1,2],[2,3],[1,4],[4,5]]
Output: 4
Explanation: The longest path of the tree is the path 3 - 2 - 1 - 4 - 5.
```

**Constraints:**

- `n == edges.length + 1`
- `1 <= n <= 10^4`
- 0 <= a<sub>i</sub>, b<sub>i</sub> < n
- a<sub>i</sub> != b<sub>i</sub>

## Hints/Notes

- N/A

## Solution

Language: **C++**

```C++
class Solution {
public:
    int res = 0;
    vector<vector<int>> graph;
    vector<bool> visited;

    int treeDiameter(vector<vector<int>>& edges) {
        if (edges.empty()) {
            return 0;
        }
        graph.resize(edges.size() + 1, vector<int>());
        visited.resize(edges.size() + 1, false);
        build(edges);
        traverse(0);
        return res;
    }

    int traverse(int root) {
        if (visited[root]) {
            return -1;
        }
        visited[root] = true;
        int mx = 0, mx2 = 0;
        for (int u : graph[root]) {
            if (visited[u]) {
                continue;
            }
            int depth = traverse(u) + 1;
            if (depth > mx) {
                mx2 = mx;
                mx = depth;
            } else if (depth > mx2) {
                mx2 = depth;
            }
        }
        res = max(res, mx + mx2);
        return mx;
    }

    void build(vector<vector<int>>& edges) {
        for (auto e : edges) {
            int u = e[0];
            int v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }
};
```
