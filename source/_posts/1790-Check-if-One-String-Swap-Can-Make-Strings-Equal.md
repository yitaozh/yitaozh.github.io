---
title: 1790. Check if One String Swap Can Make Strings Equal
categories: Leetcode
date: 2025-03-22 16:05:01
tags:
    - Hash Table
    - String
    - Counting
---

[1790. Check if One String Swap Can Make Strings Equal](https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/description/?envType=company&envId=doordash&favoriteSlug=doordash-six-months)

## Description

You are given two strings `s1` and `s2` of equal length. A **string swap**  is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.

Return `true` if it is possible to make both strings equal by performing **at most one string swap** on **exactly one**  of the strings. Otherwise, return `false`.

**Example 1:**

```bash
Input: s1 = "bank", s2 = "kanb"
Output: true
Explanation: For example, swap the first character with the last character of s2 to make "bank".
```

**Example 2:**

```bash
Input: s1 = "attack", s2 = "defend"
Output: false
Explanation: It is impossible to make them equal with one string swap.
```

**Example 3:**

```bash
Input: s1 = "kelb", s2 = "kelb"
Output: true
Explanation: The two strings are already equal, so no string swap operation is required.
```

**Constraints:**

- `1 <= s1.length, s2.length <= 100`
- `s1.length == s2.length`
- `s1` and `s2` consist of only lowercase English letters.

## Hints/Notes

- 2025/03/15 Q1
- hashMap
- [Leetcode solution](https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        if (s2.size() != n) {
            return false;
        }
        if (s1 == s2) {
            return true;
        }
        int count1[26]{}, count2[26]{};
        int numDiff = 0;
        for (int i = 0; i < n; i++) {
            char& c1 = s1[i], &c2 = s2[i];
            if (c1 != c2) {
                numDiff++;
            }
            if (numDiff > 2) {
                return false;
            }
            count1[c1 - 'a']++;
            count2[c2 - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (count1[i] != count2[i]) {
                return false;
            }
        }
        return true;
    }
};
```
