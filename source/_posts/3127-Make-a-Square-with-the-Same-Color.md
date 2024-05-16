---
title: 3127. Make a Square with the Same Color
categories: Leetcode
date: 2024-05-16 00:26:35
tags:
    - Array
    - Matrix
    - Enumeration
---

[3127. Make a Square with the Same Color](https://leetcode.com/problems/make-a-square-with-the-same-color/description/)

You are given a 2D matrix `grid` of size `3 x 3` consisting only of characters `'B'` and `'W'`. Character `'W'` represents the white color, and character `'B'` represents the black color.

Your task is to change the color of **at most one**  cell so that the matrix has a `2 x 2` square where all cells are of the same color.

Return `true` if it is possible to create a `2 x 2` square of the same color, otherwise, return `false`.

**Example 1:**

```bash
Input: grid = [["B","W","B"],["B","W","W"],["B","W","B"]]

Output: true

Explanation:

It can be done by changing the color of the `grid[0][2]`.
```

**Example 2:**

```bash
Input: grid = [["B","W","B"],["W","B","W"],["B","W","B"]]

Output: false

Explanation:

It cannot be done by changing at most one cell.
```

**Example 3:**

```bash
Input: grid = [["B","W","B"],["B","W","W"],["B","W","W"]]

Output: true

Explanation:

The `grid` already contains a `2 x 2` square of the same color.
```

**Constraints:**

- `grid.length == 3`
- `grid[i].length == 3`
- `grid[i][j]` is either `'W'` or `'B'`.

## Hints/Notes

- N/A

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        for (int i = 0; i <= 1; i++) {
            for (int j = 0; j <= 1; j++) {
                // left = i, up = j
                vector<pair<int, int>> square = squareColor(i, j);
                int whiteCount = 0;
                for (auto cordinate : square) {
                    if (grid[cordinate.first][cordinate.second] == 'W') {
                        whiteCount++;
                    }
                }
                if (whiteCount != 2) {
                    return true;
                }
            }
        }
        return false;
    }

    vector<pair<int, int>> squareColor(int i, int j) {
        vector<pair<int, int>> res;
        res.push_back({i, j});
        res.push_back({i + 1, j});
        res.push_back({i, j + 1});
        res.push_back({i + 1, j + 1});
        return res;
    }
};
```
