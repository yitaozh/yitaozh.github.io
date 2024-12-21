---
title: 50. Pow(x, n)
categories: Leetcode
date: 2024-12-21 01:39:51
tags:
    - Math
    - Recursion
---

[50. Pow(x, n)](https://leetcode.com/problems/powx-n/description/?envType=problem-list-v2&envId=plakya4j)

## Description

Implement pow(x, n), which calculates `x` raised to the power `n` (i.e., `x^n`).

**Example 1:**

```bash
Input: x = 2.00000, n = 10
Output: 1024.00000
```

**Example 2:**

```bash
Input: x = 2.10000, n = 3
Output: 9.26100
```

**Example 3:**

```bash
Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25
```

**Constraints:**

- `-100.0 < x < 100.0`
- `-2^31 <= n <= 2^31-1`
- `n` is an integer.
- Either `x` is not zero or `n > 0`.
- `-10^4 <= x^n <= 10^4`

## Hints/Notes

- 2024/12/20
- fast power
- [0x3F's solution](https://leetcode.cn/problems/powx-n/solutions/2858114/tu-jie-yi-zhang-tu-miao-dong-kuai-su-mi-ykp3i/)

## Solution

Language: **C++**

```C++
class Solution {
public:
    double myPow(double x, int n) {
        double f = x, res = 1;
        long abs_n = abs((long)n);
        while(abs_n > 0) {
            if (abs_n % 2) {
                res = res * f;
            }
            f = f * f;
            abs_n /= 2;
        }
        return n > 0 ? res : 1 / res;
    }
};
```
