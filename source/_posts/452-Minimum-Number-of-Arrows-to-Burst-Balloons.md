---
title: 452. Minimum Number of Arrows to Burst Balloons
categories: Leetcode
date: 2025-04-09 16:33:44
tags:
    - Array
    - Greedy
    - Sorting
---

[452. Minimum Number of Arrows to Burst Balloons](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/)

## Description

There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array `points` where points[i] = [x<sub>start</sub>, x<sub>end</sub>] denotes a balloon whose **horizontal diameter**  stretches between x<sub>start</sub> and x<sub>end</sub>. You do not know the exact y-coordinates of the balloons.

Arrows can be shot up **directly vertically**  (in the positive y-direction) from different points along the x-axis. A balloon with x<sub>start</sub> and x<sub>end</sub> is **burst**  by an arrow shot at `x` if x<sub>start</sub> <= x <= x<sub>end</sub>. There is **no limit**  to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.

Given the array `points`, return the **minimum**  number of arrows that must be shot to burst all balloons.

**Example 1:**

```bash
Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
- Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].
```

**Example 2:**

```bash
Input: points = [[1,2],[3,4],[5,6],[7,8]]
Output: 4
Explanation: One arrow needs to be shot for each balloon for a total of 4 arrows.
```

**Example 3:**

```bash
Input: points = [[1,2],[2,3],[3,4],[4,5]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 2, bursting the balloons [1,2] and [2,3].
- Shoot an arrow at x = 4, bursting the balloons [3,4] and [4,5].
```

**Constraints:**

- `1 <= points.length <= 10^5`
- `points[i].length == 2`
- -2^31 <= x<sub>start</sub> < x<sub>end</sub> <= 2^31 - 1

## Hints/Notes

- 2025/04/08 Q1
- sorting
- [0x3F's solution](https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/solutions/2974741/qu-jian-xuan-dian-wen-ti-pythonjavaccgoj-w9am/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        auto cmp = [](vector<int> lhs, vector<int> rhs) {
            if (lhs[1] == rhs[1]) {
                return lhs[0] < rhs[0];
            }
            return lhs[1] < rhs[1];
        };
        sort(points.begin(), points.end(), cmp);
        int index = 0, n = points.size(), res = 0;
        while (index < n) {
            int right_boundary = points[index][1];
            while (index < n && points[index][0] <= right_boundary) {
                index++;
            }
            res++;
        }
        return res;
    }
};
```
