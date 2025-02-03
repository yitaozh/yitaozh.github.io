---
title: 392. Is Subsequence
categories: Leetcode
date: 2025-02-02 23:49:17
tags:
    - Two Pointers
    - String
    - Dynamic Programming
---

[392. Is Subsequence](https://leetcode.com/problems/is-subsequence/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

Given two strings `s` and `t`, return `true` if `s` is a **subsequence**  of `t`, or `false` otherwise.

A **subsequence**  of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., `"ace"` is a subsequence of `"abcde"` while `"aec"` is not).

**Example 1:**

```bash
Input: s = "abc", t = "ahbgdc"
Output: true
```

**Example 2:**

```bash
Input: s = "axc", t = "ahbgdc"
Output: false
```

**Constraints:**

- `0 <= s.length <= 100`
- `0 <= t.length <= 10^4`
- `s` and `t` consist only of lowercase English letters.

**Follow up:**  Suppose there are lots of incoming `s`, say `s<sub>1</sub>, s<sub>2</sub>, ..., s<sub>k</sub>` where `k >= 10^9`, and you want to check one by one to see if `t` has its subsequence. In this scenario, how would you change your code?

## Hints/Notes

- 2025/02/01
- two pointers
- [Leetcode solution](https://leetcode.com/problems/is-subsequence/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx1 = 0, idx2 = 0;
        while (idx1 < s.size() && idx2 < t.size()) {
            if (s[idx1] == t[idx2]) {
                idx1++;
            }
            idx2++;
        }
        return idx1 == s.size();
    }
};
```
