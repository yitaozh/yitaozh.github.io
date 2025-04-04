---
title: 221. Maximal Square
categories: Leetcode
date: 2025-04-04 13:33:10
tags:
    - Array
    - Dynamic Programming
    - Matrix
---

[221. Maximal Square](https://leetcode.com/problems/maximal-square/description/)

## Description

Given an `m x n` binary `matrix` filled with `0`'s and `1`'s, find the largest square containing only `1`'s and return its area.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/11/26/max1grid.jpg" style="width: 400px; height: 319px;">

```bash
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/11/26/max2grid.jpg" style="width: 165px; height: 165px;">

```bash
Input: matrix = [["0","1"],["1","0"]]
Output: 1
```

**Example 3:**

```bash
Input: matrix = [["0"]]
Output: 0
```

**Constraints:**

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 300`
- `matrix[i][j]` is `'0'` or `'1'`.

## Hints/Notes

- 2025/03/28 Q2
- translate to dp
- [Leetcode solution](https://leetcode.com/problems/maximal-square/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<int>> preSum;

    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        preSum.resize(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int val = matrix[i][j] - '0';
                preSum[i + 1][j + 1] = preSum[i][j + 1] + preSum[i + 1][j] + val - preSum[i][j];
            }
        }
        int cur = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = cur + 1; k <= min(i, j); k++) {
                    if (preSum[i][j] - preSum[i - k][j] - preSum[i][j - k] + preSum[i - k][j - k] == k * k) {
                        cout << i << " " << j << endl;
                        cur = k;
                    } else {
                        break;
                    }
                }
            }
        }
        return cur * cur;
    }
};
```
