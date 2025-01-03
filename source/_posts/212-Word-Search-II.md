---
title: 212. Word Search II
categories: Leetcode
date: 2025-01-03 00:41:44
tags:
    - Array
    - String
    - Backtracking
    - Trie
    - Matrix
---

[212. Word Search II](https://leetcode.com/problems/word-search-ii/description/?envType=problem-list-v2&envId=plakya4j)

## Description

Given an `m x n` `board`of characters and a list of strings `words`, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where **adjacent cells**  are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

**Example 1:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/11/07/search1.jpg" style="width: 322px; height: 322px;">

```bash
Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]
```

**Example 2:**

<img alt="" src="https://assets.leetcode.com/uploads/2020/11/07/search2.jpg" style="width: 162px; height: 162px;">

```bash
Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []
```

**Constraints:**

- `m == board.length`
- `n == board[i].length`
- `1 <= m, n <= 12`
- `board[i][j]` is a lowercase English letter.
- `1 <= words.length <= 3 * 10^4`
- `1 <= words[i].length <= 10`
- `words[i]` consists of lowercase English letters.
- All the strings of `words` are unique.

## Hints/Notes

- 2025/01/02
- Trie
- No solution from 0x3F

## Solution

Language: **C++**

```C++
class Solution {
public:
    struct TrieNode {
        bool end = false;
        TrieNode* children[26]{};
    };

    static constexpr int DIRs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    unordered_set<string> res;
    string cur;
    int m, n;

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode root;
        for (auto& word : words) {
            TrieNode* head = &root;
            for (auto& c : word) {
                if (!head->children[c - 'a']) {
                    head->children[c - 'a'] = new TrieNode();
                }
                head = head->children[c - 'a'];
            }
            head->end = true;
        }

        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(&root, i, j, board);
            }
        }
        return vector<string>(res.begin(), res.end());
    }

    void dfs(TrieNode* node, int x, int y, vector<vector<char>>& board) {
        char c = board[x][y];
        int index = board[x][y] - 'a';
        if (index < 0) {
            return;
        }
        if (node->children[index] == nullptr) {
            return;
        }
        cur.push_back(c);
        board[x][y] = 'a' - 1;
        node = node->children[index];
        if (node->end) {
            res.insert(cur);
        }
        for (int i = 0; i < 4; i++) {
            int dx = x + DIRs[i][0], dy = y + DIRs[i][1];
            if (dx >= 0 && dx < m && dy >= 0 && dy < n) {
                dfs(node, dx, dy, board);
            }
        }
        cur.pop_back();
        board[x][y] = c;
    }
};
```
