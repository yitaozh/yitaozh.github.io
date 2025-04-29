---
title: 69. Sqrt(x)
categories: Leetcode
date: 2025-04-29 02:20:53
tags:
    - Math
    - Binary Search
---

[69. Sqrt(x)](https://leetcode.com/problems/sqrtx/description/?envType=company&envId=tiktok&favoriteSlug=tiktok-three-months)

## Description

Given a non-negative integer <code>x</code>, return the square root of <code>x</code> rounded down to the nearest integer. The returned integer should be **non-negative**  as well.

You **must not use**  any built-in exponent function or operator.

- For example, do not use <code>pow(x, 0.5)</code> in c++ or <code>x ** 0.5</code> in python.

**Example 1:**

```bash
Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
```

**Example 2:**

```bash
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
```

**Constraints:**

- <code>0 <= x <= 2^31 - 1</code>

## Hints/Notes

- 2025/04/26 Q1
- binary search
- [Leetcode solution](https://leetcode.com/problems/sqrtx/editorial/?envType=company&envId=tiktok&favoriteSlug=tiktok-three-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    int mySqrt(int x) {
        int left = -1, right = 2 << 16;
        while (left + 1 < right) {
            long mid = (left + right) / 2;
            if (mid * mid == x) {
                return mid;
            } else if (mid * mid < x) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
```
