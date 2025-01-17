---
title: 3417. Zigzag Grid Traversal With Skip
categories: Leetcode
date: 2025-01-16 23:43:17
tags:
    - Array
    - Matrix
    - Simulation
---

[3417. Zigzag Grid Traversal With Skip](https://leetcode.com/problems/zigzag-grid-traversal-with-skip/description/)

## Description

You are given an `m x n` 2D array `grid` of **positive**  integers.

Your task is to traverse `grid` in a **zigzag**  pattern while skipping every **alternate**  cell.

Zigzag pattern traversal is defined as following the below actions:

- Start at the top-left cell `(0, 0)`.
- Move right within a row until the end of the row is reached.
- Drop down to the next row, then traverse left until the beginning of the row is reached.
- Continue **alternating**  between right and left traversal until every row has been traversed.

**Note** that you **must skip** every alternate cell during the traversal.

Return an array of integers `result` containing, **in order** , the value of the cells visited during the zigzag traversal with skips.

**Example 1:**

```bash
Input: grid = [[1,2],[3,4]]

Output: [1,4]
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/11/23/4012_example0.png" style="width: 200px; height: 200px;">

**Example 2:**

```bash
Input: grid = [[2,1],[2,1],[2,1]]

Output: [2,1,2]
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/11/23/4012_example1.png" style="width: 200px; height: 240px;">

**Example 3:**

```bash
Input: grid = [[1,2,3],[4,5,6],[7,8,9]]

Output: [1,3,5,7,9]
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/11/23/4012_example2.png" style="width: 260px; height: 250px;">

**Constraints:**

- `2 <= n == grid.length <= 50`
- `2 <= m == grid[i].length <= 50`
- `1 <= grid[i][j] <= 2500`

## Hints/Notes

- 2025/01/16
- [0x3F's solution](https://leetcode.cn/problems/zigzag-grid-traversal-with-skip/solutions/3045134/mo-ni-pythonjavacgo-by-endlesscheng-9jn7/)(checked)
- Weekly Contest 432

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> res;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            if (i % 2) {
                for (int j = n - 1 - n % 2; j >= 0; j -= 2) {
                    res.push_back(grid[i][j]);
                }
            } else {
                for (int j = 0; j < max(n - n % 2, n); j += 2) {
                    res.push_back(grid[i][j]);
                }
            }
        }
        return res;
    }
};
```
