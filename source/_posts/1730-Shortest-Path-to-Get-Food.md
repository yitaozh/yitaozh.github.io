---
title: 1730. Shortest Path to Get Food
categories: Leetcode
date: 2025-04-19 02:41:54
tags:
    - Array
    - Breadth-First Search
    - Matrix
---

[1730. Shortest Path to Get Food](https://leetcode.com/problems/shortest-path-to-get-food/description/?envType=company&envId=doordash&favoriteSlug=doordash-more-than-six-months)

## Description

You are starving and you want to eat food as quickly as possible. You want to find the shortest path to arrive at any food cell.

You are given an `m x n` character matrix, `grid`, of these different types of cells:

- `'*'` is your location. There is **exactly one** `'*'` cell.
- `'#'` is a food cell. There may be **multiple**  food cells.
- `'O'` is free space, and you can travel through these cells.
- `'X'` is an obstacle, and you cannot travel through these cells.

You can travel to any adjacent cell north, east, south, or west of your current location if there is not an obstacle.

Return the **length**  of the shortest path for you to reach **any**  food cell. If there is no path for you to reach food, return `-1`.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/09/21/img1.jpg" style="width: 300px; height: 201px;">

```bash
Input: grid = [["X","X","X","X","X","X"],["X","*","O","O","O","X"],["X","O","O","#","O","X"],["X","X","X","X","X","X"]]
Output: 3
Explanation: It takes 3 steps to reach the food.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/09/21/img2.jpg" style="width: 300px; height: 241px;">

```bash
Input: grid = [["X","X","X","X","X"],["X","*","X","O","X"],["X","O","X","#","X"],["X","X","X","X","X"]]
Output: -1
Explanation: It is not possible to reach the food.
```

**Example 3:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/09/21/img3.jpg" style="width: 300px; height: 188px;">

```bash
Input: grid = [["X","X","X","X","X","X","X","X"],["X","*","O","X","O","#","O","X"],["X","O","O","X","O","O","X","X"],["X","O","O","O","O","#","O","X"],["X","X","X","X","X","X","X","X"]]
Output: 6
Explanation: There can be multiple food cells. It only takes 6 steps to reach the bottom food.```

**Example 4:**

```bash
Input: grid = [["X","X","X","X","X","X","X","X"],["X","*","O","X","O","#","O","X"],["X","O","O","X","O","O","X","X"],["X","O","O","O","O","#","O","X"],["O","O","O","O","O","O","O","O"]]
Output: 5
```

**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 200`
- `grid[row][col]` is `'*'`, `'X'`, `'O'`, or `'#'`.
- The `grid` contains **exactly one**  `'*'`.

## Hints/Notes

- 2025/04/15 Q2
- bfs
- [Leetcode solution](https://leetcode.com/problems/shortest-path-to-get-food/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    static constexpr int DIRs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int getFood(vector<vector<char>>& grid) {
        int x, y, m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            bool exit = false;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '*') {
                    x = i; y = j; exit = true;
                    break;
                }
            }
            if (exit) break;
        }
        queue<pair<int, int>> q;
        q.emplace(x, y);
        grid[x][y] = 'X';
        int curStep = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int dx = x + DIRs[k][0], dy = y + DIRs[k][1];
                    if (dx >= 0 && dx < m && dy >= 0 && dy < n && grid[dx][dy] != 'X') {
                        if (grid[dx][dy] == '#') {
                            return curStep;
                        }
                        grid[dx][dy] = 'X';
                        q.emplace(dx, dy);
                    }
                }
            }
            curStep++;
        }
        return -1;
    }
};
```
