---
title: 1201. Ugly Number III
categories: Leetcode
date: 2023-11-06 22:18:42
tags:
    - Math
    - Binary Search
    - Number Theory
---

[1201\. Ugly Number III](https://leetcode.com/problems/ugly-number-iii/)

## Description

Difficulty: **Medium**

Related Topics: [Math](https://leetcode.com/tag/https://leetcode.com/tag/math//), [Binary Search](https://leetcode.com/tag/https://leetcode.com/tag/binary-search//), [Number Theory](https://leetcode.com/tag/https://leetcode.com/tag/number-theory//)

An **ugly number** is a positive integer that is divisible by `a`, `b`, or `c`.

Given four integers `n`, `a`, `b`, and `c`, return the n<sup>th</sup> **ugly number**.

**Example 1:**

```bash
Input: n = 3, a = 2, b = 3, c = 5
Output: 4
Explanation: The ugly numbers are 2, 3, 4, 5, 6, 8, 9, 10... The 3rd is 4.
```

**Example 2:**

```bash
Input: n = 4, a = 2, b = 3, c = 4
Output: 6
Explanation: The ugly numbers are 2, 3, 4, 6, 8, 9, 10, 12... The 4th is 6.
```

**Example 3:**

```bash
Input: n = 5, a = 2, b = 11, c = 13
Output: 10
Explanation: The ugly numbers are 2, 4, 6, 8, 10, 11, 12, 13... The 5th is 10.
```

**Constraints:**

* 1 <= n, a, b, c <= 10<sup>9</sup>
* 1 <= *a * b * c* <= 10<sup>18</sup>
* It is guaranteed that the result will be in range [1, 2 * 10<sup>9</sup>].

## Hints/Notes

* binary search
* The difference between this and lc 264: it's divisible, not a, b, c are the only factors

## Solution

Language: **C++**

```C++
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        int left = 1, right = 2 * pow(10, 9);
        while (left < right) {
            int mid = left + (right - left) / 2;
            int numUglyNumber = find((long)mid, (long)a, (long)b, (long)c);
            if (numUglyNumber < n) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    int find(long n, long a, long b, long c) {
        long numUglyNumber = n / a + n / b + n / c - n / lcm(a, b) - n / lcm(a, c) - n / lcm(b, c) 
        + n / lcm(lcm(a, b), c);
        return numUglyNumber;
    }
};
```
