---
title: 191. Number of 1 Bits
categories: Leetcode
date: 2025-01-02 23:41:02
tags:
    - Divide and Conquer
    - Bit Manipulation
---

[191. Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/description/?envType=problem-list-v2&envId=plakya4j)

## Description

Given a positive integer `n`, write a function that returns the number of set bits in its binary representation (also known as the <a href="http://en.wikipedia.org/wiki/Hamming_weight" target="_blank">Hamming weight</a>).

**Example 1:**

```bash
Input: n = 11

Output: 3
```

Explanation:

The input binary string **1011**  has a total of three set bits.

**Example 2:**

```bash
Input: n = 128

Output: 1
```

Explanation:

The input binary string **10000000**  has a total of one set bit.

**Example 3:**

```bash
Input: n = 2147483645

Output: 30
```

Explanation:

The input binary string **1111111111111111111111111111101**  has a total of thirty set bits.

**Constraints:**

- `1 <= n <= 2^31 - 1`

**Follow up:**  If this function is called many times, how would you optimize it?

## Hints/Notes

- 2025/01/01
- bit manipulation
- No solution from 0x3F

## Solution

Language: **C++**

Low bit:

```C++
class Solution {
public:
    int hammingWeight(int n) {
        int res = 0;
        while (n) {
            n &= n - 1;
            res++;
        }
        return res;
    }
};
```

```C++
class Solution {
public:
    int hammingWeight(int n) {
        int res = 0;
        while (n) {
            res += n % 2;
            n /= 2;
        }
        return res;
    }
};
```
