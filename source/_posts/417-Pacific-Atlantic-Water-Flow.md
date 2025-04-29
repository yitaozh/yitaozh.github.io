---
title: 417. Pacific Atlantic Water Flow
categories: Leetcode
date: 2025-01-08 17:17:34
tags:
    - Array
    - Depth-First Search
    - Breadth-First Search
    - Matrix
---

[417. Pacific Atlantic Water Flow](https://leetcode.com/problems/pacific-atlantic-water-flow/description/?envType=problem-list-v2&envId=plakya4j)

## Description

There is an `m x n` rectangular island that borders both the **Pacific Ocean**  and **Atlantic Ocean** . The **Pacific Ocean**  touches the island's left and top edges, and the **Atlantic Ocean**  touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an `m x n` integer matrix `heights` where `heights[r][c]` represents the **height above sea level**  of the cell at coordinate `(r, c)`.

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is **less than or equal to**  the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a **2D list**  of grid coordinates `result` where result[i] = [r<sub>i</sub>, c<sub>i</sub>] denotes that rain water can flow from cell (r<sub>i</sub>, c<sub>i</sub>) to **both**  the Pacific and Atlantic oceans.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/06/08/waterflow-grid.jpg" style="width: 400px; height: 400px;">

```bash
Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
[0,4]: [0,4] -> Pacific Ocean
      [0,4] -> Atlantic Ocean
[1,3]: [1,3] -> [0,3] -> Pacific Ocean
      [1,3] -> [1,4] -> Atlantic Ocean
[1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean
      [1,4] -> Atlantic Ocean
[2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean
      [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
[3,0]: [3,0] -> Pacific Ocean
      [3,0] -> [4,0] -> Atlantic Ocean
[3,1]: [3,1] -> [3,0] -> Pacific Ocean
      [3,1] -> [4,1] -> Atlantic Ocean
[4,0]: [4,0] -> Pacific Ocean
       [4,0] -> Atlantic Ocean
Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.
```

**Example 2:**

```bash
Input: heights = [[1]]
Output: [[0,0]]
Explanation: The water can flow from the only cell to the Pacific and Atlantic oceans.
```

**Constraints:**

- `m == heights.length`
- `n == heights[r].length`
- `1 <= m, n <= 200`
- `0 <= heights[r][c] <= 10^5`

## Hints/Notes

- 2025/01/07
- dfs
- No solution from 0x3F

## Solution

Language: **C++**

```C++
class Solution {
public:
    static constexpr int DIRs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int m, n;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            dfs(i, 0, pacific, heights);
            dfs(i, n - 1, atlantic, heights);
        }
        for (int j = 0; j < n; j++) {
            dfs(0, j, pacific, heights);
            dfs(m - 1, j, atlantic, heights);
        }
        vector<vector<int>> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }

    void dfs(int i, int j, vector<vector<int>>& ocean, vector<vector<int>>& heights) {
        if (ocean[i][j]) {
            return;
        }
        ocean[i][j] = 1;
        for (int k = 0; k < 4; k++) {
            int di = i + DIRs[k][0], dj = j + DIRs[k][1];
            if (di >= 0 && di < m && dj >= 0 && dj < n && heights[di][dj] >= heights[i][j] && !ocean[di][dj]) {
                dfs(di, dj, ocean, heights);
            }
        }
    }
};
```
