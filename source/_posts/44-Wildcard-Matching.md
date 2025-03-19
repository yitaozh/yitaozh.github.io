---
title: 44. Wildcard Matching
categories: Leetcode
date: 2025-03-19 16:50:01
tags:
    - String
    - Dynamic Programming
    - Greedy
    - Recursion
---

[44. Wildcard Matching](https://leetcode.com/problems/wildcard-matching/description/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Description

Given an input string (`s`) and a pattern (`p`), implement wildcard pattern matching with support for `'?'` and `'*'` where:

- `'?'` Matches any single character.
- `'*'` Matches any sequence of characters (including the empty sequence).

The matching should cover the **entire**  input string (not partial).

**Example 1:**

```bash
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
```

**Example 2:**

```bash
Input: s = "aa", p = "*"
Output: true
Explanation:'*' matches any sequence.
```

**Example 3:**

```bash
Input: s = "cb", p = "?a"
Output: false
Explanation:'?' matches 'c', but the second letter is 'a', which does not match 'b'.
```

**Constraints:**

- `0 <= s.length, p.length <= 2000`
- `s` contains only lowercase English letters.
- `p` contains only lowercase English letters, `'?'` or `'*'`.

## Hints/Notes

- 2025/02/21 Q2
- dp
- [Leetcode solution](https://leetcode.com/problems/wildcard-matching/editorial/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int n1, n2;
    vector<vector<int>> dp;

    bool isMatch(string s, string p) {
        n1 = s.size();
        n2 = p.size();
        dp.resize(n1, vector<int>(n2, -1));
        return dfs(0, 0, s, p);
    }

    bool dfs(int idx1, int idx2, string& s, string& p) {
        if (idx1 == n1) {
            if (idx2 == n2) {
                return true;
            } else if (p[idx2] == '*') {
                return dfs(idx1, idx2 + 1, s, p);
            } else {
                return false;
            }
        }
        if (idx2 == n2) {
            return false;
        }
        if (dp[idx1][idx2] != -1) {
            return dp[idx1][idx2];
        }
        int& res = dp[idx1][idx2];
        if (s[idx1] == p[idx2] || p[idx2] == '?') {
            res = dfs(idx1 + 1, idx2 + 1, s, p);
            return res;
        } else if (p[idx2] == '*') {
            for (int idx = idx1; idx <= n1; idx++) {
                res = dfs(idx, idx2 + 1, s, p);
                if (res) {
                    return res;
                }
            }
        }
        res = false;
        return res;
    }
};
```
