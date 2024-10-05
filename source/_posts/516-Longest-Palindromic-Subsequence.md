---
title: 516. Longest Palindromic Subsequence
categories: Leetcode
date: 2024-07-23 13:51:22
tags:
    - String
    - Dynamic Programming
---

[516. Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence/description/)

## Description

Given a string `s`, find the longest palindromic **subsequence** 's length in `s`.

A **subsequence**  is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

**Example 1:**

```bash
Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
```

**Example 2:**

```bash
Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
```

**Constraints:**

- `1 <= s.length <= 1000`
- `s` consists only of lowercase English letters.

## Hints/Notes

- dp
- note: subsequence not substring

## Solution

Language: **C++**

```C++
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        int res = 1;
        // because for the state transition
        //  dp[i][j] requires value at i + 1 and/or j - 1
        //  so the i is iterated reversely
        for (int i = n - 1; i >= 0; i- -) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};
```
