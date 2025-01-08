---
title: 338. Counting Bits
categories: Leetcode
date: 2025-01-08 00:50:12
tags:
    - Dynamic Programming
    - Bit Manipulation
---

[338. Counting Bits](https://leetcode.com/problems/counting-bits/description/?envType=problem-list-v2&envId=plakya4j)

## Description

Given an integer `n`, return an array `ans` of length `n + 1` such that for each `i` (`0 <= i <= n`), `ans[i]` is the **number of** `1`**'s**  in the binary representation of `i`.

**Example 1:**

```bash
Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
```

**Example 2:**

```bash
Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
```

**Constraints:**

- `0 <= n <= 10^5`

**Follow up:**

- It is very easy to come up with a solution with a runtime of `O(n log n)`. Can you do it in linear time `O(n)` and possibly in a single pass?
- Can you do it without using any built-in function (i.e., like `__builtin_popcount` in C++)?

## Hints/Notes

- 2025/01/06
- bit operation
- No solution from 0x3F

## Solution

Language: **C++**

```C++
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            res[i] = res[(i >> 1)] + i % 2;
        }
        return res;
    }
};
```
