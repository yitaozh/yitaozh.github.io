---
title: 1353. Maximum Number of Events That Can Be Attended
categories: Leetcode
date: 2025-04-04 13:51:53
tags:
    - Array
    - Greedy
    - Sorting
    - Heap (Priority Queue)
---

[1353. Maximum Number of Events That Can Be Attended](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/description/)

## Description

You are given an array of `events` where `events[i] = [startDay<sub>i</sub>, endDay<sub>i</sub>]`. Every event `i` starts at `startDay<sub>i</sub>`<sub> </sub>and ends at `endDay<sub>i</sub>`.

You can attend an event `i` at any day `d` where `startTime<sub>i</sub> <= d <= endTime<sub>i</sub>`. You can only attend one event at any time `d`.

Return the maximum number of events you can attend.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/02/05/e1.png" style="width: 400px; height: 267px;">

```bash
Input: events = [[1,2],[2,3],[3,4]]
Output: 3
Explanation: You can attend all the three events.
One way to attend them all is as shown.
Attend the first event on day 1.
Attend the second event on day 2.
Attend the third event on day 3.
```

**Example 2:**

```bash
Input: events= [[1,2],[2,3],[3,4],[1,2]]
Output: 4
```

**Constraints:**

- `1 <= events.length <= 10^5`
- `events[i].length == 2`
- `1 <= startDay<sub>i</sub> <= endDay<sub>i</sub> <= 10^5`

## Hints/Notes

- 2025/03/29 Q2
- priority queue
- No solution from 0x3F or Leetcode

## Solution

Language: **C++**

```C++
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        ranges::sort(events);
        int start = events[0][0], n = events.size(), res = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        int idx = 0;
        while (idx != n || !pq.empty()) {
            if (pq.empty() && idx < n) {
                start = events[idx][0];
            }
            while (idx < n && events[idx][0] <= start) {
                pq.push(events[idx++][1]);
            }
            while (!pq.empty() && pq.top() < start) {
                pq.pop();
            }
            if (!pq.empty()) {
                start = start + 1;
                pq.pop();
                res++;
            }
        }
        return res;
    }
};
```
