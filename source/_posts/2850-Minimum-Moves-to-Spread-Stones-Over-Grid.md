---
title: 2850. Minimum Moves to Spread Stones Over Grid
categories: Leetcode
date: 2025-04-05 23:00:14
tags:
    - Array
    - Dynamic Programming
    - Breadth-First Search
    - Matrix
---

[2850. Minimum Moves to Spread Stones Over Grid](https://leetcode.com/problems/minimum-moves-to-spread-stones-over-grid/description/?envType=company&envId=tiktok&favoriteSlug=tiktok-six-months)

## Description

You are given a **0-indexed**  2D integer matrix `grid` of size `3 * 3`, representing the number of stones in each cell. The grid contains exactly `9` stones, and there can be **multiple**  stones in a single cell.

In one move, you can move a single stone from its current cell to any other cell if the two cells share a side.

Return the **minimum number of moves**  required to place one stone in each cell.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2023/08/23/example1-3.svg" style="width: 401px; height: 281px;">

```bash
Input: grid = [[1,1,0],[1,1,1],[1,2,1]]
Output: 3
Explanation: One possible sequence of moves to place one stone in each cell is:
1- Move one stone from cell (2,1) to cell (2,2).
2- Move one stone from cell (2,2) to cell (1,2).
3- Move one stone from cell (1,2) to cell (0,2).
In total, it takes 3 moves to place one stone in each cell of the grid.
It can be shown that 3 is the minimum number of moves required to place one stone in each cell.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2023/08/23/example2-2.svg" style="width: 401px; height: 281px;">

```bash
Input: grid = [[1,3,0],[1,0,0],[1,0,3]]
Output: 4
Explanation: One possible sequence of moves to place one stone in each cell is:
1- Move one stone from cell (0,1) to cell (0,2).
2- Move one stone from cell (0,1) to cell (1,1).
3- Move one stone from cell (2,2) to cell (1,2).
4- Move one stone from cell (2,2) to cell (2,1).
In total, it takes 4 moves to place one stone in each cell of the grid.
It can be shown that 4 is the minimum number of moves required to place one stone in each cell.
```

**Constraints:**

- `grid.length == grid[i].length == 3`
- `0 <= grid[i][j] <= 9`
- Sum of `grid` is equal to `9`.

## Hints/Notes

- 2025/04/04 Q3
- backtracking
- [0x3F's solution](https://leetcode.cn/problems/minimum-moves-to-spread-stones-over-grid/solutions/2435313/tong-yong-zuo-fa-zui-xiao-fei-yong-zui-d-iuw8/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> v;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 1) {
                    v.push_back({grid[i][j] - 1, i, j});
                }
            }
        }
        return dfs(0, v);
    }

    int dfs(int idx, vector<vector<int>>& v) {
        while (idx < v.size() && v[idx][0] == 0) {
            idx++;
        }
        if (idx == v.size()) {
            return 0;
        }
        long res = INT_MAX;
        int val = v[idx][0], x = v[idx][1], y = v[idx][2];
        for (int i = idx + 1; i < v.size(); i++) {
            if (v[i][0] * v[idx][0] < 0) {
                if (v[idx][0] < 0) {
                    v[i][0] -= 1;
                    res = min(res, (long)dfs(idx + 1, v) + abs(v[i][1] - x) + abs(v[i][2] - y));
                    v[i][0] += 1;
                } else {
                    v[idx][0] -= 1;
                    v[i][0] += 1;
                    res = min(res, (long)dfs(idx, v) + abs(v[i][1] - x) + abs(v[i][2] - y));
                    v[idx][0] += 1;
                    v[i][0] -= 1;
                }
            }
        }
        return res;
    }
};
```
