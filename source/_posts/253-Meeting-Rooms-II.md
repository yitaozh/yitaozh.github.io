---
title: 253. Meeting Rooms II
categories: Leetcode
date: 2025-01-07 02:14:00
tags:
    - Array
    - Two Pointers
    - Greedy
    - Sorting
    - Heap (Priority Queue)
    - Prefix Sum
---

[253. Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/description/?envType=problem-list-v2&envId=plakya4j)

## Description

Given an array of meeting time intervals `intervals` where intervals[i] = [start<sub>i</sub>, end<sub>i</sub>], return the minimum number of conference rooms required.

**Example 1:**

```bash
Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2
```

**Example 2:**

```bash
Input: intervals = [[7,10],[2,4]]
Output: 1
```

**Constraints:**

- `1 <=intervals.length <= 10^4`
- 0 <= start<sub>i</sub> < end<sub>i</sub> <= 10^6

## Hints/Notes

- 2025/01/03
- diff array
- premium

## Solution

Language: **C++**

```C++
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> diff;
        for (auto& i : intervals) {
            int start = i[0], end = i[1];
            diff[start]++;
            diff[end]--;
        }
        int cur = 0, sum = 0;
        for (auto& [_, v] : diff) {
            cur += v;
            sum = max(cur, sum);
        }
        return sum;
    }
};
```
