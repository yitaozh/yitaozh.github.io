---
title: 252. Meeting Rooms
categories: Leetcode
date: 2025-01-07 02:12:01
tags:
    - Array
    - Sorting
---

[252. Meeting Rooms](https://leetcode.com/problems/meeting-rooms/description/?envType=problem-list-v2&envId=plakya4j)

## Description

Given an array of meeting time `intervals`where intervals[i] = [start<sub>i</sub>, end<sub>i</sub>], determine if a person could attend all meetings.

**Example 1:**

```bash
Input: intervals = [[0,30],[5,10],[15,20]]
Output: false
```

**Example 2:**

```bash
Input: intervals = [[7,10],[2,4]]
Output: true
```

**Constraints:**

- `0 <= intervals.length <= 10^4`
- `intervals[i].length == 2`
- 0 <= start<sub>i</sub> <end<sub>i</sub> <= 10^6

## Hints/Notes

- 2025/01/03
- sort
- premium

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        ranges::sort(intervals);
        int end = -1;
        for (auto interval : intervals) {
            if (interval[0] < end) {
                return false;
            }
            end = max(end, interval[1]);
        }
        return true;
    }
};
```
