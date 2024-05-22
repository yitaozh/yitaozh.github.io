---
title: 3143. Maximum Points Inside the Square
categories: Leetcode
date: 2024-05-22 10:01:30
tags:
    - Array
    - Hash Table
    - String
    - Binary Search
    - Sorting
---

[3143. Maximum Points Inside the Square](https://leetcode.com/problems/maximum-points-inside-the-square/description/)

You are given a 2D** ** array `points` and a string `s` where, `points[i]` represents the coordinates of point `i`, and `s[i]` represents the **tag**  of point `i`.

A **valid**  square is a square centered at the origin `(0, 0)`, has edges parallel to the axes, and **does not**  contain two points with the same tag.

Return the **maximum**  number of points contained in a **valid**  square.

Note:

- A point is considered to be inside the square if it lies on or within the square's boundaries.
- The side length of the square can be zero.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2024/03/29/3708-tc1.png" style="width: 303px; height: 303px;">

```bash
Input: points = [[2,2],[-1,-2],[-4,4],[-3,1],[3,-3]], s = "abdca"

Output: 2

Explanation:

The square of side length 4 covers two points `points[0]` and `points[1]`.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2024/03/29/3708-tc2.png" style="width: 302px; height: 302px;">

```bash
Input: points = [[1,1],[-2,-2],[-2,2]], s = "abb"

Output: 1

Explanation:

The square of side length 2 covers one point, which is `points[0]`.
```

**Example 3:**

```bash
Input: points = [[1,1],[-1,-1],[2,-2]], s = "ccd"

Output: 0

Explanation:

It's impossible to make any valid squares centered at the origin such that it covers only one point among `points[0]` and `points[1]`.
```

**Constraints:**

- `1 <= s.length, points.length <= 10^5`
- `points[i].length == 2`
- `-10^9 <= points[i][0], points[i][1] <= 10^9`
- `s.length == points.length`
- `points` consists of distinct coordinates.
- `s` consists only of lowercase English letters.

## Hints/Notes

- N/A

## Solution

Language: **C++**

```C++
class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        map<int, vector<int>> m;
        int size = points.size();
        for (int i = 0; i < size; i++) {
            auto point = points[i];
            char c = s[i];
            int x = abs(point[0]);
            int y = abs(point[1]);
            int r = max(x, y);
            m[r].push_back(c - 'a');
        }
        int res = 0;
        int count[26] = {0};
        bool finished = false;
        for (auto it : m) {
            auto v = it.second;
            for (int tag : v) {
                count[tag]++;
                if (count[tag] > 1) {
                    finished = true;
                    break;
                }
            }
            if (finished) {
                break;
            }
            res += v.size();
        }
        return res;
    }
};
```
