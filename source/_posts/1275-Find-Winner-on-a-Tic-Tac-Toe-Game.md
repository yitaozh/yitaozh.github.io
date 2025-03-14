---
title: 1275. Find Winner on a Tic Tac Toe Game
categories: Leetcode
date: 2025-03-14 02:05:07
tags:
    - Array
    - Hash Table
    - Matrix
    - Simulation
---

[1275. Find Winner on a Tic Tac Toe Game](https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/description/)

## Description

**Tic-tac-toe**  is played by two players `A` and `B` on a `3 x 3` grid. The rules of Tic-Tac-Toe are:

- Players take turns placing characters into empty squares `' '`.
- The first player `A` always places `'X'` characters, while the second player `B` always places `'O'` characters.
- `'X'` and `'O'` characters are always placed into empty squares, never on filled ones.
- The game ends when there are **three**  of the same (non-empty) character filling any row, column, or diagonal.
- The game also ends if all squares are non-empty.
- No more moves can be played if the game is over.

Given a 2D integer array `moves` where `moves[i] = [row<sub>i</sub>, col<sub>i</sub>]` indicates that the `i^th` move will be played on `grid[row<sub>i</sub>][col<sub>i</sub>]`. return the winner of the game if it exists (`A` or `B`). In case the game ends in a draw return `"Draw"`. If there are still movements to play return `"Pending"`.

You can assume that `moves` is valid (i.e., it follows the rules of **Tic-Tac-Toe** ), the grid is initially empty, and `A` will play first.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/09/22/xo1-grid.jpg" style="width: 244px; height: 245px;">

```bash
Input: moves = [[0,0],[2,0],[1,1],[2,1],[2,2]]
Output: "A"
Explanation: A wins, they always play first.
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/09/22/xo2-grid.jpg" style="width: 244px; height: 245px;">

```bash
Input: moves = [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]
Output: "B"
Explanation: B wins.
```

**Example 3:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/09/22/xo3-grid.jpg" style="width: 244px; height: 245px;">

```bash
Input: moves = [[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]
Output: "Draw"
Explanation: The game ends in a draw since there are no moves to make.
```

**Constraints:**

- `1 <= moves.length <= 9`
- `moves[i].length == 2`
- `0 <= row<sub>i</sub>, col<sub>i</sub> <= 2`
- There are no repeated elements on `moves`.
- `moves` follow the rules of tic tac toe.

## Hints/Notes

- 2025/03/06 Q2
- matrix
- [Leetcode solution](https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<int> rols(3, 0), cols(3, 0);
        int diag1 = 0, diag2 = 0, curPlayer = 1;
        for (auto& move : moves) {
            int i = move[0], j = move[1];
            rols[i] += curPlayer; cols[j] += curPlayer;
            if (i == j) diag1 += curPlayer;
            if (i + j == 2) diag2 += curPlayer;
            if (rols[i] * curPlayer == 3 ||
                cols[j] * curPlayer == 3 ||
                diag1 * curPlayer == 3 || diag2 * curPlayer == 3) {
                    return curPlayer > 0 ? "A" : "B";
                }
            curPlayer *= -1;
        }
        if (moves.size() == 9) {
            return "Draw";
        } else {
            return "Pending";
        }
    }
};
```
