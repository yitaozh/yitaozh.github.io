---
title: 3228. Maximum Number of Operations to Move Ones to the End
categories: Leetcode
date: 2024-07-23 14:01:53
tags:
    - String
    - Greedy
    - Counting
---

[3228. Maximum Number of Operations to Move Ones to the End](https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/description/)

## Description

You are given a binary string `s`.

You can perform the following operation on the string **any**  number of times:

- Choose **any**  index `i` from the string where `i + 1 < s.length` such that `s[i] == '1'` and `s[i + 1] == '0'`.
- Move the character `s[i]` to the **right**  until it reaches the end of the string or another `'1'`. For example, for `s = "010010"`, if we choose `i = 1`, the resulting string will be s = "0**001**10".

Return the **maximum**  number of operations that you can perform.

**Example 1:**

```bash
Input: s = "1001101"

Output: 4
```

Explanation:

We can perform the following operations:

- Choose index `i = 0`. The resulting string is s = "**001** 1101".
- Choose index `i = 4`. The resulting string is s = "0011**01** 1".
- Choose index `i = 3`. The resulting string is s = "001**01** 11".
- Choose index `i = 2`. The resulting string is s = "00**01** 111".

**Example 2:**

```bash
Input: s = "00111"

Output: 0
```

**Constraints:**

- `1 <= s.length <= 10^5`
- `s[i]` is either `'0'` or `'1'`.

## Hints/Notes

- Move 1s from left to right
- Weekly Contest 407

## Solution

Language: **C++**

```C++
class Solution {
public:
    int maxOperations(string s) {
        int curOnes = 0, res = 0;
        for (int i = 0; i < s.size();) {
            if (s[i] == '1') {
                curOnes++;
                i++;
            } else {
                while (i < s.size() && s[i] == '0') {
                    i++;
                }
                res += curOnes;
            }
        }
        return res;
    }
};
```
