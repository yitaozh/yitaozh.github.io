---
title: 2352. Equal Row and Column Pairs
categories: Leetcode
date: 2025-03-14 00:44:35
tags:
    - Array
    - Hash Table
    - Matrix
    - Simulation
---

[2352. Equal Row and Column Pairs](https://leetcode.com/problems/equal-row-and-column-pairs/description/)

## Description

Given a **0-indexed**  `n x n` integer matrix `grid`, return the number of pairs `(r<sub>i</sub>, c<sub>j</sub>)` such that row `r<sub>i</sub>` and column `c<sub>j</sub>` are equal.

A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2022/06/01/ex1.jpg" style="width: 150px; height: 153px;">

```bash
Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
Output: 1
Explanation: There is 1 equal row and column pair:
- (Row 2, Column 1): [2,7,7]
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2022/06/01/ex2.jpg" style="width: 200px; height: 209px;">

```bash
Input: grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
Output: 3
Explanation: There are 3 equal row and column pairs:
- (Row 0, Column 0): [3,1,2,2]
- (Row 2, Column 2): [2,4,2,2]
- (Row 3, Column 2): [2,4,2,2]
```

**Constraints:**

- `n == grid.length == grid[i].length`
- `1 <= n <= 200`
- `1 <= grid[i][j] <= 10^5`

## Hints/Notes

- 2025/03/04 Q3
- map
- [0x3F's solution](https://leetcode.com/problems/equal-row-and-column-pairs/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, int> rows;
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            string cur;
            for (int j = 0; j < n; j++) {
                cur += to_string(grid[i][j]) + ',';
            }
            rows[cur]++;
        }
        int res = 0;
        for (int j = 0; j < n; j++) {
            string cur;
            for (int i = 0; i < n; i++) {
                cur += to_string(grid[i][j]) + ',';
            }
            res += rows[cur];
        }
        return res;
    }
};
```
