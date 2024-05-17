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

You are given a string `s`, which is known to be a concatenation of **anagrams**  of some string `t`.

Return the **minimum**  possible length of the string `t`.

An **anagram**  is formed by rearranging the letters of a string. For example, "aab", "aba", and, "baa" are anagrams of "aab".

**Example 1:**

```bash
Input: s = "abba"

Output: 2

Explanation:

One possible string `t` could be `"ba"`.
```

**Example 2:**

```bash
Input: s = "cdef"

Output: 4

Explanation:

One possible string `t` could be `"cdef"`, notice that `t` can be equal to `s`.
```

**Constraints:**

- `1 <= s.length <= 10^5`
- `s` consist only of lowercase English letters.

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
