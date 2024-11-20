---
title: 3335. Total Characters in String After Transformations I
categories: Leetcode
date: 2024-11-20 14:55:54
tags:
    - Hash Table
    - Math
    - String
    - Dynamic Programming
    - Counting
---

[3335. Total Characters in String After Transformations I](https://leetcode.com/problems/total-characters-in-string-after-transformations-i/description/)

## Description

You are given a string `s` and an integer `t`, representing the number of **transformations**  to perform. In one **transformation** , every character in `s` is replaced according to the following rules:

- If the character is `'z'`, replace it with the string `"ab"`.
- Otherwise, replace it with the **next**  character in the alphabet. For example, `'a'` is replaced with `'b'`, `'b'` is replaced with `'c'`, and so on.

Return the **length**  of the resulting string after **exactly**  `t` transformations.

Since the answer may be very large, return it **modulo**  `10^9 + 7`.

**Example 1:**

```bash
Input: s = "abcyy", t = 2

Output: 7
```

Explanation:

- **First Transformation (t = 1)** :

  - `'a'` becomes `'b'`
  - `'b'` becomes `'c'`
  - `'c'` becomes `'d'`
  - `'y'` becomes `'z'`
  - `'y'` becomes `'z'`
  - String after the first transformation: `"bcdzz"`

- **Second Transformation (t = 2)** :

  - `'b'` becomes `'c'`
  - `'c'` becomes `'d'`
  - `'d'` becomes `'e'`
  - `'z'` becomes `"ab"`
  - `'z'` becomes `"ab"`
  - String after the second transformation: `"cdeabab"`

- **Final Length of the string** : The string is `"cdeabab"`, which has 7 characters.

**Example 2:**

```bash
Input: s = "azbk", t = 1

Output: 5
```

Explanation:

- **First Transformation (t = 1)** :

  - `'a'` becomes `'b'`
  - `'z'` becomes `"ab"`
  - `'b'` becomes `'c'`
  - `'k'` becomes `'l'`
  - String after the first transformation: `"babcl"`

- **Final Length of the string** : The string is `"babcl"`, which has 5 characters.

**Constraints:**

- `1 <= s.length <= 10^5`
- `s` consists only of lowercase English letters.
- `1 <= t <= 10^5`

## Hints/Notes

- 2024/11/04
- [0x3F's solution](https://leetcode.cn/problems/total-characters-in-string-after-transformations-i/solutions/2967041/zhuang-tai-ji-dp-ju-zhen-kuai-su-mi-you-6rmqh/)
- Weekly Contest 421

## Solution

Language: **C++**

```C++
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        array<long, 26> m;
        int n = s.size(), MOD = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            m[c]++;
        }
        for (int i = 0; i < t; i++) {
            array<long, 26> tmp(m);
            for (int j = 0; j < 26; j++) {
                m[j] = tmp[(j + 25) % 26];
                if (j == 1) {
                    m[j] = (m[j] + tmp[25]) % MOD;
                }
            }
        }
        long res = 0;
        for (int i = 0; i < 26; i++) {
            res = (res + m[i]) % MOD;
        }
        return res;
    }
};
```
