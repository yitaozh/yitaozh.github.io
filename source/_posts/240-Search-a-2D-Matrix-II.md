---
title: 240. Search a 2D Matrix II
categories: Leetcode
date: 2023-12-01 21:38:40
tags:
    - Array
    - Binary Search
    - Divide and Conquer
    - Matrix
---

# [240\. Search a 2D Matrix II](https://leetcode.com/problems/search-a-2d-matrix-ii/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Binary Search](https://leetcode.com/tag/https://leetcode.com/tag/binary-search//), [Divide and Conquer](https://leetcode.com/tag/https://leetcode.com/tag/divide-and-conquer//), [Matrix](https://leetcode.com/tag/https://leetcode.com/tag/matrix//)

Write an efficient algorithm that searches for a value `target` in an `m x n` integer matrix `matrix`. This matrix has the following properties:

* Integers in each row are sorted in ascending from left to right.
* Integers in each column are sorted in ascending from top to bottom.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/11/24/searchgrid2.jpg)

```bash
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2020/11/24/searchgrid.jpg)

```bash
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output: false
```

**Constraints:**

* `m == matrix.length`
* `n == matrix[i].length`
* `1 <= n, m <= 300`
* -10<sup>9</sup> <= `matrix[i][j]` <= 10<sup>9</sup>
* All the integers in each row are **sorted** in ascending order.
* All the integers in each column are **sorted** in ascending order.
* -10<sup>9</sup> <= target <= 10<sup>9</sup>

## Hints/Notes

* start from top right corner

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = 0, n = matrix[0].size() - 1;
        while (m < matrix.size() && n >= 0) {
            if (matrix[m][n] == target) {
                return true;
            } else if (matrix[m][n] < target) {
                m++;
            } else {
                n--;
            }
        }   
        return false;
    }
};
```
