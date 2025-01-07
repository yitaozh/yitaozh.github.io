---
title: 743. Network Delay Time
categories: Leetcode
date: 2023-09-05 23:37:07
tags:
    - Depth-First Search
    - Breadth-First Search
    - Graph
    - Heap (Priority Queue)
    - Shortest Path
---

[743\. Network Delay Time](https://leetcode.com/problems/network-delay-time/)

## Description

Difficulty: **Medium**

Related Topics: [Depth-First Search](https://leetcode.com/tag/https://leetcode.com/tag/depth-first-search//), [Breadth-First Search](https://leetcode.com/tag/https://leetcode.com/tag/breadth-first-search//), [Graph](https://leetcode.com/tag/https://leetcode.com/tag/graph//), [Heap (Priority Queue)](https://leetcode.com/tag/https://leetcode.com/tag/heap-priority-queue//), [Shortest Path](https://leetcode.com/tag/https://leetcode.com/tag/shortest-path//)

You are given a network of `n` nodes, labeled from `1` to `n`. You are also given `times`, a list of travel times as directed edges times[i] = (u<sub>i</sub>, v<sub>i</sub>, w<sub>i</sub>), where u<sub>i</sub> is the source node, v<sub>i</sub> is the target node, and w<sub>i</sub> is the time it takes for a signal to travel from source to target.

We will send a signal from a given node `k`. Return _the **minimum** time it takes for all the_ `n` _nodes to receive the signal_. If it is impossible for all the `n` nodes to receive the signal, return `-1`.

**Example 1:**

![](https://assets.leetcode.com/uploads/2019/05/23/931_example_1.png)

```bash
Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
```

**Example 2:**

```bash
Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
```

**Example 3:**

```bash
Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
```

**Constraints:**

* `1 <= k <= n <= 100`
* `1 <= times.length <= 6000`
* `times[i].length == 3`
* 1 <= u<sub>i</sub>, v<sub>i</sub> <= n
* u<sub>i</sub> != v<sub>i</sub>
* 0 <= w<sub>i</sub> <= 100
* All the pairs (u<sub>i</sub>, v<sub>i</sub>) are **unique**. (i.e., no multiple edges.)

## Hints/Notes

* 2023/09/05
* Dijkstra algorithm
* The dijkstra algorithm always try to find the shortest route from the root
* [0x3F's solution](https://leetcode.cn/problems/network-delay-time/solutions/2668220/liang-chong-dijkstra-xie-fa-fu-ti-dan-py-ooe8/)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<vector<int>>> graph;
    vector<int> distances;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        graph = vector<vector<vector<int>>>(n + 1, vector<vector<int>>());
        distances = vector<int>(n + 1, INT_MAX);
        buildGraph(times);
        pq.push({0, k});
        distances[k] = 0;

        while (!pq.empty()) {
            vector<int> point = pq.top();
            pq.pop();

            int distance = point[0];
            int to = point[1];
            // it's possible that one route with more time is pushed before
            // a better route, so the following condition would shortcut that
            if (distance > distances[to]) {
                continue;
            }

            for (auto edge : graph[to]) {
                int dis_next = edge[1] + distance;
                // we only add new path if there's better route
                if (distances[edge[0]] > dis_next) {
                    distances[edge[0]] = dis_next;
                    pq.push({dis_next, edge[0]});
                }
            }
        }

        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (distances[i] == INT_MAX) {
                return -1;
            }
            res = max(res, distances[i]);
        }

        return res;
    }

    void buildGraph(vector<vector<int>>& times) {
        for (auto time : times) {
            int from = time[0];
            int to = time[1];
            int dis = time[2];
            graph[from].push_back({to, dis});
        }
    }
};
```
