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

- 2024/07/19
- range dp
- note: subsequence not substring
- [0x3F's solution](https://leetcode.cn/problems/longest-palindromic-subsequence/solutions/2203001/shi-pin-jiao-ni-yi-bu-bu-si-kao-dong-tai-kgkg/)(checked)

## Solution

Language: **C++**

More intuitive way

```C++
class Solution {
public:
    vector<vector<int>> dp;

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        dp.resize(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        return dfs(s, 0, n - 1);
    }

    int dfs(string& s, int start, int end) {
        if (start > end) {
            return 0;
        }
        if (dp[start][end] != -1) {
            return dp[start][end];
        }
        if (s[start] == s[end]) {
            dp[start][end] = 2 + dfs(s, start + 1, end - 1);
        } else {
            dp[start][end] = max(dfs(s, start + 1, end), dfs(s, start, end - 1));
        }
        return dp[start][end];
    }
};
```

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
        for (int i = n - 1; i >= 0; i--) {
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
