---
title: 74. Search a 2D Matrix
categories: Leetcode
date: 2023-11-30 21:17:00
tags:
    - Array
    - Binary Search
    - Matrix
---

[74\. Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Binary Search](https://leetcode.com/tag/https://leetcode.com/tag/binary-search//), [Matrix](https://leetcode.com/tag/https://leetcode.com/tag/matrix//)

You are given an `m x n` integer matrix `matrix` with the following two properties:

* Each row is sorted in non-decreasing order.
* The first integer of each row is greater than the last integer of the previous row.

Given an integer `target`, return `true` _if_ `target` _is in_ `matrix` _or_ `false` _otherwise_.

You must write a solution in `O(log(m * n))` time complexity.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/10/05/mat.jpg)

```bash
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2020/10/05/mat2.jpg)

```bash
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
```

**Constraints:**

* `m == matrix.length`
* `n == matrix[i].length`
* `1 <= m, n <= 100`
* -10<sup>4</sup> <= `matrix[i][j]`, target <= 10<sup>4</sup>

## Hints/Notes

* 2023/11/11
* binary search
* [0x3F's solution](https://leetcode.cn/problems/search-a-2d-matrix/solutions/2783931/liang-chong-fang-fa-er-fen-cha-zhao-pai-39d74/)(checked)

## Solution

Language: **C++**

Simpler solution:

```C++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = -1, right = m * n;
        while (left + 1 < right) {
            int mid = (right - left) / 2 + left;
            int x = mid / n, y = mid % n;
            if (matrix[x][y] == target) {
                return true;
            } else if (matrix[x][y] > target) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return false;
    }
};
```

```C++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, right = m;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (matrix[mid][0] <= target && matrix[mid][n - 1] >= target) {
                left = mid;
                break;
            } else if (matrix[mid][0] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        int i = left;
        if (left >= m) {
            return false;
        }
        left = 0; right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (matrix[i][mid] == target) {
                return true;
            } else if (matrix[i][mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (left >= n) {
            return false;
        }
        return matrix[i][left] == target;
    }
};
```
