---
title: 207. Course Schedule
categories: Leetcode
date: 2023-09-01 12:18:58
tags:
    - Depth-First Search
    - Breadth-First Search
    - Graph
    - Topological Sort
---

[207\. Course Schedule](https://leetcode.com/problems/course-schedule/)

## Description

Difficulty: **Medium**

Related Topics: [Depth-First Search](https://leetcode.com/tag/https://leetcode.com/tag/depth-first-search//), [Breadth-First Search](https://leetcode.com/tag/https://leetcode.com/tag/breadth-first-search//), [Graph](https://leetcode.com/tag/https://leetcode.com/tag/graph//), [Topological Sort](https://leetcode.com/tag/https://leetcode.com/tag/topological-sort//)

There are a total of `numCourses` courses you have to take, labeled from `0` to `numCourses - 1`. You are given an array `prerequisites` where prerequisites[i] = [a<sub>i</sub>, b<sub>i</sub>] indicates that you **must** take course b<sub>i</sub> first if you want to take course a<sub>i</sub>.

* For example, the pair `[0, 1]`, indicates that to take course `0` you have to first take course `1`.

Return `true` if you can finish all courses. Otherwise, return `false`.

**Example 1:**

```bash
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0\. So it is possible.
```

**Example 2:**

```bash
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1\. So it is impossible.
```

**Constraints:**

* `1 <= numCourses <= 2000`
* `0 <= prerequisites.length <= 5000`
* `prerequisites[i].length == 2`
* 0 <= a<sub>i</sub>, b<sub>i</sub> < numCourses
* All the pairs prerequisites[i] are **unique**.

## Hints/Nodes

* Traverse the graph and check if there's a cycle

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> visited;
    vector<bool> onPath;
    int can = true;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph = vector<vector<int>>(numCourses, vector<int>());
        visited = vector<bool>(numCourses, false);
        onPath = vector<bool>(numCourses, false);

        for (auto pair : prerequisites) {
            int from = pair[0], to = pair[1];
            graph[from].push_back(to);
        }

        for (int i = 0; i < numCourses; i++) {
            traverse(i);
        }
        return can;
    }

    void traverse(int node) {
        if (onPath[node]) {
            can = false;
        }

        if (!can || visited[node]) {
            return;
        }

        onPath[node] = true;
        visited[node] = true;

        for (int to : graph[node]) {
            traverse(to);
        }

        onPath[node] = false;
    }
};
```
