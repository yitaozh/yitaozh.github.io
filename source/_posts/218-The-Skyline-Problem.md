---
title: 218. The Skyline Problem
categories: Leetcode
date: 2025-03-31 01:56:33
tags:
    - Array
    - Divide and Conquer
    - Binary Indexed Tree
    - Segment Tree
    - Line Sweep
    - Heap (Priority Queue)
    - Ordered Set
---

[218. The Skyline Problem](https://leetcode.com/problems/the-skyline-problem/description/?envType=company&envId=apple&favoriteSlug=apple-six-months)

## Description

A city's **skyline**  is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Given the locations and heights of all the buildings, return the **skyline**  formed by these buildings collectively.

The geometric information of each building is given in the array `buildings` where `buildings[i] = [left<sub>i</sub>, right<sub>i</sub>, height<sub>i</sub>]`:

- `left<sub>i</sub>` is the x coordinate of the left edge of the `i^th` building.
- `right<sub>i</sub>` is the x coordinate of the right edge of the `i^th` building.
- `height<sub>i</sub>` is the height of the `i^th` building.

You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height `0`.

The **skyline**  should be represented as a list of "key points" **sorted by their x-coordinate**  in the form `[[x<sub>1</sub>,y<sub>1</sub>],[x<sub>2</sub>,y<sub>2</sub>],...]`. Each key point is the left endpoint of some horizontal segment in the skyline except the last point in the list, which always has a y-coordinate `0` and is used to mark the skyline's termination where the rightmost building ends. Any ground between the leftmost and rightmost buildings should be part of the skyline's contour.

<b>Note:</b> There must be no consecutive horizontal lines of equal height in the output skyline. For instance, `[...,[2 3],[4 5],[7 5],[11 5],[12 7],...]` is not acceptable; the three lines of height 5 should be merged into one in the final output as such: `[...,[2 3],[4 5],[12 7],...]`

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/12/01/merged.jpg" style="width: 800px; height: 331px;">

```bash
Input: buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
Output: [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
Explanation:
Figure A shows the buildings of the input.
Figure B shows the skyline formed by those buildings. The red points in figure B represent the key points in the output list.
```

**Example 2:**

```bash
Input: buildings = [[0,2,3],[2,5,3]]
Output: [[0,3],[5,0]]
```

**Constraints:**

- `1 <= buildings.length <= 10^4`
- `0 <= left<sub>i</sub> < right<sub>i</sub> <= 2^31 - 1`
- `1 <= height<sub>i</sub> <= 2^31 - 1`
- `buildings` is sorted by `left<sub>i</sub>` innon-decreasing order.

## Hints/Notes

- 2025/03/30
- sorting
- [Leetcode solution](https://leetcode.cn/problems/the-skyline-problem/solutions/872710/tian-ji-xian-wen-ti-by-leetcode-solution-ozse/?envType=company&envId=apple&favoriteSlug=apple-six-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> events;
        for (auto building : buildings) {
            int start = building[0], end = building[1], height = building[2];
            events.push_back({start, height, 1});
            events.push_back({end, height, 0});
        }
        ranges::sort(events);
        int prev_h = -1;
        vector<vector<int>> res;
        multiset<int> cur;
        int n = events.size();
        for (int i = 0; i < n; ) {
            int t = events[i][0];
            while (i < n && events[i][0] == t) {
                auto event = events[i];
                int h = event[1], type = event[2];
                if (type) {
                    cur.insert(h);
                } else {
                    auto it = cur.find(h);
                    cur.erase(it);
                }
                i++;
            }
            int max_h = cur.empty() ? 0 : *cur.rbegin();
            if (max_h != prev_h) {
                res.push_back({t, max_h});
                prev_h = max_h;
            }
        }
        return res;
    }
};
```
