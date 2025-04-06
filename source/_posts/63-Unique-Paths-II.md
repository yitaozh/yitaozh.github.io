---
title: 63. Unique Paths II
categories: Leetcode
date: 2025-04-05 22:18:04
tags:
    - Array
    - Dynamic Programming
    - Matrix
---

[63. Unique Paths II](https://leetcode.com/problems/unique-paths-ii/description/?envType=company&envId=tiktok&favoriteSlug=tiktok-six-months)

## Description

You are given an `m x n` integer array `grid`. There is a robot initially located at the <b>top-left corner</b> (i.e., `grid[0][0]`). The robot tries to move to the **bottom-right corner**  (i.e., `grid[m - 1][n - 1]`). The robot can only move either down or right at any point in time.

An obstacle and space are marked as `1` or `0` respectively in `grid`. A path that the robot takes cannot include **any**  square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to `2 * 10^9`.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/11/04/robot1.jpg" style="width: 242px; height: 242px;">

```bash
Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/11/04/robot2.jpg" style="width: 162px; height: 162px;">

```bash
Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
```

**Constraints:**

- `m == obstacleGrid.length`
- `n == obstacleGrid[i].length`
- `1 <= m, n <= 100`
- `obstacleGrid[i][j]` is `0` or `1`.

## Hints/Notes

- 2025/04/03 Q3
- dp
- [Leetcode solution](https://leetcode.com/problems/unique-paths-ii/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    static constexpr int dirs[2][2] = {{1, 0}, {0, 1}};

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1]) {
            return 0;
        }
        dp.resize(m, vector<int>(n, -1));
        int res = dfs(0, 0, obstacleGrid);
        return res;
    }

    int dfs(int x, int y, vector<vector<int>>& obstacleGrid) {
        if (x == m - 1 && y == n - 1) {
            return 1;
        }
        if (dp[x][y] != -1) {
            return dp[x][y];
        }
        int& res = dp[x][y];
        res = 0;
        for (int k = 0; k < 2; k++) {
            int dx = x + dirs[k][0], dy = y + dirs[k][1];
            if (dx >= 0 && dx < m && dy >= 0 && dy < n && obstacleGrid[dx][dy] != 1) {
                res += dfs(dx, dy, obstacleGrid);
            }
        }
        return res;
    }
};
```
