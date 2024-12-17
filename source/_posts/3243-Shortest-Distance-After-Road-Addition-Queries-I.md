---
title: 3243. Shortest Distance After Road Addition Queries I
categories: Leetcode
date: 2024-08-14 23:59:02
tags:
    - Array
    - Breadth-First Search
    - Graph
---

[3243. Shortest Distance After Road Addition Queries I](https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i/description/)

## Description

You are given an integer `n` and a 2D integer array `queries`.

There are `n` cities numbered from `0` to `n - 1`. Initially, there is a **unidirectional**  road from city `i` to city `i + 1` for all `0 <= i < n - 1`.

queries[i] = [u<sub>i</sub>, v<sub>i</sub>] represents the addition of a new **unidirectional**  road from city u<sub>i</sub> to city v<sub>i</sub>. After each query, you need to find the **length**  of the **shortest path**  from city `0` to city `n - 1`.

Return an array `answer` where for each `i` in the range `[0, queries.length - 1]`, `answer[i]` is the length of the shortest path from city `0` to city `n - 1` after processing the **first** `i + 1` queries.

**Example 1:**

```bash
Input: n = 5, queries = [[2,4],[0,2],[0,4]]

Output: [3,2,1]
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/06/28/image8.jpg" style="width: 350px; height: 60px;">

After the addition of the road from 2 to 4, the length of the shortest path from 0 to 4 is 3.

<img alt="" src="https://assets.leetcode.com/uploads/2024/06/28/image9.jpg" style="width: 350px; height: 60px;">

After the addition of the road from 0 to 2, the length of the shortest path from 0 to 4 is 2.

<img alt="" src="https://assets.leetcode.com/uploads/2024/06/28/image10.jpg" style="width: 350px; height: 96px;">

After the addition of the road from 0 to 4, the length of the shortest path from 0 to 4 is 1.

**Example 2:**

```bash
Input: n = 4, queries = [[0,3],[0,2]]

Output: [1,1]
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/06/28/image11.jpg" style="width: 300px; height: 70px;">

After the addition of the road from 0 to 3, the length of the shortest path from 0 to 3 is 1.

<img alt="" src="https://assets.leetcode.com/uploads/2024/06/28/image12.jpg" style="width: 300px; height: 70px;">

After the addition of the road from 0 to 2, the length of the shortest path remains 1.

**Constraints:**

- `3 <= n <= 500`
- `1 <= queries.length <= 500`
- `queries[i].length == 2`
- `0 <= queries[i][0] < queries[i][1] < n`
- `1 < queries[i][1] - queries[i][0]`
- There are no repeated roads among the queries.

## Hints/Notes

- 2024/08/06
- BFS for each query
- [0x3F's solution](https://leetcode.cn/problems/shortest-distance-after-road-addition-queries-i/solutions/2869215/liang-chong-fang-fa-bfs-dppythonjavacgo-mgunf/)(checked)
- Weekly Contest 409

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> visited;
    queue<int> q;

    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>>& queries) {
        graph.resize(n, vector<int>());
        for (int i = 0; i < n; i++) {
            if (i < n - 1) {
                graph[i].push_back(i + 1);
            }
        }
        vector<int> res;
        for (auto& query : queries) {
            int u = query[0];
            int v = query[1];
            graph[u].push_back(v);
            visited = vector<bool>(n, false);
            q = queue<int>();
            cut(0);
            int cur = 0;
            bool finished = false;
            while (!q.empty()) {
                cur++;
                int size = q.size();
                for (int i = 0; i < size; i++) {
                    int u = q.front();
                    q.pop();
                    if (u == n - 1) {
                        res.push_back(cur);
                        finished = true;
                        break;
                    }
                    cut(u);
                }
                if (finished) {
                    break;
                }
            }
        }
        return res;
    }

    void cut(int u) {
        for (int v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
};
```
