---
title: 3123. Find Edges in Shortest Paths
categories: Leetcode
date: 2024-05-16 00:09:35
tags:
    - Depth-First Search
    - Breadth-First Search
    - Graph
    - Heap (Priority Queue)
    - Shortest Path
---

[3123. Find Edges in Shortest Paths](https://leetcode.com/problems/find-edges-in-shortest-paths/description/)

You are given an undirected weighted graph of `n` nodes numbered from 0 to `n - 1`. The graph consists of `m` edges represented by a 2D array `edges`, where edges[i] = [a<sub>i</sub>, b<sub>i</sub>, w<sub>i</sub>] indicates that there is an edge between nodes a<sub>i</sub> and b<sub>i</sub> with weight w<sub>i</sub>.

Consider all the shortest paths from node 0 to node `n - 1` in the graph. You need to find a **boolean**  array `answer` where `answer[i]` is `true` if the edge `edges[i]` is part of **at least**  one shortest path. Otherwise, `answer[i]` is `false`.

Return the array `answer`.

**Note**  that the graph may not be connected.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2024/03/05/graph35drawio-1.png" style="height: 129px; width: 250px;">

```bash
Input: n = 6, edges = [[0,1,4],[0,2,1],[1,3,2],[1,4,3],[1,5,1],[2,3,1],[3,5,3],[4,5,2]]

Output: [true,true,true,false,true,true,true,false]

Explanation:

The following are **all**  the shortest paths between nodes 0 and 5:

- The path `0 -> 1 -> 5`: The sum of weights is `4 + 1 = 5`.
- The path `0 -> 2 -> 3 -> 5`: The sum of weights is `1 + 1 + 3 = 5`.
- The path `0 -> 2 -> 3 -> 1 -> 5`: The sum of weights is `1 + 1 + 2 + 1 = 5`.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2024/03/05/graphhhh.png" style="width: 185px; height: 136px;">

```bash
Input: n = 4, edges = [[2,0,1],[0,1,1],[0,3,4],[3,2,2]]

Output: [true,false,false,true]

Explanation:

There is one shortest path between nodes 0 and 3, which is the path `0 -> 2 -> 3` with the sum of weights `1 + 2 = 3`.
```

**Constraints:**

- `2 <= n <= 5 * 10^4`
- `m == edges.length`
- `1 <= m <= min(5 * 10^4, n * (n - 1) / 2)`
- 0 <= a<sub>i</sub>, b<sub>i</sub> < n
- a<sub>i</sub> != b<sub>i</sub>
- 1 <= w<sub>i</sub> <= 10^5
- There are no repeated edges.

## Hints/Notes

- use dijkstra's algorithm to find the minimum cost to get to each point, then use dfs/bfs to get to all points

## Solution

Language: **C++**

```C++
class Solution {
public:
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<vector<int>>> graph(n, vector<vector<int>>());
        buildGraph(graph, edges);
        vector<bool> res(edges.size(), false);
        vector<int> fromRoot(n, INT_MAX);
        fromRoot[0] = 0;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto e = pq.top();
            pq.pop();
            int u = e[0];
            int w = e[1];
            if (fromRoot[u] < w) {
                continue;
            }
            fromRoot[u] = w;
            for (auto edge : graph[u]) {
                int v = edge[0];
                int weight = edge[1];
                if (fromRoot[v] > w + weight) {
                    fromRoot[v] = w + weight;
                    pq.push({v, w + weight});
                }
            }
        }

        queue<int> q;
        vector<bool> visited(n - 1, false);
        q.push(n - 1);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (visited[u]) {
                continue;
            }
            visited[u] = true;
            for (auto edge : graph[u]) {
                int v = edge[0];
                int weight = edge[1];
                int index = edge[2];
                if (fromRoot[v] == INT_MAX) {
                    continue;
                }
                if (fromRoot[v] + weight == fromRoot[u]) {
                    res[index] = true;
                    q.push(v);
                }
            }
        }
        return res;
    }

    void buildGraph(vector<vector<vector<int>>>& graph, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); i++) {
            auto edge = edges[i];
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            graph[u].push_back({v, w, i});
            graph[v].push_back({u, w, i});
        }
    }
};
```
