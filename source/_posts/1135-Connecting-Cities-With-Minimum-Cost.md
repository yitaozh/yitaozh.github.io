---
title: 1135. Connecting Cities With Minimum Cost
categories: Leetcode
date: 2023-09-03 23:45:31
tags:
    - Union Find
    - Graph
    - Heap (Priority Queue)
    - Minimum Spanning Tree
---

# [1135\. Connecting Cities With Minimum Cost](https://leetcode.com/problems/connecting-cities-with-minimum-cost/)

## Description

Difficulty: **Medium**

Related Topics: [Union Find](https://leetcode.com/tag/https://leetcode.com/tag/union-find//), [Graph](https://leetcode.com/tag/https://leetcode.com/tag/graph//), [Heap (Priority Queue)](https://leetcode.com/tag/https://leetcode.com/tag/heap-priority-queue//), [Minimum Spanning Tree](https://leetcode.com/tag/https://leetcode.com/tag/minimum-spanning-tree//)

There are `n` cities labeled from `1` to `n`. You are given the integer `n` and an array `connections` where connections[i] = [x<sub>i</sub>, y<sub>i</sub>, cost<sub>i</sub>] indicates that the cost of connecting city x<sub>i</sub> and city y<sub>i</sub> (bidirectional connection) is cost<sub>i</sub>.

Return _the minimum **cost** to connect all the_ `n` _cities such that there is at least one path between each pair of cities_. If it is impossible to connect all the `n` cities, return `-1`,

The **cost** is the sum of the connections' costs used.

**Example 1:**

![](https://assets.leetcode.com/uploads/2019/04/20/1314_ex2.png)

```bash
Input: n = 3, connections = [[1,2,5],[1,3,6],[2,3,1]]
Output: 6
Explanation: Choosing any 2 edges will connect all cities so we choose the minimum 2.
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2019/04/20/1314_ex1.png)

```bash
Input: n = 4, connections = [[1,2,3],[3,4,4]]
Output: -1
Explanation: There is no way to connect all cities even if all edges are used.
```

**Constraints:**

* 1 <= n <= 10<sup>4</sup>
* 1 <= connections.length <= 10<sup>4</sup>
* `connections[i].length == 3`
* 1 <= x<sub>i</sub>, y<sub>i</sub> <= n
* x<sub>i</sub> != y<sub>i</sub>
* 0 <= cost<sub>i</sub> <= 10<sup>5</sup>

## Hints/Notes

* Kruskal's algorithm: union find + weight
* Prim's algorithm: BFS + priority queue

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> parent;
    int count;

    int minimumCost(int n, vector<vector<int>>& connections) {
        int count = n;
        for (int i = 0; i <= n; i++) {
            parent.push_back(i);
        }

        auto cmp = [](vector<int> lhs, vector<int> rhs) {
            return lhs[2] < rhs[2];
        };
        sort(connections.begin(), connections.end(), cmp);

        int sum = 0;
        for (auto connection : connections) {
            int p = connection[0];
            int q = connection[1];
            int findP = find(p);
            int findQ = find(q);
            if (findP == findQ) {
                continue;
            } else {
                parent[findP] = findQ;
                sum += connection[2];
                count--;
            }
        }

        return count == 1 ? sum : -1;
    }

    int find(int node) {
        if (parent[node] != node) {
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }
};
```

Prim's algorithm

```C++
class Solution {
public:
    vector<vector<vector<int>>> graph;
    vector<bool> visited;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    int minimumCost(int n, vector<vector<int>>& connections) {
        int count = n;
        graph = vector<vector<vector<int>>>(n + 1, vector<vector<int>>());
        visited = vector<bool>(n + 1, false);

        for (auto connection : connections) {
            int p = connection[0];
            int q = connection[1];
            int w = connection[2];
            graph[p].push_back({w, q});
            graph[q].push_back({w, p});
        }

        int cost = 0;
        visited[1] = true;
        cut(1);
        while (!pq.empty()) {
            vector<int> pair = pq.top();
            pq.pop();
            int node = pair[1];
            if (visited[node]) {
                continue;
            }
            n--;
            int w = pair[0];
            visited[node] = true;
            cost += w;
            cut(node);
        }

        return n == 1 ? cost : -1;
    }

    void cut(int node) {
        for (auto edge : graph[node]) {
            int to = edge[1];
            if (visited[to]) {
                continue;
            } else {
                int w = edge[0];
                pq.push({w, to});
            }
        }
    }
};
```
