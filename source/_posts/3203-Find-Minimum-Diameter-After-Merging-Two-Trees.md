---
title: 3203. Find Minimum Diameter After Merging Two Trees
categories: Leetcode
date: 2024-07-03 23:44:27
tags:
    - Tree
    - Depth-First Search
    - Breadth-First Search
    - Graph
---

[3203. Find Minimum Diameter After Merging Two Trees](https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/description/)

## Description

There exist two **undirected** trees with `n` and `m` nodes, numbered from `0` to `n - 1` and from `0` to `m - 1`, respectively. You are given two 2D integer arrays `edges1` and `edges2` of lengths `n - 1` and `m - 1`, respectively, where edges1[i] = [a<sub>i</sub>, b<sub>i</sub>] indicates that there is an edge between nodes a<sub>i</sub> and b<sub>i</sub> in the first tree and edges2[i] = [u<sub>i</sub>, v<sub>i</sub>] indicates that there is an edge between nodes u<sub>i</sub> and v<sub>i</sub> in the second tree.

You must connect one node from the first tree with another node from the second tree with an edge.

Return the **minimum** possible **diameter** of the resulting tree.

The **diameter** of a tree is the length of the longest path between any two nodes in the tree.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2024/04/22/example11-transformed.png">

```bash
Input: edges1 = [[0,1],[0,2],[0,3]], edges2 = [[0,1]]

Output: 3

Explanation:

We can obtain a tree of diameter 3 by connecting node 0 from the first tree with any node from the second tree.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2024/04/22/example211.png">

```bash
Input: edges1 = [[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]], edges2 = [[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]]

Output: 5

Explanation:

We can obtain a tree of diameter 5 by connecting node 0 from the first tree with node 0 from the second tree.
```

**Constraints:**

- `1 <= n, m <= 10^5`
- `edges1.length == n - 1`
- `edges2.length == m - 1`
- `edges1[i].length == edges2[i].length == 2`
- `edges1[i] = [a<sub>i</sub>, b<sub>i</sub>]`
- `0 <= a<sub>i</sub>, b<sub>i</sub> < n`
- `edges2[i] = [u<sub>i</sub>, v<sub>i</sub>]`
- `0 <= u<sub>i</sub>, v<sub>i</sub> < m`
- The input is generated such that `edges1` and `edges2` represent valid trees.

## Hints/Notes

- Weekly Contest 404

## Solution

Language: **C++**

```C++
class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int selfD1, selfD2;
        int d1 = findRoot(edges1, selfD1);
        int d2 = findRoot(edges2, selfD2);
        // cout << d1 << " " << d2 << " " << selfD1 << " " << selfD2 << endl;
        return max(d1 + d2 + 1, max(selfD1, selfD2));
    }

    int findRoot(vector<vector<int>>& edges, int& self) {
        if (edges.empty()) {
            self = 0;
            return 0;
        }
        self = 0;
        int size = edges.size() + 1;
        vector<vector<int>> tree(size, vector<int>());
        unordered_map<int, int> m;
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
            m[u]++;
            m[v]++;
        }
        unordered_set<int> visited;
        queue<int> q;
        for (int i = 0; i < size; i++) {
            if (m[i] == 1) {
                visited.insert(i);
                m[i]--;
                q.push(i);
            }
        }
        int d = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int u = q.front();
                q.pop();
                for (int num : tree[u]) {
                    m[num]--;
                    if (!visited.contains(num) && m[num] == 1) {
                        visited.insert(num);
                        m[num]--;
                        q.push(num);
                    }
                }
            }
            if (q.size() > 1) {
                d++;
                self += 2;
            } else {
                self += 1;
            }
        }
        return d;
    }
};
```
