---
title: 79. Word Search
categories: Leetcode
date: 2024-12-25 00:31:42
tags:
    - Array
    - String
    - Backtracking
    - Matrix
---

[79. Word Search](https://leetcode.com/problems/word-search/description/?envType=problem-list-v2&envId=plakya4j)

## Description

Given an `m x n` grid of characters `board` and a string `word`, return `true` if `word` exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/11/04/word2.jpg" style="width: 322px; height: 242px;">

```bash
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/11/04/word-1.jpg" style="width: 322px; height: 242px;">

```bash
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
```

**Example 3:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/10/15/word3.jpg" style="width: 322px; height: 242px;">

```bash
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
```

**Constraints:**

- `m == board.length`
- `n = board[i].length`
- `1 <= m, n <= 6`
- `1 <= word.length <= 15`
- `board` and `word` consists of only lowercase and uppercase English letters.

**Follow up:**  Could you use search pruning to make your solution faster with a larger `board`?

## Hints/Notes

- 2024/12/24
- dfs
- [0x3F's solution](https://leetcode.cn/problems/word-search/solutions/2927294/liang-ge-you-hua-rang-dai-ma-ji-bai-jie-g3mmm/)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    static constexpr int DIRs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    string word;
    int m, n;

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        this->word = word;
        vector<pair<int, int>> origins;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(i, j, 0, board)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(int x, int y, int index, vector<vector<char>>& board) {
        if (board[x][y] != word[index]) {
            return false;
        }
        if (index == word.size() - 1) {
            return true;
        }
        char c = board[x][y];
        board[x][y] = '.';
        for (int p = 0; p < 4; p++) {
            int dx = x + DIRs[p][0], dy = y + DIRs[p][1];
            if (dx >= 0 && dx < m && dy >= 0 && dy < n) {
                if(dfs(dx, dy, index + 1, board)) {
                    return true;
                }
            }
        }
        board[x][y] = c;
        return false;
    }
};
```
