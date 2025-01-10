---
title: 3394. Check if Grid can be Cut into Sections
categories: Leetcode
date: 2025-01-10 00:55:05
tags:
    - Array
    - Sorting
---

[3394. Check if Grid can be Cut into Sections](https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/description/)

## Description

You are given an integer `n` representing the dimensions of an `n x n` grid, with the origin at the bottom-left corner of the grid. You are also given a 2D array of coordinates `rectangles`, where `rectangles[i]` is in the form [start<sub>x</sub>, start<sub>y</sub>, end<sub>x</sub>, end<sub>y</sub>], representing a rectangle on the grid. Each rectangle is defined as follows:

- (start<sub>x</sub>, start<sub>y</sub>): The bottom-left corner of the rectangle.
- (end<sub>x</sub>, end<sub>y</sub>): The top-right corner of the rectangle.

**Note** that the rectangles do not overlap. Your task is to determine if it is possible to make **either two horizontal or two vertical cuts**  on the grid such that:

- Each of the three resulting sections formed by the cuts contains **at least**  one rectangle.
- Every rectangle belongs to **exactly**  one section.

Return `true` if such cuts can be made; otherwise, return `false`.

**Example 1:**

```bash
Input: n = 5, rectangles = [[1,0,5,2],[0,2,2,4],[3,2,5,3],[0,4,4,5]]

Output: true
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/10/23/tt1drawio.png" style="width: 285px; height: 280px;">

The grid is shown in the diagram. We can make horizontal cuts at `y = 2` and `y = 4`. Hence, output is true.

**Example 2:**

```bash
Input: n = 4, rectangles = [[0,0,1,1],[2,0,3,4],[0,2,2,3],[3,0,4,3]]

Output: true
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/10/23/tc2drawio.png" style="width: 240px; height: 240px;">

We can make vertical cuts at `x = 2` and `x = 3`. Hence, output is true.

**Example 3:**

```bash
Input: n = 4, rectangles = [[0,2,2,4],[1,0,3,2],[2,2,3,4],[3,0,4,2],[3,2,4,4]]

Output: false
```

Explanation:

We cannot make two horizontal or two vertical cuts that satisfy the conditions. Hence, output is false.

**Constraints:**

- `3 <= n <= 10^9`
- `3 <= rectangles.length <= 10^5`
- `0 <= rectangles[i][0] < rectangles[i][2] <= n`
- `0 <= rectangles[i][1] < rectangles[i][3] <= n`
- No two rectangles overlap.

## Hints/Notes

- 2025/01/10
- sort
- [0x3F's solution](https://leetcode.cn/problems/check-if-grid-can-be-cut-into-sections/solutions/3026888/he-bing-qu-jian-pythonjavacgo-by-endless-dn1g/)(checked)
- Biweekly Contest 146

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int, int>> verticals;
        vector<pair<int, int>> horizontals;
        for (auto& r : rectangles) {
            horizontals.push_back({r[0], r[2]});
            verticals.push_back({r[1], r[3]});
        }
        return check(verticals) || check(horizontals);
    }

    bool check(vector<pair<int, int>>& intervals) {
        ranges::sort(intervals);
        int r = 0, res = 0;
        for (auto interval : intervals) {
            if (interval.first >= r) {
                res++;
            }
            r = max(r, interval.second);
        }
        return res >= 3;
    }
};
```
