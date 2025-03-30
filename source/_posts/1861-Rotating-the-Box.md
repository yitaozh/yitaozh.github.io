---
title: 1861. Rotating the Box
categories: Leetcode
date: 2025-03-28 00:39:22
tags:
    - Array
    - Two Pointers
    - Matrix
---

[1861. Rotating the Box](https://leetcode.com/problems/rotating-the-box/description/)

## Description

You are given an `m x n` matrix of characters `boxGrid` representing a side-view of a box. Each cell of the box is one of the following:

- A stone `'#'`
- A stationary obstacle `'*'`
- Empty `'.'`

The box is rotated **90 degrees clockwise** , causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity **does not**  affect the obstacles' positions, and the inertia from the box's rotation **does not** affect the stones' horizontal positions.

It is **guaranteed**  that each stone in `boxGrid` rests on an obstacle, another stone, or the bottom of the box.

Return an `n x m` matrix representing the box after the rotation described above.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/04/08/rotatingtheboxleetcodewithstones.png" style="width: 300px; height: 150px;">

```bash
Input: boxGrid = [["#",".","#"]]
Output: [["."],
        ["#"],
        ["#"]]
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/04/08/rotatingtheboxleetcode2withstones.png" style="width: 375px; height: 195px;">

```bash
Input: boxGrid = [["#",".","*","."],
             ["#","#","*","."]]
Output: [["#","."],
        ["#","#"],
        ["*","*"],
        [".","."]]
```

**Example 3:**

<img alt="" src="https://assets.leetcode.com/uploads/2021/04/08/rotatingtheboxleetcode3withstone.png" style="width: 400px; height: 218px;">

```bash
Input: boxGrid = [["#","#","*",".","*","."],
             ["#","#","#","*",".","."],
             ["#","#","#",".","#","."]]
Output: [[".","#","#"],
        [".","#","#"],
        ["#","#","*"],
        ["#","*","."],
        ["#",".","*"],
        ["#",".","."]]
```

**Constraints:**

- `m == boxGrid.length`
- `n == boxGrid[i].length`
- `1 <= m, n <= 500`
- `boxGrid[i][j]` is either `'#'`, `'*'`, or `'.'`.

## Hints/Notes

- 2025/03/25 Q1
- matrix
- [Leetcode solution](https://leetcode.com/problems/rotating-the-box/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();
        vector<vector<char>> res(n, vector<char>(m, '.'));
        for (int i = 0; i < m; i++) {
            int emptySpot = n - 1;
            for (int j = n - 1; j >= 0; j--) {
                if (boxGrid[i][j] == '#') {
                    res[emptySpot][m - 1 - i] = '#';
                    emptySpot--;
                } else if (boxGrid[i][j] == '*') {
                    res[j][m - 1 - i] = '*';
                    emptySpot = j - 1;
                }
            }
        }
        return res;
    }
};
```
