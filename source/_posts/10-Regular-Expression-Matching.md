---
title: 10. Regular Expression Matching
categories: Leetcode
date: 2024-10-03 10:58:46
tags:
    - String
    - Dynamic Programming
    - Recursion
---

[10. Regular Expression Matching](https://leetcode.com/problems/regular-expression-matching/description/)

## Description

Given an input string `s`and a pattern `p`, implement regular expression matching with support for `'.'` and `'*'` where:

- `'.'` Matches any single character.​​​​
- `'*'` Matches zero or more of the preceding element.

The matching should cover the **entire**  input string (not partial).

**Example 1:**

```bash
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
```

**Example 2:**

```bash
Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
```

**Example 3:**

```bash
Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
```

**Constraints:**

- `1 <= s.length<= 20`
- `1 <= p.length<= 20`
- `s` contains only lowercase English letters.
- `p` contains only lowercase English letters, `'.'`, and`'*'`.
- It is guaranteed for each appearance of the character `'*'`, there will be a previous valid character to match.

## Hints/Notes

- dp

## Solution

Language: **C++**

```C++
class Solution {
public:
    string s_, p_;
    // the meaning of dp[i][j]: is it possible to match
    // when we are at index i in s and index j in p
    vector<vector<int>> dp;

    bool isMatch(string s, string p) {
        s_ = s;
        p_ = p;
        dp.resize(s.size(), vector<int>(p.size(), -1));
        bool res = traverse(0, 0);
        return res;
    }

    bool traverse(int idx1, int idx2) {
        if (idx1 == s_.size() && idx2 == p_.size()) {
            return true;
        }
        if (idx2 == p_.size()) {
            return false;
        }
        if (idx1 == s_.size()) {
            // it means we cannot match an empty string
            if (idx2 == p_.size() - 1 || p_[idx2 + 1] != '*') {
                return false;
            } else {
                // try to match an empty string
                return traverse(idx1, idx2 + 2);
            }
        }
        if (dp[idx1][idx2] != -1) {
            return dp[idx1][idx2];
        }
        // the three cases we can continue:
        // 1. s[idx1] = p[idx2]
        // 2. s[idx1] != p[idx2] but p[idx2] = '.'
        // 3. s[idx2 + 1] = '*'
        if (s_[idx1] != p_[idx2] && p_[idx2] != '.' &&
            !(idx2 + 1 < p_.size() && p_[idx2 + 1] == '*')) {
            return false;
        }
        bool res = false;
        // the next item is not *, which means either the character
        // at idx1 and idx2 match or p_[idx2] = '.'
        if (idx2 == p_.size() - 1 || p_[idx2 + 1] != '*') {
            res = traverse(idx1 + 1, idx2 + 1);
        // it's a empty string match, i.e. any character with * is empty
        } else if (s_[idx1] != p_[idx2] && p_[idx2] != '.') {
            res = traverse(idx1, idx2 + 2);
        } else {
            // we need to decide how many characters to match with *
            char c = s_[idx1];
            res = traverse(idx1, idx2 + 2);
            for (int i = idx1; i < s_.size() && (s_[i] == c || p_[idx2] == '.');
                 i++) {
                res |= traverse(i + 1, idx2 + 2);
                if (res) {
                    break;
                }
            }
        }
        dp[idx1][idx2] = res;
        return res;
    }
};
```
