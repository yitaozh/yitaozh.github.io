---
title: 72. Edit Distance
categories: Leetcode
date: 2024-07-16 00:25:32
tags:
    - String
    - Dynamic Programming
---

[72. Edit Distance](https://leetcode.com/problems/edit-distance/description/)

## Description

Given two strings `word1` and `word2`, return the minimum number of operations required to convert `word1` to `word2`.

You have the following three operations permitted on a word:

- Insert a character
- Delete a character
- Replace a character

**Example 1:**

```bash
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
```

**Example 2:**

```bash
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
```

**Constraints:**

- `0 <= word1.length, word2.length <= 500`
- `word1` and `word2` consist of lowercase English letters.

## Hints/Notes

- N/A

## Solution

Language: **C++**

```C++
class Solution {
public:
    string word1_, word2_;
    vector<vector<int>> dp;

    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        word1_ = word1;
        word2_ = word2;
        dp.resize(m, vector<int>(n, -1));
        int res = traverse(0, 0);
        return res;
    }

    int traverse(int idx1, int idx2) {
        if (idx2 == word2_.size()) {
            return word1_.size() - idx1;
        }
        if (idx1 == word1_.size()) {
            return word2_.size() - idx2;
        }
        if (dp[idx1][idx2] != -1) {
            return dp[idx1][idx2];
        }
        int ans = 0;
        if (word1_[idx1] == word2_[idx2]) {
            ans = traverse(idx1 + 1, idx2 + 1);
        } else {
            ans = min(traverse(idx1 + 1, idx2 + 1),         // replacement
                      min(traverse(idx1, idx2 + 1),         // insert
                          traverse(idx1 + 1, idx2))) + 1;   // delete
        }
        dp[idx1][idx2] = ans;
        return ans;
    }
};
```
