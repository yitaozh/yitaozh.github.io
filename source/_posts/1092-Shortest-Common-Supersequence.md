---
title: 1092. Shortest Common Supersequence
categories: Leetcode
date: 2025-03-14 00:52:18
tags:
    - String
    - Dynamic Programming
---

[1092. Shortest Common Supersequence](https://leetcode.com/problems/shortest-common-supersequence/description/)

## Description

Given two strings `str1` and `str2`, return the shortest string that has both `str1` and `str2` as **subsequences** . If there are multiple valid strings, return **any**  of them.

A string `s` is a **subsequence**  of string `t` if deleting some number of characters from `t` (possibly `0`) results in the string `s`.

**Example 1:**

```bash
Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation:
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
```

**Example 2:**

```bash
Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"
```

**Constraints:**

- `1 <= str1.length, str2.length <= 1000`
- `str1` and `str2` consist of lowercase English letters.

## Hints/Notes

- 2025/03/05 Q1
- dp
- [0x3F's solution](https://leetcode.cn/problems/shortest-common-supersequence/solutions/2194615/cong-di-gui-dao-di-tui-jiao-ni-yi-bu-bu-auy8z/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<int>> dp;

    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        dp.resize(m, vector<int>(n, -1));
        int minLen = dfs(str1, str2, 0, 0);
        string res;
        int idx1 = 0, idx2 = 0;
        while (minLen > 0) {
            if (idx1 == str1.size()) {
                res += str2[idx2++];
                minLen--;
                continue;
            }
            if (idx2 == str2.size()) {
                res += str1[idx1++];
                minLen--;
                continue;
            }
            if (str1[idx1] == str2[idx2]) {
                res += str1[idx1];
                idx1++; idx2++;
                minLen--;
                continue;
            }
            if (idx1 + 1 < str1.size() && dp[idx1 + 1][idx2] == minLen - 1) {
                res += str1[idx1++];
                minLen--;
            } else {
                res += str2[idx2++];
                minLen--;
            }
        }
        return res;
    }

    int dfs(string& str1, string& str2, int idx1, int idx2) {
        if (idx1 == str1.size()) {
            return str2.size() - idx2;
        }
        if (idx2 == str2.size()) {
            return str1.size() - idx1;
        }
        if (dp[idx1][idx2] != -1) {
            return dp[idx1][idx2];
        }
        int res = INT_MAX;
        if (str1[idx1] == str2[idx2]) {
            res = 1 + dfs(str1, str2, idx1 + 1, idx2 + 1);
        } else {
            res = 1 + min(dfs(str1, str2, idx1 + 1, idx2), dfs(str1, str2, idx1, idx2 + 1));
        }
        dp[idx1][idx2] = res;
        return res;
    }
};
```
