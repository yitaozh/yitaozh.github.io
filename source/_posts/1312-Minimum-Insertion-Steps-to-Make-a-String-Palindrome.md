---
title: 1312. Minimum Insertion Steps to Make a String Palindrome
categories: Leetcode
date: 2024-07-26 01:03:07
tags:
    - String
    - Dynamic Programming
---

[1312. Minimum Insertion Steps to Make a String Palindrome](https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/)

## Description

Given a string `s`. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make `s` palindrome.

A <b>Palindrome String</b> is one that reads the same backward as well as forward.

**Example 1:**

```bash
Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.
```

**Example 2:**

```bash
Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
```

**Example 3:**

```bash
Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".
```

**Constraints:**

- `1 <= s.length <= 500`
- `s` consists of lowercase English letters.

## Hints/Notes

- digit dp

## Solution

Language: **C++**

```C++
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // state transition:
        // dp[i][j] is the number of insertion from i ~ j
        // base case: i == j => 0
        // if s[i] == s[j]
        //  => dp[i][j] = dp[i + 1][j - 1]
        // else
        //  => dp[i][j] = min(dp[i][j - 1], dp[i + 1][j]) + 1
        // the direction: when calculating s[i][j], we need
        // the dp value with bigger i and smaller j
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = i + 1 > j - 1 ? 0 : dp[i + 1][j - 1];
                } else {
                    dp[i][j] = i + 1 > j - 1 ? 1 : min(dp[i][j - 1], dp[i + 1][j]) + 1;
                }
            }
        }
        return dp[0][n - 1];
    }
};
```
