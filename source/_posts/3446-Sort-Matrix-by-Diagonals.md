---
title: 3446. Sort Matrix by Diagonals
categories: Leetcode
date: 2025-03-10 01:55:02
tags:
    - Array
    - Sorting
    - Matrix
---

[3446. Sort Matrix by Diagonals](https://leetcode.com/problems/sort-matrix-by-diagonals/description/)

## Description

You are given an `n x n` square matrix of integers `grid`. Return the matrix such that:

- The diagonals in the **bottom-left triangle**  (including the middle diagonal) are sorted in **non-increasing order** .
- The diagonals in the **top-right triangle**  are sorted in **non-decreasing order** .

**Example 1:**

```bash
Input: grid = [[1,7,3],[9,8,2],[4,5,6]]

Output: [[8,2,3],[9,6,7],[4,5,1]]
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/12/29/4052example1drawio.png" style="width: 461px; height: 181px;">

The diagonals with a black arrow (bottom-left triangle) should be sorted in non-increasing order:

- `[1, 8, 6]` becomes `[8, 6, 1]`.
- `[9, 5]` and `[4]` remain unchanged.

The diagonals with a blue arrow (top-right triangle) should be sorted in non-decreasing order:

- `[7, 2]` becomes `[2, 7]`.
- `[3]` remains unchanged.

**Example 2:**

```bash
Input: grid = [[0,1],[1,2]]

Output: [[2,1],[1,0]]
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/12/29/4052example2adrawio.png" style="width: 383px; height: 141px;">

The diagonals with a black arrow must be non-increasing, so `[0, 2]` is changed to `[2, 0]`. The other diagonals are already in the correct order.

**Example 3:**

```bash
Input: grid = [[1]]

Output: [[1]]
```

Explanation:

Diagonals with exactly one element are already in order, so no changes are needed.

**Constraints:**

- `grid.length == grid[i].length == n`
- `1 <= n <= 10`
- `-10^5 <= grid[i][j] <= 10^5`

## Hints/Notes

- 2025/02/23 Q1
- sort
- [0x3F's solution](https://leetcode.cn/problems/sort-matrix-by-diagonals/solutions/3068709/mo-ban-mei-ju-dui-jiao-xian-pythonjavacg-pjxp/)
- Weekly Contest 436

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> res(n, vector<int>(n));
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                m[i - j].push_back(grid[i][j]);
            }
        }
        for (auto& [k, v] : m) {
            if (k < 0) {
                ranges::sort(v);
            } else {
                sort(v.begin(), v.end(), greater<int>());
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = m[i - j].front();
                m[i - j].erase(m[i - j].begin());
                res[i][j] = val;
            }
        }
        return res;
    }
};
```
