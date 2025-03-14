---
title: 1229. Meeting Scheduler
categories: Leetcode
date: 2025-03-14 13:04:56
tags:
    - Array
    - Two Pointers
    - Sorting
---

[1229. Meeting Scheduler](https://leetcode.com/problems/meeting-scheduler/description/)

## Description

Given the availability time slots arrays `slots1` and `slots2` of two people and a meeting duration `duration`, return the **earliest time slot**  that works for both of them and is of duration `duration`.

If there is no common time slot that satisfies the requirements, return an **empty array** .

The format of a time slot is an array of two elements `[start, end]` representing an inclusive time range from `start` to `end`.

It is guaranteed that no two availability slots of the same person intersect with each other. That is, for any two time slots `[start1, end1]` and `[start2, end2]` of the same person, either `start1 > end2` or `start2 > end1`.

**Example 1:**

```bash
Input: slots1 = [[10,50],[60,120],[140,210]], slots2 = [[0,15],[60,70]], duration = 8
Output: [60,68]
```

**Example 2:**

```bash
Input: slots1 = [[10,50],[60,120],[140,210]], slots2 = [[0,15],[60,70]], duration = 12
Output: []
```

**Constraints:**

- `1 <= slots1.length, slots2.length <= 10^4`
- `slots1[i].length, slots2[i].length == 2`
- `slots1[i][0] < slots1[i][1]`
- `slots2[i][0] < slots2[i][1]`
- `0 <= slots1[i][j], slots2[i][j] <= 10^9`
- `1 <= duration <= 10^6`

## Hints/Notes

- 2025/03/13 Q2
- two pointers
- [Leetcode solution](https://leetcode.com/problems/meeting-scheduler/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        int idx1 = 0, idx2 = 0, n1 = slots1.size(), n2 = slots2.size();
        ranges::sort(slots1);
        ranges::sort(slots2);
        while (idx1 < n1 && idx2 < n2) {
            if (slots1[idx1][1] <= slots2[idx2][0]) {
                idx1++;
                continue;
            }
            if (slots2[idx2][1] <= slots1[idx1][0]) {
                idx2++;
                continue;
            }
            int startTime = max(slots1[idx1][0], slots2[idx2][0]);
            int endTime = min(slots1[idx1][1], slots2[idx2][1]);
            if (startTime + duration <= endTime) {
                return {startTime, startTime + duration};
            }
            if (slots1[idx1][1] < slots2[idx2][1]) {
                idx1++;
            } else {
                idx2++;
            }
        }
        return {};
    }
};
```
