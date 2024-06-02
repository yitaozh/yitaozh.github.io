---
title: 3146. Permutation Difference between Two Strings
categories: Leetcode
date: 2024-05-22 11:58:53
tags:
    - Hash Table
    - String
---

[3146. Permutation Difference between Two Strings](https://leetcode.com/problems/permutation-difference-between-two-strings/description/)

## Description

You are given two strings `s` and `t` such that every character occurs at most once in `s` and `t` is a permutation of `s`.

The **permutation difference**  between `s` and `t` is defined as the **sum**  of the absolute difference between the index of the occurrence of each character in `s` and the index of the occurrence of the same character in `t`.

Return the **permutation difference**  between `s` and `t`.

**Example 1:**

```bash
Input: s = "abc", t = "bac"

Output: 2

Explanation:

For `s = "abc"` and `t = "bac"`, the permutation difference of `s` and `t` is equal to the sum of:

- The absolute difference between the index of the occurrence of `"a"` in `s` and the index of the occurrence of `"a"` in `t`.
- The absolute difference between the index of the occurrence of `"b"` in `s` and the index of the occurrence of `"b"` in `t`.
- The absolute difference between the index of the occurrence of `"c"` in `s` and the index of the occurrence of `"c"` in `t`.

That is, the permutation difference between `s` and `t` is equal to `|0 - 1| + |2 - 2| + |1 - 0| = 2`.
```

**Example 2:**

```bash
Input: s = "abcde", t = "edbac"

Output: 12

Explanation: The permutation difference between `s` and `t` is equal to `|0 - 3| + |1 - 2| + |2 - 4| + |3 - 1| + |4 - 0| = 12`.
```

**Constraints:**

- `1 <= s.length <= 26`
- Each character occurs at most once in `s`.
- `t` is a permutation of `s`.
- `s` consists only of lowercase English letters.

## Hints/Notes

- N/A

## Solution

Language: **C++**

```C++
class Solution {
public:
    int findPermutationDifference(string s, string t) {
        map<char, int> m;
        for (int i = 0; i < s.size(); i++) {
            m[s[i]] = i;
        }
        int res = 0;
        for (int i = 0; i < t.size(); i++) {
            res += abs(i - m[t[i]]);
        }
        return res;
    }
};
```
