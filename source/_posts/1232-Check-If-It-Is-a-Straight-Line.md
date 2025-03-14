---
title: 1232. Check If It Is a Straight Line
categories: Leetcode
date: 2025-03-14 12:52:16
tags:
    - Array
    - Math
    - Geometry
---

[1232. Check If It Is a Straight Line](https://leetcode.com/problems/check-if-it-is-a-straight-line/description/)

## Description

You are given an array`coordinates`, `coordinates[i] = [x, y]`, where `[x, y]` represents the coordinate of a point. Check if these pointsmake a straight line in the XY plane.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2019/10/15/untitled-diagram-2.jpg" style="width: 336px; height: 336px;">

```bash
Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true
```

**Example 2:**

**<img alt="" src="https://assets.leetcode.com/uploads/2019/10/09/untitled-diagram-1.jpg" style="width: 348px; height: 336px;">**

```bash
Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false
```

**Constraints:**

- `2 <=coordinates.length <= 1000`
- `coordinates[i].length == 2`
- `-10^4 <=coordinates[i][0],coordinates[i][1] <= 10^4`
- `coordinates`contains no duplicate point.

## Hints/Notes

- 2025/03/12 Q3
- math
- [0x3F's solution](https://leetcode.com/problems/check-if-it-is-a-straight-line/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() == 2) {
            return true;
        }
        int dx0 = coordinates[0][0] - coordinates[1][0];
        int dy0 = coordinates[0][1] - coordinates[1][1];
        // dy0 / dx0 = dy / dx => dy0 * dx = dx0 * dy
        int n = coordinates.size();
        for (int i = 2; i < coordinates.size(); i++) {
            int dx = coordinates[i][0] - coordinates[0][0];
            int dy = coordinates[i][1] - coordinates[0][1];
            if (dx * dy0 != dx0 * dy) {
                return false;
            }
        }
        return true;
    }
};
```
