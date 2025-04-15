---
title: 1857. Largest Color Value in a Directed Graph
categories: Leetcode
date: 2025-04-15 01:21:52
tags:
    - Hash Table
    - Dynamic Programming
    - Graph
    - Topological Sort
    - Memoization
    - Counting
---

[1857. Largest Color Value in a Directed Graph](https://leetcode.com/problems/largest-color-value-in-a-directed-graph/description/?envType=company&envId=linkedin&favoriteSlug=linkedin-six-months)

## Description

There is a **directed graph**  of `n` colored nodes and `m` edges. The nodes are numbered from `0` to `n - 1`.

You are given a string `colors` where `colors[i]` is a lowercase English letter representing the **color**  of the `i^th` node in this graph (**0-indexed** ). You are also given a 2D array `edges` where edges[j] = [a<sub>j</sub>, b<sub>j</sub>] indicates that there is a **directed edge**  from node a<sub>j</sub> to node b<sub>j</sub>.

A valid **path**  in the graph is a sequence of nodes x<sub>1</sub> -> x<sub>2</sub> -> x<sub>3</sub> -> ... -> x<sub>k</sub> such that there is a directed edge from x<sub>i</sub> to x<sub>i+1</sub> for every `1 <= i < k`. The **color value**  of the path is the number of nodes that are colored the **most frequently**  occurring color along that path.

Return the **largest color value**  of any valid path in the given graph, or `-1` if the graph contains a cycle.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/04/21/leet1.png" style="width: 400px; height: 182px;">

```bash
Input: colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
Output: 3
Explanation: The path 0 -> 2 -> 3 -> 4 contains 3 nodes that are colored `"a" (red in the above image)`.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/04/21/leet2.png" style="width: 85px; height: 85px;">

```bash
Input: colors = "a", edges = [[0,0]]
Output: -1
Explanation: There is a cycle from 0 to 0.
```

**Constraints:**

- `n == colors.length`
- `m == edges.length`
- `1 <= n <= 10^5`
- `0 <= m <= 10^5`
- `colors` consists of lowercase English letters.
- 0 <= a<sub>j</sub>, b<sub>j</sub>< n

## Hints/Notes

- 2025/04/13 Q2
- topological sort
- [Leetcode solution](https://leetcode.com/problems/largest-color-value-in-a-directed-graph/editorial/?envType=company&envId=linkedin&favoriteSlug=linkedin-six-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> graph(n);
        vector<int> indegree(n);

        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }

        vector<vector<int>> count(n, vector<int>(26));
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        int res = 0, visited = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count[node][colors[node] - 'a']++;
            res = max(res, count[node][colors[node] - 'a']);
            visited++;

            for (auto& v : graph[node]) {
                for (int i = 0; i < 26; i++) {
                    count[v][i] = max(count[v][i], count[node][i]);
                }
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        return visited == n ? res : -1;
    }
};
```
