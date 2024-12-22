---
title: 56. Merge Intervals
categories: Leetcode
date: 2024-12-22 01:25:58
tags:
    - Array
    - Sorting
---

[56. Merge Intervals](https://leetcode.com/problems/merge-intervals/description/?envType=problem-list-v2&envId=plakya4j)

## Description

Given an array of `intervals`where `intervals[i] = [start<sub>i</sub>, end<sub>i</sub>]`, merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

**Example 1:**

```bash
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
```

**Example 2:**

```bash
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
```

**Constraints:**

- `1 <= intervals.length <= 10^4`
- `intervals[i].length == 2`
- `0 <= start<sub>i</sub> <= end<sub>i</sub> <= 10^4`

## Hints/Notes

- 2024/12/21
- sort
- [0x3F's solution](https://leetcode.cn/problems/merge-intervals/solutions/2798138/jian-dan-zuo-fa-yi-ji-wei-shi-yao-yao-zh-f2b3/)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        ranges::sort(intervals);
        int n = intervals.size();
        for (int i = 0; i < n; ) {
            int start = intervals[i][0], end = intervals[i][1];
            i++;
            while (i < n && intervals[i][0] <= end) {
                end = max(end, intervals[i][1]);
                i++;
            }
            res.push_back({start, end});
        }
        return res;
    }
};
```
