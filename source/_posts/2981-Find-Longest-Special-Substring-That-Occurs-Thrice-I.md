---
title: 2981. Find Longest Special Substring That Occurs Thrice I
categories: Leetcode
date: 2025-03-13 23:26:39
tags:
---

[2981. Find Longest Special Substring That Occurs Thrice I](https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/description/)

## Description

You are given a string `s` that consists of lowercase English letters.

A string is called **special**  if it is made up of only a single character. For example, the string `"abc"` is not special, whereas the strings `"ddd"`, `"zz"`, and `"f"` are special.

Return the length of the **longest special substring**  of `s` which occurs **at least thrice** , or `-1` if no special substring occurs at least thrice.

A **substring**  is a contiguous **non-empty**  sequence of characters within a string.

**Example 1:**

```bash
Input: s = "aaaa"
Output: 2
Explanation: The longest special substring which occurs thrice is "aa": substrings "**aa** aa", "a**aa** a", and "aa**aa** ".
It can be shown that the maximum length achievable is 2.
```

**Example 2:**

```bash
Input: s = "abcdef"
Output: -1
Explanation: There exists no special substring which occurs at least thrice. Hence return -1.
```

**Example 3:**

```bash
Input: s = "abcaba"
Output: 1
Explanation: The longest special substring which occurs thrice is "a": substrings "**a** bcaba", "abc**a** ba", and "abcab**a** ".
It can be shown that the maximum length achievable is 1.
```

**Constraints:**

- `3 <= s.length <= 50`
- `s` consists of only lowercase English letters.

## Hints/Notes

- 2025/03/03 Q3
- map
- [0x3F's solution](https://leetcode.cn/problems/find-longest-special-substring-that-occurs-thrice-i/solutions/2585837/fei-bao-li-zuo-fa-fen-lei-tao-lun-python-p1g2/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string, int> m;
        int n = s.size(), res = -1;
        for (int i = 0; i < n; ) {
            int start = i;
            while (s[i] == s[start]) {
                i++;
            }
            int len = i - start;
            string cur = s.substr(start, len);
            m[cur]++;
            if (m[cur] >= 3) res = max(res, (int)cur.size());
            cur.pop_back();
            if (!cur.empty()) {
                m[cur] += 2;
                if (m[cur] >= 3) {
                    res = max(res, (int)cur.size());
                }
                cur.pop_back();
                if (!cur.empty()) {
                    res = max(res, (int)cur.size());
                }
            }
        }
        return res;
    }
};
```
