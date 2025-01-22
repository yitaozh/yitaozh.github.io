---
title: 766. Toeplitz Matrix
categories: Leetcode
date: 2025-01-22 00:26:18
tags:
    - Array
    - Matrix
---

[766. Toeplitz Matrix](https://leetcode.com/problems/toeplitz-matrix/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

Given an `m x n` `matrix`, return`true`if the matrix is Toeplitz. Otherwise, return `false`.

A matrix is **Toeplitz**  if every diagonal from top-left to bottom-right has the same elements.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/11/04/ex1.jpg" style="width: 322px; height: 242px;">

```bash
Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
Output: true
Explanation:
In the above grid, the diagonals are:
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
In each diagonal all elements are the same, so the answer is True.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/11/04/ex2.jpg" style="width: 162px; height: 162px;">

```bash
Input: matrix = [[1,2],[2,2]]
Output: false
Explanation:
The diagonal "[1, 2]" has different elements.
```

**Constraints:**

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 20`
- `0 <= matrix[i][j] <= 99`

**Follow up:**

- What if the `matrix` is stored on disk, and the memory is limited such that you can only load at most one row of the matrix into the memory at once?
- What if the `matrix` is so large that you can only load up a partial row into the memory at once?

## Hints/Notes

- 2025/01/21
- [Good solution](https://leetcode.cn/problems/toeplitz-matrix/solutions/614494/cong-ci-pan-du-qu-cheng-ben-fen-xi-liang-f20w/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] != matrix[i - 1][j - 1]) {
                    return false;
                }
            }
        }
        return true;
    }
};
```
