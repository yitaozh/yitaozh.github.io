---
title: 29. Divide Two Integers
categories: Leetcode
date: 2025-02-12 16:17:02
tags:
    - Math
    - Bit Manipulation
---

[29. Divide Two Integers](https://leetcode.com/problems/divide-two-integers/description/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Description

Given two integers `dividend` and `divisor`, divide two integers **without**  using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, `8.345` would be truncated to `8`, and `-2.7335` would be truncated to `-2`.

Return the **quotient**  after dividing `dividend` by `divisor`.

**Note:** Assume we are dealing with an environment that could only store integers within the **32-bit**  signed integer range: `[−2^31, 2^31 − 1]`. For this problem, if the quotient is **strictly greater than**  `2^31 - 1`, then return `2^31 - 1`, and if the quotient is **strictly less than**  `-2^31`, then return `-2^31`.

**Example 1:**

```bash
Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.
```

**Example 2:**

```bash
Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.
```

**Constraints:**

- `-2^31 <= dividend, divisor <= 2^31 - 1`
- `divisor != 0`

## Hints/Notes

- 2025/02/06 Q1
- [Leetcode solution](https://leetcode.com/problems/divide-two-integers/editorial/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int HALF_INT_MIN = -1073741824;

    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        int sign = 1;
        if (dividend < 0) {
            sign = -sign;
        } else {
            dividend = -dividend;
        }
        if (divisor < 0) {
            sign = -sign;
        } else {
            divisor = - divisor;
        }
        long res = 0;
        while (dividend <= divisor) {
            int val = divisor;
            int powerOfTwo = -1;
            while (val >= HALF_INT_MIN && val + val >= dividend) {
                val += val;
                powerOfTwo += powerOfTwo;
            }
            res += powerOfTwo;
            dividend -= val;
        }
        if (sign == 1) {
            res = -res;
        }
        return res;
    }
};
```

The linear solution(not passed)

```C++
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        int sign = 1;
        if (dividend < 0) {
            sign = -sign;
        } else {
            dividend = -dividend;
        }
        if (divisor < 0) {
            sign = -sign;
        } else {
            divisor = - divisor;
        }
        long res = 0, cur = divisor;
        while (dividend - divisor <= 0) {
            dividend -= divisor;
            res++;
        }
        if (sign == -1) {
            res = -res;
        }
        return res;
    }
};
```
