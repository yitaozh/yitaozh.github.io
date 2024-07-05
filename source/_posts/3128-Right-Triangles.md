---
title: 3128. Right Triangles
categories: Leetcode
date: 2024-05-16 00:28:41
tags:
    - Array
    - Hash Table
    - Math
    - Combinatorics
    - Counting
---

[3128. Right Triangles](https://leetcode.com/problems/right-triangles/description/)

## Description

You are given a 2D boolean matrix `grid`.

Return an integer that is the number of **right triangles**  that can be made with the 3 elements of `grid` such that **all**  of them have a value of 1.

**Note:**

- A collection of 3 elements of `grid` is a **right triangle**  if one of its elements is in the **same row**  with another element and in the **same column**  with the third element. The 3 elements do not have to be next to each other.

**Example 1:**

<table border="1" cellspacing="3" style="border-collapse: separate; text-align: center;"><tbody><tr><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;">0</td><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid red; --darkreader-inline-border-top: #ff0000; --darkreader-inline-border-right: #ff0000; --darkreader-inline-border-bottom: #ff0000; --darkreader-inline-border-left: #ff0000;">1</td><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;">0</td></tr><tr><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;">0</td><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid red; --darkreader-inline-border-top: #ff0000; --darkreader-inline-border-right: #ff0000; --darkreader-inline-border-bottom: #ff0000; --darkreader-inline-border-left: #ff0000;">1</td><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid red; --darkreader-inline-border-top: #ff0000; --darkreader-inline-border-right: #ff0000; --darkreader-inline-border-bottom: #ff0000; --darkreader-inline-border-left: #ff0000;">1</td></tr><tr><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;">0</td><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;">1</td><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;">0</td></tr></tbody></table>

<table border="1" cellspacing="3" style="border-collapse: separate; text-align: center;"><tbody><tr><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;">0</td><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;">1</td><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;">0</td></tr><tr><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;">0</td><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid red; --darkreader-inline-border-top: #ff0000; --darkreader-inline-border-right: #ff0000; --darkreader-inline-border-bottom: #ff0000; --darkreader-inline-border-left: #ff0000;">1</td><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid red; --darkreader-inline-border-top: #ff0000; --darkreader-inline-border-right: #ff0000; --darkreader-inline-border-bottom: #ff0000; --darkreader-inline-border-left: #ff0000;">1</td></tr><tr><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;">0</td><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid red; --darkreader-inline-border-top: #ff0000; --darkreader-inline-border-right: #ff0000; --darkreader-inline-border-bottom: #ff0000; --darkreader-inline-border-left: #ff0000;">1</td><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;">0</td></tr></tbody></table>

```bash
Input: grid = [[0,1,0],[0,1,1],[0,1,0]]

Output: 2

Explanation:

There are two right triangles.
```

**Example 2:**

<table border="1" cellspacing="3" style="border-collapse: separate; text-align: center;"><tbody><tr><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;">1</td><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;">0</td><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;">0</td><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;">0</td></tr><tr><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;">0</td><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;">1</td><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;">0</td><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;">1</td></tr><tr><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;">1</td><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;">0</td><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;">0</td><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;">0</td></tr></tbody></table>

```bash
Input: grid = [[1,0,0,0],[0,1,0,1],[1,0,0,0]]

Output: 0

Explanation:

There are no right triangles.
```

**Example 3:**

<table border="1" cellspacing="3" style="border-collapse: separate; text-align: center;"><tbody><tr><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid red; --darkreader-inline-border-top: #ff0000; --darkreader-inline-border-right: #ff0000; --darkreader-inline-border-bottom: #ff0000; --darkreader-inline-border-left: #ff0000;">1</td><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;">0</td><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid red; --darkreader-inline-border-top: #ff0000; --darkreader-inline-border-right: #ff0000; --darkreader-inline-border-bottom: #ff0000; --darkreader-inline-border-left: #ff0000;">1</td></tr><tr><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid red; --darkreader-inline-border-top: #ff0000; --darkreader-inline-border-right: #ff0000; --darkreader-inline-border-bottom: #ff0000; --darkreader-inline-border-left: #ff0000;">1</td><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;">0</td><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;">0</td></tr><tr><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;">1</td><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;">0</td><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;">0</td></tr></tbody></table>

<table border="1" cellspacing="3" style="border-collapse: separate; text-align: center;"><tbody><tr><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid red; --darkreader-inline-border-top: #ff0000; --darkreader-inline-border-right: #ff0000; --darkreader-inline-border-bottom: #ff0000; --darkreader-inline-border-left: #ff0000;">1</td><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;">0</td><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid red; --darkreader-inline-border-top: #ff0000; --darkreader-inline-border-right: #ff0000; --darkreader-inline-border-bottom: #ff0000; --darkreader-inline-border-left: #ff0000;">1</td></tr><tr><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;">1</td><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;">0</td><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;">0</td></tr><tr><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid red; --darkreader-inline-border-top: #ff0000; --darkreader-inline-border-right: #ff0000; --darkreader-inline-border-bottom: #ff0000; --darkreader-inline-border-left: #ff0000;">1</td><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;">0</td><td data-darkreader-inline-border-bottom="" data-darkreader-inline-border-left="" data-darkreader-inline-border-right="" data-darkreader-inline-border-top="" style="padding: 5px 10px; border: 1px solid black; --darkreader-inline-border-top: #d2c3ad; --darkreader-inline-border-right: #d2c3ad; --darkreader-inline-border-bottom: #d2c3ad; --darkreader-inline-border-left: #d2c3ad;">0</td></tr></tbody></table>

```bash
Input: grid = [[1,0,1],[1,0,0],[1,0,0]]

Output:2

Explanation:

There are two right triangles.
```

**Constraints:**

- `1 <= grid.length <= 1000`
- `1 <= grid[i].length <= 1000`
- `0 <= grid[i][j] <= 1`

## Hints/Notes

- N/A

## Solution

Language: **C++**

```C++
class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int numRows = grid.size();
        int numColumns = grid[0].size();
        vector<int> rows(numRows, 0);
        vector<int> colomns(numColumns, 0);
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numColumns; j++) {
                if (grid[i][j] == 1) {
                    rows[i]++;
                    colomns[j]++;
                }
            }
        }
        long long res = 0;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numColumns; j++) {
                if (grid[i][j] == 1) {
                    res += (rows[i] - 1) * (colomns[j] - 1);
                }
            }
        }
        return res;
    }
};
```
