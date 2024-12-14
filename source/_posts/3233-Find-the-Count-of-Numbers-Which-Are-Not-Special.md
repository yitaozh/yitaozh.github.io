---
title: 3233. Find the Count of Numbers Which Are Not Special
categories: Leetcode
date: 2024-08-14 23:46:21
tags:
    - Array
    - Math
    - Number Theory
---

[3233. Find the Count of Numbers Which Are Not Special](https://leetcode.com/problems/find-the-count-of-numbers-which-are-not-special/description/)

## Description

You are given 2 **positive**  integers `l` and `r`. For any number `x`, all positive divisors of `x` except `x` are called the **proper divisors**  of `x`.

A number is called **special**  if it has exactly 2 **proper divisors** . For example:

- The number 4 is special because it has proper divisors 1 and 2.
- The number 6 is not special because it has proper divisors 1, 2, and 3.

Return the count of numbers in the range `[l, r]` that are **not**  **special** .

**Example 1:**

```bash
Input: l = 5, r = 7

Output: 3
```

Explanation:

There are no special numbers in the range `[5, 7]`.

**Example 2:**

```bash
Input: l = 4, r = 16

Output: 11
```

Explanation:

The special numbers in the range `[4, 16]` are 4 and 9.

**Constraints:**

- `1 <= l <= r <= 10^9`

## Hints/Notes

- 2024/08/01
- only value that's square of prime number satisfies the need
- [0x3F's solution](https://leetcode.cn/problems/find-the-count-of-numbers-which-are-not-special/solutions/2860276/yu-chu-li-zhi-shu-o1hui-da-pythonjavacgo-7xaq/)(checked)
- Weekly Contest 408

## Solution

Language: **C++**

Pre-calculate the prime numbers

```C++
const int MX = 31622;
int pi[MX + 1];

auto init = [] {
    for (int i = 2; i <= MX; i++) {
        if (pi[i] == 0) {
            pi[i] = pi[i - 1] + 1;
            for (int j = i * i; j <= MX; j += i) {
                pi[j] = -1;
            }
        } else {
            pi[i] = pi[i - 1];
        }
    }
    return 0;
}();

// to calculate the number of prime numbers within l and r
res = pi[r] - pi[l - 1]
```

```C++
class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int count = 0;
        for (int i = 0; i * i <= r; i++) {
            if (i * i < l) {
                continue;
            }
            if (isPrime(i)) {
                count++;
            }
        }
        return r - l + 1 - count;
    }

    bool isPrime(int n) {
        if (n == 1) {
            return false;
        }
        int i = 2;
        while (i * i <= n) {
            if (n % i == 0) {
                return false;
            }
            i++;
        }
        return true;
    }
};
```
