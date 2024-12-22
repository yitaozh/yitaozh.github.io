---
title: 51. N-Queens
categories: Leetcode
date: 2024-12-22 00:40:31
tags:
    - Array
    - Backtracking
---

[51. N-Queens](https://leetcode.com/problems/n-queens/description/?envType=problem-list-v2&envId=plakya4j)

## Description

The **n-queens**  puzzle is the problem of placing `n` queens on an `n x n` chessboard such that no two queens attack each other.

Given an integer `n`, return all distinct solutions to the **n-queens puzzle** . You may return the answer in **any order** .

Each solution contains a distinct board configuration of the n-queens' placement, where `'Q'` and `'.'` both indicate a queen and an empty space, respectively.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/queens.jpg" style="width: 600px; height: 268px;">

```bash
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
```

**Example 2:**

```bash
Input: n = 1
Output: [["Q"]]
```

**Constraints:**

- `1 <= n <= 9`

## Hints/Notes

- 2024/12/21
- backtracking
- [0x3F's solution](https://leetcode.cn/problems/n-queens/solutions/2079586/hui-su-tao-lu-miao-sha-nhuang-hou-shi-pi-mljv/)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> rows, cols, diag1, diag2;
    vector<vector<string>> res;
    int n;

    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        rows.resize(n, 0); cols.resize(n, 0); diag1.resize(2 * n, 0); diag2.resize(2 * n - 1, 0);
        dfs(0);
        return res;
    }

    void dfs(int index) {
        if (index == n) {
            vector<string> ans;
            for (int i = 0; i < n; i++) {
                string cow = string(rows[i], '.') + 'Q' + string(n - 1 - rows[i], '.');
                ans.push_back(cow);
            }
            res.push_back(ans);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!cols[i] && !diag1[i - index + n] && !diag2[index + i]) {
                rows[index] = i;
                cols[i] = diag1[i - index + n] = diag2[index + i] = true;
                dfs(index + 1);
                cols[i] = diag1[i - index + n] = diag2[index + i] = false;
            }
        }
    }
};
```
