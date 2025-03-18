---
title: 7. Reverse Integer
categories: Leetcode
date: 2024-12-16 14:42:39
tags:
    - Math
---

[7. Reverse Integer](https://leetcode.com/problems/reverse-integer/description/?envType=problem-list-v2&envId=plakya4j)

## Description

Given a signed 32-bit integer `x`, return `x` with its digits reversed. If reversing `x` causes the value to go outside the signed 32-bit integer range `[-2^31, 2^31 - 1]`, then return `0`.

**Assume the environment does not allow you to store 64-bit integers (signed or unsigned).**

**Example 1:**

```bash
Input: x = 123
Output: 321
```

**Example 2:**

```bash
Input: x = -123
Output: -321
```

**Example 3:**

```bash
Input: x = 120
Output: 21
```

**Constraints:**

- `-2^31 <= x <= 2^31 - 1`

## Hints/Notes

- 2024/12/16
- digit
- No solution from 0x3F

## Solution

Language: **C++**

Correct solution:

```C++
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7))
                return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8))
                return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};
```

```C++
class Solution {
public:
    int reverse(int x) {
        long res = 0;
        while (x) {
            int digit = x % 10;
            int prev = res;
            res = res * 10 + digit;
            if ((int)res / 10 != prev) {
                return 0;
            }
            x /= 10;
        }
        return res;
    }
};
```
