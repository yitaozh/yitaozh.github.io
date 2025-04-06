---
title: 1136. Parallel Courses
categories: Leetcode
date: 2025-04-05 22:33:31
tags:
    - Graph
    - Topological Sort
---

[1136. Parallel Courses](https://leetcode.com/problems/parallel-courses/description/?envType=company&envId=tiktok&favoriteSlug=tiktok-six-months)

## Description

You are given an integer `n`, which indicates that there are `n` courses labeled from `1` to `n`. You are also given an array `relations` where relations[i] = [prevCourse<sub>i</sub>, nextCourse<sub>i</sub>], representing a prerequisite relationship between course prevCourse<sub>i</sub> and course nextCourse<sub>i</sub>: course prevCourse<sub>i</sub> has to be taken before course nextCourse<sub>i</sub>.

In one semester, you can take **any number**  of courses as long as you have taken all the prerequisites in the **previous**  semester for the courses you are taking.

Return the **minimum**  number of semesters needed to take all courses. If there is no way to take all the courses, return `-1`.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/02/24/course1graph.jpg" style="width: 222px; height: 222px;">

```bash
Input: n = 3, relations = [[1,3],[2,3]]
Output: 2
Explanation: The figure above represents the given graph.
In the first semester, you can take courses 1 and 2.
In the second semester, you can take course 3.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/02/24/course2graph.jpg" style="width: 222px; height: 222px;">

```bash
Input: n = 3, relations = [[1,2],[2,3],[3,1]]
Output: -1
Explanation: No course can be studied because they are prerequisites of each other.
```

**Constraints:**

- `1 <= n <= 5000`
- `1 <= relations.length <= 5000`
- `relations[i].length == 2`
- `1 <= prevCourse<sub>i</sub>, nextCourse<sub>i</sub> <= n`
- `prevCourse<sub>i</sub> != nextCourse<sub>i</sub>`
- All the pairs `[prevCourse<sub>i</sub>, nextCourse<sub>i</sub>]` are **unique** .

## Hints/Notes

- 2025/04/04 Q2
- topological sort
- [Leetcode solution](https://leetcode.com/problems/parallel-courses/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<int> indegree(n + 1, 0);
        vector<vector<int>> graph(n + 1);
        for (auto r : relations) {
            int from = r[0], to = r[1];
            graph[from].push_back(to);
            indegree[to]++;
        }
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        int courseTaken = 0, semester = 0;
        while (!q.empty()) {
            int size = q.size();
            courseTaken += size;
            for (int i = 0; i < size; i++) {
                int from = q.front();
                q.pop();
                for (auto to : graph[from]) {
                    indegree[to]--;
                    if (indegree[to] == 0) {
                        q.push(to);
                    }
                }
            }
            semester++;
        }
        return courseTaken == n ? semester : -1;
    }
};
```
