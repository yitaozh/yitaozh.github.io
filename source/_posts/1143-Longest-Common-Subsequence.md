---
title: 1143. Longest Common Subsequence
categories: Leetcode
date: 2024-07-16 13:11:42
tags:
    - String
    - Dynamic Programming
---

[1143. Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/description/)

## Description

Given two strings `text1` and `text2`, return the length of their longest **common subsequence** . If there is no **common subsequence** , return `0`.

A **subsequence**  of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

- For example, `"ace"` is a subsequence of `"abcde"`.

A **common subsequence**  of two strings is a subsequence that is common to both strings.

**Example 1:**

```bash
Input: text1 = "abcde", text2 = "ace"
Output: 3
Explanation: The longest common subsequence is "ace" and its length is 3.
```

**Example 2:**

```bash
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
```

**Example 3:**

```bash
Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
```

**Constraints:**

- `1 <= text1.length, text2.length <= 1000`
- `text1` and `text2` consist of only lowercase English characters.

## Hints/Notes

- 2024/07/16
- dp
- [0x3F's solution](https://leetcode.cn/problems/longest-common-subsequence/solutions/2133188/jiao-ni-yi-bu-bu-si-kao-dong-tai-gui-hua-lbz5/)(checked)

## Solution

Language: **C++**

```C++
class Solution {
public:
    string text1_;
    string text2_;
    vector<vector<int>> dp;

    int longestCommonSubsequence(string text1, string text2) {
        text1_ = text1;
        text2_ = text2;
        int m = text1.size(), n = text2.size();
        dp.resize(m, vector<int>(n, -1));
        int res = traverse(0, 0);
        return res;
    }

    int traverse(int i, int j) {
        if (i == text1_.size() || j == text2_.size()) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int res = 0;
        if (text1_[i] == text2_[j]) {
            res = 1 + traverse(i + 1, j + 1);
        } else {
            res = max(traverse(i, j + 1), traverse(i + 1, j));
        }
        dp[i][j] = res;
        return res;
    }
};
```
