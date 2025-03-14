---
title: 205. Isomorphic Strings
categories: Leetcode
date: 2025-03-14 02:17:55
tags:
    - Hash Table
    - String
---

[205. Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings/description/)

## Description

Given two strings `s` and `t`, determine if they are isomorphic.

Two strings `s` and `t` are isomorphic if the characters in `s` can be replaced to get `t`.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

**Example 1:**

```bash
Input: s = "egg", t = "add"

Output: true
```

Explanation:

The strings `s` and `t` can be made identical by:

- Mapping `'e'` to `'a'`.
- Mapping `'g'` to `'d'`.

**Example 2:**

```bash
Input: s = "foo", t = "bar"

Output: false
```

Explanation:

The strings `s` and `t` can not be made identical as `'o'` needs to be mapped to both `'a'` and `'r'`.

**Example 3:**

```bash
Input: s = "paper", t = "title"

Output: true
```

**Constraints:**

- `1 <= s.length <= 5 * 10^4`
- `t.length == s.length`
- `s` and `t` consist of any valid ascii character.

## Hints/Notes

- 2025/03/08 Q1
- map
- [Leetcode solution](https://leetcode.com/problems/isomorphic-strings/editorial/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m = s.size(), n = t.size();
        if (m != n) {
            return false;
        }
        unordered_map<char, char> mapping;
        unordered_set<char> mapped;
        for (int i = 0; i < n; i++) {
            if (mapping.contains(s[i]) && mapping[s[i]] != t[i]) {
                return false;
            }
            if (!mapping.contains(s[i]) && mapped.contains(t[i])) {
                return false;
            }
            mapping[s[i]] = t[i];
            mapped.insert(t[i]);
        }
        return true;
    }
};
```
