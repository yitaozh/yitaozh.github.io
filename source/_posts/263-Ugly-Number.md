---
title: 263. Ugly Number
categories: Leetcode
date: 2023-10-17 23:47:55
tags:
    - Math
---

[263\. Ugly Number](https://leetcode.com/problems/ugly-number/)

## Description

Difficulty: **Easy**

Related Topics: [Math](https://leetcode.com/tag/https://leetcode.com/tag/math//)

An **ugly number** is a positive integer whose prime factors are limited to `2`, `3`, and `5`.

Given an integer `n`, return `true` _if_ `n` _is an **ugly number**_.

**Example 1:**

```bash
Input: n = 6
Output: true
Explanation: 6 = 2 × 3
```

**Example 2:**

```bash
Input: n = 1
Output: true
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
```

**Example 3:**

```bash
Input: n = 14
Output: false
Explanation: 14 is not ugly since it includes the prime factor 7.
```

**Constraints:**

* -2<sup>31</sup> <= n <= 2<sup>31</sup> - 1

## Hints/Notes

* N/A

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool isUgly(int n) {
        if (n == 0) return false;
        while (n % 2 == 0) n /= 2;
        while (n % 3 == 0) n /= 3;
        while (n % 5 == 0) n /= 5;
        return n == 1;
    }
};
```
