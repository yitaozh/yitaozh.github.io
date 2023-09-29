---
title: 797. All Paths From Source to Target
categories: Leetcode
date: 2023-08-31 23:04:08
tags:
    - Backtracking
    - Depth-First Search
    - Breadth-First Search
    - Graph
---

# [797\. All Paths From Source to Target](https://leetcode.com/problems/all-paths-from-source-to-target/)

## Description

Difficulty: **Medium**

Related Topics: [Backtracking](https://leetcode.com/tag/https://leetcode.com/tag/backtracking//), [Depth-First Search](https://leetcode.com/tag/https://leetcode.com/tag/depth-first-search//), [Breadth-First Search](https://leetcode.com/tag/https://leetcode.com/tag/breadth-first-search//), [Graph](https://leetcode.com/tag/https://leetcode.com/tag/graph//)

Given a directed acyclic graph (**DAG**) of `n` nodes labeled from `0` to `n - 1`, find all possible paths from node `0` to node `n - 1` and return them in **any order**.

The graph is given as follows: `graph[i]` is a list of all nodes you can visit from node `i` (i.e., there is a directed edge from node `i` to node `graph[i][j]`).

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/09/28/all_1.jpg)

```bash
Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2020/09/28/all_2.jpg)

```bash
Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
```

**Constraints:**

* `n == graph.length`
* `2 <= n <= 15`
* `0 <= graph[i][j] < n`
* `graph[i][j] != i` (i.e., there will be no self-loops).
* All the elements of `graph[i]` are **unique**.
* The input graph is **guaranteed** to be a **DAG**.

## Hints/Notes

* Traverse the graph, add node to the path when entering and remove the node from the path when exiting
* DAG, i.e. directed acyclic graph, so there's no cycle

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        traverse(graph, 0, path);
        return res;
    }

    void traverse(vector<vector<int>>& graph, int n, vector<int>& path) {
        path.push_back(n);
        
        if (n == graph.size() - 1) {
            res.push_back(path);
        }

        for (int num : graph[n]) {
            traverse(graph, num, path);
        }    

        path.pop_back();
    }
};
```
