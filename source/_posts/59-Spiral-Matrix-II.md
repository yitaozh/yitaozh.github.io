---
title: 59. Spiral Matrix II
categories: Leetcode
date: 2023-01-23 12:36:02
tags:
    - Array
    - Matrix
    - Simulation
---

# [59\. Spiral Matrix II](https://leetcode.com/problems/spiral-matrix-ii/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/array/), [Matrix](https://leetcode.com/tag/matrix/), [Simulation](https://leetcode.com/tag/simulation/)

Given a positive integer `n`, generate an `n x n` `matrix` filled with elements from `1` to n<sup>2</sup> in spiral order.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/11/13/spiraln.jpg)

```bash
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
```

**Example 2:**

```bash
Input: n = 1
Output: [[1]]
```

**Constraints:**

* `1 <= n <= 20`

## Hints/Notes

* Traverse the four sides in one iteration

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        if (n == 0) return res;
        int left = 0, right = n - 1, up = 0, down = n - 1, val = 1;
        while (val <= n * n) {
            if (up <= down) {
                for (int i = left; i <= right; i++) {
                    res[up][i] = val++;
                }
                up++;
            }
            if (left <= right) {
                for (int i = up; i <= down; i++) {
                    res[i][right] = val++;
                }
                right--;
            }
            if (up <= down) {
                for (int i = right; i >= left; i--) {
                    res[down][i] = val++;
                }
                down--;
            }
            if (left <= right) {
                for (int i = down; i >= up; i--) {
                    res[i][left] = val++;
                }
                left++;
            }
        }
        return res;
    }
};
```
