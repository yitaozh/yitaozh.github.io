---
title: 3136. Valid Word
categories: Leetcode
date: 2024-05-17 11:49:57
tags:
    - String
---

[3136. Valid Word](https://leetcode.com/problems/valid-word/description/)

A word is considered **valid**  if:

- It contains a **minimum**  of 3 characters.
- It contains only digits (0-9), and English letters (uppercase and lowercase).
- It includes **at least**  one **vowel** .
- It includes **at least**  one **consonant** .

You are given a string `word`.

Return `true` if `word` is valid, otherwise, return `false`.

**Notes:**

- `'a'`, `'e'`, `'i'`, `'o'`, `'u'`, and their uppercases are **vowels** .
- A **consonant**  is an English letter that is not a vowel.

**Example 1:**

```bash
Input: word = "234Adas"

Output: true

Explanation:

This word satisfies the conditions.
```

**Example 2:**

```bash
Input: word = "b3"

Output: false

Explanation:

The length of this word is fewer than 3, and does not have a vowel.
```

**Example 3:**

```bash
Input: word = "a3$e"

Output: false

Explanation:

This word contains a `'$'` character and does not have a consonant.
```

**Constraints:**

- `1 <= word.length <= 20`
- `word` consists of English uppercase and lowercase letters, digits, `'@'`, `'#'`, and `'$'`.

## Hints/Notes

- N/A

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool isValid(string word) {
        int length = 0;
        bool vowels = false, consonant = false;
        for (char c : word) {
            length++;
            if (c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U') {
                vowels = true;
            } else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                consonant = true;
            } else if (c < '0' || c > '9') {
                return false;
            }
        }
        return length >= 3 && vowels && consonant;
    }
};
```
