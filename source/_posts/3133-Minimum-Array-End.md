---
title: 3133. Minimum Array End
categories: Leetcode
date: 2024-05-17 11:36:07
tags:
    - Bit Manipulation
---

[3133. Minimum Array End](https://leetcode.com/problems/minimum-array-end/description/)

You are given two integers `n` and `x`. You have to construct an array of **positive**  integers `nums` of size `n` where for every `0 <= i < n - 1`, `nums[i + 1]` is **greater than**  `nums[i]`, and the result of the bitwise `AND` operation between all elements of `nums` is `x`.

Return the **minimum**  possible value of `nums[n - 1]`.

**Example 1:**

```bash
Input: n = 3, x = 4

Output: 6

Explanation:

`nums` can be `[4,5,6]` and its last element is 6.
```

**Example 2:**

```bash
Input: n = 2, x = 7

Output: 15

Explanation:

`nums` can be `[7,15]` and its last element is 15.
```

**Constraints:**

- `1 <= n, x <= 10^8`

## Hints/Notes

- put 1 into the 0 slots of n

## Solution

Language: **C++**

```C++
class Solution {
public:
    long long minEnd(int n, int x) {
        long long res = x;
        int index = 0;
        n--;
        while (n) {
            while (index < 32 && x & (1 << index)) {
                index++;
            }
            res |= ((long)n % 2) << index++;
            n /= 2;
        }
        return res;
    }
};
```
