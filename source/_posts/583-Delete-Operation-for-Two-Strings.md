---
title: 583. Delete Operation for Two Strings
categories: Leetcode
date: 2024-07-23 13:47:44
tags:
    - String
    - Dynamic Programming
---

[583. Delete Operation for Two Strings](https://leetcode.com/problems/delete-operation-for-two-strings/description/)

## Description

Given two strings `word1` and `word2`, return the minimum number of **steps**  required to make `word1` and `word2` the same.

In one **step** , you can delete exactly one character in either string.

**Example 1:**

```bash
Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
```

**Example 2:**

```bash
Input: word1 = "leetcode", word2 = "etco"
Output: 4
```

**Constraints:**

- `1 <= word1.length, word2.length <= 500`
- `word1` and `word2` consist of only lowercase English letters.

## Hints/Notes

- dp

## Solution

Language: **C++**

```C++
class Solution {
public:
    string word1_, word2_;
    vector<vector<int>> dp;

    int minDistance(string word1, string word2) {
        word1_ = word1;
        word2_ = word2;
        dp.resize(word1.size(), vector<int>(word2.size(), -1));
        int l = traverse(0, 0);
        return word1.size() - l + word2.size() - l;
    }

    int traverse(int i, int j) {
        if (i == word1_.size() || j == word2_.size()) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int res = 0;
        if (word1_[i] == word2_[j]) {
            res = 1 + traverse(i + 1, j + 1);
        } else {
            res = max(traverse(i, j + 1), traverse(i + 1, j));
        }
        dp[i][j] = res;
        return res;
    }
};
```

The other dp approach:

```C++
class Solution {
public:
    string word1_, word2_;
    vector<vector<int>> dp;

    int minDistance(string word1, string word2) {
        word1_ = word1;
        word2_ = word2;
        dp.resize(word1.size(), vector<int>(word2.size(), -1));
        int l = traverse(0, 0);
        return l;
    }

    int traverse(int i, int j) {
        if (i == word1_.size()) {
            return word2_.size() - j;
        }
        if (j == word2_.size()) {
            return word1_.size() - i;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int res = 0;
        if (word1_[i] == word2_[j]) {
            res = traverse(i + 1, j + 1);
        } else {
            res = min(1 + traverse(i, j + 1), 1 + traverse(i + 1, j));
        }
        dp[i][j] = res;
        return res;
    }
};
```
