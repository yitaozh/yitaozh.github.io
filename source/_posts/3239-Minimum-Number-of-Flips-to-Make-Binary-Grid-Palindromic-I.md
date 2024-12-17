---
title: 3239. Minimum Number of Flips to Make Binary Grid Palindromic I
categories: Leetcode
date: 2024-08-14 23:51:15
tags:
    - Array
    - Two Pointers
    - Matrix
---

[3239. Minimum Number of Flips to Make Binary Grid Palindromic I](https://leetcode.com/problems/minimum-number-of-flips-to-make-binary-grid-palindromic-i/description/)

## Description

You are given an `m x n` binary matrix `grid`.

A row or column is considered **palindromic**  if its values read the same forward and backward.

You can **flip**  any number of cells in `grid` from `0` to `1`, or from `1` to `0`.

Return the **minimum**  number of cells that need to be flipped to make **either**  all rows **palindromic**  or all columns **palindromic** .

**Example 1:**

```bash
Input: grid = [[1,0,0],[0,0,0],[0,0,1]]

Output: 2
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/07/07/screenshot-from-2024-07-08-00-20-10.png" style="width: 420px; height: 108px;">

Flipping the highlighted cells makes all the rows palindromic.

**Example 2:**

```bash
Input: grid = [[0,1],[0,1],[0,0]]

Output: 1
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/07/07/screenshot-from-2024-07-08-00-31-23.png" style="width: 300px; height: 100px;">

Flipping the highlighted cell makes all the columns palindromic.

**Example 3:**

```bash
Input: grid = [[1],[0]]

Output: 0
```

Explanation:

All rows are already palindromic.

**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m * n <= 2 * 10^5`
- `0 <= grid[i][j] <= 1`

## Hints/Notes

- 2024/08/03
- [0x3F's solution](https://leetcode.cn/problems/minimum-number-of-flips-to-make-binary-grid-palindromic-i/solutions/2868250/fen-bie-ji-suan-pythonjavacgo-by-endless-771t/)(checked)
- Biweekly Contest 136

## Solution

Language: **C++**

```C++
class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int hRes = 0, vRes = 0, m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n / 2; j++) {
                if (grid[i][j] != grid[i][n - 1 - j]) {
                    hRes++;
                }
            }
        }
        for (int i = 0; i < m / 2; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != grid[m - 1 - i][j]) {
                    vRes++;
                }
            }
        }
        return min(hRes, vRes);
    }
};
```
