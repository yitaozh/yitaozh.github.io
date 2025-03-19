---
title: 161. One Edit Distance
categories: Leetcode
date: 2025-03-18 21:51:52
tags:
    - Two Pointers
    - String
---

[161. One Edit Distance](https://leetcode.com/problems/one-edit-distance/description/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Description

Given two strings `s` and `t`, return `true` if they are both one edit distance apart, otherwise return `false`.

A string `s` is said to be one distance apart from a string `t` if you can:

- Insert **exactly one**  character into `s` to get `t`.
- Delete **exactly one**  character from `s` to get `t`.
- Replace **exactly one**  character of `s` with **a different character**  to get `t`.

**Example 1:**

```bash
Input: s = "ab", t = "acb"
Output: true
Explanation: We can insert 'c' into sto gett.
```

**Example 2:**

```bash
Input: s = "", t = ""
Output: false
Explanation: We cannot get t from s by only one step.
```

**Constraints:**

- `0 <= s.length, t.length <= 10^4`
- `s` and `t` consist of lowercase letters, uppercase letters, and digits.

## Hints/Notes

- 2025/02/19 Q2
- string
- [Leetcode solution](https://leetcode.com/problems/one-edit-distance/editorial/?envType=company&envId=snapchat&favoriteSlug=snapchat-more-than-six-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int idx1 = 0, idx2 = 0;
        int n1 = s.size(), n2 = t.size();
        if (abs(n1 - n2) > 1) {
            return false;
        }
        if (n1 > n2) return isOneEditDistance(t, s);
        // so t is always the one shorter
        for (int i = 0; i < n1; i++) {
            if (s[i] != t[i]) {
                if (n1 != n2) {
                    return s.substr(i) == t.substr(i + 1);
                } else {
                    return s.substr(i + 1) == t.substr(i + 1);
                }
            }
        }
        // if we reach here, it means we didn't find unmatched character
        // if n1 == n2, then they are the same
        return n1 != n2;
    }
};
```
