---
title: 1443. Minimum Time to Collect All Apples in a Tree
categories: Leetcode
date: 2025-03-14 11:54:47
tags:
    - Hash Table
    - Tree
    - Depth-First Search
    - Breadth-First Search
---

[1443. Minimum Time to Collect All Apples in a Tree](https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/description/)

## Description

Given an undirected tree consisting of `n` vertices numbered from `0` to `n-1`, which has some apples in their vertices. You spend 1 second to walk over one edge of the tree. Return the minimum time in seconds you have to spend to collect all apples in the tree, starting at **vertex 0**  and coming back to this vertex.

The edges of the undirected tree are given in the array `edges`, where `edges[i] = [a<sub>i</sub>, b<sub>i</sub>]` means that exists an edge connecting the vertices `a<sub>i</sub>` and `b<sub>i</sub>`. Additionally, there is a boolean array `hasApple`, where `hasApple[i] = true` means that vertex `i` has an apple; otherwise, it does not have any apple.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/04/23/min_time_collect_apple_1.png" style="width: 300px; height: 212px;">

```bash
Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,true,true,false]
Output: 8
Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/04/23/min_time_collect_apple_2.png" style="width: 300px; height: 212px;">

```bash
Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,false,true,false]
Output: 6
Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.
```

**Example 3:**

```bash
Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,false,false,false,false,false]
Output: 0
```

**Constraints:**

- `1 <= n <= 10^5`
- `edges.length == n - 1`
- `edges[i].length == 2`
- 0 <= a<sub>i</sub> < b<sub>i</sub> <= n - 1
- `hasApple.length == n`

## Hints/Notes

- 2025/03/10 Q1
- tree dfs
- [0x3F's solution](https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<int>> graph;

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        graph.resize(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int res = dfs(0, -1, hasApple);
        return res;
    }

    int dfs(int node, int parent, vector<bool>& hasApple) {
        int res = 0;
        for (int u : graph[node]) {
            if (u == parent) {
                continue;
            }
            res += dfs(u, node, hasApple);
        }
        if (parent != -1 && (hasApple[node] || res > 0)) {
            res += 2;
        }
        return res;
    }
};
```
