---
title: 264. Ugly Number II
categories: Leetcode
date: 2023-11-06 17:56:30
tags:
    - Hash Table
    - Math
    - Dynamic Programming
    - Heap (Priority Queue)
---

[264\. Ugly Number II](https://leetcode.com/problems/ugly-number-ii/)

## Description

Difficulty: **Medium**

Related Topics: [Hash Table](https://leetcode.com/tag/https://leetcode.com/tag/hash-table//), [Math](https://leetcode.com/tag/https://leetcode.com/tag/math//), [Dynamic Programming](https://leetcode.com/tag/https://leetcode.com/tag/dynamic-programming//), [Heap (Priority Queue)](https://leetcode.com/tag/https://leetcode.com/tag/heap-priority-queue//)

An **ugly number** is a positive integer whose prime factors are limited to `2`, `3`, and `5`.

Given an integer `n`, return _the_ n<sup>th</sup> _**ugly number**_.

**Example 1:**

```bash
Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
```

**Example 2:**

```bash
Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
```

**Constraints:**

* `1 <= n <= 1690`

## Hints/Notes

* It's like combining 3 linked lists
* No need to use priority queue, just compare the 3 values

## Solution

Language: **C++**

```C++
class Solution {
public:
    int nthUglyNumber(int n) {
        int val1 = 1, val2 = 1, val3 = 1;
        int index1 = 0, index2 = 0, index3 = 0;
        int index = 0;
        vector<int> res(n, 0);
        while (index < n) {
            int val = min({val1, val2, val3});
            res[index] = val;
            index++;
            if (val == val1) {
                val1 = res[index1] * 2;
                index1++;
            }
            if (val == val2) {
                val2 = res[index2] * 3;
                index2++;
            }
            if (val == val3) {
                val3 = res[index3] * 5;
                index3++;
            }
        }
        return res[n - 1];
    }
};
```
