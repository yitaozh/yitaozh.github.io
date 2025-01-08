---
title: 371. Sum of Two Integers
categories: Leetcode
date: 2025-01-08 17:04:44
tags:
    - Math
    - Bit Manipulation
---

[371. Sum of Two Integers](https://leetcode.com/problems/sum-of-two-integers/description/?envType=problem-list-v2&envId=plakya4j)

## Description

Given two integers `a` and `b`, return the sum of the two integers without using the operators `+` and `-`.

**Example 1:**

```bash
Input: a = 1, b = 2
Output: 3
```

**Example 2:**

```bash
Input: a = 2, b = 3
Output: 5
```

**Constraints:**

- `-1000 <= a, b <= 1000`

## Hints/Notes

- 2025/01/07
- bit manipulation
- No solution from 0x3F

## Solution

Language: **C++**

```C++
class Solution {
public:
    int getSum(int a, int b) {
        if (abs(a) < abs(b)) {
            return getSum(b, a);
        }
        int res = 0;
        if (a * b < 0) {
            // the problem becomes a - b
            int borrow = 0, x = abs(a), y = abs(b), index = 0;
            while (x) {
                int bitX = x % 2;
                int bitY = y % 2;
                int bit = bitX ^ bitY ^ borrow;
                res |= bit << index++;
                if ((bitX < bitY) || (bitX == bitY && borrow)) {
                    borrow = 1;
                } else {
                    borrow = 0;
                }
                x >>= 1;
                y >>= 1;
            }
            if (a < 0) {
                res *= -1;
            }
        } else {
            // the problem becomes a + b
            int carry = 0, x = abs(a), y = abs(b), index = 0;
            while (x || carry) {
                int bitX = x % 2;
                int bitY = y % 2;
                int bit = bitX ^ bitY ^ carry;
                res |= bit << index++;
                if ((bitX && bitY) || (bitX && carry) || (bitY && carry)) {
                    carry = 1;
                } else {
                    carry = 0;
                }
                x >>= 1;
                y >>= 1;
            }
            if (a < 0) {
                res *= -1;
            }
        }
        return res;

    }
};
```
