---
title: 291. Word Pattern II
categories: Leetcode
date: 2024-05-24 14:49:37
tags:
    - Hash Table
    - String
    - Backtracking
---

[291. Word Pattern II](https://leetcode.com/problems/word-pattern-ii/description/?envType=weekly-question&envId=2024-05-22)

Given a `pattern` and a string `s`, return `true` if `s` **matches**  the `pattern`.

A string `s` <b>matches</b> a `pattern` if there is some **bijective mapping**  of single characters to **non-empty**  strings such that if each character in `pattern` is replaced by the string it maps to, then the resulting string is `s`. A **bijective mapping**  means that no two characters map to the same string, and no character maps to two different strings.

**Example 1:**

```bash
Input: pattern = "abab", s = "redblueredblue"
Output: true
Explanation: One possible mapping is as follows:
'a' -> "red"
'b' -> "blue"```

**Example 2:**

```bash
Input: pattern = "aaaa", s = "asdasdasdasd"
Output: true
Explanation: One possible mapping is as follows:
'a' -> "asd"
```

**Example 3:**

```bash
Input: pattern = "aabb", s = "xyzabcxzyabc"
Output: false
```

**Constraints:**

- `1 <= pattern.length, s.length <= 20`
- `pattern` and `s` consist of only lowercase English letters.

## Hints/Notes

- dynamic programming
- DCC 5/24/2024

## Solution

Language: **C++**

```C++
class Solution {
public:
    map<char, string> m;
    map<string, char> rev;

    bool wordPatternMatch(string pattern, string s) {
        return dfs(0, 0, pattern, s);
    }

    bool dfs(int i, int j, string& pattern, string& s) {
        if (i == pattern.size() && j == s.size()) {
            return true;
        }
        if (i == pattern.size() || j == s.size()) {
            return false;
        }
        if (pattern.size() - i > s.size() - j) {
            return false;
        }
        char c = pattern[i];
        if (m.contains(c)) {
            string t = m[c];
            int size = t.size();
            if (t == s.substr(j, size)) {
                return dfs(i + 1, j + size, pattern, s);
            } else {
                return false;
            }
        } else {
            for (int k = j + 1; k <= s.size(); k++) {
                string t = s.substr(j, k - j);
                if (rev.contains(t)) {
                    continue;
                }
                m[c] = t;
                rev[t] = c;
                if (dfs(i + 1, k, pattern, s)) {
                    return true;
                } else {
                    m.erase(c);
                    rev.erase(t);
                }
            }
        }
        return false;
    }
};
```
