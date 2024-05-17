---
title: 3137. Minimum Number of Operations to Make Word K-Periodic
categories: Leetcode
date: 2024-05-17 11:51:28
tags:
    - Hash Table
    - String
    - Counting
---

[3137. Minimum Number of Operations to Make Word K-Periodic](https://leetcode.com/problems/minimum-number-of-operations-to-make-word-k-periodic/description/)

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
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int maxCount = 0;
        map<string, int> m;
        for (int i = 0; i < word.size(); i = i + k) {
            string cur = word.substr(i, k);
            m[cur]++;
            maxCount = max(maxCount, m[cur]);
        }
        return word.size() / k - maxCount;
    }
};
```
