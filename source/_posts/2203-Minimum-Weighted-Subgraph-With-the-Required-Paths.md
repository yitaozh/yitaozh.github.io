---
title: 2203. Minimum Weighted Subgraph With the Required Paths
categories: Leetcode
date: 2025-05-03 15:47:54
tags:
    - Graph
    - Shortest Path
---

[2203. Minimum Weighted Subgraph With the Required Paths](https://leetcode.com/problems/minimum-weighted-subgraph-with-the-required-paths/description/?envType=company&envId=google&favoriteSlug=google-thirty-days)

## Description

You are given an integer <code>n</code> denoting the number of nodes of a **weighted directed**  graph. The nodes are numbered from <code>0</code> to <code>n - 1</code>.

You are also given a 2D integer array <code>edges</code> where <code>edges[i] = [from<sub>i</sub>, to<sub>i</sub>, weight<sub>i</sub>]</code> denotes that there exists a **directed**  edge from <code>from<sub>i</sub></code> to <code>to<sub>i</sub></code> with weight <code>weight<sub>i</sub></code>.

Lastly, you are given three **distinct**  integers <code>src1</code>, <code>src2</code>, and <code>dest</code> denoting three distinct nodes of the graph.

Return the **minimum weight**  of a subgraph of the graph such that it is **possible**  to reach <code>dest</code> from both <code>src1</code> and <code>src2</code> via a set of edges of this subgraph. In case such a subgraph does not exist, return <code>-1</code>.

A **subgraph**  is a graph whose vertices and edges are subsets of the original graph. The **weight**  of a subgraph is the sum of weights of its constituent edges.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2022/02/17/example1drawio.png" style="width: 263px; height: 250px;">

```bash
Input: n = 6, edges = [[0,2,2],[0,5,6],[1,0,3],[1,4,5],[2,1,1],[2,3,3],[2,3,4],[3,4,2],[4,5,1]], src1 = 0, src2 = 1, dest = 5
Output: 9
Explanation:
The above figure represents the input graph.
The blue edges represent one of the subgraphs that yield the optimal answer.
Note that the subgraph [[1,0,3],[0,5,6]] also yields the optimal answer. It is not possible to get a subgraph with less weight satisfying all the constraints.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2022/02/17/example2-1drawio.png" style="width: 350px; height: 51px;">

```bash
Input: n = 3, edges = [[0,1,1],[2,1,1]], src1 = 0, src2 = 1, dest = 2
Output: -1
Explanation:
The above figure represents the input graph.
It can be seen that there does not exist any path from node 1 to node 2, hence there are no subgraphs satisfying all the constraints.
```

**Constraints:**

- <code>3 <= n <= 10^5</code>
- <code>0 <= edges.length <= 10^5</code>
- <code>edges[i].length == 3</code>
- <code>0 <= from<sub>i</sub>, to<sub>i</sub>, src1, src2, dest <= n - 1</code>
- <code>from<sub>i</sub> != to<sub>i</sub></code>
- <code>src1</code>, <code>src2</code>, and <code>dest</code> are pairwise distinct.
- <code>1 <= weight[i] <= 10^5</code>

## Hints/Notes

- 2025/04/30 Q1
- dijkstra
- [0x3F's solution](https://leetcode.cn/problems/minimum-weighted-subgraph-with-the-required-paths/solutions/1332967/by-endlesscheng-2mxm/)

## Solution

Language: **C++**

```C++
class Solution {
public:

    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int, int>>> graph(n), reverse(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].push_back({v, w});
            reverse[v].push_back({u, w});
        }
        auto d1 = dijkstra(graph, src1);
        auto d2 = dijkstra(graph, src2);
        auto d3 = dijkstra(reverse, dest);

        long long res = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            if (d1[i] == LLONG_MAX || d2[i] == LLONG_MAX || d3[i] == LLONG_MAX) continue;
            res = min(res, d1[i] + d2[i] + d3[i]);
        }
        return res == LLONG_MAX ? -1 : res;
    }

    vector<long long> dijkstra(vector<vector<pair<int, int>>>& graph, int root) {
        int n = graph.size();
        vector<long long> dis(n, LLONG_MAX);
        dis[root] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, root});
        while (!pq.empty()) {
            auto [cur_dis, node] = pq.top();
            pq.pop();
            if (dis[node] < cur_dis) {
                continue;
            }
            dis[node] = cur_dis;
            for (auto [next_node, weight] : graph[node]) {
                long long next_weight = cur_dis + weight;
                if (next_weight < dis[next_node]) {
                    dis[next_node] = next_weight;
                    pq.emplace(next_weight, next_node);
                }
            }
        }
        return dis;
    }
};
```
