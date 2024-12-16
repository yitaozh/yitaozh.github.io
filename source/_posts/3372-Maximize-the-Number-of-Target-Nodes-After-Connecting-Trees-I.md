---
title: 3372. Maximize the Number of Target Nodes After Connecting Trees I
categories: Leetcode
date: 2024-12-15 23:10:01
tags:
    - Tree
    - Depth-First Search
    - Breadth-First Search
---

[3372. Maximize the Number of Target Nodes After Connecting Trees I](https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/description/)

## Description

There exist two **undirected** trees with `n` and `m` nodes, with **distinct**  labels in ranges `[0, n - 1]` and `[0, m - 1]`, respectively.

You are given two 2D integer arrays `edges1` and `edges2` of lengths `n - 1` and `m - 1`, respectively, where edges1[i] = [a<sub>i</sub>, b<sub>i</sub>] indicates that there is an edge between nodes a<sub>i</sub> and b<sub>i</sub> in the first tree and edges2[i] = [u<sub>i</sub>, v<sub>i</sub>] indicates that there is an edge between nodes u<sub>i</sub> and v<sub>i</sub> in the second tree. You are also given an integer `k`.

Node `u` is **target**  to node `v` if the number of edges on the path from `u` to `v` is less than or equal to `k`. **Note**  that a node is always **target**  to itself.

Return an array of `n` integers `answer`, where `answer[i]` is the **maximum**  possible number of nodes **target**  to node `i` of the first tree if you have to connect one node from the first tree to another node in the second tree.

**Note**  that queries are independent from each other. That is, for every query you will remove the added edge before proceeding to the next query.

**Example 1:**

```bash
Input: edges1 = [[0,1],[0,2],[2,3],[2,4]], edges2 = [[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]], k = 2

Output: [9,7,9,8,8]
```

Explanation:

- For `i = 0`, connect node 0 from the first tree to node 0 from the second tree.
- For `i = 1`, connect node 1 from the first tree to node 0 from the second tree.
- For `i = 2`, connect node 2 from the first tree to node 4 from the second tree.
- For `i = 3`, connect node 3 from the first tree to node 4 from the second tree.
- For `i = 4`, connect node 4 from the first tree to node 4 from the second tree.

<img alt="" src="https://assets.leetcode.com/uploads/2024/09/24/3982-1.png" style="width: 600px; height: 169px;">

**Example 2:**

```bash
Input: edges1 = [[0,1],[0,2],[0,3],[0,4]], edges2 = [[0,1],[1,2],[2,3]], k = 1

Output: [6,3,3,3,3]
```

Explanation:

For every `i`, connect node `i` of the first tree with any node of the second tree.

<img alt="" src="https://assets.leetcode.com/uploads/2024/09/24/3928-2.png" style="height: 281px; width: 500px;">

**Constraints:**

- `2 <= n, m <= 1000`
- `edges1.length == n - 1`
- `edges2.length == m - 1`
- `edges1[i].length == edges2[i].length == 2`
- edges1[i] = [a<sub>i</sub>, b<sub>i</sub>]
- 0 <= a<sub>i</sub>, b<sub>i</sub> < n
- edges2[i] = [u<sub>i</sub>, v<sub>i</sub>]
- 0 <= u<sub>i</sub>, v<sub>i</sub> < m
- The input is generated such that `edges1` and `edges2` represent valid trees.
- `0 <= k <= 1000`

## Hints/Notes

- 2024/12/07
- tree dfs
- [0x3F's solution](https://leetcode.cn/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/solutions/3006334/nao-jin-ji-zhuan-wan-bao-li-mei-ju-pytho-ua6k/)(checked)
- Weekly Contest 426

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> dp1, dp2;
    vector<vector<int>> tree1, tree2;

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        buildTree(edges1, tree1);
        buildTree(edges2, tree2);
        int n = tree1.size();
        dp1.resize(n, 1);
        for (int i = 0; i < n; i++) {
            dp1[i] = dfs(i, k, -1, tree1);
        }
        if (k == 0) {
            return dp1;
        }
        int m = tree2.size();
        dp2.resize(m, 1);
        for (int i = 0; i < m; i++) {
            dp2[i] = dfs(i, k - 1, -1, tree2);
        }
        int max_d = *ranges::max_element(dp2);
        for (int i = 0; i < n; i++) {
            dp1[i] += max_d;
        }
        return dp1;
    }

    int dfs(int cur, int k, int prev, vector<vector<int>>& tree) {
        if (k == 0) {
            return 1;
        }
        int res = 1;
        for (int u : tree[cur]) {
            if (u != prev) {
                res += dfs(u, k - 1, cur, tree);
            }
        }
        return res;
    }

    void buildTree(vector<vector<int>>& edges, vector<vector<int>>& tree) {
        int n = edges.size() + 1;
        tree.resize(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
    }
};
```
