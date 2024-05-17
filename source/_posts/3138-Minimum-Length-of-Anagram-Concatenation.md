---
title: 3138. Minimum Length of Anagram Concatenation
categories: Leetcode
date: 2024-05-17 11:53:07
tags:
    - Hash Table
    - String
    - Counting
---

[3138. Minimum Length of Anagram Concatenation](https://leetcode.com/problems/minimum-length-of-anagram-concatenation/description/)

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

- iterate the factors

## Solution

Language: **C++**

```C++
class Solution {
public:
    int minAnagramLength(string s) {
        int size = s.size();
        for (int i = 1; i <= size / 2; i++) {
            if (size % i != 0) {
                continue;
            }
            map<int, int> m;
            int j;
            for (j = 0; j < i; j++) {
                m[s[j] - 'a']++;
            }
            int ok = true;
            while(j < size) {
                map<int, int> cur;
                for (int k = j; k < j + i; k++) {
                    cur[s[k] - 'a']++;
                }
                for (auto it : m) {
                    if (it.second != cur[it.first]) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) break;
                j += i;
            }
            if (ok) return i;
        }
        return size;
    }
};
```
