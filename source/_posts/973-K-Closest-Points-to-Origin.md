---
title: 973. K Closest Points to Origin
categories: Leetcode
date: 2025-01-08 23:22:45
tags:
    - Array
    - Math
    - Divide and Conquer
    - Geometry
    - Sorting
    - Heap (Priority Queue)
    - Quickselect
---

[973. K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin/description/?envType=problem-list-v2&envId=plakya4j)

## Description

Given an array of `points` where points[i] = [x<sub>i</sub>, y<sub>i</sub>] represents a point on the **X-Y**  plane and an integer `k`, return the `k` closest points to the origin `(0, 0)`.

The distance between two points on the **X-Y**  plane is the Euclidean distance (i.e., √(x<sub>1</sub> - x<sub>2</sub>)^2 + (y<sub>1</sub> - y<sub>2</sub>)^2).

You may return the answer in **any order** . The answer is **guaranteed**  to be **unique**  (except for the order that it is in).

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/03/03/closestplane1.jpg" style="width: 400px; height: 400px;">

```bash
Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
```

**Example 2:**

```bash
Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.
```

**Constraints:**

- `1 <= k <= points.length <= 10^4`
- -10^4 <= x<sub>i</sub>, y<sub>i</sub> <= 10^4

## Hints/Notes

- 2025/01/08
- priority queue
- No solution from 0x3F

## Solution

Language: **C++**

quick select

```C++
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        quick_select(points, k, 0, points.size() - 1);
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }

    void quick_select(vector<vector<int>>& points, int k, int left, int right) {
        int pivot = right, pivotDist = points[pivot][0] * points[pivot][0] + points[pivot][1] * points[pivot][1];
        int i = left - 1;
        for (int j = left; j < right; j++) {
            int dist = points[j][0] * points[j][0] + points[j][1] * points[j][1];
            if (dist <= pivotDist) {
                swap(points[++i], points[j]);
            }
        }
        i++;
        swap(points[i], points[right]);
        // from left to i, a total of i - left + 1 numbers are <= pivot
        if (i - left + 1 > k) {
            quick_select(points, k, left, i - 1);
        } else if (i - left + 1 < k) {
            quick_select(points, k - i + left - 1, i + 1, right);
        }
    }
};
```

priority queue:

```C++
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            int x = points[i][0], y = points[i][1], d = x * x + y * y;
            pq.push({d, i});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<vector<int>> res;
        while (!pq.empty()) {
            int idx = pq.top().second;
            pq.pop();
            res.push_back(points[idx]);
        }
        return res;
    }
};
```
