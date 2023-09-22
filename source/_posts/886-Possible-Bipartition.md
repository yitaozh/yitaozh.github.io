---
title: 886. Possible Bipartition
categories: Leetcode
date: 2023-09-02 23:19:19
tags:
    - Depth-First Search
    - Breadth-First Search
    - Union Find
    - Graph
---

# [886\. Possible Bipartition](https://leetcode.com/problems/possible-bipartition/)

## Description

Difficulty: **Medium**

Related Topics: [Depth-First Search](https://leetcode.com/tag/https://leetcode.com/tag/depth-first-search//), [Breadth-First Search](https://leetcode.com/tag/https://leetcode.com/tag/breadth-first-search//), [Union Find](https://leetcode.com/tag/https://leetcode.com/tag/union-find//), [Graph](https://leetcode.com/tag/https://leetcode.com/tag/graph//)

We want to split a group of `n` people (labeled from `1` to `n`) into two groups of **any size**. Each person may dislike some other people, and they should not go into the same group.

Given the integer `n` and the array `dislikes` where dislikes[i] = [a<sub>i</sub>, b<sub>i</sub>] indicates that the person labeled a<sub>i</sub> does not like the person labeled b<sub>i</sub>, return `true` _if it is possible to split everyone into two groups in this way_.

**Example 1:**

```bash
Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: The first group has [1,4], and the second group has [2,3].
```

**Example 2:**

```bash
Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Explanation: We need at least 3 groups to divide them. We cannot put them in two groups.
```

**Constraints:**

* `1 <= n <= 2000`
* 0 <= dislikes.length <= 10<sup>4</sup>
* `dislikes[i].length == 2`
* 1 <= a<sub>i</sub> < b<sub>i</sub> <= n
* All the pairs of `dislikes` are **unique**.

## Hints/Nodes

* Build the map, then it's find bipartition of the graph
* Use two vectors: visited and color
* Use a global boolean ok for fast return

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> visited;
    vector<bool> color;
    int ok = true;

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        graph = vector<vector<int>>(n + 1, vector<int>());
        visited = vector<bool>(n + 1, false);
        color = vector<bool>(n + 1, false);

        buildGraph(dislikes);

        for (int i = 1; i <= n; i++) {
            traverse(i);
        }

        return ok;
    }

    void buildGraph(vector<vector<int>>& dislikes) {
        for (auto pair : dislikes) {
            int n1 = pair[0];
            int n2 = pair[1];
            graph[n1].push_back(n2);
            graph[n2].push_back(n1);
        }
    }

    void traverse(int node) {
        if (!ok) return;
        visited[node] = true;

        for (int to : graph[node]) {
            if (visited[to]) {
                if (color[to] == color[node]) {
                    ok = false;
                    return;
                }
            } else {
                color[to] = !color[node];
                traverse(to);
            }
        }
    }
};
```
