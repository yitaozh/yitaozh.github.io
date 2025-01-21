---
title: 1216. Valid Palindrome III
categories: Leetcode
date: 2025-01-21 02:19:12
tags:
    - String
    - Dynamic Programming
---

[1216. Valid Palindrome III](https://leetcode.com/problems/valid-palindrome-iii/description/)

## Description

Given a string `s` and an integer `k`, return `true` if `s` is a `k`**-palindrome** .

A string is `k`**-palindrome**  if it can be transformed into a palindrome by removing at most `k` characters from it.

**Example 1:**

```bash
Input: s = "abcdeca", k = 2
Output: true
Explanation: Remove 'b' and 'e' characters.
```

**Example 2:**

```bash
Input: s = "abbababa", k = 1
Output: true
```

**Constraints:**

- `1 <= s.length <= 1000`
- `s` consists of only lowercase English letters.
- `1 <= k <= s.length`

## Hints/Notes

- 2025/01/19
- dp
- premium

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<int>> dp;

    bool isValidPalindrome(string s, int k) {
        int n = s.size();
        dp.resize(n, vector<int>(n, -1));
        int res = dfs(s, 0, n - 1);
        return res <= k;
    }

    int dfs(string& s, int left, int right) {
        if (left >= right) {
            return 0;
        }
        if (dp[left][right] != -1) {
            return dp[left][right];
        }
        int& res = dp[left][right];
        if (s[left] == s[right]) {
            res = dfs(s, left + 1, right - 1);
        } else {
            res =  min(dfs(s, left, right - 1), dfs(s, left + 1, right)) + 1;
        }
        return res;
    }
};
```
