---
title: 1834. Single-Threaded CPU
categories: Leetcode
date: 2023-11-07 00:01:44
tags:
    - Array
    - Sorting
    - Heap (Priority Queue)
---

[1834\. Single-Threaded CPU](https://leetcode.com/problems/single-threaded-cpu/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Sorting](https://leetcode.com/tag/https://leetcode.com/tag/sorting//), [Heap (Priority Queue)](https://leetcode.com/tag/https://leetcode.com/tag/heap-priority-queue//)

You are given `n`​​​​​​ tasks labeled from `0` to `n - 1` represented by a 2D integer array `tasks`, where tasks[i] = [enqueueTime<sub>i</sub>, processingTime<sub>i</sub>] means that the i<sup>​​​​​​th</sup>​​​​ task will be available to process at enqueueTime<sub>i</sub> and will take processingTime<sub>i</sub>to finish processing.

You have a single-threaded CPU that can process **at most one** task at a time and will act in the following way:

* If the CPU is idle and there are no available tasks to process, the CPU remains idle.
* If the CPU is idle and there are available tasks, the CPU will choose the one with the **shortest processing time**. If multiple tasks have the same shortest processing time, it will choose the task with the smallest index.
* Once a task is started, the CPU will **process the entire task** without stopping.
* The CPU can finish a task then start a new one instantly.

Return _the order in which the CPU will process the tasks._

**Example 1:**

```bash
Input: tasks = [[1,2],[2,4],[3,2],[4,1]]
Output: [0,2,3,1]
Explanation: The events go as follows:
- At time = 1, task 0 is available to process. Available tasks = {0}.
- Also at time = 1, the idle CPU starts processing task 0\. Available tasks = {}.
- At time = 2, task 1 is available to process. Available tasks = {1}.
- At time = 3, task 2 is available to process. Available tasks = {1, 2}.
- Also at time = 3, the CPU finishes task 0 and starts processing task 2 as it is the shortest. Available tasks = {1}.
- At time = 4, task 3 is available to process. Available tasks = {1, 3}.
- At time = 5, the CPU finishes task 2 and starts processing task 3 as it is the shortest. Available tasks = {1}.
- At time = 6, the CPU finishes task 3 and starts processing task 1\. Available tasks = {}.
- At time = 10, the CPU finishes task 1 and becomes idle.
```

**Example 2:**

```bash
Input: tasks = [[7,10],[7,12],[7,5],[7,4],[7,2]]
Output: [4,3,2,0,1]
Explanation: The events go as follows:
- At time = 7, all the tasks become available. Available tasks = {0,1,2,3,4}.
- Also at time = 7, the idle CPU starts processing task 4\. Available tasks = {0,1,2,3}.
- At time = 9, the CPU finishes task 4 and starts processing task 3\. Available tasks = {0,1,2}.
- At time = 13, the CPU finishes task 3 and starts processing task 2\. Available tasks = {0,1}.
- At time = 18, the CPU finishes task 2 and starts processing task 0\. Available tasks = {1}.
- At time = 28, the CPU finishes task 0 and starts processing task 1\. Available tasks = {}.
- At time = 40, the CPU finishes task 1 and becomes idle.
```

**Constraints:**

* `tasks.length == n`
* 1 <= n <= 10<sup>5</sup>
* 1 <= enqueueTime<sub>i</sub>, processingTime<sub>i</sub> <= 10<sup>9</sup>

## Hints/Notes

* Sort first, then use priority queue

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> triples;
        for (int i = 0; i < tasks.size(); i++) {
            triples.push_back({tasks[i][0], tasks[i][1], i});
        }
        sort(triples.begin(), triples.end());
        int i = 0;
        long cur = 0;
        vector<int> res;
        while (res.size() < tasks.size()) {
            if (!pq.empty()) {
                auto pair = pq.top();
                pq.pop();
                res.push_back(pair[1]);
                cur = cur + pair[0];
            } else {
                cur = triples[i][0];
            }
            for (; i < triples.size() && triples[i][0] <= cur; i++) {
                pq.push({triples[i][1], triples[i][2]});
            }
        }
        return res;
    }
};
```
