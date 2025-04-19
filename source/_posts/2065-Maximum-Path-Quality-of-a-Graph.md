---
title: 2065. Maximum Path Quality of a Graph
categories: Leetcode
date: 2025-04-19 15:00:03
tags:
    - Array
    - Backtracking
    - Graph
---

[2065. Maximum Path Quality of a Graph](https://leetcode.com/problems/maximum-path-quality-of-a-graph/description/?envType=company&envId=doordash&favoriteSlug=doordash-more-than-six-months)

## Description

There is an **undirected**  graph with `n` nodes numbered from `0` to `n - 1` (**inclusive** ). You are given a **0-indexed**  integer array `values` where `values[i]` is the **value** of the `i^th` node. You are also given a **0-indexed**  2D integer array `edges`, where each `edges[j] = [u<sub>j</sub>, v<sub>j</sub>, time<sub>j</sub>]` indicates that there is an undirected edge between the nodes `u<sub>j</sub>` and `v<sub>j</sub>`,<sub> </sub>and it takes `time<sub>j</sub>` seconds to travel between the two nodes. Finally, you are given an integer `maxTime`.

A **valid**  **path**  in the graph is any path that starts at node `0`, ends at node `0`, and takes **at most**  `maxTime` seconds to complete. You may visit the same node multiple times. The **quality**  of a valid path is the **sum**  of the values of the **unique nodes**  visited in the path (each node's value is added **at most once**  to the sum).

Return the **maximum**  quality of a valid path.

**Note:**  There are **at most four**  edges connected to each node.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/10/19/ex1drawio.png" style="width: 269px; height: 170px;">

```bash
Input: values = [0,32,10,43], edges = [[0,1,10],[1,2,15],[0,3,10]], maxTime = 49
Output: 75
Explanation:
One possible path is 0 -> 1 -> 0 -> 3 -> 0. The total time taken is 10 + 10 + 10 + 10 = 40 <= 49.
The nodes visited are 0, 1, and 3, giving a maximal path quality of 0 + 32 + 43 = 75.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/10/19/ex2drawio.png" style="width: 269px; height: 170px;">

```bash
Input: values = [5,10,15,20], edges = [[0,1,10],[1,2,10],[0,3,10]], maxTime = 30
Output: 25
Explanation:
One possible path is 0 -> 3 -> 0. The total time taken is 10 + 10 = 20 <= 30.
The nodes visited are 0 and 3, giving a maximal path quality of 5 + 20 = 25.
```

**Example 3:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/10/19/ex31drawio.png" style="width: 236px; height: 170px;">

```bash
Input: values = [1,2,3,4], edges = [[0,1,10],[1,2,11],[2,3,12],[1,3,13]], maxTime = 50
Output: 7
Explanation:
One possible path is 0 -> 1 -> 3 -> 1 -> 0. The total time taken is 10 + 13 + 13 + 10 = 46 <= 50.
The nodes visited are 0, 1, and 3, giving a maximal path quality of 1 + 2 + 4 = 7.
```

**Constraints:**

- `n == values.length`
- `1 <= n <= 1000`
- `0 <= values[i] <= 10^8`
- `0 <= edges.length <= 2000`
- `edges[j].length == 3`
- 0 <= u<sub>j </sub>< v<sub>j</sub> <= n - 1
- 10 <= time<sub>j</sub>, maxTime <= 100
- All the pairs [u<sub>j</sub>, v<sub>j</sub>] are **unique** .
- There are **at most four**  edges connected to each node.
- The graph may not be connected.

## Hints/Notes

- 2025/04/16 Q3
- backtracking
- [0x3F's solution](https://leetcode.cn/problems/maximum-path-quality-of-a-graph/solutions/1088414/bao-sou-jian-zhi-by-endlesscheng-iv6z/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int res = 0;
    vector<bool> visited;
    vector<vector<pair<int, int>>> graph;

    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        graph.resize(n);
        visited.resize(n, false);
        for (auto& e : edges) {
            int u = e[0], v = e[1], t = e[2];
            graph[u].push_back({v, t});
            graph[v].push_back({u, t});
        }
        visited[0] = true;
        dfs(0, values[0], maxTime, values, edges);
        return res;
    }

    void dfs(int curPoint, int curValue, int remaining_time, vector<int>& values, vector<vector<int>>& edges) {
        if (curPoint == 0) {
            res = max(res, curValue);
        }
        for (auto [v, t] : graph[curPoint]) {
            if (t > remaining_time) {
                continue;
            }
            if (visited[v]) {
                dfs(v, curValue, remaining_time - t, values, edges);
            } else {
                visited[v] = true;
                dfs(v, curValue + values[v], remaining_time - t, values, edges);
                visited[v] = false;
            }
        }
    }
};
```
