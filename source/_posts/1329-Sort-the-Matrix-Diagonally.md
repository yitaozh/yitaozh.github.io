---
title: 1329. Sort the Matrix Diagonally
categories: Leetcode
date: 2025-03-19 17:08:20
tags:
    - Array
    - Sorting
    - Matrix
---

[1329. Sort the Matrix Diagonally](https://leetcode.com/problems/sort-the-matrix-diagonally/description/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Description

A **matrix diagonal**  is a diagonal line of cells starting from some cell in either the topmost row or leftmost column and going in the bottom-right direction until reaching the matrix's end. For example, the **matrix diagonal**  starting from `mat[2][0]`, where `mat` is a `6 x 3` matrix, includes cells `mat[2][0]`, `mat[3][1]`, and `mat[4][2]`.

Given an `m x n` matrix `mat` of integers, sort each **matrix diagonal**  in ascending order and return the resulting matrix.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/01/21/1482_example_1_2.png" style="width: 500px; height: 198px;">

```bash
Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]
```

**Example 2:**

```bash
Input: mat = [[11,25,66,1,69,7],[23,55,17,45,15,52],[75,31,36,44,58,8],[22,27,33,25,68,4],[84,28,14,11,5,50]]
Output: [[5,17,4,1,52,7],[11,11,25,45,8,69],[14,23,25,44,58,15],[22,27,31,36,50,66],[84,28,75,33,55,68]]
```

**Constraints:**

- `m == mat.length`
- `n == mat[i].length`
- `1 <= m, n <= 100`
- `1 <= mat[i][j] <= 100`

## Hints/Notes

- 2025/02/21 Q3
- bfs
- [0x3F's solution](https://leetcode.cn/problems/sort-the-matrix-diagonally/solutions/2760094/dui-jiao-xian-pai-xu-fu-yuan-di-pai-xu-p-uts8/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        queue<pair<int, int>> q;
        q.push({m - 1, 0});
        list<int> nums;
        nums.push_back(mat[m - 1][0]);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
                res[x][y] = nums.front();
                nums.pop_front();
                if (y == 0) {
                    int dx = x - 1;
                    if (dx >= 0) {
                        nums.push_back(mat[dx][y]);
                        q.push({dx, y});
                    }
                }
                int dy = y + 1;
                if (dy < n) {
                    nums.push_back(mat[x][dy]);
                    q.push({x, dy});
                }
            }
            nums.sort();
        }
        return res;
    }
};
```
