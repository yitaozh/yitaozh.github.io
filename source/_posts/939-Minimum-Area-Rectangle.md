---
title: 939. Minimum Area Rectangle
categories: Leetcode
date: 2025-04-19 22:11:49
tags:
    - Array
    - Hash Table
    - Math
    - Geometry
    - Sorting
---

[939. Minimum Area Rectangle](https://leetcode.com/problems/minimum-area-rectangle/description/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Description

You are given an array of points in the **X-Y**  plane `points` where `points[i] = [x<sub>i</sub>, y<sub>i</sub>]`.

Return the minimum area of a rectangle formed from these points, with sides parallel to the X and Y axes. If there is not any such rectangle, return `0`.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/08/03/rec1.JPG" style="width: 500px; height: 447px;">

```bash
Input: points = [[1,1],[1,3],[3,1],[3,3],[2,2]]
Output: 4
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/08/03/rec2.JPG" style="width: 500px; height: 477px;">

```bash
Input: points = [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
Output: 2
```

**Constraints:**

- `1 <= points.length <= 500`
- `points[i].length == 2`
- `0 <= x<sub>i</sub>, y<sub>i</sub> <= 4 * 10^4`
- All the given points are **unique** .

## Hints/Notes

- 2025/04/18 Q3
- matrix
- [Leetcode solution](https://leetcode.com/problems/minimum-area-rectangle/editorial)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        map<int, set<int>> Xcoordinates;
        map<int, set<int>> Ycoordinates;
        for (auto& p : points) {
            int x = p[0], y = p[1];
            Xcoordinates[x].insert(y);
            Ycoordinates[y].insert(x);
        }
        int res = INT_MAX;
        for (auto& [x, s] : Xcoordinates) {
            if (s.size() < 2) {
                continue;
            }
            vector<int> yIndex(s.begin(), s.end());
            int n = yIndex.size();
            for (int i = 0; i < n; i++) {
                int y1 = yIndex[i];
                if (Ycoordinates[y1].size() < 2 || *Ycoordinates[y1].rbegin() == x) {
                    continue;
                }
                for (int j = i + 1; j < n; j++) {
                    int y2 = yIndex[j];
                    if (Ycoordinates[y2].size() < 2 || *Ycoordinates[y2].rbegin() == x) {
                        continue;
                    }
                    auto it1 = Ycoordinates[y1].lower_bound(x + 1);
                    auto it2 = Ycoordinates[y2].lower_bound(x + 1);
                    while (it1 != Ycoordinates[y1].end() && it2 != Ycoordinates[y2].end()) {
                        if (*it1 == *it2) {
                            res = min(res, (*it1 - x) * (y2 - y1));
                            it1++;
                            it2++;
                        } else if (*it1 > *it2) {
                            it2++;
                        } else {
                            it1++;
                        }
                    }
                }
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
```
