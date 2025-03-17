---
title: 542. 01 Matrix
categories: Leetcode
date: 2025-03-17 01:29:52
tags:
    - Array
    - Dynamic Programming
    - Breadth-First Search
    - Matrix
---

[542. 01 Matrix](https://leetcode.com/problems/01-matrix/description/?envType=company&envId=linkedin&favoriteSlug=linkedin-three-months)

## Description

Given an `m x n` binary matrix `mat`, return the distance of the nearest `0` for each cell.

The distance between two cells sharing a common edge is `1`.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/04/24/01-1-grid.jpg" style="width: 253px; height: 253px;">

```bash
Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/04/24/01-2-grid.jpg" style="width: 253px; height: 253px;">

```bash
Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
```

**Constraints:**

- `m == mat.length`
- `n == mat[i].length`
- `1 <= m, n <= 10^4`
- `1 <= m * n <= 10^4`
- `mat[i][j]` is either `0` or `1`.
- There is at least one `0` in `mat`.

**Note:**  This question is the same as 1765: <a href="https://leetcode.com/problems/map-of-highest-peak/description/" target="_blank">https://leetcode.com/problems/map-of-highest-peak/</a>

## Hints/Notes

- 2025/02/13 Q2
- bfs
- [Leetcode solution](https://leetcode.com/problems/01-matrix/editorial/?envType=company&envId=linkedin&favoriteSlug=linkedin-three-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> res;
    int m, n;

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        res.resize(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    res[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        int cur = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int dx = x + dirs[k][0], dy = y + dirs[k][1];
                    if (dx >= 0 && dx < m && dy >= 0 && dy < n && res[dx][dy] == INT_MAX) {
                        res[dx][dy] = cur;
                        q.push({dx, dy});
                    }
                }
            }
            cur++;
        }

        return res;
    }
};
```
