---
title: 1584. Min Cost to Connect All Points
categories: Leetcode
date: 2023-09-04 00:07:07
tags:
    - Array
    - Union Find
    - Graph
    - Minimum Spanning Tree
---

[1584\. Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Union Find](https://leetcode.com/tag/https://leetcode.com/tag/union-find//), [Graph](https://leetcode.com/tag/https://leetcode.com/tag/graph//), [Minimum Spanning Tree](https://leetcode.com/tag/https://leetcode.com/tag/minimum-spanning-tree//)

You are given an array `points` representing integer coordinates of some points on a 2D-plane, where points[i] = [x<sub>i</sub>, y<sub>i</sub>].

The cost of connecting two points [x<sub>i</sub>, y<sub>i</sub>] and [x<sub>j</sub>, y<sub>j</sub>] is the **manhattan distance** between them: |x<sub>i</sub> - x<sub>j</sub>| + |y<sub>i</sub> - y<sub>j</sub>|, where `|val|` denotes the absolute value of `val`.

Return _the minimum cost to make all points connected._ All points are connected if there is **exactly one** simple path between any two points.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/08/26/d.png)

```bash
Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation:

We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.
```

**Example 2:**

```bash
Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18
```

**Constraints:**

* `1 <= points.length <= 1000`
* -10<sup>6</sup> <= x<sub>i</sub>, y<sub>i</sub> <= 10<sup>6</sup>
* All pairs (x<sub>i</sub>, y<sub>i</sub>) are distinct.

## Hints/Notes

* Kruskal's algorithm
* Prim's algorithm
* cpp sort performance is worse than priority queue
* Use count(number of separarte items) to return early

## Solution

Language: **C++**

Kruskal's algorithm

```C++
class Solution {
public:
    vector<int> parent;

    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> edges;
        int count = points.size();
        for (int i = 0; i < points.size(); i++) {
            parent.push_back(i);
        }
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                int distance = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({distance, i, j});
            }
        }

        priority_queue pq(edges.begin(), edges.end(), greater<vector<int>>());

        int sum = 0;

        while (!pq.empty() && count > 1) {
            auto edge = pq.top();
            pq.pop();
            int p = edge[1];
            int q = edge[2];
            int rootP = find(p);
            int rootQ = find(q);
            if (rootP == rootQ) {
                continue;
            } else {
                parent[rootP] = rootQ;
                sum += edge[0];
                count--;
            }
        }
        return sum;
    }

    int find(int node) {
        if (parent[node] != node) {
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }
};
```

Prim's algorithm

```C++
class Solution {
public:
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<vector<vector<int>>> edges;
    vector<bool> visited;

    int minCostConnectPoints(vector<vector<int>>& points) {
        int size = points.size();
        edges = vector<vector<vector<int>>>(size, vector<vector<int>>());
        visited = vector<bool>(size, false);
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                int distance = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges[i].push_back({distance, j});
                edges[j].push_back({distance, i});
            }
        }

        int sum = 0;
        int count = 1;
        cut(0);
        visited[0] = true;

        while (!pq.empty()) {
            auto edge = pq.top();
            pq.pop();
            int to = edge[1];
            if (visited[to]) {
                continue;
            }
            int w = edge[0];
            sum += w;
            count++;
            if (count == size) break;
            cut(to);
            visited[to] = true;
        }

        return sum;
    }

    void cut(int node) {
        for (auto edge : edges[node]) {
            int to = edge[1];
            if (!visited[to]) {
                int w = edge[0];
                pq.push({w, to});
            }
        }
    }
};
```
