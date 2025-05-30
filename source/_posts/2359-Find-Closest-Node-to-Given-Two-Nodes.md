---
title: 2359. Find Closest Node to Given Two Nodes
categories: Leetcode
date: 2025-05-30 17:44:06
tags:
    - Depth-First Search
    - Graph
---

[2359. Find Closest Node to Given Two Nodes](https://leetcode.com/problems/find-closest-node-to-given-two-nodes/description/?envType=daily-question&envId=2025-05-30)

## Description

You are given a **directed**  graph of <code>n</code> nodes numbered from <code>0</code> to <code>n - 1</code>, where each node has **at most one**  outgoing edge.

The graph is represented with a given **0-indexed**  array <code>edges</code> of size <code>n</code>, indicating that there is a directed edge from node <code>i</code> to node <code>edges[i]</code>. If there is no outgoing edge from <code>i</code>, then <code>edges[i] == -1</code>.

You are also given two integers <code>node1</code> and <code>node2</code>.

Return the **index**  of the node that can be reached from both <code>node1</code> and <code>node2</code>, such that the **maximum**  between the distance from <code>node1</code> to that node, and from <code>node2</code> to that node is **minimized** . If there are multiple answers, return the node with the **smallest**  index, and if no possible answer exists, return <code>-1</code>.

Note that <code>edges</code> may contain cycles.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2022/06/07/graph4drawio-2.png" style="width: 321px; height: 161px;">

```bash
Input: edges = [2,2,3,-1], node1 = 0, node2 = 1
Output: 2
Explanation: The distance from node 0 to node 2 is 1, and the distance from node 1 to node 2 is 1.
The maximum of those two distances is 1. It can be proven that we cannot get a node with a smaller maximum distance than 1, so we return node 2.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2022/06/07/graph4drawio-4.png" style="width: 195px; height: 161px;">

```bash
Input: edges = [1,2,-1], node1 = 0, node2 = 2
Output: 2
Explanation: The distance from node 0 to node 2 is 2, and the distance from node 2 to itself is 0.
The maximum of those two distances is 2. It can be proven that we cannot get a node with a smaller maximum distance than 2, so we return node 2.
```

**Constraints:**

- <code>n == edges.length</code>
- <code>2 <= n <= 10^5</code>
- <code>-1 <= edges[i] < n</code>
- <code>edges[i] != i</code>
- <code>0 <= node1, node2 < n</code>

## Hints/Notes

- 2025/05/10 Q1
- dfs
- [0x3F's solution](https://leetcode.cn/problems/find-closest-node-to-given-two-nodes/solutions/1710829/ji-suan-dao-mei-ge-dian-de-ju-chi-python-gr2u/?envType=daily-question&envId=2025-05-30)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dis1(n, -1), dis2(n, -1);
        findDis(edges, dis1, node1);
        findDis(edges, dis2, node2);
        int mx = INT_MAX, node = -1;
        for (int i = 0; i < n; i++) {
            if (dis1[i] != -1 && dis2[i] != -1) {
                int cur = max(dis1[i], dis2[i]);
                if (cur < mx) {
                    mx = cur;
                    node = i;
                }
            }
        }
        return node;
    }

    void findDis(vector<int>& edges, vector<int>& dis, int node) {
        int cur = node, curDis = 0;
        int n = edges.size();
        while (cur != -1 && dis[cur] == -1) {
            dis[cur] = curDis++;
            cur = edges[cur];
        }
    }
};
```
