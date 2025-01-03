---
title: 684. Redundant Connection
categories: Leetcode
date: 2025-01-02 23:28:50
tags:
    - Depth-First Search
    - Breadth-First Search
    - Union Find
    - Graph
---

[684. Redundant Connection](https://leetcode.com/problems/redundant-connection/description/?envType=problem-list-v2&envId=plakya4j)

## Description

In this problem, a tree is an **undirected graph**  that is connected and has no cycles.

You are given a graph that started as a tree with `n` nodes labeled from `1` to `n`, with one additional edge added. The added edge has two **different**  vertices chosen from `1` to `n`, and was not an edge that already existed. The graph is represented as an array `edges` of length `n` where edges[i] = [a<sub>i</sub>, b<sub>i</sub>] indicates that there is an edge between nodes a<sub>i</sub> and b<sub>i</sub> in the graph.

Return an edge that can be removed so that the resulting graph is a tree of `n` nodes. If there are multiple answers, return the answer that occurs last in the input.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/05/02/reduntant1-1-graph.jpg" style="width: 222px; height: 222px;">

```bash
Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/05/02/reduntant1-2-graph.jpg" style="width: 382px; height: 222px;">

```bash
Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]
```

**Constraints:**

- `n == edges.length`
- `3 <= n <= 1000`
- `edges[i].length == 2`
- 1 <= a<sub>i</sub> < b<sub>i</sub> <= edges.length
- a<sub>i</sub> != b<sub>i</sub>
- There are no repeated edges.
- The given graph is connected.

## Hints/Notes

- 2024/12/31
- union find
- No solution fromm 0x3F

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> roots;

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        roots.resize(n + 1);
        iota(roots.begin(), roots.end(), 0);
        for (int i = 0; i < n; i++) {
            auto& e = edges[i];
            int u = e[0], v = e[1];
            int rootU = findRoot(u), rootV = findRoot(v);
            if (rootU == rootV) {
                return e;
            }
            roots[rootU] = rootV;
        }
        return {};
    }

    int findRoot(int root) {
        int input = root;
        while (roots[root] != root) {
            root = roots[root];
        }
        roots[input] = root;
        return root;
    }
};
```
