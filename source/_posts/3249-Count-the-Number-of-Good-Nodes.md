---
title: 3249. Count the Number of Good Nodes
categories: Leetcode
date: 2024-08-15 00:04:21
tags:
    - Tree
    - Depth-First Search
---

[3249. Count the Number of Good Nodes](https://leetcode.com/problems/count-the-number-of-good-nodes/description/)

## Description

There is an **undirected**  tree with `n` nodes labeled from `0` to `n - 1`, and rooted at node `0`. You are given a 2D integer array `edges` of length `n - 1`, where edges[i] = [a<sub>i</sub>, b<sub>i</sub>] indicates that there is an edge between nodes a<sub>i</sub> and b<sub>i</sub> in the tree.

A node is **good**  if all the subtrees rooted at its children have the same size.

Return the number of **good**  nodes in the given tree.

A **subtree**  of `treeName` is a tree consisting of a node in `treeName` and all of its descendants.

**Example 1:**

```bash
Input: edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]]

Output: 7
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/05/26/tree1.png" style="width: 360px; height: 158px;">

All of the nodes of the given tree are good.

**Example 2:**

```bash
Input: edges = [[0,1],[1,2],[2,3],[3,4],[0,5],[1,6],[2,7],[3,8]]

Output: 6
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/06/03/screenshot-2024-06-03-193552.png" style="width: 360px; height: 303px;">

There are 6 good nodes in the given tree. They are colored in the image above.

**Example 3:**

```bash
Input: edges = [[0,1],[1,2],[1,3],[1,4],[0,5],[5,6],[6,7],[7,8],[0,9],[9,10],[9,12],[10,11]]

Output: 12
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/08/08/rob.jpg" style="width: 450px; height: 277px;">

All nodes except node 9 are good.

**Constraints:**

- `2 <= n <= 10^5`
- `edges.length == n - 1`
- `edges[i].length == 2`
- 0 <= a<sub>i</sub>, b<sub>i</sub> < n
- The input is generated such that `edges` represents a valid tree.

## Hints/Notes

- Weekly Contest 410

## Solution

Language: **C++**

```C++
class Solution {
public:
    int res = 0;
    vector<vector<int>> graph;
    unordered_map<int, int> m;
    vector<bool> visited;

    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        graph.resize(n, vector<int>());
        visited.resize(n, false);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            m[u]++;
            m[v]++;
        }
        traverse(0);
        return res;
    }

    int traverse(int root) {
        if (m[root] == 0) {
            res++;
            return 1;
        }
        visited[root] = true;
        int first = -1, sum = 0;
        bool valid = true;
        for (auto& u : graph[root]) {
            if (visited[u]) {
                continue;
            }
            m[u]--;
            int cur = traverse(u);
            if (first == -1) {
                first = cur;
            } else if (first != cur) {
                valid = false;
            }
            sum += cur;
        }
        if (valid) {
            res++;
        }
        sum++;
        return sum;
    }
};
```
