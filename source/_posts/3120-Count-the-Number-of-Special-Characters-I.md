---
title: 3120. Count the Number of Special Characters I
categories: Leetcode
date: 2024-05-15 23:58:51
tags:
    - Hash Table
    - String
---

[3120. Count the Number of Special Characters I](https://leetcode.com/problems/count-the-number-of-special-characters-i/description/)

## Description

You are given a string `word`. A letter is called **special**  if it appears **both**  in lowercase and uppercase in `word`.

Return the number of **special**  letters in `word`.

**Example 1:**

```bash
Input: word = "aaAbcBC"

Output: 3

Explanation:

The special characters in `word` are `'a'`, `'b'`, and `'c'`.
```

**Example 2:**

```bash
Input: word = "abc"

Output: 0

Explanation:

No character in `word` appears in uppercase.
```

**Example 3:**

```bash
Input: word = "abBCab"

Output: 1

Explanation:

The only special character in `word` is `'b'`.
```

**Constraints:**

- `1 <= word.length <= 50`
- `word` consists of only lowercase and uppercase English letters.

## Hints/Notes

- N/A

## Solution

Language: **C++**

```C++
class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<int> s;
        for (char c : word) {
            s.insert(c - 'A');
        }
        int res = 0;
        for (int i = 0; i < 26; i++) {
            if (s.contains(i) && s.contains(i + 'a' - 'A')) {
                res++;
            }
        }
        return res;
    }
};
```
