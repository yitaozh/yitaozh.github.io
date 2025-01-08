---
title: 435. Non-overlapping Intervals
categories: Leetcode
date: 2025-01-08 17:23:06
tags:
    - Array
    - Dynamic Programming
    - Greedy
    - Sorting
---

[435. Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/description/?envType=problem-list-v2&envId=plakya4j)

## Description

Given an array of intervals `intervals` where intervals[i] = [start<sub>i</sub>, end<sub>i</sub>], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

**Note**  that intervals which only touch at a point are **non-overlapping** . For example, `[1, 2]` and `[2, 3]` are non-overlapping.

**Example 1:**

```bash
Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
```

**Example 2:**

```bash
Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
```

**Example 3:**

```bash
Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
```

**Constraints:**

- `1 <= intervals.length <= 10^5`
- `intervals[i].length == 2`
- -5 \* 10^4 <= start<sub>i</sub> < end<sub>i</sub> <= 5 \* 10^4

## Hints/Notes

- 2025/01/08
- greedy
- No solution from 0x3F

## Solution

Language: **C++**

```C++
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        auto cmp = [](vector<int>& lhs, vector<int>& rhs) {
            return lhs[1] < rhs[1];
        };
        ranges::sort(intervals, cmp);
        int end = INT_MIN, res = 0, n = intervals.size();
        for (int i = 0; i < n; i++) {
            if (intervals[i][0] < end) {
                res++;
            } else {
                end = intervals[i][1];
            }
        }
        return res;
    }
};
```
