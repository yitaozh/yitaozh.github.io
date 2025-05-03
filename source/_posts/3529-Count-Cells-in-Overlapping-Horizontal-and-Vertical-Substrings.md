---
title: 3529. Count Cells in Overlapping Horizontal and Vertical Substrings
categories: Leetcode
date: 2025-05-03 02:34:25
tags:
    - Array
    - String
    - Rolling Hash
    - String Matching
    - Matrix
    - Hash Function
---

[3529. Count Cells in Overlapping Horizontal and Vertical Substrings](https://leetcode.com/problems/count-cells-in-overlapping-horizontal-and-vertical-substrings/description/?envType=company&envId=google&favoriteSlug=google-thirty-days)

## Description

You are given an <code>m x n</code> matrix <code>grid</code> consisting of characters and a string <code>pattern</code>.

A **horizontal substring**  is a contiguous sequence of characters read from left to right. If the end of a row is reached before the substring is complete, it wraps to the first column of the next row and continues as needed. You do **not**  wrap from the bottom row back to the top.

A **vertical substring**  is a contiguous sequence of characters read from top to bottom. If the bottom of a column is reached before the substring is complete, it wraps to the first row of the next column and continues as needed. You do **not**  wrap from the last column back to the first.

Count the number of cells in the matrix that satisfy the following condition:

- The cell must be part of **at least**  one horizontal substring and **at least**  one vertical substring, where **both**  substrings are equal to the given <code>pattern</code>.

Return the count of these cells.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2025/03/03/gridtwosubstringsdrawio.png" style="width: 150px; height: 187px;">

```bash
Input: grid = [["a","a","c","c"],["b","b","b","c"],["a","a","b","a"],["c","a","a","c"],["a","a","b","a"]], pattern = "abaca"

Output: 1
```

Explanation:

The pattern <code>"abaca"</code> appears once as a horizontal substring (colored blue) and once as a vertical substring (colored red), intersecting at one cell (colored purple).

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2025/03/03/gridexample2fixeddrawio.png" style="width: 150px; height: 150px;">

```bash
Input: grid = [["c","a","a","a"],["a","a","b","a"],["b","b","a","a"],["a","a","b","a"]], pattern = "aba"

Output: 4
```

Explanation:

The cells colored above are all part of at least one horizontal and one vertical substring matching the pattern <code>"aba"</code>.

**Example 3:**

```bash
Input: grid = [["a"]], pattern = "a"

Output: 1
```

**Constraints:**

- <code>m == grid.length</code>
- <code>n == grid[i].length</code>
- <code>1 <= m, n <= 1000</code>
- <code>1 <= m * n <= 10^5</code>
- <code>1 <= pattern.length <= m * n</code>
- <code>grid</code> and <code>pattern</code> consist of only lowercase English letters.

## Hints/Notes

- 2025/04/29 Q1
- string
- [0x3F's solution](https://leetcode.cn/problems/count-cells-in-overlapping-horizontal-and-vertical-substrings/solutions/3663069/kmp-chai-fen-shu-zu-pythonjavacgo-by-end-h5mz)
- Weekly/Biweekly Contest XXX

## Solution

Language: **C++**

```C++
class Solution {
public:
    int countCells(vector<vector<char>>& grid, string pattern) {
        int m = grid.size(), n = grid[0].size(), p = pattern.size();
        vector<vector<int>> flags(m, vector<int>(n, 0));
        string cur1, cur2;
        for (int i = 0; i < m * n; i++) {
            int x1 = (i / n) % m, y1 = i % n;
            int x2 = i % m, y2 = (i / m) % n;
            cur1.push_back(grid[x1][y1]);
            cur2.push_back(grid[x2][y2]);
            if (i >= p - 1) {
                if (cur1 == pattern) {
                    for (int j = 0; j < p; j++) {
                        int prev = i - j, prev_x = (prev / n) % m, prev_y = prev % n;
                        if (flags[prev_x][prev_y] & 1) {
                            break;
                        }
                        flags[prev_x][prev_y] |= 1;
                    }
                }
                if (cur2 == pattern) {
                    for (int j = 0; j < p; j++) {
                        int prev = i - j, prev_x = prev % m, prev_y = (prev / m) % n;
                        if (flags[prev_x][prev_y] & 2) {
                            break;
                        }
                        flags[prev_x][prev_y] |= 2;
                    }
                }
                cur1.erase(0, 1);
                cur2.erase(0, 1);
            }
        }
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (flags[i][j] == 3) {
                    res++;
                }
            }
        }
        return res;
    }
};
```
