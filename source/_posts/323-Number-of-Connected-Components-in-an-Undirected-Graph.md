---
title: 323. Number of Connected Components in an Undirected Graph
categories: Leetcode
date: 2023-09-02 23:51:01
tags:
    - Depth-First Search
    - Breadth-First Search
    - Union Find
    - Graph
---

[323\. Number of Connected Components in an Undirected Graph](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/)

## Description

Difficulty: **Medium**

Related Topics: [Depth-First Search](https://leetcode.com/tag/https://leetcode.com/tag/depth-first-search//), [Breadth-First Search](https://leetcode.com/tag/https://leetcode.com/tag/breadth-first-search//), [Union Find](https://leetcode.com/tag/https://leetcode.com/tag/union-find//), [Graph](https://leetcode.com/tag/https://leetcode.com/tag/graph//)

You have a graph of `n` nodes. You are given an integer `n` and an array `edges` where edges[i] = [a<sub>i</sub>, b<sub>i</sub>] indicates that there is an edge between a<sub>i</sub> and b<sub>i</sub> in the graph.

Return _the number of connected components in the graph_.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/03/14/conn1-graph.jpg)

```bash
Input: n = 5, edges = [[0,1],[1,2],[3,4]]
Output: 2
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/03/14/conn2-graph.jpg)

```bash
Input: n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]
Output: 1
```

**Constraints:**

* `1 <= n <= 2000`
* `1 <= edges.length <= 5000`
* `edges[i].length == 2`
* 0 <= a<sub>i</sub> <= b<sub>i</sub> < n
* a<sub>i</sub> != b<sub>i</sub>
* There are no repeated edges.

## Hints/Notes

* 2023/09/02
* union find
* if the edge's two nodes are not connected previously, then minus the number of component since they are connected now
* premium

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> roots;

    int countComponents(int n, vector<vector<int>>& edges) {
        roots = vector<int>(n, 0);

        iota(roots.begin(), roots.end(), 0);

        int num = n;
        for (auto pair : edges) {
            int p = pair[0];
            int q = pair[1];
            int rootP = find(p);
            int rootQ = find(q);
            if (rootP != rootQ) {
                roots[rootP] = rootQ;
                num--;
            }
        }

        return num;
    }

    int find(int node) {
        if (roots[node] != node) {
            roots[node] = find(roots[node]);
        }
        return roots[node];
    }
};
```
