---
title: 326. Power of Three
categories: Leetcode
date: 2025-05-02 23:18:50
tags:
    - Math
    - Recursion
---

[326. Power of Three](https://leetcode.com/problems/power-of-three/description/?envType=company&envId=google&favoriteSlug=google-three-months)

## Description

Given an integer <code>n</code>, return <code>true</code> if it is a power of three. Otherwise, return <code>false</code>.

An integer <code>n</code> is a power of three, if there exists an integer <code>x</code> such that <code>n == 3^x</code>.

**Example 1:**

```bash
Input: n = 27
Output: true
Explanation: 27 = 3^3
```

**Example 2:**

```bash
Input: n = 0
Output: false
Explanation: There is no x where 3^x = 0.
```

**Example 3:**

```bash
Input: n = -1
Output: false
Explanation: There is no x where 3^x = (-1).
```

**Constraints:**

- <code>-2^31 <= n <= 2^31 - 1</code>

**Follow up:**  Could you solve it without loops/recursion?

## Hints/Notes

- 2025/04/27 Q1
- math
- [Leetcode solution](https://leetcode.com/problems/power-of-three/editorial)

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) {
            return false;
        }
        while (n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
};
```
