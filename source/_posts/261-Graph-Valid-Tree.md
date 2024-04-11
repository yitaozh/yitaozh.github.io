---
title: 261. Graph Valid Tree
categories: Leetcode
date: 2023-09-03 23:34:43
tags:
    - Depth-First Search
    - Breadth-First Search
    - Union Find
    - Graph
---

[261\. Graph Valid Tree](https://leetcode.com/problems/graph-valid-tree/)

## Description

Difficulty: **Medium**

Related Topics: [Depth-First Search](https://leetcode.com/tag/https://leetcode.com/tag/depth-first-search//), [Breadth-First Search](https://leetcode.com/tag/https://leetcode.com/tag/breadth-first-search//), [Union Find](https://leetcode.com/tag/https://leetcode.com/tag/union-find//), [Graph](https://leetcode.com/tag/https://leetcode.com/tag/graph//)

You have a graph of `n` nodes labeled from `0` to `n - 1`. You are given an integer n and a list of `edges` where edges[i] = [a<sub>i</sub>, b<sub>i</sub>] indicates that there is an undirected edge between nodes a<sub>i</sub> and b<sub>i</sub> in the graph.

Return `true` _if the edges of the given graph make up a valid tree, and_ `false` _otherwise_.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/03/12/tree1-graph.jpg)

```bash
Input: n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]
Output: true
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/03/12/tree2-graph.jpg)

```bash
Input: n = 5, edges = [[0,1],[1,2],[2,3],[1,3],[1,4]]
Output: false
```

**Constraints:**

* `1 <= n <= 2000`
* `0 <= edges.length <= 5000`
* `edges[i].length == 2`
* 0 <= a<sub>i</sub>, b<sub>i</sub> < n
* a<sub>i</sub> != b<sub>i</sub>
* There are no self-loops or repeated edges.

## Hints/Notes

* Union find
* A valid tree doesn't have a cycle, and there's only one component

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> parent;
    int count;

    bool validTree(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
        }
        count = n;
        for (auto edge : edges) {
            int p = edge[0];
            int q = edge[1];
            int rootP = find(p);
            int rootQ = find(q);
            if (rootP == rootQ) {
                return false;
            } else {
                parent[rootP] = rootQ;
                count--;
            }
        }

        return count == 1;
    }

    int find(int node) {
        if (parent[node] != node) {
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }
};
```
