---
title: 3121. Count the Number of Special Characters II
categories: Leetcode
date: 2024-05-16 00:01:51
tags:
  - Hash Table
  - String
---

[3121. Count the Number of Special Characters II](https://leetcode.com/problems/count-the-number-of-special-characters-ii/description/)

You are given a string `word`. A letter`c` is called **special**  if it appears **both**  in lowercase and uppercase in `word`, and **every**  lowercase occurrence of `c` appears before the **first**  uppercase occurrence of `c`.

Return the number of **special**  letters in `word`.

**Example 1:**

```bash
Input: word = "aaAbcBC"

Output: 3

Explanation:

The special characters are `'a'`, `'b'`, and `'c'`.
```

**Example 2:**

```bash
Input: word = "abc"

Output: 0

Explanation:

There are no special characters in `word`.
```

**Example 3:**

```bash
Input: word = "AbBCab"

Output: 0

Explanation:

There are no special characters in `word`.
```

**Constraints:**

- `1 <= word.length <= 2 * 10^5`
- `word` consists of only lowercase and uppercase English letters.

## Hints/Notes

- N/A

## Solution

Language: **C++**

```C++
class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<int, int> lower;
        map<int, int> higher;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (c >= 'A' && c <= 'Z' && !higher.contains(c - 'A')) {
                higher[c - 'A'] = i;
            } else if (c >= 'a' && c <= 'z') {
                lower[c - 'a'] = i;
            }
        }
        int res = 0;
        for (int i = 0; i < 26; i++) {
            if (higher.contains(i) && lower.contains(i) && higher[i] > lower[i]) {
                res++;
            }
        }
        return res;
    }
};
```
