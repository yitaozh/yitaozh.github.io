---
title: 3407. Substring Matching Pattern
categories: Leetcode
date: 2025-01-10 17:06:33
tags:
    - String
    - String Matching
---

[3407. Substring Matching Pattern](https://leetcode.com/problems/substring-matching-pattern/description/)

## Description

You are given a string `s` and a pattern string `p`, where `p` contains **exactly one**  `'*'` character.

The `'*'` in `p` can be replaced with any sequence of zero or more characters.

Return `true` if `p` can be made a substring of `s`, and `false` otherwise.

**Example 1:**

```bash
Input: s = "leetcode", p = "ee*e"

Output: true
```

Explanation:

By replacing the `'*'` with `"tcod"`, the substring `"eetcode"` matches the pattern.

**Example 2:**

```bash
Input: s = "car", p = "c*v"

Output: false
```

Explanation:

There is no substring matching the pattern.

**Example 3:**

```bash
Input: s = "luck", p = "u*"

Output: true
```

Explanation:

The substrings `"u"`, `"uc"`, and `"uck"` match the pattern.

**Constraints:**

- `1 <= s.length <= 50`
- `1 <= p.length <= 50`
- `s` contains only lowercase English letters.
- `p` contains only lowercase English letters and exactly one `'*'`

## Hints/Notes

- 2025/01/12
- string
- [0x3F's solution](https://leetcode.cn/problems/substring-matching-pattern/solutions/3038944/ku-han-shu-jian-ji-xie-fa-pythonjavacgo-sukdf/)(checked)
- Biweekly Contest 147

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool hasMatch(const string& s, const string& p) {
        int star = p.find('*');
        int i = s.find(p.substr(0, star));
        return i != string::npos && s.substr(i + star).find(p.substr(star + 1)) != string::npos;
    }
};
```
