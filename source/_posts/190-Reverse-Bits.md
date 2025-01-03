---
title: 190. Reverse Bits
categories: Leetcode
date: 2025-01-02 23:39:35
tags:
    - Divide and Conquer
    - Bit Manipulation
---

[190. Reverse Bits](https://leetcode.com/problems/reverse-bits/description/?envType=problem-list-v2&envId=plakya4j)

## Description

Reverse bits of a given 32 bits unsigned integer.

**Note:**

- Note that in some languages, such as Java, there is no unsigned integer type. In this case, both input and output will be given as a signed integer type. They should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.

- In Java, the compiler represents the signed integers using <a href="https://en.wikipedia.org/wiki/Two%27s_complement" target="_blank">2's complement notation</a>. Therefore, in **Example 2**  above, the input represents the signed integer `-3` and the output represents the signed integer `-1073741825`.

**Example 1:**

```bash
Input: n = 00000010100101000001111010011100
Output:    964176192 (00111001011110000010100101000000)
Explanation: The input binary string **00000010100101000001111010011100**  represents the unsigned integer 43261596, so return 964176192 which its binary representation is **00111001011110000010100101000000** .
```

**Example 2:**

```bash
Input: n = 11111111111111111111111111111101
Output:   3221225471 (10111111111111111111111111111111)
Explanation: The input binary string **11111111111111111111111111111101**  represents the unsigned integer 4294967293, so return 3221225471 which its binary representation is **10111111111111111111111111111111** .
```

**Constraints:**

- The input must be a **binary string**  of length `32`

**Follow up:**  If this function is called many times, how would you optimize it?

## Hints/Notes

- 2024/12/31
- bit manipulation
- No solution from 0x3F

## Solution

Language: **C++**

```C++
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int m = 31;
        uint32_t res = 0;
        while (n) {
            int residue = n % 2;
            n /= 2;
            res += residue << m;
            m--;
        }
        return res;
    }
};
```
