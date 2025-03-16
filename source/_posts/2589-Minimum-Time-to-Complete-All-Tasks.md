---
title: 2589. Minimum Time to Complete All Tasks
categories: Leetcode
date: 2025-03-16 14:44:41
tags:
    - Array
    - Binary Search
    - Stack
    - Greedy
    - Sorting
---

[2589. Minimum Time to Complete All Tasks](https://leetcode.com/problems/minimum-time-to-complete-all-tasks/description/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Description

There is a computer that can run an unlimited number of tasks **at the same time** . You are given a 2D integer array `tasks` where tasks[i] = [start<sub>i</sub>, end<sub>i</sub>, duration<sub>i</sub>] indicates that the `i^th` task should run for a total of duration<sub>i</sub> seconds (not necessarily continuous) within the **inclusive**  time range [start<sub>i</sub>, end<sub>i</sub>].

You may turn on the computer only when it needs to run a task. You can also turn it off if it is idle.

Return the minimum time during which the computer should be turned on to complete all tasks.

**Example 1:**

```bash
Input: tasks = [[2,3,1],[4,5,1],[1,5,2]]
Output: 2
Explanation:
- The first task can be run in the inclusive time range [2, 2].
- The second task can be run in the inclusive time range [5, 5].
- The third task can be run in the two inclusive time ranges [2, 2] and [5, 5].
The computer will be on for a total of 2 seconds.
```

**Example 2:**

```bash
Input: tasks = [[1,3,2],[2,5,3],[5,6,2]]
Output: 4
Explanation:
- The first task can be run in the inclusive time range [2, 3].
- The second task can be run in the inclusive time ranges [2, 3] and [5, 5].
- The third task can be run in the two inclusive time range [5, 6].
The computer will be on for a total of 4 seconds.
```

**Constraints:**

- `1 <= tasks.length <= 2000`
- `tasks[i].length == 3`
- 1 <= start<sub>i</sub>, end<sub>i</sub> <= 2000
- 1 <= duration<sub>i</sub> <= end<sub>i</sub> - start<sub>i</sub> + 1

## Hints/Notes

- 2025/02/07 Q2
- sort
- [0x3F's solution](https://leetcode.cn/problems/minimum-time-to-complete-all-tasks/solutions/2163130/tan-xin-pythonjavacgo-by-endlesscheng-w3k3/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        // the goal: for one task, wait until we can gather as many tasks as possible
        // to run together
        auto cmp = [](vector<int> lhs, vector<int> rhs) {
            return lhs[1] < rhs[1];
        };
        ranges::sort(tasks, cmp);
        vector<int> time(tasks.back()[1] + 1, 0);
        int res = 0, n = tasks.size();
        for (int i = 0; i < n; i++) {
            int start = tasks[i][0], end = tasks[i][1], duration = tasks[i][2];
            int used = reduce(time.begin() + start, time.begin() + end + 1);
            int need = max(0, duration - used);
            for (int j = end; need > 0; j--) {
                if (!time[j]) {
                    need--;
                    time[j] = 1;
                    res++;
                }
            }
        }
        return res;
    }
};
```
