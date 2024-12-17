---
title: 3365. Rearrange K Substrings to Form Target String
categories: Leetcode
date: 2024-12-03 21:19:38
tags:
    - Hash Table
    - String
    - Sorting
---

[3365. Rearrange K Substrings to Form Target String](https://leetcode.com/problems/rearrange-k-substrings-to-form-target-string/description/)

## Description

You are given two strings `s` and `t`, both of which are anagrams of each other, and an integer `k`.

Your task is to determine whether it is possible to split the string `s` into `k` equal-sized substrings, rearrange the substrings, and concatenate them in any order to create a new string that matches the given string `t`.

Return `true` if this is possible, otherwise, return `false`.

An **anagram**  is a word or phrase formed by rearranging the letters of a different word or phrase, using all the original letters exactly once.

A **substring**  is a contiguous <b>non-empty</b> sequence of characters within a string.

**Example 1:**

```bash
Input: s = "abcd", t = "cdab", k = 2

Output: true
```

Explanation:

- Split `s` into 2 substrings of length 2: `["ab", "cd"]`.
- Rearranging these substrings as `["cd", "ab"]`, and then concatenating them results in `"cdab"`, which matches `t`.

**Example 2:**

```bash
Input: s = "aabbcc", t = "bbaacc", k = 3

Output: true
```

Explanation:

- Split `s` into 3 substrings of length 2: `["aa", "bb", "cc"]`.
- Rearranging these substrings as `["bb", "aa", "cc"]`, and then concatenating them results in `"bbaacc"`, which matches `t`.

**Example 3:**

```bash
Input: s = "aabbcc", t = "bbaacc", k = 2

Output: false
```

Explanation:

- Split `s` into 2 substrings of length 3: `["aab", "bcc"]`.
- These substrings cannot be rearranged to form `t = "bbaacc"`, so the output is `false`.

**Constraints:**

- `1 <= s.length == t.length <= 2 * 10^5`
- `1 <= k <= s.length`
- `s.length` is divisible by `k`.
- `s` and `t` consist only of lowercase English letters.
- The input is generated such that `s` and `t` are anagrams of each other.

## Hints/Notes

- 2024/12/03
- map
- [0x3F's solution](https://leetcode.cn/problems/rearrange-k-substrings-to-form-target-string/solutions/2998881/pai-xu-pythonjavacgo-by-endlesscheng-wslh/)
- Weekly Contest 425

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        unordered_map<string, int> m;
        int size = s.size();
        for (int i = 0; i < size; i += size / k) {
            string cur = s.substr(i, size / k);
            m[cur]++;
        }
        for (int i = 0; i < size; i += size / k) {
            string cur = t.substr(i, size / k);
            m[cur]--;
            if (m[cur] == 0) {
                m.erase(cur);
            }
        }
        return m.empty();
    }
};
```
