---
title: 759. Employee Free Time
categories: Leetcode
date: 2025-03-29 12:29:42
tags:
    - Array
    - Sorting
    - Heap (Priority Queue)
---

[759. Employee Free Time](https://leetcode.com/problems/employee-free-time/description/?envType=company&envId=apple&favoriteSlug=apple-six-months)

## Description

We are given a list `schedule` of employees, which represents the working time for each employee.

Each employee has a list of non-overlapping `Intervals`, and these intervals are in sorted order.

Return the list of finite intervals representing <b>common, positive-length free time</b> for <i>all</i> employees, also in sorted order.

(Even though we are representing `Intervals` in the form `[x, y]`, the objects inside are `Intervals`, not lists or arrays. For example, `schedule[0][0].start = 1`, `schedule[0][0].end = 2`, and `schedule[0][0][0]` is not defined). Also, we wouldn't include intervals like [5, 5] in our answer, as they have zero length.

**Example 1:**

```bash
Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
Output: [[3,4]]
Explanation: There are a total of three employees, and all common
free time intervals would be [-inf, 1], [3, 4], [10, inf].
We discard any intervals that contain inf as they aren't finite.
```

**Example 2:**

```bash
Input: schedule = [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
Output: [[5,6],[7,9]]
```

**Constraints:**

- `1 <= schedule.length , schedule[i].length <= 50`
- `0 <= schedule[i].start < schedule[i].end <= 10^8`

## Hints/Notes

- 2025/03/21 Q3
- sweep line
- [Leetcode solution](https://leetcode.com/problems/employee-free-time/editorial/)

## Solution

Language: **C++**

```C++
/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        map<int, int> diff;
        for (auto s : schedule) {
            for (auto i : s) {
                int start = i.start, end = i.end;
                diff[start]++;
                diff[end]--;
            }
        }
        int prevIdx = INT_MAX, cur = 0;
        vector<Interval> res;
        for (auto [k, v] : diff) {
            if (k > prevIdx && cur == 0) {
                res.emplace_back(prevIdx, k);
            }
            cur += v;
            prevIdx = k;
        }
        return res;
    }
};
```
