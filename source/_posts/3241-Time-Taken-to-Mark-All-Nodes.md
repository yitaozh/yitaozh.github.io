---
title: 3241. Time Taken to Mark All Nodes
categories: Leetcode
date: 2024-08-14 23:54:24
tags:
    - Dynamic Programming
    - Tree
    - Depth-First Search
    - Graph
---

[3241. Time Taken to Mark All Nodes](https://leetcode.com/problems/time-taken-to-mark-all-nodes/description/)

## Description

There exists an **undirected**  tree with `n` nodes numbered `0` to `n - 1`. You are given a 2D integer array `edges` of length `n - 1`, where edges[i] = [u<sub>i</sub>, v<sub>i</sub>] indicates that there is an edge between nodes u<sub>i</sub> and v<sub>i</sub> in the tree.

Initially, **all**  nodes are **unmarked** . For each node `i`:

- If `i` is odd, the node will get marked at time `x` if there is **at least**  one node adjacent to it which was marked at time `x - 1`.
- If `i` is even, the node will get marked at time `x` if there is **at least**  one node adjacent to it which was marked at time `x - 2`.

Return an array `times` where `times[i]` is the time when all nodes get marked in the tree, if you mark node `i` at time `t = 0`.

**Note**  that the answer for each `times[i]` is **independent** , i.e. when you mark node `i` all other nodes are unmarked.

**Example 1:**

```bash
Input: edges = [[0,1],[0,2]]

Output: [2,4,3]
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/06/01/screenshot-2024-06-02-122236.png" style="width: 500px; height: 241px;">

- For `i = 0`:

- Node 1 is marked at `t = 1`, and Node 2 at `t = 2`.

- For `i = 1`:

- Node 0 is marked at `t = 2`, and Node 2 at `t = 4`.

- For `i = 2`:

- Node 0 is marked at `t = 2`, and Node 1 at `t = 3`.

**Example 2:**

```bash
Input: edges = [[0,1]]

Output: [1,2]
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/06/01/screenshot-2024-06-02-122249.png" style="width: 500px; height: 257px;">

- For `i = 0`:

- Node 1 is marked at `t = 1`.

- For `i = 1`:

- Node 0 is marked at `t = 2`.

**Example 3:**

```bash
Input: edges = [[2,4],[0,1],[2,3],[0,2]]

Output: [4,6,3,5,5]
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/06/03/screenshot-2024-06-03-210550.png" style="height: 266px; width: 500px;">

**Constraints:**

- `2 <= n <= 10^5`
- `edges.length == n - 1`
- `edges[i].length == 2`
- `0 <= edges[i][0], edges[i][1] <= n - 1`
- The input is generated such that `edges` represents a valid tree.

## Hints/Notes

- reroot dp
- Biweekly Contest 136

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<int>> graph;
    vector<vector<int>> nodes;
    vector<int> res;
    vector<int> timeTaken(vector<vector<int>>& edges) {
        // dfs then reroot
        int n = edges.size() + 1;
        graph.resize(n, vector<int>());
        nodes.resize(n, vector<int>());
        res.resize(n, 0);
        build(edges);
        // what we get from dfs?
        //  after dfs, for each of the node in the graph
        //  we get {mx, mx2, mv}:
        //      mx: the time to mark the node's children
        //      mv: to mark the node's children, mv taking longest time
        //      mx2: the time to mark the node's children other than mv
        dfs(0, -1);
        // now how to reroot?
        //  for the root, we can just use mx
        //  for the nodes not root:
        //      the mx value can come either from downstream or upstream
        //      for downstream, the value is fixed at mx
        //      for upstream, the value can be either from upper, or from
        //      another branch of the parent node
        reroot(0, -1, 0);
        return res;
    }

    void reroot(int node, int origin, int up) {
        int mx = nodes[node][0], mx2 = nodes[node][1], mv = nodes[node][2];
        res[node] = max(up, mx);
        for (int v : graph[node]) {
            if (v != origin) {
                int up1 = up + (node + 1) % 2 + 1;
                int up2 = (node + 1) % 2 + 1 + ((v == mv) ? mx2 : mx);
                reroot(v, node, max(up1, up2));
            }
        }
    }

    int dfs(int node, int origin) {
        int mx = 0, mx2 = 0, mv = 0;
        for (int v : graph[node]) {
            if (v == origin) {
                continue;
            }
            int tmp = (v + 1) % 2 + 1 + dfs(v, node);
            if (tmp > mx) {
                mx2 = mx;
                mx = tmp;
                mv = v;
            } else if (tmp > mx2) {
                mx2 = tmp;
            }
        }
        nodes[node] = {mx, mx2, mv};
        return mx;
    }

    void build(vector<vector<int>>& edges) {
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }
};
```
