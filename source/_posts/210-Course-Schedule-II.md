---
title: 210. Course Schedule II
categories: Leetcode
date: 2023-09-01 12:43:27
tags:
---

# [210\. Course Schedule II](https://leetcode.com/problems/course-schedule-ii/)

## Description

Difficulty: **Medium**

Related Topics: [Depth-First Search](https://leetcode.com/tag/https://leetcode.com/tag/depth-first-search//), [Breadth-First Search](https://leetcode.com/tag/https://leetcode.com/tag/breadth-first-search//), [Graph](https://leetcode.com/tag/https://leetcode.com/tag/graph//), [Topological Sort](https://leetcode.com/tag/https://leetcode.com/tag/topological-sort//)

There are a total of `numCourses` courses you have to take, labeled from `0` to `numCourses - 1`. You are given an array `prerequisites` where prerequisites[i] = [a<sub>i</sub>, b<sub>i</sub>] indicates that you **must** take course b<sub>i</sub> first if you want to take course a<sub>i</sub>.

* For example, the pair `[0, 1]`, indicates that to take course `0` you have to first take course `1`.

Return _the ordering of courses you should take to finish all courses_. If there are many valid answers, return **any** of them. If it is impossible to finish all courses, return **an empty array**.

**Example 1:**

```bash
Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0\. So the correct course order is [0,1].
```

**Example 2:**

```bash
Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2\. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
```

**Example 3:**

```bash
Input: numCourses = 1, prerequisites = []
Output: [0]
```

**Constraints:**

* `1 <= numCourses <= 2000`
* `0 <= prerequisites.length <= numCourses * (numCourses - 1)`
* `prerequisites[i].length == 2`
* 0 <= a<sub>i</sub>, b<sub>i</sub> < numCourses
* a<sub>i</sub> != b<sub>i</sub>
* All the pairs [a<sub>i</sub>, b<sub>i</sub>] are **distinct**.

## Hints/Notes

* Use postOrder to record the route
* Reverse the postOrder to get the topology

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> visited;
    vector<bool> onPath;
    bool can = true;
    vector<int> postOrder;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        graph = vector<vector<int>>(numCourses, vector<int>());
        visited = vector<bool>(numCourses, false);
        onPath = vector<bool>(numCourses, false);

        for (auto pair : prerequisites) {
            int from = pair[1], to = pair[0];
            graph[from].push_back(to);
        }

        for (int i = 0; i < numCourses; i++) {
            traverse(i);
        }

        if (!can) {
            return vector<int>();
        }

        reverse(postOrder.begin(), postOrder.end());

        return postOrder;
    }

    void traverse(int node) {
        if (onPath[node]) {
            can = false;
        }

        if (onPath[node] || visited[node]) {
            return;
        }

        visited[node] = true;
        onPath[node] = true;

        for (int i : graph[node]) {
            traverse(i);
        }

        postOrder.push_back(node);
        onPath[node] = false;
    }
};
```
