---
title: 529. Minesweeper
categories: Leetcode
date: 2025-02-23 13:40:09
tags:
    - Array
    - Depth-First Search
    - Breadth-First Search
    - Matrix
---

[529. Minesweeper](https://leetcode.com/problems/minesweeper/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

Let's play the minesweeper game (<a href="https://en.wikipedia.org/wiki/Minesweeper_(video_game)" target="_blank">Wikipedia</a>, <a href="http://minesweeperonline.com" target="_blank">online game</a>)!

You are given an `m x n` char matrix `board` representing the game board where:

- `'M'` represents an unrevealed mine,
- `'E'` represents an unrevealed empty square,
- `'B'` represents a revealed blank square that has no adjacent mines (i.e., above, below, left, right, and all 4 diagonals),
- digit (`'1'` to `'8'`) represents how many mines are adjacent to this revealed square, and
- `'X'` represents a revealed mine.

You are also given an integer array `click` where `click = [click<sub>r</sub>, click<sub>c</sub>]` represents the next click position among all the unrevealed squares (`'M'` or `'E'`).

Return the board after revealing this position according to the following rules:

- If a mine `'M'` is revealed, then the game is over. You should change it to `'X'`.
- If an empty square `'E'` with no adjacent mines is revealed, then change it to a revealed blank `'B'` and all of its adjacent unrevealed squares should be revealed recursively.
- If an empty square `'E'` with at least one adjacent mine is revealed, then change it to a digit (`'1'` to `'8'`) representing the number of adjacent mines.
- Return the board when no more squares will be revealed.

**Example 1:**

<img src="https://assets.leetcode.com/uploads/2023/08/09/untitled.jpeg" style="width: 500px; max-width: 400px; height: 269px;">

```bash
Input: board = [["E","E","E","E","E"],["E","E","M","E","E"],["E","E","E","E","E"],["E","E","E","E","E"]], click = [3,0]
Output: [["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]]
```

**Example 2:**

<img src="https://assets.leetcode.com/uploads/2023/08/09/untitled-2.jpeg" style="width: 489px; max-width: 400px; height: 269px;">

```bash
Input: board = [["B","1","E","1","B"],["B","1","M","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]], click = [1,2]
Output: [["B","1","E","1","B"],["B","1","X","1","B"],["B","1","1","1","B"],["B","B","B","B","B"]]
```

**Constraints:**

- `m == board.length`
- `n == board[i].length`
- `1 <= m, n <= 50`
- `board[i][j]` is either `'M'`, `'E'`, `'B'`, or a digit from `'1'` to `'8'`.
- `click.length == 2`
- `0 <= click<sub>r</sub> < m`
- `0 <= click<sub>c</sub> < n`
- `board[click<sub>r</sub>][click<sub>c</sub>]` is either `'M'` or `'E'`.

## Hints/Notes

- 2025/02/18 Q1
- dfs/bfs
- No solution from leetcode or 0x3F

## Solution

Language: **C++**

```C++
class Solution {
public:
    static constexpr int DIRs[8][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0},
                                     {-1, 1}, {-1, -1}, {1, -1}, {1, 1}};

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size(), n = board[0].size();
        int x = click[0], y = click[1];
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return board;
        }
        // now we should find all adjacent empty
        queue<pair<int, int>> q;
        q.emplace(x, y);
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            int numMines = 0;
            for (int i = 0; i < 8; i++) {
                int dx = x + DIRs[i][0], dy = y + DIRs[i][1];
                if (dx >= 0 && dx < m && dy >= 0 && dy < n && board[dx][dy] == 'M') {
                    numMines++;
                }
            }
            if (numMines) {
                board[x][y] = '0' + numMines;
            } else {
                board[x][y] = 'B';
                for (int i = 0; i < 8; i++) {
                    int dx = x + DIRs[i][0], dy = y + DIRs[i][1];
                    if (dx >= 0 && dx < m && dy >= 0 && dy < n && board[dx][dy] == 'E') {
                        board[dx][dy] = 'P';
                        q.emplace(dx, dy);
                    }
                }
            }
        }
        return board;
    }
};
```
