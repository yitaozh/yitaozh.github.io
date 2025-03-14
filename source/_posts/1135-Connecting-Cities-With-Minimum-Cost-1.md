---
title: 1135. Connecting Cities With Minimum Cost
categories: Leetcode
date: 2025-03-14 02:10:01
tags:
    - Union Find
    - Graph
    - Heap (Priority Queue)
    - Minimum Spanning Tree
---

[1135. Connecting Cities With Minimum Cost](https://leetcode.com/problems/connecting-cities-with-minimum-cost/description/)

## Description

There are `n` cities labeled from `1` to `n`. You are given the integer `n` and an array `connections` where connections[i] = [x<sub>i</sub>, y<sub>i</sub>, cost<sub>i</sub>] indicates that the cost of connecting city x<sub>i</sub> and city y<sub>i</sub> (bidirectional connection) is cost<sub>i</sub>.

Return the minimum **cost**  to connect all the `n` cities such that there is at least one path between each pair of cities. If it is impossible to connect all the `n` cities, return `-1`,

The **cost**  is the sum of the connections' costs used.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2019/04/20/1314_ex2.png" style="width: 161px; height: 141px;">

```bash
Input: n = 3, connections = [[1,2,5],[1,3,6],[2,3,1]]
Output: 6
Explanation: Choosing any 2 edges will connect all cities so we choose the minimum 2.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2019/04/20/1314_ex1.png" style="width: 136px; height: 91px;">

```bash
Input: n = 4, connections = [[1,2,3],[3,4,4]]
Output: -1
Explanation: There is no way to connect all cities even if all edges are used.
```

**Constraints:**

- `1 <= n <= 10^4`
- `1 <= connections.length <= 10^4`
- `connections[i].length == 3`
- 1 <= x<sub>i</sub>, y<sub>i</sub> <= n
- x<sub>i</sub> != y<sub>i</sub>
- 0 <= cost<sub>i</sub> <= 10^5

## Hints/Notes

- 2025/03/07 Q1
- rewrite with union find
- [Leetcode solution](https://leetcode.com/problems/connecting-cities-with-minimum-cost/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        // space: O(n)
        vector<bool> visited(n + 1, false);
        // space: O(n)
        vector<vector<pair<int, int>>> graph(n + 1);
        for (auto& c : connections) {
            int u = c[0], v = c[1], cost = c[2];
            graph[u].push_back({v, cost});
            graph[v].push_back({u, cost});
        }
        // 1: (2, 3)
        // 2: (1, 3)
        // 3: (4, 4)
        // 4: (3, 4)

        // pq:  {3, 2}
        // O(nlogn)
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        cut(1, pq, graph, visited);
        int numOfConnection = n, minCost = 0;
        while (!pq.empty() && numOfConnection > 1) {
            auto v = pq.top();
            pq.pop();
            int cost = v[0], u = v[1];
            if (visited[u]) {
                continue;
            }
            minCost += cost;
            cut(u, pq, graph, visited);
            numOfConnection--;
        }
        if (numOfConnection == 1) {
            return minCost;
        } else {
            return -1;
        }
    }

    void cut(int root, priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>& pq, vector<vector<pair<int, int>>>& graph, vector<bool>& visited) {
        visited[root] = true;
        for (auto& [u, cost] : graph[root]) {
            if (!visited[u]) {
                pq.push({cost, u});
            }
        }
    }
};
```
