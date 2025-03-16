---
title: 2050. Parallel Courses III
categories: Leetcode
date: 2025-03-15 21:32:44
tags:
    - Array
    - Dynamic Programming
    - Graph
    - Topological Sort
---

[2050. Parallel Courses III](https://leetcode.com/problems/parallel-courses-iii/description/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Description

You are given an integer `n`, which indicates that there are `n` courses labeled from `1` to `n`. You are also given a 2D integer array `relations` where `relations[j] = [prevCourse<sub>j</sub>, nextCourse<sub>j</sub>]` denotes that course `prevCourse<sub>j</sub>` has to be completed **before**  course `nextCourse<sub>j</sub>` (prerequisite relationship). Furthermore, you are given a **0-indexed**  integer array `time` where `time[i]` denotes how many **months**  it takes to complete the `(i+1)^th` course.

You must find the **minimum**  number of months needed to complete all the courses following these rules:

- You may start taking a course at **any time**  if the prerequisites are met.
- **Any number of courses**  can be taken at the **same time** .

Return the **minimum**  number of months needed to complete all the courses.

**Note:**  The test cases are generated such that it is possible to complete every course (i.e., the graph is a directed acyclic graph).

**Example 1:**

**<img alt="" src="https://assets.leetcode.com/uploads/2021/10/07/ex1.png" style="width: 392px; height: 232px;">**

```bash
Input: n = 3, relations = [[1,3],[2,3]], time = [3,2,5]
Output: 8
Explanation: The figure above represents the given graph and the time required to complete each course.
We start course 1 and course 2 simultaneously at month 0.
Course 1 takes 3 months and course 2 takes 2 months to complete respectively.
Thus, the earliest time we can start course 3 is at month 3, and the total time required is 3 + 5 = 8 months.
```

**Example 2:**

**<img alt="" src="https://assets.leetcode.com/uploads/2021/10/07/ex2.png" style="width: 500px; height: 365px;">**

```bash
Input: n = 5, relations = [[1,5],[2,5],[3,5],[3,4],[4,5]], time = [1,2,3,4,5]
Output: 12
Explanation: The figure above represents the given graph and the time required to complete each course.
You can start courses 1, 2, and 3 at month 0.
You can complete them after 1, 2, and 3 months respectively.
Course 4 can be taken only after course 3 is completed, i.e., after 3 months. It is completed after 3 + 4 = 7 months.
Course 5 can be taken only after courses 1, 2, 3, and 4 have been completed, i.e., after max(1,2,3,7) = 7 months.
Thus, the minimum time needed to complete all the courses is 7 + 5 = 12 months.
```

**Constraints:**

- `1 <= n <= 5 * 10^4`
- `0 <= relations.length <= min(n * (n - 1) / 2, 5 * 10^4)`
- `relations[j].length == 2`
- 1 <= prevCourse<sub>j</sub>, nextCourse<sub>j</sub> <= n
- prevCourse<sub>j</sub> != nextCourse<sub>j</sub>
- All the pairs [prevCourse<sub>j</sub>, nextCourse<sub>j</sub>] are **unique** .
- `time.length == n`
- `1 <= time[i] <= 10^4`
- The given graph is a directed acyclic graph.

## Hints/Notes

- 2025/02/05 Q3
- topological sort
- [0x3F's solution](https://leetcode.cn/problems/parallel-courses-iii/solutions/1063928/tuo-bu-pai-xu-dong-tai-gui-hua-by-endles-dph6/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        // 1. build the prev -> next graph
        // 2. we need two vector of vectors: from and two
        // 3. the algorithm:
        //      1. enqueue all nodes with no pre-requiste
        //      2. from each of them, their value should be time[idx]
        //      3. check each of their to point, if the point doesn't have a pre-requisite, then enque int
        vector<vector<int>> from(n);
        vector<int> inDegree(n, 0);
        for (auto r : relations) {
            int u = r[0] - 1, v = r[1] - 1;
            from[u].push_back(v);
            inDegree[v]++;
        }
        // vector<int> minTime(n, );
        queue<int> courseProcessing;
        vector<int> maxTime(n, 0);
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                courseProcessing.push(i);
                maxTime[i] = time[i];
            }
        }
        int res = 0, curTime = 0;
        while (!courseProcessing.empty()) {
            int curCourse = courseProcessing.front();
            courseProcessing.pop();
            for (int v : from[curCourse]) {
                inDegree[v]--;
                maxTime[v] = max(maxTime[v], maxTime[curCourse] + time[v]);
                if (inDegree[v] == 0) {
                    courseProcessing.push(v);
                }
            }
        }
        return ranges::max(maxTime);

    }
};
```
