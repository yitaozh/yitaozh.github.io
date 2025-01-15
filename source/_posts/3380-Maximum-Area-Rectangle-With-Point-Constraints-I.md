---
title: 3380. Maximum Area Rectangle With Point Constraints I
categories: Leetcode
date: 2024-12-16 00:34:56
tags:
    - Array
    - Math
    - Binary Indexed Tree
    - Segment Tree
    - Geometry
    - Sorting
    - Enumeration
---

[3380. Maximum Area Rectangle With Point Constraints I](https://leetcode.com/problems/maximum-area-rectangle-with-point-constraints-i/description/)

## Description

You are given an array `points` where points[i] = [x<sub>i</sub>, y<sub>i</sub>] represents the coordinates of a point on an infinite plane.

Your task is to find the **maximum** area of a rectangle that:

- Can be formed using **four**  of these points as its corners.
- Does **not**  contain any other point inside or on its border.
- Has its edges**parallel**  to the axes.

Return the **maximum area**  that you can obtain or -1 if no such rectangle is possible.

**Example 1:**

```bash
Input: points = [[1,1],[1,3],[3,1],[3,3]]

Output: 4
```

Explanation:

<img alt="Example 1 diagram" src="https://assets.leetcode.com/uploads/2024/11/02/example1.png" style="width: 229px; height: 228px;">

We can make a rectangle with these 4 points as corners and there is no other point that lies inside or on the border. Hence, the maximum possible area would be 4.

**Example 2:**

```bash
Input: points = [[1,1],[1,3],[3,1],[3,3],[2,2]]

Output: -1
```

Explanation:

<img alt="Example 2 diagram" src="https://assets.leetcode.com/uploads/2024/11/02/example2.png" style="width: 229px; height: 228px;">

There is only one rectangle possible is with points `[1,1], [1,3], [3,1]` and `[3,3]` but `[2,2]` will always lie inside it. Hence, returning -1.

**Example 3:**

```bash
Input: points = [[1,1],[1,3],[3,1],[3,3],[1,2],[3,2]]

Output: 2
```

Explanation:

<img alt="Example 3 diagram" src="https://assets.leetcode.com/uploads/2024/11/02/example3.png" style="width: 229px; height: 228px;">

The maximum area rectangle is formed by the points `[1,3], [1,2], [3,2], [3,3]`, which has an area of 2. Additionally, the points `[1,1], [1,2], [3,1], [3,2]` also form a valid rectangle with the same area.

**Constraints:**

- `1 <= points.length <= 10`
- `points[i].length == 2`
- 0 <= x<sub>i</sub>, y<sub>i</sub> <= 100
- All the given points are **unique** .

## Hints/Notes

- 2024/12/12
- No solution from 0x3F for t3
- Weekly Contest 427

## Solution

Language: **C++**

Cleaner solution

```C++
class Solution {
public:
    int maxRectangleArea(vector<vector<int>>& points) {
        int n = points.size();
        int res = -1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int xa = min(points[i][0], points[j][0]), xb = max(points[i][0], points[j][0]);
                int ya = min(points[i][1], points[j][1]), yb = max(points[i][1], points[j][1]);
                auto check = [&]() {
                    int count = 0;
                    for (int k = 0; k < n; k++) {
                        if (points[k][0] < xa || points[k][0] > xb) continue;
                        if (points[k][1] < ya || points[k][1] > yb) continue;
                        if ((points[k][0] == xa || points[k][0] == xb) && (points[k][1] == ya || points[k][1] == yb)) {
                            count++;
                            continue;
                        }
                        return false;
                    }
                    return count == 4;
                };
                if (check()) {
                    res = max(res, (xb - xa) * (yb - ya));
                }
            }
        }
        return res;
    }
};
```

```C++
class Solution {
public:
    int maxRectangleArea(vector<vector<int>>& points) {
        int n = points.size();
        int res = -1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    for (int l = k + 1; l < n; l++) {
                        unordered_set<int> checking = {i, j, k, l};
                        if (checkRectangle(checking, points)) {
                            // cout << i << j << k << l << endl;
                            res = max(res, noPointswithin(checking, points));
                        }
                    }
                }
            }
        }
        return res;
    }


    int noPointswithin(unordered_set<int>& checking, vector<vector<int>>& points) {
        int n = points.size();
        map<int, vector<int>> indexByX, indexByY;
        for (int i = 0; i < n; i++) {
            if (!checking.contains(i)) {
                continue;
            }
            int x = points[i][0], y = points[i][1];
            indexByX[x].push_back(y);
            indexByY[y].push_back(x);
        }
        int x1 = indexByX.begin()->first, x2 = indexByX.rbegin()->first;
        int y1 = indexByY.begin()->first, y2 = indexByY.rbegin()->first;
        for (int i = 0; i < n; i++) {
            if (checking.contains(i)) {
                continue;
            }
            int x = points[i][0], y = points[i][1];
            if (x >= x1 && x <= x2 && y >= y1 && y <= y2) {
                return -1;
            }
        }
        return (x2 - x1) * (y2 - y1);
    }

    bool checkRectangle(unordered_set<int>& checking, vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<int, vector<int>> indexByX, indexByY;
        for (int i = 0; i < n; i++) {
            if (!checking.contains(i)) {
                continue;
            }
            int x = points[i][0], y = points[i][1];
            indexByX[x].push_back(y);
            indexByY[y].push_back(x);
        }
        if (indexByX.size() != 2 || indexByX.begin()->second.size() != 2) {
            return false;
        }
        if (indexByY.size() != 2 || indexByY.begin()->second.size() != 2) {
            return false;
        }
        return true;
    }
};
```
