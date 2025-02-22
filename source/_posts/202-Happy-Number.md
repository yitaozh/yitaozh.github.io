---
title: 202. Happy Number
categories: Leetcode
date: 2025-01-02 23:55:17
tags:
    - Hash Table
    - Math
    - Two Pointers
---

[202. Happy Number](https://leetcode.com/problems/happy-number/description/?envType=problem-list-v2&envId=plakya4j)

## Description

Write an algorithm to determine if a number `n` is happy.

A **happy number**  is a number defined by the following process:

- Starting with any positive integer, replace the number by the sum of the squares of its digits.
- Repeat the process until the number equals 1 (where it will stay), or it **loops endlessly in a cycle**  which does not include 1.
- Those numbers for which this process **ends in 1**  are happy.

Return `true` if `n` is a happy number, and `false` if not.

**Example 1:**

```bash
Input: n = 19
Output: true
Explanation:
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
```

**Example 2:**

```bash
Input: n = 2
Output: false
```

**Constraints:**

- `1 <= n <= 2^31 - 1`

## Hints/Notes

- 2025/01/02
- The important thing is the proof
- [Leetcode solution](https://leetcode.com/problems/happy-number/editorial/?envType=company&envId=facebook&favoriteSlug=facebook-three-months)

## Solution

Language: **C++**

```C++
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while (!s.contains(n) && n != 1) {
            s.insert(n);
            int next = 0;
            while (n) {
                int rev = n % 10;
                n /= 10;
                next += rev * rev;
            }
            n = next;
        }
        return n == 1;
    }
};
```
