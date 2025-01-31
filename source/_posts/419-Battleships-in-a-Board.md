---
title: 419. Battleships in a Board
categories: Leetcode
date: 2025-01-31 17:23:07
tags:
    - Array
    - Depth-First Search
    - Matrix
---

[419. Battleships in a Board](https://leetcode.com/problems/battleships-in-a-board/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

Given an `m x n` matrix `board` where each cell is a battleship `'X'` or empty `'.'`, return the number of the **battleships**  on `board`.

**Battleships**  can only be placed horizontally or vertically on `board`. In other words, they can only be made of the shape `1 x k` (`1` row, `k` columns) or `k x 1` (`k` rows, `1` column), where `k` can be of any size. At least one horizontal or vertical cell separates between two battleships (i.e., there are no adjacent battleships).

**Example 1:**

<img height="333" src="https://assets.leetcode.com/uploads/2024/06/21/image.png" width="333">

```bash
Input: board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
Output: 2
```

**Example 2:**

```bash
Input: board = [["."]]
Output: 0
```

**Constraints:**

- `m == board.length`
- `n == board[i].length`
- `1 <= m, n <= 200`
- `board[i][j]` is either `'.'` or `'X'`.

**Follow up:**  Could you do it in one-pass, using only `O(1)` extra memory and without modifying the values `board`?

## Hints/Notes

- 2025/01/31
- iteration
- [0x3F's solution](https://leetcode.cn/problems/battleships-in-a-board/solutions/2807145/yi-ci-bian-li-mei-ju-zhan-jian-qi-dian-p-34o7/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size(), res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X' && (i == 0 || board[i - 1][j] != 'X') && (j == 0 || board[i][j - 1] != 'X')) {
                    res++;
                }
            }
        }
        return res;
    }
};
```
