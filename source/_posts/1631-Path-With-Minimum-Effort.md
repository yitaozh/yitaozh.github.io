---
title: 1631. Path With Minimum Effort
categories: Leetcode
date: 2023-09-07 01:13:26
tags:
    - Array
    - Binary Search
    - Depth-First Search
    - Breadth-First Search
    - Union Find
    - Heap (Priority Queue)
    - Matrix
---

[1631\. Path With Minimum Effort](https://leetcode.com/problems/path-with-minimum-effort/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Binary Search](https://leetcode.com/tag/https://leetcode.com/tag/binary-search//), [Depth-First Search](https://leetcode.com/tag/https://leetcode.com/tag/depth-first-search//), [Breadth-First Search](https://leetcode.com/tag/https://leetcode.com/tag/breadth-first-search//), [Union Find](https://leetcode.com/tag/https://leetcode.com/tag/union-find//), [Heap (Priority Queue)](https://leetcode.com/tag/https://leetcode.com/tag/heap-priority-queue//), [Matrix](https://leetcode.com/tag/https://leetcode.com/tag/matrix//)

You are a hiker preparing for an upcoming hike. You are given `heights`, a 2D array of size `rows x columns`, where `heights[row][col]` represents the height of cell `(row, col)`. You are situated in the top-left cell, `(0, 0)`, and you hope to travel to the bottom-right cell, `(rows-1, columns-1)` (i.e., **0-indexed**). You can move **up**, **down**, **left**, or **right**, and you wish to find a route that requires the minimum **effort**.

A route's **effort** is the **maximum absolute difference**in heights between two consecutive cells of the route.

Return _the minimum **effort** required to travel from the top-left cell to the bottom-right cell._

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/10/04/ex1.png)

```bash
Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2020/10/04/ex2.png)

```bash
Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
```

**Example 3:**

![](https://assets.leetcode.com/uploads/2020/10/04/ex3.png)

```bash
Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.
```

**Constraints:**

* `rows == heights.length`
* `columns == heights[i].length`
* `1 <= rows, columns <= 100`
* `1 <= heights[i][j] <= 10<sup>6</sup>`

## Hints/Notes

* Dijkstra algorithm: BFS with dp table

## Solution

Language: **C++**

```C++
class Solution {
public:
    int m, n;

    int minimumEffortPath(vector<vector<int>>& heights) {
        m = heights.size(); n = heights[0].size();

        vector<vector<int>> efforts(m, vector<int>(n, INT_MAX));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({0, 0, 0});
        while (!pq.empty()) {
            vector<int> point = pq.top();
            pq.pop();
            int i = point[1];
            int j = point[2];
            int e = point[0];
            if (i == m - 1 && j == n - 1) {
                return e;
            }
            if (e > efforts[i][j]) {
                continue;
            }
            vector<pair<int, int>>points = adj(i, j);
            for (auto point : points) {
                int nextI = point.first;
                int nextJ = point.second;
                int effort = efforts[nextI][nextJ];
                int newEffort = max(abs(heights[nextI][nextJ] - heights[i][j]), e);
                if (effort > newEffort) {
                    efforts[nextI][nextJ] = newEffort;
                    pq.push({newEffort, nextI, nextJ});
                }
            }
        }
        return -1;
    }

    vector<pair<int, int>> adj(int i, int j) {
        vector<pair<int, int>> res;
        if (i - 1 >= 0) {
            res.push_back({i - 1, j});
        }
        if (i + 1 < m) {
            res.push_back({i + 1, j});
        }
        if (j - 1 >= 0) {
            res.push_back({i, j - 1});
        }
        if (j + 1 < n) {
            res.push_back({i, j + 1});
        }
        return res;
    }
};
```
