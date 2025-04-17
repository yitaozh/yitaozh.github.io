---
title: 37. Sudoku Solver
categories: Leetcode
date: 2025-04-17 17:16:26
tags:
    - Array
    - Hash Table
    - Backtracking
    - Matrix
---

[37. Sudoku Solver](https://leetcode.com/problems/sudoku-solver/description/?envType=company&envId=doordash&favoriteSlug=doordash-more-than-six-months)

## Description

Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy **all of the following rules** :

- Each of the digits `1-9` must occur exactly once in each row.
- Each of the digits `1-9` must occur exactly once in each column.
- Each of the digits `1-9` must occur exactly once in each of the 9 `3x3` sub-boxes of the grid.

The `'.'` character indicates empty cells.

**Example 1:**

<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png" style="height: 250px; width: 250px;">

```bash
Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
Explanation:The input board is shown above and the only valid solution is shown below:
```

<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/3/31/Sudoku-by-L2G-20050714_solution.svg/250px-Sudoku-by-L2G-20050714_solution.svg.png" style="height: 250px; width: 250px;">

**Constraints:**

- `board.length == 9`
- `board[i].length == 9`
- `board[i][j]` is a digit or `'.'`.
- It is **guaranteed**  that the input board has only one solution.

## Hints/Notes

- 2025/04/14 Q2
- dfs
- [Leetcode solution](https://leetcode.com/problems/sudoku-solver/editorial/?envType=company&envId=doordash&favoriteSlug=doordash-more-than-six-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    // i, j to square:
    // i / 3 * 3 + j / 3
    int rows[9]{}, colomns[9]{}, squares[9]{};

    void solveSudoku(vector<vector<char>>& board) {
        int num_missing = 0;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int val = board[i][j] - '0';
                    int s = i / 3 * 3 + j / 3;
                    rows[i] |= 1 << val;
                    colomns[j] |= 1 << val;
                    squares[s] |= 1 << val;
                } else {
                    num_missing++;
                }
            }
        }
        if (num_missing) {
            dfs(0, 0, board, num_missing);
        }
        cout << num_missing << endl;
    }

    bool dfs(int x, int y, vector<vector<char>>& board, int& num_missing) {
        if (num_missing == 0) {
            return true;
        }
        if (x >= 9 || y >= 9) return true;
        if (board[x][y] == '.') {
            for (int k = 1; k <= 9; k++) {
                int s = x / 3 * 3 + y / 3;
                if (((rows[x] & (1 << k)) == 0)
                && ((colomns[y] & (1 << k)) == 0)
                && ((squares[s] & (1 << k)) == 0)) {
                    rows[x] ^= (1 << k);
                    colomns[y] ^= (1 << k);
                    squares[s] ^= (1 << k);
                    num_missing--;
                    board[x][y] = '0' + k;
                    // if we are at the end of the row, go to next row
                    bool res = false;
                    if (y == 8) {
                        res = dfs(x + 1, 0, board, num_missing);
                    } else {
                        res = dfs(x, y + 1, board, num_missing);
                    }
                    if (res) {
                        return true;
                    } else {
                        board[x][y] = '.';
                        num_missing++;
                        rows[x] ^= (1 << k);
                        colomns[y] ^= (1 << k);
                        squares[s] ^= (1 << k);
                    }
                }
            }
            return false;
        } else {
            if (y == 8) {
                return dfs(x + 1, 0, board, num_missing);
            } else {
                return dfs(x, y + 1, board, num_missing);
            }
        }
    }
};
```
