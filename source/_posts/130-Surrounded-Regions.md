---
title: 130. Surrounded Regions
categories: Leetcode
date: 2024-12-28 23:11:30
tags:
    - Array
    - Depth-First Search
    - Breadth-First Search
    - Union Find
    - Matrix
---

[130. Surrounded Regions](https://leetcode.com/problems/surrounded-regions/description/?envType=problem-list-v2&envId=plakya4j)

## Description

You are given an `m x n` matrix `board` containing **letters**  `'X'` and `'O'`, **capture regions**  that are **surrounded** :

- **Connect** : A cell is connected to adjacent cells horizontally or vertically.
- **Region** : To form a region **connect every**  `'O'` cell.
- **Surround** : The region is surrounded with `'X'` cells if you can **connect the region** with `'X'` cells and none of the region cells are on the edge of the `board`.

To capture a **surrounded region** , replace all `'O'`s with `'X'`s **in-place**  within the original board. You do not need to return anything.

**Example 1:**

```bash
Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/xogrid.jpg" style="width: 367px; height: 158px;">

In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

**Example 2:**

```bash
Input: board = [["X"]]

Output: [["X"]]
```

**Constraints:**

- `m == board.length`
- `n == board[i].length`
- `1 <= m, n <= 200`
- `board[i][j]` is `'X'` or `'O'`.

## Hints/Notes

- 2024/12/28
- bfs
- No solution from 0x3F

## Solution

Language: **C++**

```C++
class Solution {
public:
    int m, n;
    static constexpr int DIRs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    void solve(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();
        unordered_set<int> visited;
        queue<pair<int, int>> q;
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') {
                q.push({0, j});
                visited.insert(encode(0, j));
            }
            if (board[m - 1][j] == 'O') {
                q.push({m - 1, j});
                visited.insert(encode(m - 1, j));
            }
        }
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                q.push({i, 0});
                visited.insert(encode(i, 0));
            }
            if (board[i][n - 1] == 'O') {
                q.push({i, n - 1});
                visited.insert(encode(i, n - 1));
            }
        }
        while (!q.empty()) {
            auto& [x, y] = q.front();
            for (int i = 0; i < 4; i++) {
                int dx = x + DIRs[i][0], dy = y + DIRs[i][1];
                if (dx >= 0 && dx < m && dy >= 0 && dy < n && board[dx][dy] == 'O' && !visited.contains(encode(dx, dy))) {
                    q.push({dx, dy});
                    visited.insert(encode(dx, dy));
                }
            }
            q.pop();
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && !visited.contains(encode(i, j))) {
                    board[i][j] = 'X';
                }
            }
        }
    }

    int encode(int i, int j) {
        return i * n + j;
    }
};
```
