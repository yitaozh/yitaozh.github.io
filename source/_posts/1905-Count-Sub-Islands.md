---
title: 1905. Count Sub Islands
categories: Leetcode
date: 2025-04-19 00:19:14
tags:
    - Array
    - Depth-First Search
    - Breadth-First Search
    - Union Find
    - Matrix
---

[1905. Count Sub Islands](https://leetcode.com/problems/count-sub-islands/description/?envType=company&envId=doordash&favoriteSlug=doordash-more-than-six-months)

## Description

You are given two `m x n` binary matrices `grid1` and `grid2` containing only `0`'s (representing water) and `1`'s (representing land). An **island**  is a group of `1`'s connected **4-directionally**  (horizontal or vertical). Any cells outside of the grid are considered water cells.

An island in `grid2` is considered a **sub-island** if there is an island in `grid1` that contains **all**  the cells that make up **this**  island in `grid2`.

Return the **number**  of islands in `grid2` that are considered **sub-islands** .

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/06/10/test1.png" style="width: 493px; height: 205px;">

```bash
Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
Output: 3
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/06/03/testcasex2.png" style="width: 491px; height: 201px;">

```bash
Input: grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
Output: 2
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are two sub-islands.
```

**Constraints:**

- `m == grid1.length == grid2.length`
- `n == grid1[i].length == grid2[i].length`
- `1 <= m, n <= 500`
- `grid1[i][j]` and `grid2[i][j]` are either `0` or `1`.

## Hints/Notes

- 2025/04/11 Q3
- bfs
- [Leetcode solution](https://leetcode.com/problems/count-sub-islands/editorial/?envType=company&envId=doordash&favoriteSlug=doordash-more-than-six-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int m, n;
    static constexpr int DIRs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size(); n = grid1[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j]) {
                    res += dfs(i, j, grid1, grid2);
                }
            }
        }
        return res;
    }

    bool dfs(int x, int y, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int valid = grid1[x][y];
        grid2[x][y] = 0;
        for (int k = 0; k < 4; k++) {
            int dx = x + DIRs[k][0], dy = y + DIRs[k][1];
            if (dx >= 0 && dx < m && dy >= 0 && dy < n && grid2[dx][dy] == 1) {
                valid &= dfs(dx, dy, grid1, grid2);
            }
        }
        return valid;
    }
};
```
