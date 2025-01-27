---
title: 498. Diagonal Traverse
categories: Leetcode
date: 2025-01-23 12:15:35
tags:
    - Array
    - Matrix
    - Simulation
---

[498. Diagonal Traverse](https://leetcode.com/problems/diagonal-traverse/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

Given an `m x n` matrix `mat`, return an array of all the elements of the array in a diagonal order.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/04/10/diag1-grid.jpg" style="width: 334px; height: 334px;">

```bash
Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,4,7,5,3,6,8,9]
```

**Example 2:**

```bash
Input: mat = [[1,2],[3,4]]
Output: [1,2,3,4]
```

**Constraints:**

- `m == mat.length`
- `n == mat[i].length`
- `1 <= m, n <= 10^4`
- `1 <= m * n <= 10^4`
- `-10^5 <= mat[i][j] <= 10^5`

## Hints/Notes

- 2025/01/23
- matrix
- [Leetcode solution](https://leetcode.com/problems/diagonal-traverse/editorial/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> res;
        bool dir = true;
        for (int i = 0; i < m + n - 1; i++) {
            if (dir) {
                for (int j = max(0, i - m + 1); j <= min(i, n - 1); j++) {
                    int x = i - j, y = j;
                    // i - j < m => j > i - m
                    // if (x >= m || y >= n) {
                    //     continue;
                    // }
                    res.push_back(mat[x][y]);
                }
            } else {
                for (int j = min(i, n - 1); j >= max(0, i - m + 1); j--) {
                    int x = i - j, y = j;
                    // if (x >= m || y >= n) {
                    //     continue;
                    // }
                    res.push_back(mat[x][y]);
                }
            }
            dir = !dir;
        }
        return res;
    }
};
```
