---
title: 986. Interval List Intersections
categories: Leetcode
date: 2025-01-17 12:23:13
tags:
    - Array
    - Two Pointers
    - Line Sweep
---

[986. Interval List Intersections](https://leetcode.com/problems/interval-list-intersections/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

You are given two lists of closed intervals, `firstList` and `secondList`, where firstList[i] = [start<sub>i</sub>, end<sub>i</sub>] and secondList[j] = [start<sub>j</sub>, end<sub>j</sub>]. Each list of intervals is pairwise **disjoint**  and in **sorted order** .

Return the intersection of these two interval lists.

A **closed interval**  `[a, b]` (with `a <= b`) denotes the set of real numbers `x` with `a <= x <= b`.

The **intersection**  of two closed intervals is a set of real numbers that are either empty or represented as a closed interval. For example, the intersection of `[1, 3]` and `[2, 4]` is `[2, 3]`.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2019/01/30/interval1.png" style="width: 700px; height: 194px;">

```bash
Input: firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
```

**Example 2:**

```bash
Input: firstList = [[1,3],[5,9]], secondList = []
Output: []
```

**Constraints:**

- `0 <= firstList.length, secondList.length <= 1000`
- `firstList.length + secondList.length >= 1`
- 0 <= start<sub>i</sub> < end<sub>i</sub> <= 10^9
- end<sub>i</sub> < start<sub>i+1</sub>
- 0 <= start<sub>j</sub> < end<sub>j</sub> <= 10^9
- end<sub>j</sub> < start<sub>j+1</sub>

## Hints/Notes

- 2025/01/17
- [Leetcode solution](https://leetcode.com/problems/interval-list-intersections/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i = 0, j = 0, m = firstList.size(), n = secondList.size();
        vector<vector<int>> res;
        while (i < m && j < n) {
            if (firstList[i][1] < secondList[j][0]) {
                i++;
                continue;
            }
            if (secondList[j][1] < firstList[i][0]) {
                j++;
                continue;
            }
            int start = max(firstList[i][0], secondList[j][0]);
            int end = min(firstList[i][1], secondList[j][1]);
            res.push_back({start, end});
            if (firstList[i][1] < secondList[j][1]) {
                i++;
            } else {
                j++;
            }
        }
        return res;
    }
};
```
