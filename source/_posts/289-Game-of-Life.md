---
title: 289. Game of Life
categories: Leetcode
date: 2025-04-19 16:59:17
tags:
    - Array
    - Matrix
    - Simulation
---

[289. Game of Life](https://leetcode.com/problems/game-of-life/description/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Description

According to <a href="https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life" target="_blank">Wikipedia's article</a>: "The <b>Game of Life</b>, also known simply as <b>Life</b>, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an `m x n` grid of cells, where each cell has an initial state: <b>live</b> (represented by a `1`) or <b>dead</b> (represented by a `0`). Each cell interacts with its <a href="https://en.wikipedia.org/wiki/Moore_neighborhood" target="_blank">eight neighbors</a> (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

- Any live cell with fewer than two live neighbors dies as if caused by under-population.
- Any live cell with two or three live neighbors lives on to the next generation.
- Any live cell with more than three live neighbors dies, as if by over-population.
- Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

The next state of the board is determined by applying the above rules simultaneously to every cell in the current state of the `m x n` grid `board`. In this process, births and deaths occur **simultaneously** .

Given the current state of the `board`, **update**  the `board` to reflect its next state.

**Note**  that you do not need to return anything.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/12/26/grid1.jpg" style="width: 562px; height: 322px;">

```bash
Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/12/26/grid2.jpg" style="width: 402px; height: 162px;">

```bash
Input: board = [[1,1],[1,0]]
Output: [[1,1],[1,1]]
```

**Constraints:**

- `m == board.length`
- `n == board[i].length`
- `1 <= m, n <= 25`
- `board[i][j]` is `0` or `1`.

**Follow up:**

- Could you solve it in-place? Remember that the board needs to be updated simultaneously: You cannot update some cells first and then use their updated values to update other cells.
- In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches upon the border of the array (i.e., live cells reach the border). How would you address these problems?

## Hints/Notes

- 2025/04/18 Q1
- matrix
- [Leetcode solution](https://leetcode.com/problems/game-of-life/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    static constexpr int DIRs[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};

    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        // the meaning of the board:
        //-1: current live, and future dead
        // 0: current dead, and future dead
        // 1: current live, and future live
        // 2: current dead, and future live
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int live_neighbors = 0;
                for (int k = 0; k < 8; k++) {
                    int di = i + DIRs[k][0], dj = j + DIRs[k][1];
                    if (di >= 0 && di < m && dj >= 0 && dj < n && abs(board[di][dj]) == 1) {
                        live_neighbors++;
                    }
                }
                if (board[i][j] == 1) {
                    if (live_neighbors < 2 || live_neighbors > 3) {
                        board[i][j] = -1;
                    }
                } else {
                    if (live_neighbors == 3) {
                        board[i][j] = 2;
                    }
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] > 0) {
                    board[i][j] = 1;
                } else {
                    board[i][j] = 0;
                }
            }
        }
    }
};
```
