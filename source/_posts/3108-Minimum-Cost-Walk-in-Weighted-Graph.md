---
title: 3108. Minimum Cost Walk in Weighted Graph
categories: Leetcode
date: 2024-05-08 13:28:08
tags:
    - Array
    - Bit Manipulation
    - Union Find
    - Graph
---

[3108. Minimum Cost Walk in Weighted Graph](https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/description/)

## Description

There is an undirected weighted graph with `n` vertices labeled from `0` to `n - 1`.

You are given the integer `n` and an array `edges`, where `edges[i] = [ui, vi, wi]` indicates that there is an edge between vertices `ui` and `vi` with a weight of `wi`.

A walk on a graph is a sequence of vertices and edges. The walk starts and ends with a vertex, and each edge connects the vertex that comes before it and the vertex that comes after it. It's important to note that a walk may visit the same edge or vertex more than once.

The **cost**  of a walk starting at node `u` and ending at node `v` is defined as the bitwise `AND` of the weights of the edges traversed during the walk. In other words, if the sequence of edge weights encountered during the walk is `w0, w1, w2, ..., wk`, then the cost is calculated as `w0 &amp; w1 &amp; w2 &amp; ... &amp; wk`, where `&amp;` denotes the bitwise `AND` operator.

You are also given a 2D array `query`, where `query[i] = [si, ti]`. For each query, you need to find the minimum cost of the walk starting at vertex `si` and ending at vertex `ti`. If there exists no such walk, the answer is `-1`.

Return the array `answer`, where `answer[i]` denotes the **minimum**  cost of a walk for query `i`.

**Example 1:**

```bash
Input: n = 5, edges = [[0,1,7],[1,3,7],[1,2,1]], query = [[0,3],[3,4]]

Output: [1,-1]

Explanation:
<img alt="" src="https://assets.leetcode.com/uploads/2024/01/31/q4_example1-1.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 351px; height: 141px; --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor: #242729;" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="">
To achieve the cost of 1 in the first query, we need to move on the following edges: `0->1` (weight 7), `1->2` (weight 1), `2->1` (weight 1), `1->3` (weight 7).

In the second query, there is no walk between nodes 3 and 4, so the answer is -1.
```

**Example 2:**

```bash
Input: n = 3, edges = [[0,2,7],[0,1,15],[1,2,6],[1,2,1]], query = [[1,2]]

Output: [0]

Explanation:
<img alt="" src="https://assets.leetcode.com/uploads/2024/01/31/q4_example2e.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 211px; height: 181px; --darkreader-inline-bgimage: initial; --darkreader-inline-bgcolor: #242729;" data-darkreader-inline-bgimage="" data-darkreader-inline-bgcolor="">
To achieve the cost of 0 in the first query, we need to move on the following edges: `1->2` (weight 1), `2->1` (weight 6), `1->2` (weight 1).
```

**Constraints:**

- `2 <= n <= 10^5`
- `0 <= edges.length <= 10^5`
- `edges[i].length == 3`
- `0 <= ui, vi <= n - 1`
- `ui != vi`
- `0 <= wi <= 10^5`
- `1 <= query.length <= 10^5`
- `query[i].length == 2`
- `0 <= si, ti <= n - 1`
- `si !=ti`

## Hints/Notes

- Union find and bit operation

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> roots;

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        roots = vector<int>(n, -1);
        vector<int> weights(n, -1);
        for (int i = 0; i < n; i++) {
            roots[i] = i;
        }
        for (auto edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            int rootU = findRoot(u);
            int rootV = findRoot(v);
            if (rootU != rootV) {
                roots[rootU] = rootV;
                if (weights[rootU] != -1) {
                    if (weights[rootV] == -1) {
                        weights[rootV] = weights[rootU];
                    } else {
                        weights[rootV] &= weights[rootU];
                    }
                }
            }
            if (weights[rootV] == -1) {
                weights[rootV] = w;
            } else {
                weights[rootV] &= w;
            }
        }

        vector<int> res;
        for (auto q : query) {
            int u = q[0];
            int v = q[1];
            if (u == v) {
                res.push_back(0);
                continue;
            }
            int rootU = findRoot(u);
            int rootV = findRoot(v);
            if (rootU != rootV) {
                res.push_back(-1);
            } else {
                res.push_back(weights[rootU]);
            }
        }
        return res;

    }

    int findRoot(int v) {
        if (v != roots[v]) {
            roots[v] = findRoot(roots[v]);
        }
        return roots[v];
    }
};
```
