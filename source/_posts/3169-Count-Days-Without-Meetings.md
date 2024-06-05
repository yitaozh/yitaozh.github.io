---
title: 3169. Count Days Without Meetings
categories: Leetcode
date: 2024-06-05 01:27:09
tags:
    - Array
    - Sorting
---

[3169. Count Days Without Meetings](https://leetcode.com/problems/count-days-without-meetings/description/)

## Description

You are given a positive integer `days` representing the total number of days an employee is available for work (starting from day 1). You are also given a 2D array `meetings` of size `n` where, `meetings[i] = [start_i, end_i]` represents the starting and ending days of meeting `i` (inclusive).

Return the count of days when the employee is available for work but no meetings are scheduled.

**Note:** The meetings may overlap.

**Example 1:**

```bash
Input: days = 10, meetings = [[5,7],[1,3],[9,10]]

Output: 2

Explanation:

There is no meeting scheduled on the 4^th and 8^th days.
```

**Example 2:**

```bash
Input: days = 5, meetings = [[2,4],[1,3]]

Output: 1

Explanation:

There is no meeting scheduled on the 5^th day.
```

**Example 3:**

```bash
Input: days = 6, meetings = [[1,6]]

Output: 0

Explanation:

Meetings are scheduled for all working days.
```

**Constraints:**

- `1 <= days <= 10^9`
- `1 <= meetings.length <= 10^5`
- `meetings[i].length == 2`
- `1 <= meetings[i][0] <= meetings[i][1] <= days`

## Hints/Notes

- Weekly Contest 400

## Solution

Language: **C++**

```C++
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        auto cmp = [](vector<int>& lhs, vector<int>& rhs) {
            if (lhs[0] == rhs[0]) {
                return lhs[1] > rhs[1];
            }
            return lhs[0] < rhs[0];
        };
        sort(meetings.begin(), meetings.end(), cmp);
        int cur = 0, res = 0;
        for (auto& meeting : meetings) {
            if (meeting[1] <= cur) {
                continue;
            } else if (meeting[0] <= cur) {
                cur = meeting[1];
            } else {
                res += meeting[0] - cur - 1;
                cur = meeting[1];
            }
        }
        if (cur < days) {
            res += days - cur;
        }
        return res;
    }
};
```
