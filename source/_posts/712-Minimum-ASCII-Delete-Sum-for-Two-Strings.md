---
title: 712. Minimum ASCII Delete Sum for Two Strings
categories: Leetcode
date: 2024-07-23 13:48:52
tags:
    - String
    - Dynamic Programming
---

[712. Minimum ASCII Delete Sum for Two Strings](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/)

## Description

Given two strings `s1` and`s2`, return the lowest **ASCII**  sum of deleted characters to make two strings equal.

**Example 1:**

```bash
Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
```

**Example 2:**

```bash
Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let",
adds 100[d] + 101[e] + 101[e] to the sum.
Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
```

**Constraints:**

- `1 <= s1.length, s2.length <= 1000`
- `s1` and `s2` consist of lowercase English letters.

## Hints/Notes

- N/A

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<vector<int>> dp;
    int minimumDeleteSum(string s1, string s2) {
        dp.resize(s1.size(), vector<int>(s2.size(), INT_MAX));
        int res = traverse(s1, s2, 0, 0);
        return res;
    }

    int traverse(string& s1, string& s2, int i, int j) {
        if (i == s1.size() || j == s2.size()) {
            int res = 0;
            for (; i < s1.size(); i++) {
                res += s1[i];
            }
            for (; j < s2.size(); j++) {
                res += s2[j];
            }
            return res;
        }
        if (dp[i][j] != INT_MAX) {
            return dp[i][j];
        }
        int res = INT_MAX;
        if (s1[i] == s2[j]) {
            res = min(res, traverse(s1, s2, i + 1, j + 1));
        } else {
            res = min(res, s1[i] + traverse(s1, s2, i + 1, j));
            res = min(res, s2[j] + traverse(s1, s2, i, j + 1));
        }
        dp[i][j] = res;
        return res;
    }
};
```
