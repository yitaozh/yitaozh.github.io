---
title: 36. Valid Sudoku
categories: Leetcode
date: 2024-12-20 00:25:02
tags:
    - Array
    - Hash Table
    - Matrix
---

[36. Valid Sudoku](https://leetcode.com/problems/valid-sudoku/description/?envType=problem-list-v2&envId=plakya4j)

## Description

Determine if a`9 x 9` Sudoku board is valid.Only the filled cells need to be validated**according to the following rules**:

- Each row must contain the digits`1-9` without repetition.
- Each column must contain the digits`1-9`without repetition.
- Each of the nine`3 x 3` sub-boxes of the grid must contain the digits`1-9`without repetition.

**Note:**

- A Sudoku board (partially filled) could be valid but is not necessarily solvable.
- Only the filled cells need to be validated according to the mentioned rules.

**Example 1:**

<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png" style="height: 250px; width: 250px;">

```bash
Input: board =
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
```

**Example 2:**

```bash
Input: board =
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the **5**  in the top left corner being modified to **8** . Since there are two 8's in the top left 3x3 sub-box, it is invalid.
```

**Constraints:**

- `board.length == 9`
- `board[i].length == 9`
- `board[i][j]` is a digit `1-9` or `'.'`.

## Hints/Notes

- 2024/11/19
- The key is to find mapping to box
- No solution from 0x3F

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool cols[9][9]{}, rows[9][9]{}, boxes[9][9]{};
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                int box = (i / 3) * 3 + j / 3;
                int idx = board[i][j] - '1';
                if (cols[i][idx] || rows[j][idx] || boxes[box][idx]) {
                    return false;
                }
                cols[i][idx] = rows[j][idx] = boxes[box][idx] = true;
            }
        }
        return true;
    }
};
```
