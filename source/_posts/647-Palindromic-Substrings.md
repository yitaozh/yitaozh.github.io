---
title: 647. Palindromic Substrings
categories: Leetcode
date: 2024-12-29 23:12:22
tags:
    - Two Pointers
    - String
    - Dynamic Programming
---

[647. Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings/description/?envType=problem-list-v2&envId=plakya4j)

## Description

Given a string `s`, return the number of **palindromic substrings**  in it.

A string is a **palindrome**  when it reads the same backward as forward.

A **substring**  is a contiguous sequence of characters within the string.

**Example 1:**

```bash
Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
```

**Example 2:**

```bash
Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
```

**Constraints:**

- `1 <= s.length <= 1000`
- `s` consists of lowercase English letters.

## Hints/Notes

- 2024/12/29
- dp
- No solution from 0x3F

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<int>> dp;

    int countSubstrings(string s) {
        int n = s.size();
        dp.resize(n, vector<int>(n, -1));
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isParlindromic(i, j, s)) {
                    res++;
                }
            }
        }
        return res;
    }

    bool isParlindromic(int i, int j, string& s) {
        if (i >= j) {
            return true;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int& res = dp[i][j];
        if (s[i] != s[j]) {
            res = false;
            return res;
        }
        res = isParlindromic(i + 1, j - 1, s);
        return res;
    }
};
```
