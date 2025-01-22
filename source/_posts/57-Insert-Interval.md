---
title: 57. Insert Interval
categories: Leetcode
date: 2024-12-22 22:49:33
tags:
---

[57. Insert Interval](https://leetcode.com/problems/insert-interval/description/?envType=problem-list-v2&envId=plakya4j)

## Description

You are given an array of non-overlapping intervals `intervals` where intervals[i] = [start<sub>i</sub>, end<sub>i</sub>] represent the start and the end of the `i^th` interval and `intervals` is sorted in ascending order by start<sub>i</sub>. You are also given an interval `newInterval = [start, end]` that represents the start and end of another interval.

Insert `newInterval` into `intervals` such that `intervals` is still sorted in ascending order by start<sub>i</sub> and `intervals` still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return `intervals` after the insertion.

**Note**  that you don't need to modify `intervals` in-place. You can make a new array and return it.

**Example 1:**

```bash
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
```

**Example 2:**

```bash
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
```

**Constraints:**

- `0 <= intervals.length <= 10^4`
- `intervals[i].length == 2`
- 0 <= start<sub>i</sub> <= end<sub>i</sub> <= 10^5
- `intervals` is sorted by start<sub>i</sub> in **ascending**  order.
- `newInterval.length == 2`
- `0 <= start <= end <= 10^5`

## Hints/Notes

- 2024/12/22
- binary search
- No solution from 0x3F

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) {
            return {newInterval};
        }
        int left = -1, right = intervals.size();
        // intervals[left][1] < newInterval[0]
        // intervals[right][1] > newInterval[0]
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            if (newInterval[0] <= intervals[mid][1]) {
                right = mid;
            } else {
                left = mid;
            }
        }
        int start = right;
        if (start == intervals.size()) {
            intervals.push_back(newInterval);
            return intervals;
        }
        left = -1, right = intervals.size();
        // intervals[left][0] < newInterval[1]
        // intervals[right][0] > newInterval[1]
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            if (newInterval[1] >= intervals[mid][0]) {
                left = mid;
            } else {
                right = mid;
            }
        }
        int end = left;
        if (end == -1) {
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        vector<vector<int>> res;
        for (int i = 0; i < start; i++) {
            res.push_back(intervals[i]);
        }
        res.push_back({min(newInterval[0], intervals[start][0]), max(newInterval[1], intervals[end][1])});
        for (int i = right; i < intervals.size(); i++) {
            res.push_back(intervals[i]);
        }
        return res;
    }
};
```
