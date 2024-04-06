---
title: 1314. Matrix Block Sum
categories: Leetcode
date: 2023-11-12 00:07:45
tags:
    - Array
    - Matrix
    - Prefix Sum
---

[1314\. Matrix Block Sum](https://leetcode.com/problems/matrix-block-sum/)

## Description

Difficulty: **Medium**

Related Topics: [Array](https://leetcode.com/tag/https://leetcode.com/tag/array//), [Matrix](https://leetcode.com/tag/https://leetcode.com/tag/matrix//), [Prefix Sum](https://leetcode.com/tag/https://leetcode.com/tag/prefix-sum//)

Given a `m x n` matrix `mat` and an integer `k`, return _a matrix_ `answer` _where each_ `answer[i][j]` _is the sum of all elements_ `mat[r][c]` _for_:

* `i - k <= r <= i + k,`
* `j - k <= c <= j + k`, and
* `(r, c)` is a valid position in the matrix.

**Example 1:**

```bash
Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
Output: [[12,21,16],[27,45,33],[24,39,28]]
```

**Example 2:**

```bash
Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 2
Output: [[45,45,45],[45,45,45],[45,45,45]]
```

**Constraints:**

* `m == mat.length`
* `n == mat[i].length`
* `1 <= m, n, k <= 100`
* `1 <= mat[i][j] <= 100`

## Hints/Notes

* matrix preSum

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        vector<vector<int>> preSum(mat.size() + 1, vector<int>(mat[0].size() + 1, 0));
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                preSum[i + 1][j + 1] = preSum[i][j + 1] + preSum[i + 1][j] - preSum[i][j] + mat[i][j];
            }
        }
        vector<vector<int>> res(mat.size(), vector<int>(mat[0].size(), 0));
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                int up = max(0, i - k);
                int down = min(i + k + 1, (int)mat.size());
                int left = max(0, j - k);
                int right = min(j + k + 1, (int)mat[0].size());
                res[i][j] = preSum[down][right] - preSum[down][left] - preSum[up][right] + preSum[up][left];
            }
        }
        return res;
    }
};
```
