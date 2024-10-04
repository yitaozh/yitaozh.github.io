---
title: 3257. Maximum Value Sum by Placing Three Rooks II
categories: Leetcode
date: 2024-10-03 23:41:23
tags:
    - Array
    - Dynamic Programming
    - Matrix
    - Enumeration
---

[3257. Maximum Value Sum by Placing Three Rooks II](https://leetcode.com/problems/maximum-value-sum-by-placing-three-rooks-ii/description/)

## Description

You are given a `m x n` 2D array `board` representing a chessboard, where `board[i][j]` represents the **value**  of the cell `(i, j)`.

Rooks in the **same**  row or column **attack**  each other. You need to place three rooks on the chessboard such that the rooks **do not**  **attack**  each other.

Return the **maximum**  sum of the cell **values**  on which the rooks are placed.

**Example 1:**

```bash
Input: board = [[-3,1,1,1],[-3,1,-3,1],[-3,2,1,1]]

Output: 4
```

Explanation:

<img alt="" src="https://assets.leetcode.com/uploads/2024/08/08/rooks2.png" style="width: 294px; height: 450px;">

We can place the rooks in the cells `(0, 2)`, `(1, 3)`, and `(2, 1)` for a sum of `1 + 1 + 2 = 4`.

**Example 2:**

```bash
Input: board = [[1,2,3],[4,5,6],[7,8,9]]

Output: 15
```

Explanation:

We can place the rooks in the cells `(0, 0)`, `(1, 1)`, and `(2, 2)` for a sum of `1 + 5 + 9 = 15`.

**Example 3:**

```bash
Input: board = [[1,1,1],[1,1,1],[1,1,1]]

Output: 3
```

Explanation:

We can place the rooks in the cells `(0, 2)`, `(1, 1)`, and `(2, 0)` for a sum of `1 + 1 + 1 = 3`.

**Constraints:**

- `3 <= m == board.length <= 500`
- `3 <= n == board[i].length <= 500`
- `-10^9 <= board[i][j] <= 10^9`

## Hints/Notes

- iterate the mid row
- preSum and suffixSum
- Biweekly Contest 137

## Solution

Language: **C++**

```C++
class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        // the pre, suf we need:
        //  when we reach a specific line, we want to know the top 3 biggest
        //  numbers in different colomn, so we need an array size of
        //  board.size(), with 3 pairs
        vector<vector<pair<int, int>>> pre, suf;
        int m = board.size(), n = board[0].size();
        suf.resize(m, vector<pair<int, int>>(3, make_pair(INT_MIN, -1)));
        vector<int> mx(3, INT_MIN), c(3, -1);
        for (int i = m - 1; i >= 0; i--) {
            update(mx, c, i, board);
            suf[i][0] = make_pair(mx[0], c[0]);
            suf[i][1] = make_pair(mx[1], c[1]);
            suf[i][2] = make_pair(mx[2], c[2]);
        }
        fill(mx.begin(), mx.end(), INT_MIN);
        fill(c.begin(), c.end(), -1);
        long long res = LLONG_MIN;
        for (int i = 0; i < m - 1; i++) {
            if (i) {
                for (int j = 0; j < n; j++) {
                    // now, iterate through the pre, suf
                    for (int k = 0; k < 3; k++) {
                        if (c[k] == j) {
                            continue;
                        }
                        for (int l = 0; l < 3; l++) {
                            if (suf[i + 1][l].second != j &&
                                suf[i + 1][l].second != c[k]) {
                                long long tmp = (long long)suf[i + 1][l].first +
                                                board[i][j] + mx[k];
                                res = max(tmp, res);
                                break;
                            }
                        }
                    }
                }
            }
            update(mx, c, i, board);
        }
        return res;
    }

    void update(vector<int>& m, vector<int>& c, int i,
                vector<vector<int>>& board) {
        int n = board[0].size();
        for (int j = 0; j < n; j++) {
            if (board[i][j] > m[0]) {
                if (j != c[0]) {
                    if (j != c[1]) {
                        m[2] = m[1];
                        c[2] = c[1];
                    }
                    m[1] = m[0];
                    c[1] = c[0];
                }
                // if j is equal to c[0], then we just need to update the m[0]
                // and c[0]
                m[0] = board[i][j];
                c[0] = j;
            } else if (board[i][j] > m[1] && j != c[0]) {
                if (j != c[1]) {
                    m[2] = m[1];
                    c[2] = c[1];
                }
                m[1] = board[i][j];
                c[1] = j;
            } else if (board[i][j] > m[2] && j != c[0] && j != c[1]) {
                m[2] = board[i][j];
                c[2] = j;
            }
        }
    }
};
```
