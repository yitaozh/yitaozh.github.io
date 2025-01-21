---
title: 118. Pascal's Triangle
categories: Leetcode
date: 2025-01-21 02:12:50
tags:
    - Array
    - Dynamic Programming
---

# [118. Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/description/)

## Description

Given an integer `numRows`, return the first numRows of **Pascal's triangle**.

In **Pascal's triangle**, each number is the sum of the two numbers directly above it as shown:

<img alt="" src="https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif" style="height: 240px; width: 260px;">

**Example 1:**

```bash
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
```

**Example 2:**

```bash
Input: numRows = 1
Output: [[1]]
```

**Constraints:**

- `1 <= numRows <= 30`

## Hints/Notes

- 2025/01/19
- [0x3F's solution](https://leetcode.cn/problems/pascals-triangle/solutions/2784222/jian-dan-ti-jian-dan-zuo-pythonjavaccgoj-z596/)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> c(numRows);
        for (int i = 0; i < numRows; i++) {
            c[i].resize(i + 1, 1);
            for (int j = 1; j < i; j++) {
                // 左上方的数 + 正上方的数
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            }
        }
        return c;
    }
};
```
