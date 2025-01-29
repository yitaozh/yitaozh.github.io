---
title: 1778. Shortest Path in a Hidden Grid
categories: Leetcode
date: 2025-01-29 16:30:51
tags:
    - Depth-First Search
    - Breadth-First Search
    - Graph
    - Interactive
---

[1778. Shortest Path in a Hidden Grid](https://leetcode.com/problems/shortest-path-in-a-hidden-grid/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

This is an **interactive problem** .

There is a robot in a hidden grid, and you are trying to get it from its starting cell to the target cell in this grid. The grid is of size `m x n`, and each cell in the grid is either empty or blocked. It is **guaranteed**  that the starting cell and the target cell are different, and neither of them is blocked.

You want to find the minimum distance to the target cell. However, you **do not know**  the grid's dimensions, the starting cell, nor the target cell. You are only allowed to ask queries to the `GridMaster` object.

Thr `GridMaster` class has the following functions:

- `boolean canMove(char direction)` Returns `true` if the robot can move in that direction. Otherwise, it returns `false`.
- `void move(char direction)` Moves the robot in that direction. If this move would move the robot to a blocked cell or off the grid, the move will be **ignored** , and the robot will remain in the same position.
- `boolean isTarget()` Returns `true` if the robot is currently on the target cell. Otherwise, it returns `false`.

Note that `direction` in the above functions should be a character from `{'U','D','L','R'}`, representing the directions up, down, left, and right, respectively.

Return the **minimum distance**  between the robot's initial starting cell and the target cell. If there is no valid path between the cells, return `-1`.

**Custom testing:**

The test input is read as a 2D matrix `grid` of size `m x n` where:

- `grid[i][j] == -1` indicates that the robot is in cell `(i, j)` (the starting cell).
- `grid[i][j] == 0` indicates that the cell `(i, j)` is blocked.
- `grid[i][j] == 1` indicates that the cell `(i, j)` is empty.
- `grid[i][j] == 2` indicates that the cell `(i, j)` is the target cell.

There is exactly one `-1` and `2` in `grid`. Remember that you will **not**  have this information in your code.

**Example 1:**

```bash
Input: grid = [[1,2],[-1,0]]
Output: 2
Explanation: One possible interaction is described below:
The robot is initially standing on cell (1, 0), denoted by the -1.
- master.canMove('U') returns true.
- master.canMove('D') returns false.
- master.canMove('L') returns false.
- master.canMove('R') returns false.
- master.move('U') moves the robot to the cell (0, 0).
- master.isTarget() returns false.
- master.canMove('U') returns false.
- master.canMove('D') returns true.
- master.canMove('L') returns false.
- master.canMove('R') returns true.
- master.move('R') moves the robot to the cell (0, 1).
- master.isTarget() returns true.
We now know that the target is the cell (0, 1), and the shortest path to the target cell is 2.
```

**Example 2:**

```bash
Input: grid = [[0,0,-1],[1,1,1],[2,0,0]]
Output: 4
Explanation:The minimum distance between the robot and the target cell is 4.
```

**Example 3:**

```bash
Input: grid = [[-1,0],[0,2]]
Output: -1
Explanation:There is no path from the robot to the target cell.
```

**Constraints:**

- `1 <= n, m <= 500`
- `m == grid.length`
- `n == grid[i].length`
- `grid[i][j]` is either `-1`, `0`, `1`, or `2`.
- There is **exactly one**  `-1` in `grid`.
- There is **exactly one**  `2` in `grid`.

## Hints/Notes

- 2025/01/29
- dfs + bfs
- [Good solution](https://leetcode.com/problems/shortest-path-in-a-hidden-grid/solutions/1095348/java-dfs-bfs-with-explanations/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)(checked)

## Solution

Language: **C++**

```C++
/**
 * // This is the GridMaster's API interface.
 * // You should not implement it, or speculate about its implementation
 * class GridMaster {
 *   public:
 *     bool canMove(char direction);
 *     void move(char direction);
 *     boolean isTarget();
 * };
 */

class Solution {
public:
    static constexpr char DIRS[4] = {'U', 'L', 'R', 'D'};
    static constexpr int dirs[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    vector<vector<int>> dp;

    int findShortestPath(GridMaster &master) {
        dp.resize(1001, vector<int>(1001, -1));
        dfs(master, 0, 500, 500);
        int res = 1;
        queue<pair<int, int>> q;
        q.emplace(500, 500);
        dp[500][500] = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int dx = x + dirs[k][0], dy = y + dirs[k][1];
                    if (dp[dx][dy] == 2) {
                        return res;
                    } else if (dp[dx][dy] == 0) {
                        dp[dx][dy] = 1;
                        q.emplace(dx, dy);
                    }
                }
            }
            res++;
        }
        return -1;
    }

    void dfs(GridMaster &master, int step, int x, int y) {
        if (dp[x][y] != -1) {
            return;
        }
        if (master.isTarget()) {
            dp[x][y] = 2;
        } else {
            dp[x][y] = 0;
        }
        long res = INT_MAX;
        for (int i = 0; i < 4; i++) {
            int dx = x + dirs[i][0], dy = y + dirs[i][1];
            if (master.canMove(DIRS[i]) && dp[dx][dy] == -1) {
                master.move(DIRS[i]);
                dfs(master, step + 1, dx, dy);
                master.move(DIRS[3 - i]);
            }
        }
    }
};
```
