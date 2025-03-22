---
title: 1347. Minimum Number of Steps to Make Two Strings Anagram
categories: Leetcode
date: 2025-03-22 03:51:07
tags:
    - Hash Table
    - String
    - Counting
---

[1347. Minimum Number of Steps to Make Two Strings Anagram](https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/description/?envType=company&envId=doordash&favoriteSlug=doordash-six-months)

## Description

You are given two strings of the same length `s` and `t`. In one step you can choose **any character**  of `t` and replace it with **another character** .

Return the minimum number of steps to make `t` an anagram of `s`.

An **Anagram**  of a string is a string that contains the same characters with a different (or the same) ordering.

**Example 1:**

```bash
Input: s = "bab", t = "aba"
Output: 1
Explanation: Replace the first 'a' in t with b, t = "bba" which is anagram of s.
```

**Example 2:**

```bash
Input: s = "leetcode", t = "practice"
Output: 5
Explanation: Replace 'p', 'r', 'a', 'i' and 'c' from t with proper characters to make t anagram of s.
```

**Example 3:**

```bash
Input: s = "anagram", t = "mangaar"
Output: 0
Explanation: "anagram" and "mangaar" are anagrams.
```

**Constraints:**

- `1 <= s.length <= 5 * 10^4`
- `s.length == t.length`
- `s` and `t` consist of lowercase English letters only.

## Hints/Notes

- 2025/02/27 Q3
- counting
- [Leetcode solution](https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/editorial/?envType=company&envId=doordash&favoriteSlug=doordash-six-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int minSteps(string s, string t) {
        int s_count[26]{}, t_count[26]{};
        int n = s.size();
        for (int i = 0; i < n; i++) {
            char c1 = s[i], c2 = t[i];
            s_count[c1 - 'a']++;
            t_count[c2 - 'a']++;
        }
        int res = 0;
        for (int i = 0; i < 26; i++) {
            if (s_count[i] != t_count[i]) {
                int diff = s_count[i] - t_count[i];
                if (diff > 0) {
                    // we need future t change to s
                    res += diff;
                }
            }
        }
        return res;
    }
};
```
