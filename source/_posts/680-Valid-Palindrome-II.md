---
title: 680. Valid Palindrome II
categories: Leetcode
date: 2025-01-15 00:41:26
tags:
    - Two Pointers
    - String
    - Greedy
---

[680. Valid Palindrome II](https://leetcode.com/problems/valid-palindrome-ii/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

Given a string `s`, return `true` if the `s` can be palindrome after deleting **at most one**  character from it.

**Example 1:**

```bash
Input: s = "aba"
Output: true
```

**Example 2:**

```bash
Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
```

**Example 3:**

```bash
Input: s = "abc"
Output: false
```

**Constraints:**

- `1 <= s.length <= 10^5`
- `s` consists of lowercase English letters.

## Hints/Notes

- 2025/01/14
- string
- No solution fromm 0x3F

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int m = word.size(), n = abbr.size(), j = 0;
        for (int i = 0; i < n; ) {
            if (isalpha(abbr[i])) {
                if (j >= word.size() || abbr[i++] != word[j++]) {
                    return false;
                }
            } else {
                if (abbr[i] == '0') {
                    return false;
                }
                int start = i;
                while (i < n && isdigit(abbr[i])) {
                    i++;
                }
                j += stoi(abbr.substr(start, i - start));
                if (j > m) {
                    return false;
                }
            }
        }
        return j == m;
    }
};
```
