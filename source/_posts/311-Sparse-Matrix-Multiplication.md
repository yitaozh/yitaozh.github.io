---
title: 311. Sparse Matrix Multiplication
categories: Leetcode
date: 2025-03-14 11:58:57
tags:
    - Array
    - Hash Table
    - Matrix
---

# [311. Sparse Matrix Multiplication](https://leetcode.com/problems/sparse-matrix-multiplication/description/)

## Description

Given two <a href="https://en.wikipedia.org/wiki/Sparse_matrix" target="_blank">sparse matrices</a> `mat1` of size `m x k` and `mat2` of size `k x n`, return the result of `mat1 x mat2`. You may assume that multiplication is always possible.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/03/12/mult-grid.jpg" style="width: 500px; height: 142px;">

```bash
Input: mat1 = [[1,0,0],[-1,0,3]], mat2 = [[7,0,0],[0,0,0],[0,0,1]]
Output: [[7,0,0],[-7,0,3]]
```

**Example 2:**

```bash
Input: mat1 = [[0]], mat2 = [[0]]
Output: [[0]]
```

**Constraints:**

- `m == mat1.length`
- `k == mat1[i].length == mat2.length`
- `n == mat2[i].length`
- `1 <= m, n, k <= 100`
- `-100 <= mat1[i][j], mat2[i][j] <= 100`

## Hints/Notes

- 2025/03/10 Q2
- matrix calculation
- [Leetcode solution](https://leetcode.com/problems/sparse-matrix-multiplication/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size(), k = mat1[0].size(), n = mat2[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        // for a specific row, the existing numbers of mat1
        // for a specific col, the existing numbers of mat2
        vector<vector<pair<int, int>>> list1(m);
        vector<vector<pair<int, int>>> list2(n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < k; j++) {
                if (mat1[i][j] != 0) {
                    list1[i].emplace_back(j, mat1[i][j]);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                if (mat2[j][i] != 0) {
                    list2[i].emplace_back(j, mat2[j][i]);
                }
            }
        }
        for (int i = 0; i < m; i++) {
            if (list1[i].empty()) continue;
            for (int j = 0; j < n; j++) {
                if (list2[j].empty()) continue;
                // now we can have two points
                int idx1 = 0, idx2 = 0;
                while (idx1 < list1[i].size() && idx2 < list2[j].size()) {
                    if (list1[i][idx1].first < list2[j][idx2].first) {
                        idx1++;
                    } else if (list1[i][idx1].first > list2[j][idx2].first) {
                        idx2++;
                    } else {
                        res[i][j] += list1[i][idx1++].second * list2[j][idx2++].second;
                    }
                }
            }
        }
        return res;
    }
};
```
